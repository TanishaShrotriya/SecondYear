//============================================================================
// Name        : trial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node {
    int m;
	node * next;
public:
	node(int n) {
		next=NULL;
		m=n;
	}
	friend class list;
};

class list {
	node *start;
public:
	list() {
		start=NULL;
	}
	void accept();
	void display();
};

void list::accept() {
int n;
node *ptr,*temp;
cin>>n;
temp=new node(n);
cout<<"Value at temp="<<temp<<endl;

if(start==NULL) {
	start=temp;
    cout<<"Adress of start="<<&start<<endl;
    cout<<"Value at start="<<start<<endl;
    cout<<"Value at object in start"<<start->m<<endl;
}
else{
	ptr=start;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
		cout<<"Value at next node:"<<ptr->next<<endl;
	}
	ptr->next=temp;
    cout<<"Value at ptr:"<<ptr<<endl;
    cout<<"Value at object in ptr"<<ptr->m<<endl;
}
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	list l;
	int a=10;
	int * p=&a;
	cout<<p<<endl;;
	cout<<*p<<endl<<&p<<endl;
	cout<<&a;

	char y;
	do{
	l.accept();
	cout<<"Continue?";
    cin>>y;
	}while(y!='n');
	return 0;
}
