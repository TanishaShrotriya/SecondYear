//============================================================================
// Name        : hashing.cpp
// Author      : 2453
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#define max 10

using namespace std;

class List {

	List *node;
	long int num,ID;

public:
    List() {
    	node=NULL;
        num=ID=0;
    }
    List(int num_,int ID_) {
    	node=NULL;
        num=num_;
        ID=ID_;
    }
    friend class Hash;
};

class Hash {

	List * table[max];
    char pKey[20],rKey[20];
public:

	Hash() {


		for(int i=0;i<max;i++)
			table[i]=NULL;
		strcpy(pKey,"root123");
		strcpy(rKey,"root");

	 }
	void insert();
	void search();
	void admin();
    void view();

};

void Hash::insert() {

    long int ID,num;
    int mod,flag;
    char ch;
    List *ptr,*trav;
    do{
    	flag=0;
		cout<<"Enter the Client ID\n";
		cin>>ID;
		cout<<"Enter the telephone number\n";
		cin>>num;
		mod=ID%max;

    	ptr = new List(num,ID);

   		 if(table[mod]==NULL)
    			table[mod]=ptr;


    	 else {

    		trav=table[mod];
    		while(trav->node!=NULL || trav->ID==ptr->ID) {

                if(trav->ID!=ptr->ID)
           	    	trav=trav->node;
    		    else {
    		    	cout<<"Client already exists, overwrite number y/n?";
    		        cin>>ch;
    		        if(ch=='y') {
    		        	trav=ptr;
      		        }
    		        else {
    		        	flag=1;
    		        }
    		        break;
    		    }

    		}

    		if(flag==0) {
    		     trav->node=ptr;
    		 	 cout<<"Collision had occurred and was resolved\n";
    	    }
    	}
    	cout<<"Do u wish to continue adding? y/n";
    	cin>>ch;
    } while(ch=='y');

}

void Hash::search() {

     long int ID;
     int mod;
     List *ptr;
     cout<<"Enter the client ID";
     cin>>ID;
     mod=ID%max;

     ptr=table[mod];
     while(ptr->ID!=ID && ptr->node!=NULL)
     	 ptr=ptr->node;

     if(ptr->node==NULL && ptr->ID!=ID) {
         cout<< "Client not found";
     }
     else {

     	 char ch;
     	 char id[20];
     	 char pass[20];
    	 cout<<"\nClient info protected, but present\n";
         cout<<"\nDo you wish to retrieve data? y/n\n";
         cin>>ch;
         if(ch=='y') {
         	cout<<"\nYou need to have admin priviledges to view client details";
         	cout<<"\nEnter root id\n";
         	cin>>id;
         	cout<<"\nEnter password\n";
         	cin>>pass;
         	if(strcmp(id,rKey)==0 && strcmp(pass,pKey)==0)
         		cout<<"Client Id "<<ptr->ID<<" Client Phone Number = "<<ptr->num<<endl;
         }
     }
 }

void Hash::admin() {

		char id[20],pass[20];
     	cout<<"\nEnter the current root id\n";
     	cin>>id;
     	cout<<"\nEnter the current root password\n";
     	cin>>pass;
     	if(strcmp(id,rKey)==0 && strcmp(pass,pKey)==0) {

     	 	cout<<"\nEnter the new root id\n";
     	    cin>>rKey;
     	    cout<<"\nEnter the new root password\n";
     	    cin>>pKey;
        }
}

void Hash::view() {

	char id[20],pass[20];
 	cout<<"\nEnter the root id to gain access\n";
 	cin>>id;
 	cout<<"\nEnter the root password to gain access\n";
 	cin>>pass;
 	if(strcmp(id,rKey)==0 && strcmp(pass,pKey)==0)  {

   		 List *ptr;
		 cout<<"\nRecords: "<<endl;
		 cout<<"Client ID:   Phone Number:   \n";
		 for(int i=0;i<max;i++) {
			 cout<<endl<<i<<"\t";
	         ptr=table[i];
		 	 while(ptr!=NULL) {
	    	     cout<<"< "<<ptr->ID<<":"<<ptr->num<<" >\t";
	    	     ptr=ptr->node;

	         }
		     cout<<endl;
	     }

   }
}
int main() {

	char ch;
	int choice;
	Hash h;
	do {
		cout << "\n1.Insert\n2.Search\n3.Change admin details\n4.Show all records" << endl;
		cin>>choice;
		switch(choice) {

			case 1:h.insert();
			       break;
			case 2:h.search();
			       break;
			case 3:h.admin();
			       break;
			case 4:h.view();
			       break;
			default:cout<<"Incorrect choice, enter another: \n";
		}
		cout<<"\n Do u want to continue?";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
