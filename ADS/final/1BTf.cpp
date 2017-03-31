//============================================================================
// Name        : Ass_1.cpp
// Author      : 2453
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

class Tnode {
  Tnode *left,*right;
  int data;
public:
  Tnode(int d) {
	  left=NULL;
	  right=NULL;
	  data=d;
  }
  friend class BinTree;
};

class BinTree {
	Tnode *root;
public:
	BinTree() {
		root=NULL;
	}
void create();
void display();
void preOrder(Tnode *temp);
void postOrder(Tnode *temp);
void inOrder(Tnode *temp);
Tnode* clone(Tnode *temp);
BinTree * operator=(BinTree* src);
Tnode* erase(Tnode*) ;
void del();
void copy(BinTree &);
};

void BinTree :: copy(BinTree &l) {
	Tnode * ptr1,*ptr2,*root2,*temp;
	queue <Tnode*> q1;
	queue <Tnode*> q2;

	if(root!=NULL)
       q1.push(root);
	else
		cout<<"Empty tree";

	ptr1=q1.front();
	ptr2= new Tnode(ptr1->data);
    l.root=ptr2;
    q2.push(l.root);

	while(q1.empty()==0) {

		 ptr1=q1.front();
		 q1.pop();
	     ptr2=q2.front();
		 q2.pop();

		 if(ptr1->left !=NULL) {

			 temp=new Tnode(ptr1->left->data);
			 ptr2->left=temp;
			 q2.push(ptr2->left);
			 q1.push(ptr1->left);

		 }
		 if(ptr1->right !=NULL) {

			 temp=new Tnode(ptr1->right->data);
			 ptr2->right=temp;
			 q2.push(ptr2->right);
			 q1.push(ptr1->right);

		 }

}
}
void BinTree:: del() {
	erase(root);
}
Tnode* BinTree:: erase(Tnode * temp) {
	if(temp->left!=NULL){
		erase(temp->left);
	}
	if(temp->right!=NULL){
		erase(temp->right);
	}
	delete temp;
	return NULL;
}
void BinTree::create() {
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
    cout<<"Add another node?";
    cin>>ch;
   }while(ch=='y');
}
void BinTree::preOrder(Tnode *temp) {
  if(temp!=NULL) {
	  cout<<temp->data<<" ";
      preOrder(temp->left);
      preOrder(temp->right);

  }
  else {
	  return;
  }

}
void BinTree::postOrder(Tnode *temp) {
  if(temp!=NULL) {

      postOrder(temp->left);
      postOrder(temp->right);
	  cout<<temp->data<<" ";

  }

}
void BinTree::inOrder(Tnode *temp) {
  if(temp!=NULL) {

      inOrder(temp->left);
      cout<<temp->data<<" ";
      inOrder(temp->right);

  }
}
void BinTree::display() {
char ch;
int choice;
do{

	cout<<"\n1.Display with Pre-order\n2.Display with Post-order";
    cout<<"\n3.Display with In-order";
    cin>>choice;
    switch(choice) {
         case 1:preOrder(this->root);
                cout<<"\n";
                break;
         case 2: postOrder(this->root);
                cout<<"\n";
                break;
         case 3: inOrder(this->root);
                cout<<"\n";
                break;
         default: cout<<"Incorrect choice"; break;
    }
    cout<<"Do you want to display differently? y/n";
    cin>>ch;
}while(ch=='y');

}

Tnode * BinTree:: clone(Tnode *temp) {
	if(temp==NULL) {
		return NULL;
	}
	else {
		Tnode * newNode;
		newNode=new Tnode(temp->data);
		newNode->left=clone(temp->left);
		newNode->right=clone(temp->right);
		return newNode;
	}
}
BinTree* BinTree :: operator=(BinTree *src) {
    if(src->root==NULL) {
        cout<<"Sorry tree is empty";
        return src;
    }
    else {
    	BinTree *copy;
    	copy=new BinTree();
    	copy->root=clone(src->root);
    	cout<<"* at copy"<<copy->root<<endl;
    	cout<<"* at src"<<src->root<<endl;
    	return copy;
    }

}

int main() {

	BinTree l1,l4;

	char ch;
	int choice;
	do{
	cout<<"\nChoose operation:\n1.Accept tree\n2.Display";
	cout<<"\n3.Copy tree to another location\n4.Delete original tree";
	cout<<"\n5.Delete copied tree\n6.Copy non-recursive";
	cin>>choice;
	switch(choice) {
	case 1:l1.create();
	       break;
	case 2:l1.display();
	       break;
	case 3:l4=l1;
		   cout<<"Display copied tree with"<<endl;
	       l4.display();
	       break;
	case 4:l1.del();
	       cout<<"\nOriginal Tree deleted";
	       break;
	case 5:l4.del();
	       cout<<"\nCopied Tree deleted";
           break;
	case 6:l1.copy(l4);
	       cout<<"Tree copied";
	       l4.display();
	       break;
    default:cout<<"\nRe-enter values";

	}
	cout<<"\nDo you want to continue? y/n";
	cin>>ch;
	}while(ch=='y');
	return 0;
}

