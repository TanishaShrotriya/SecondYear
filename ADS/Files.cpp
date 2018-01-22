#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
char file[50] = " ";
class Student
{
	int rollno,age;
	int static count,cnt;
	char name[30],class1[5],div[5],address[50];
public:
	Student();                           //default constructor
	void get_data();
	void put_data();
	void createfile();
	void readfile();
	void search();
	void del();
};
//change the count from static to non -static!!
int Student::count=0;    //initializing count
int Student::cnt=0;
Student::Student()                      //calling default constructor
{
	rollno=0;
	age=0;
	strcpy(name,"____________");
	strcpy(class1,"____________");
	strcpy(div,"____________");
	strcpy(address,"____________");
}
void Student::createfile()
{
	char ch;
	Student s;
	fstream f;
	cout<<"Enter the name of file to open \n";
	cin>>file;
	f.open(file,ios::out);
	do{
		s.get_data();
		f.seekp(count*sizeof(s),ios::beg);
		f.write((char*)&s,sizeof(s));
		count ++;
		cout<<"\n Do you want to continue?(y/n)\n";
		cin>>ch;
	}while(ch=='y');
	f.close();
}
void Student::get_data()                             //definition of get_data()
{
	cout<<"\nEnter name:";
	cin.ignore();
	cin>>name;

	cout<<"\nEnter class: ";
	cin.ignore();
	cin>>class1;
	
	cout<<"\nEnter division:";
	cin.ignore();
	cin>>div;
	
	cout<<"\nEnter address !!WITHOUT SPACES!!: ";
	cin.ignore();
	cin>>address;
	
	cout<<"\nEnter roll no: ";
	cin>>rollno;
	
	cout<<"\nEnter age: ";
	cin>>age;
}
void Student::put_data()                            //definition of put_data()
{
	cout<<"\nName     : "<<name;
	cout<<"\nClass    : "<<class1;
	cout<<"\nDivision : "<<div;
	cout<<"\nAddress  : "<<address;
	cout<<"\nRoll no  : "<<rollno;
	cout<<"\nAge      : "<<age;
	cout<<"\n";
}
void Student::readfile()                           //definition of readfile()
{
	Student s;
	fstream f;
	f.open(file,ios::in);
	for(int i=0;i<count;i++)
	{
		cout<<"\n---Number---:"<<i+1<<"\nStudent Information is: \n";
		f.seekg(i*sizeof(s),ios::beg);
		f.read((char*)&s,sizeof(s));
		s.put_data();
	}
	f.close();
}
void Student::search() {
	Student s;
    fstream f;
    int offset,pos,i,r;

    cout<<"\n Enter roll number : ";
    cin>>r;
	
	f.open(file,ios::ate|ios::in|ios::out);
	f.seekg(0,ios::beg);
	pos=-1;
	i=0;
	while(f.read((char*)&s,sizeof(s))) {
    			
			if(r==s.rollno) {
    				
				pos=i;
				break;
    		}
    		i++;
    		
    }
    offset=pos*sizeof(s);
    f.seekp(offset);
	f.read((char*)&s,sizeof(s));
	s.put_data();
	f.close();

}
void Student::del() {

	Student s;
    fstream f;
	fstream temp;
	int offset,pos,i,r,flag=0;

	cout<<"\n Enter roll number of student record to be deleted : ";
	cin>>r;
    f.open(file,ios::ate|ios::in|ios::out);
    temp.open("newstudent.txt",ios::ate|ios::in|ios::out);
    f.seekg(0,ios::beg);
    i=0;
    while(f.read((char*)&s,sizeof(s))) {
    	     
    	     if(r!=s.rollno) {
    	       // cout<<cnt;
    			temp.seekp(cnt*sizeof(s),ios::beg);
				temp.write((char*)&s,sizeof(s));
				cnt ++;
    		}
			else {
    			
    			flag=1;
			}
    }
   
    if(flag==0) 
    	cout<<"\n record not present";
    		
    else {
    	
    	for(int i=0;i<cnt;i++) {

    			cout<<"\n---Number---:"<<i<<"\nAfter deletion of the record Student Information is: \n";
    			temp.seekg(i*sizeof(s),ios::beg);
    			temp.read((char*)&s,sizeof(s));
    			s.put_data();
        }


    }

	f.close();
	temp.close();
	remove(file);
	rename("newstudent.txt",file);

}
int main()                                        //main function
{
	Student s;
	int c;
	char ch;
	do{
		cout<<" \nOPERATION: \n";
		cout<<"\n1. Create file\n2. Read file\n3. Search file\n4. Delete file\n\n";
		cout<<"\nEnter your choice: ";
		cin>>c;
		switch(c)
		{
		case 1:
			s.createfile();
			break;
		case 2:
			s.readfile();
			break;
		case 3:
			s.search();
			break;
		case 4:
			s.del();
			break;
		default:
			cout<<"\nInvalid Choice!";
		}
		cout<<"\n Do you want to continue operations on file? (y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}                                              //end of main function
/*putput=>
 *
       **********MENU**********

1. Create file
2. Read file
3. Search file
4. Delete file


Enter your choice: 1

Enter name:abc.

Enter class: SE
.

Enter division:D
.

Enter address: pune.

Enter roll no: 1452

Enter age: 18

 Do you want to continue?(1/0)1

Enter name:xyz
.

Enter class: se.

Enter division:d.

Enter address: pune.

Enter roll no: 2222

Enter age: 18

 Do you want to continue?(1/0)0

 Do you want to continue in main MENU? (y/n)y

       **********MENU**********

1. Create file
2. Read file
3. Search file
4. Delete file


Enter your choice: 2

---Number---:0
Student Information is:

Name     : abc
Class    : SE

Division : D

Address  : pune
Roll no  : 1452
Age      : 18

---Number---:1
Student Information is:

Name     : xyz

Class    : se
Division : d
Address  : pune
Roll no  : 2222
Age      : 18

 Do you want to continue in main MENU? (y/n)y

       **********MENU**********

1. Create file
2. Read file
3. Search file
4. Delete file


Enter your choice: 3

 Enter roll number : 1452

Name     : abc
Class    : SE

Division : D

Address  : pune
Roll no  : 1452
Age      : 18

 Do you want to continue in main MENU? (y/n)y

       **********MENU**********

1. Create file
2. Read file
3. Search file
4. Delete file


Enter your choice: 4

 Enter roll number of student record to be deleted : 1452
0
---Number---:0
After deletion of the record Student Information is:

Name     : xyz

Class    : se
Division : d
Address  : pune
Roll no  : 2222
Age      : 18

 Do you want to continue in main MENU? (y/n)n
 *
 */
