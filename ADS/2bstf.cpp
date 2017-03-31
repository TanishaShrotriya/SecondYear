//============================================================================
// Name        : Ass_2.cpp Binary Search Tree
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
void	 create();
void	 display();
int		 max(int,int);
int		 height(Tnode* temp);
int  	 Height();
void     insert(int data);
Tnode*   inOrder(Tnode * node);
void     min();
void     Min_Rec(Tnode *);
int      Min(Tnode *temp);
void     max();
void     Max_Rec(Tnode *);
int      Max(Tnode *temp);
int      search( Tnode *root,int key);
int      Search(int);
void     mirrornr(Tnode *temp);
void     mirror();
Tnode *  mirror(Tnode *temp);
//search
};
void BinTree :: mirror() {

	char ch;
	int choice;
	do{
		cout<<"\nSwap nodes with \n 1.Recursion \n 2. Non-recursion";
		cin>>choice;
		switch(choice) {
			case 1:mirror(root);
				   break;
			case 2:mirrornr(root);
				   break;
			default:cout<<"\nIncorrect choice!!";
	        	    break;
	     }
		cout<<"Do you want to swap data again?";
		cin>>ch;
    }while(ch=='y');
}
Tnode* BinTree ::mirror(Tnode *temp) {
	Tnode *ptr;
	if(temp==NULL)
		return NULL;
	else {

		ptr=mirror(temp->left);
		temp->left=mirror(temp->right);
        temp->right=ptr;
	}

}
void BinTree ::mirrornr(Tnode *root) {
    Tnode * temp;
	queue <Tnode*> q;
	q.push(root);

	while(q.empty()==0) {
        root=q.front();
        q.pop();
        cout<<root->data<<" ";
		temp=root->left;
		root->left=root->right;
		root->right=temp;

		if(root->left!=NULL) {
		    q.push(root->left);
		}
		if(root->right!=NULL) {
		    q.push(root->right);
		}
   }
	cout<<endl;

}
int BinTree :: Search(int key) {

	return search(root,key);
}
int BinTree::search(Tnode *temp,int key) {
	if(temp==NULL)
		return 0;
	else if(temp->data==key)
		return 1;
	else if(temp->data < key)
		search(temp->right,key);
	else if(temp->data > key)
		search(temp->right,key);
}
int BinTree::Height() {

	return height(root);
}
int BinTree::height(Tnode* temp) {

  if(temp!=NULL){
    return max(height(temp->left),height(temp->right))+1;
  }
  else {
	  return 0;
  }
 }
int BinTree::max(int l,int r){

     if(l>r) {
    	 return l;
     }
     else
    	 return r;
}

void BinTree :: min() {

	cout<<"\nMinimum value is : "<<Min(root) <<" Not recursion";
	cout<<"\nMinimum value is : ";
    Min_Rec(root);
	cout<<" With Recursion";

}
int BinTree :: Min(Tnode *temp) {
    int d=0;
    Tnode * ptr;
    ptr=temp;
	while(ptr->left !=NULL) {
		   ptr=ptr->left;
	}
		d=ptr->data;
		return d;

}
void BinTree :: Min_Rec(Tnode * temp) {

    Tnode * ptr;
    ptr=temp;
    if(ptr->left!=NULL) {
     Min_Rec(ptr->left);
    }
    else{
     cout<<ptr->data;
    }

}
void BinTree :: max() {

	cout<<"\nMaximum value is : "<<Max(root) <<" Not recursion";
	cout<<"\nMaximum value is : ";
    Max_Rec(root);
	cout<<" With Recursion";

}
int BinTree :: Max(Tnode *temp) {
    int d=0;
    Tnode * ptr;
    ptr=temp;
	while(ptr->right !=NULL) {
		   ptr=ptr->right;
	}
		d=ptr->data;
		return d;

}
void BinTree :: Max_Rec(Tnode * temp) {

    Tnode * ptr;
    ptr=temp;
    if(ptr->right!=NULL) {
     Max_Rec(ptr->right);
    }
    else{
     cout<<ptr->data;
    }

}

void BinTree::insert(int d) {
    Tnode *ptr,*temp;
	temp=new Tnode(d);
    if(root==NULL){
		root=temp;
    }
	else {
	      ptr=root;
		  while(1) {

		      if(temp->data < ptr->data){
		    	  if(ptr->left==NULL){
		    		  ptr->left=temp;
		    	      break;
		    	  }
		    	  else
		    		  ptr=ptr->left;

		      }
		      else if(temp->data > ptr->data){
		      	   if(ptr->right==NULL){
		      		   ptr->right=temp;
		      	       break;
		      	   }
		      	   else
		      		   ptr=ptr->right;
		       }

		  }

	}

}

Tnode* BinTree::inOrder(Tnode *temp) {
  if(temp!=NULL) {

      inOrder(temp->left);
      cout<<temp->data<<" ";
      inOrder(temp->right);
      return NULL;
  }
  else {
	  return NULL;
  }
}
  void BinTree::display() {
  inOrder(this->root);
  cout<<"\n";
}

int main() {
    BinTree T1;
    int choice;
    int d;
	char ch;
	do{
	cout<<"\nChoose operation:\n1.Accept tree\n2.Display";
	cout<<"\n3.Find the minimum element\n4.Find max element";
	cout<<"\n5.Find height of tree\n6.Find an element";
	cout<<"\n7.Swap nodes";
	cin>>choice;
	switch(choice) {
	case 1:	{
		      char ch;
	          do{
	               cout<<"\nEnter data node :";
	               cin>>d;
		           T1.insert(d);
		           cout<<"Add another node?";
		           cin>>ch;
		        }while(ch=='y');
         	}
	        break;
	case 2:T1.display();
	       break;
	case 3:T1.min();
	       break;
	case 4:T1.max();
	       break;
	case 5:cout<<T1.Height();
	       break;
	case 6:{
		    int ch;
		    cout<<"\nEnter element to search";
		    cin>>ch;
		    int x=T1.Search(ch);
		    if(x==0)
		    	cout<<"\nElement not found";
		    else if(x==1)
		    	cout<<"\nElement found";
	        }
			break;
	case 7: T1.mirror();
			break;
	}
	cout<<"\nDo you want to continue? y/n";
	cin>>ch;
	}while(ch=='y');
	return 0;
}
/*
Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes
1

Enter data node :15
Add another node?y

Enter data node :12
Add another node?y

Enter data node :9
Add another node?y

Enter data node :13
Add another node?y

Enter data node :44
Add another node?y

Enter data node :20
Add another node?y

Enter data node :80
Add another node?y

Enter data node :59
Add another node?n

Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes2
9 12 13 15 20 44 59 80

Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes3

Minimum value is : 9 Not recursion
Minimum value is : 9 With Recursion
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes3

Minimum value is : 9 Not recursion
Minimum value is : 9 With Recursion
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes4

Maximum value is : 80 Not recursion
Maximum value is : 80 With Recursion
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes5
4
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes6

Enter element to search3

Element not found
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes9

Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes6

Enter element to search9

Element not found
Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes7

Swap nodes with
 1.Recursion
 2. Non-recursion1
Do you want to swap data again?n

Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes2
80 59 44 20 15 13 12 9

Do you want to continue? y/ny

Choose operation:
1.Accept tree
2.Display
3.Find the minimum element
4.Find max element
5.Find height of tree
6.Find an element
7.Swap nodes7

Swap nodes with
 1.Recursion
 2. Non-recursion2
15 12 44 9 13 20 80 59
Do you want to swap data again?n

Do you want to continue? y/n
n
 */
 