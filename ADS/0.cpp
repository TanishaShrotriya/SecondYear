//============================================================================
// Name        : Ass_zero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

class node {
public:
	int m;
	node(int d){
		m=d;
	}
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	char ch;
	int choice,d;
	list <node> s,q; //list object
	list <node>::iterator it,itr;
	do{
    cout<<"Select operation:\n1.Push on stack\n2.Display stack";
    cout<<"\n3.Pop last element from stack\n4.Enter queue element";
    cout<<"\n5.Display Queue\n6.Delete queue element";
    cin>>choice;
    switch(choice) {

    case 1: cout<<"Enter the element\n";
            cin>>d;
            node *temp;
            temp = new node(d);
            s.push_front(*temp);
            cout<<"Item added\n";
            break;
    case 2: cout<<"Elements in stack are:\n";
            if(s.empty()==0) {
            for(it=s.begin();it!= s.end();it++)
            	cout<<it->m<<endl;
            }
            else {
            	cout<<"Stack underflow\n";
            }
            break;
    case 3: s.pop_front();
            cout<<"Element deleted\n";
            break;
    case 4: cout<<"Enter the element\n";
            cin>>d;
            q.push_back(d);
            cout<<"Item added\n";
            break;
    case 5: cout<<"Elements in stack are:\n";
            if(q.empty()==0) {
            for(itr=q.begin();itr!= q.end();itr++)
            	cout<<itr->m<<endl;
            }
            else {
            	cout<<"Queue underflow\n";
            }
            break;
    case 6: q.pop_front();
            cout<<"Element deleted\n";

    }
    cout<<"Want to continue?";
    cin>>ch;
	}while(ch=='y');
    return 0;

}
