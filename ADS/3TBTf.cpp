//============================================================================
// Name        : TBT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//DO PROPERLY!!!!!
#include <iostream>
using namespace std;
#define max 20

class Tnode {

  Tnode *left,*right;
  int r,l;
  int data;
public:
  Tnode(int d) {
	  left=NULL;
	  right=NULL;
	  data=d;
	  r=l=0;
	  cout<<"\nEmpty node created";
  }
  Tnode() {
	  left=NULL;
	  right=NULL;
	  data=0;
	  r=l=0;
	  cout<<"\nEmpty node created";
  }

  friend class TBT;
};

class TBT {

	Tnode *root;
	Tnode *head;
	Tnode *nodes[max];

public:

	TBT(){
		root=NULL;
		head=NULL;
		for(int i=0;i<max;i++) {
			nodes[i]=NULL;
		}
		cout<<"\nEmpty tree created";
		count=0;
	}
     int     count;
     void    create();
     void    display();
    void     createTBT();  			 //uses inOrder nodes[]
   Tnode*    inOrder(Tnode *temp);  //stores in nodes[] in inOrder
    void	 displayNodes();
   Tnode*	 findLeft(Tnode*);
    void	 inOrderTrav();
    void	 preOrderTrav();

};

void TBT::create() {
	Tnode *ptr,*temp; //local pointer to Tnode
	int d;
	char ch;
	do{
	cout<<"\nEnter data node :";
	cin>>d;
	temp=new Tnode(d);
    if(root==NULL){
		root=temp;
    }
	else {
	      ptr=root;
		  while(1) {
			  cout<<"\nLeft or right from : "<<ptr->data<<" l/r";
		      cin>>ch;
		      if(ch=='l'){
		    	  if(ptr->left==NULL){
		    		  ptr->left=temp;
		    	      break;
		    	  }
		    	  else
		    		  ptr=ptr->left;

		      }
		      else if(ch=='r'){
		      	   if(ptr->right==NULL){
		      		   ptr->right=temp;
		      	       break;
		      	   }
		      	   else
		      		   ptr=ptr->right;
		       }
		      else
		    	  cout<<"\nIncorrect choice";
		  }

	}
    cout<<"\nAdd another node?";
    cin>>ch;
   }while(ch=='y');
}

void TBT:: createTBT() {

	if(head==NULL) {
		head->left  = root;
		head->right = head;
	}
    for(int i=0;i<=count;i++) {
    	if(nodes[i]->left==NULL) {
          if(i==0)
        	  nodes[i]->left=head;
          else {
        	  nodes[i]->left=nodes[i-1];
        	  nodes[i]->l=1;
          }
        }
    	if(nodes[i]->right==NULL) {
          if(i==count)
        	  nodes[i]->right=head;
          else {
        	  nodes[i]->right=nodes[i+1];
        	  nodes[i]->r=1;
          }
        }

    }

}

 Tnode* TBT::inOrder(Tnode *temp) {

 if(temp!=NULL) {

      inOrder(temp->left);
      nodes[count++]=temp;
      inOrder(temp->right);
      return NULL;
  }
  else {
	  return NULL;
  }
}
void TBT:: displayNodes() {

	inOrder(root);
	for(int i=0;i<count;i++) {
	  cout<<nodes[i]->data<<" ";
	}
	cout<<endl;
}
Tnode* TBT :: findLeft(Tnode* temp) {
	if(temp->l==0){
		findLeft(temp->left);
		return temp;
	}
	else if(temp->l==1)
		return temp;
}
void TBT :: inOrderTrav() {
   Tnode* ptr;
   ptr=findLeft(root);
   while(ptr!=head) {
	   cout<<ptr->data<<" ";
      /* if(ptr->r==1) {             //right child exists
    	   ptr=ptr->right;
       }
       else {					   //right child doesn't exist
    	   ptr=findLeft(ptr->right);
       }*/
   }

}
int main() {

	    TBT T1;
	    int choice;
	    int d;
		char ch;
		do{
		cout<<"\nChoose operation:\n1.Accept tree\n2.DisplayNodes";
		cout<<"\n3. Traverse inOrder";
		cin>>choice;
		switch(choice) {
		case 1:T1.create();
			   T1.createTBT();
			   break;
		case 2:T1.displayNodes();
		       break;
		case 3:T1.inOrderTrav();
		       break;

		}
		cout<<"\nDo you want to continue? y/n";
		cin>>ch;
		}while(ch=='y');
	return 0;
}
