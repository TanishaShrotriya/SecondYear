

#include <iostream>
using namespace std;
#include <string.h>
#define MAX 10
class node
{
	node *right;
	node *left;
	int height;
	char keyword[10];
	char meaning[30];
public:
	node(char k[], char m[])
	{
		right=NULL;
		left=NULL;
		strcpy(keyword,k);
		strcpy(meaning,m);
		height =0;
	}
	friend class avl;
};

class avl
{
	node *root1;
public:
	avl(){
			root1=NULL;
		}
	void switchmenu();
	void insert1();
	node* insert(node* root, char[], char[]);
	int getht(node*);
	int bfactor(node*);
	node* LL(node*);
	node* LR(node*);
	node* RL(node*);
	node* RR(node*);
	node* rotateleft(node*);
	node* rotateright(node*);
	void inorder(node*);
	void descending(node*);
	int search(char[]);
	void modify(char[]);
	node* delete1(node*, char[]);
};
void avl::switchmenu(){
	char key[MAX];
	cout<<"Dictionary Facility";
	int choice;
	char c;
	do{
	cout<<"\nPress\n1.Insert\n2.Search\n3.Modify\n4.Delete\n5.Ascending\n6.Descending";
	cin>>choice;
	switch(choice){
	case 1:
		insert1();
		break;
	case 2:
		cout<<"\nEnter the word for search :: ";
		cin>>key;
		if(search(key)==1)
			cout<<"\nWord present ";
		else
			cout<<"\nWord not present ";
		break;
	case 3:
		cout<<"\nEnter the word for search :: ";
		cin>>key;
		modify(key);
		break;
	case 4:
		cout<<"\nEnter the word to delete :: ";
		cin>>key;
		root1=delete1(root1, key);

		break;
	case 5:
		cout<<endl;
		inorder(root1);
		break;
	case 6:
		cout<<endl;
		descending(root1);
		break;
	default:
		cout<<"\nInvalid";
		break;
	}
	cout<<"\nPress y to continue ";
	cin>>c;
	cout<<endl;
	}while(c=='y');
}
void avl::insert1()
{
	char k[MAX], m[MAX];
	cout<<"\n   Enter word :: ";
	cin>>k;
	cout<<"\nEnter meaning :: ";
	cin>>m;
	root1=insert(root1,k,m);
}

node* avl::insert(node* root,char k[], char m[])
{
	node* temp;
	if(root==NULL){
		temp = new node(k,m);
		root=temp;
		return root;
	}
	else if(strcmp(k,root->keyword)<0){
			root->left = insert(root->left,k,m);
			if(bfactor(root)==2){
				if(strcmp(k,root->left->keyword)<0)
					root=LL(root);
				else
					root=LR(root);
			}
		}
		else if(strcmp(k,root->keyword)>0){
			root->right = insert(root->right,k,m);
				if(bfactor(root)==-2){
					if(strcmp(k,root->right->keyword)>0)
						root=RR(root);
					else
						root=RL(root);
				}
		}
	 root->height = getht(root);
	 return root;
}

int avl::getht(node *root){
	int lh, rh;
	if(root==NULL)
		return 0;
	if(root->left==NULL)
		lh=0;
	 	else
		lh=1+root->left->height;
	if(root->right==NULL)
			rh=0;
		else
			rh=1+root->right->height;
	if(lh>rh)
		return lh;
	else
		return rh;
}
int avl::bfactor(node *root){
	int lh, rh;
		if(root==NULL)
			return 0;
		if(root->left==NULL)
			lh=0;
		 	else
			lh=1+root->left->height;
		if(root->right==NULL)
				rh=0;
			else
				rh=1+root->right->height;

			return (lh-rh);
	}
node* avl::LL(node *root){
	root=rotateright(root);
	return (root);
 	 }
node* avl::RR(node *root){
	root=rotateleft(root);
	return (root);
	}
node* avl::RL(node *root){
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return(root);
}
node* avl::LR(node *root){
	root->left=rotateleft(root->left);
	root=rotateright(root);
	return(root);
}
node* avl::rotateleft(node *root){
		node *temp;
		temp=root->right;
		root->right=temp->left;
		temp->left=root;
		root->height=getht(root);
		temp->height=getht(temp);
		return temp;
}
node* avl::rotateright(node *root){
		node *temp;
		temp=root->left;
		root->left=temp->right;
		temp->right=root;
		root->height=getht(root);
		temp->height=getht(temp);
		return temp;
}
void avl::inorder(node *t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->keyword<<" -> "<<t->meaning<<"\n";
		inorder(t->right);
	}
}
void avl::descending(node *t){
	if(t!=NULL){
		descending(t->right);
		cout<<t->keyword<<" -> "<<t->meaning<<"\n";
		descending(t->left);
	}
}
int avl::search(char k[])
{
	int flag =0;
	node *ptr;
	ptr = root1;
	while(ptr!=NULL)
	{
		if(strcmp(k,ptr->keyword)==0)
		{
			flag = 1;
			break;
		}
		else if(strcmp(k,ptr->keyword)<0)
		{
			ptr = ptr->left;
		}
		else if(strcmp(k,ptr->keyword)>0)
		{
			ptr = ptr->right;
		}
	}

	return flag;
}
void avl::modify(char k[])
{
	int flag =0;
	node *ptr;
	ptr = root1;
	char m[MAX];
	while(ptr!=NULL)
	{
		if(strcmp(k,ptr->keyword)==0)
		{
			flag = 1;
			break;
		}
		else if(strcmp(k,ptr->keyword)<0)
		{
			ptr = ptr->left;
		}
		else if(strcmp(k,ptr->keyword)>0)
		{
			ptr = ptr->right;
		}
	}
	if (flag==1){
		cout<<"\nCurrent meaning :: "<<ptr->meaning;
		cout<<"\nEnter new meaning :: ";
		cin>>m;
		strcpy(ptr->meaning,m);
		cout<<"\nMeaning modified ";
	}
	else
		cout<<"\nWord not present";
}
node* avl::delete1(node* root,char k[])
{
	node* temp;
	if(root==NULL){
		return NULL;
	}
	else if(strcmp(k,root->keyword)<0){
			root->left = delete1(root->left,k);
			if(bfactor(root)==-2){
				if(bfactor(root->right)<=0)
					root=RR(root);
				else
					root=RL(root);
			}
		}
		else if(strcmp(k,root->keyword)>0){
			root->right = delete1(root->right,k);
				if(bfactor(root)==2){
					if(bfactor(root->left)>=0)
						root=LL(root);
					else
						root=LR(root);
				}
		}
		else{
			if(root->right!=NULL){
				temp = root->right;
				while(temp->left!=NULL){
					temp = temp->left;
					}
				strcpy(root->keyword,temp->keyword);
				strcpy(root->meaning,temp->meaning);
				root->right = delete1(root->right, temp->keyword);
				if(bfactor(root)==2){
					if(bfactor(root->left)>=0)
						root = LL(root);
					else
						root = LR(root);
				}
			}
			else
				return (root->left);
		}

			root->height = getht(root);
			return(root);
	}
int main() {
	avl obj;
	obj.switchmenu();
	return 0;
}
/*
 Dictionary Facility
Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: important

Enter meaning :: value

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: kind

Enter meaning :: generous

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: welcome

Enter meaning :: entry

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: idea

Enter meaning :: plan

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: apple

Enter meaning :: fruit

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: extra

Enter meaning :: second

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: follow

Enter meaning :: path

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: pursue

Enter meaning :: dream

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

apple -> fruit
extra -> second
follow -> path
idea -> plan
important -> value
kind -> generous
pursue -> dream
welcome -> entry

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending6

welcome -> entry
pursue -> dream
kind -> generous
important -> value
idea -> plan
follow -> path
extra -> second
apple -> fruit

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending2

Enter the word for search :: water

Word not present
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending2

Enter the word for search :: apple

Word present
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending3

Enter the word for search :: follow

Current meaning :: path
Enter new meaning :: rules

Meaning modified
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

apple -> fruit
extra -> second
follow -> rules
idea -> plan
important -> value
kind -> generous
pursue -> dream
welcome -> entry

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending4

Enter the word to delete :: extra

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

apple -> fruit
follow -> rules
idea -> plan
important -> value
kind -> generous
pursue -> dream
welcome -> entry

Press y to continue

*/

