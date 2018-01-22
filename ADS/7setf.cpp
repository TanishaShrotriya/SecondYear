#include<iostream>
#include<string.h>
#define max 20
using namespace std;
//make for size of set

class set {

	int size;
	int data[max];
	int cnt;
	char name[30];

public:
	set() {

		size=0;
		for(int i=0;i<max;i++) {
           data[i]=0;
		}
		cnt=0;
		strcpy(name,"default");

	}
	~set() { };
    void add();
    void remove();
    void search();
    void display();
    set  intersect(set a);
    set  union_(set a);
    set  difference(set a);
    set  subset(set a);
    void reset();
};
void set:: reset() {
		size=0;
		for(int i=0;i<max;i++) {
           data[i]=0;
		}
		cnt=0;
		strcpy(name,"default");


}
void set::display() {
	cout<<"{ ";
	for(int i=0;i<size;i++) {
		cout<<data[i]<<" ";
		if(i!=(size-1))
			cout<<", ";
	}
	cout<<" }";

}
void set::remove() {
    int num;
	cout<<"\nEnter element to delete from set "<<name<<" \n";
    cin>>num;
	for(int i=0;i<size;i++) {
		 if(num==data[i] && i!=size) {
				 data[i]=data[i+1];
				 num=data[i+1];
	     }
	}
	size=size-1;
}
void set::search() {
   int num,flag=0;
   cout<<"\nEnter the element to search for in set "<<name<<"\n";
   cin>>num;
   for(int i=0;i<size;i++) {
	   if(num==data[i]) {
		   cout<<"\nElement found\n";
	       flag=1;
	       break;
	   }

   }
   if(flag==0) {
	   cout<<"\nElement not found\n";
   }
}
void set::add() {

  cout<<"\nEnter the name of set\n";
  cin>>name;	
  cout<<"\nEnter size of set\n";
  cin>>size;
  cout<<"\nEnter the data:\n";
  for(int i=0;i<size;i++) {
	  cin>>data[i];
  }
}

set set::intersect(set a) {

	set t;
	int flag=0;

	for(int i=0;i<size;i++) { // 3 4 5 6 7
		 for(int j=0;j<a.size;j++) { // 1 2 3 4  
			 if(a.data[j]==data[i]) {
				flag=1;
			    break;
			 }
		 }
		 if(flag==1) {
		    t.data[t.size++]=data[i];
	        flag=0;
	     }
	}
    cout<<"\nFor intersection_of_sets  ";
	return t;
}

set set::union_(set a) {
	set t;
	int flag;
	for(int i=0;i<size;i++) { // 1 2 3 4 || 3 4 5 6 7 
 		t.data[t.size++]=data[i];
	}
	for(int i=0;i<a.size;i++) { // 3 4 5 6 7 || 1 2 3 4 

		for(int j=0;j<size;j++) { // 1 2 3 4 || 3 4 5 6 7

			 if(a.data[i]==data[j]) {
			    flag=1;
			    break;
			 }
		}
        if(flag==0) {
			t.data[t.size++]=a.data[i];
		}
        flag=0;
	}
    cout<<"\nFor union_of_sets  ";
	return t;
}
set set::difference(set a) {
	set t;
	int flag=0;
	//a-b
	for(int i=0;i<a.size;i++) {
		 for(int j=0;j<size;j++) {
			 if(a.data[i]==data[j]) {
			     flag=1;
				 break;
			 }
		 }
		 if(flag==0)
			 t.data[t.size++]=a.data[i];
	     flag=0;
	}
   cout<<"\nSet "<<a.name<<" - "<<name<<" ";
   return t;
}
set set::subset(set a) {

    if(a.size!=0) {
    	cout<<"\nIntersection exists , therefore we have subset :  ";
    }
    else {
    	cout<<"\nIntersection doesn't exist, therefore subset is : ";
    }
	return a;
}

int main() {

	int choice;
	char ch;
	set a,b,t;
	do{

		cout<<"\n\nOperations:\n1.add\n2.remove\n3.search\n5.intersection\n6.union\n7.difference\n8.subset\n\n";
        cin>>choice;
        switch(choice) {

            case 1: cout<<"\nCreating first set, enter the size :\n";
                    b.add();
                    cout<<"\nCreated set: \n";
                    b.display();
                    cout<<"\n\nCreating second set, enter the size :\n";
                    a.add();
                    cout<<"\nCreated set: \n";
                    a.display();
                    break;
            case 2: b.remove();
                    b.display();
                    break;
            case 3: b.search();
                    break;
            case 4: //b.search();
                    break;
	        case 5:t=a.intersect(b);
	                t.display();
	                t.reset();

                    break;
            case 6: t=b.union_(a);
                    t.display();
                    t.reset();
                    break;
            case 7: t=b.difference(a);
                    t.display();
                    t=a.difference(b);
                    t.display();
                    t.reset();
                    break;
            case 8: t=b.intersect(a);
                    b.subset(t).display();
                    t.reset();

                    break;
       }
        cout<<"\n\nDo u want to continue? y/n";
        cin>>ch;

	}while(ch=='y');

	return 0;

}
/*
OUTPUT:

Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

1

Creating first set, enter the size :

Enter the name of set
A

Enter size of set
6

Enter the data:
1
2
3
4
5
6

Created set: 
{ 1 , 2 , 3 , 4 , 5 , 6  }

Creating second set, enter the size :

Enter the name of set
B

Enter size of set
5

Enter the data:
7
8
9
10
4

Created set: 
{ 7 , 8 , 9 , 10 , 4  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

2

Enter element to delete from set A 
3
{ 1 , 2 , 4 , 5 , 6  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

3

Enter the element to search for in set A
7

Element not found


Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

2

Enter element to delete from set A 
0
{ 1 , 2 , 4 , 5  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

5

For intersection_of_sets  { 4  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

6

For union_of_sets  { 1 , 2 , 4 , 5 , 8 , 9 , 10  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

7

Set B - A { 7 , 8 , 9 , 10  }
Set A - B { 1 , 2 , 5  }

Do u want to continue? y/n
y


Operations:
1.add
2.remove
3.search
5.intersection
6.union
7.difference
8.subset

8

For intersection_of_sets  
Intersection exists , therefore we have subset :  { 4  }

Do u want to continue? y/n
n

*/