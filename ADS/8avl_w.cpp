//============================================================================
// Name          : RHEA MADHUSUTHAN
// Roll No       : 2443
// Assignment 8  : AVL TREE
//============================================================================

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

	void insert1();
	node* insert(node* root, char[], char[]);
	int getheight(node*);
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
	void inorder_display();
	void descending_display();
	void delete_call();
};

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
	 root->height = getheight(root);
	 return root;
}

int avl::getheight(node *root){
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
		root->height=getheight(root);
		temp->height=getheight(temp);
		return temp;
}
node* avl::rotateright(node *root){
		node *temp;
		temp=root->left;
		root->left=temp->right;
		temp->right=root;
		root->height=getheight(root);
		temp->height=getheight(temp);
		return temp;
}

void avl::inorder_display()
{
	inorder(root1);
}

void avl::inorder(node *t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->keyword<<" -> "<<t->meaning<<"\n";
		inorder(t->right);
	}
}

void avl::descending_display()
{
	descending(root1);
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

void avl::delete_call()
{
	char key[MAX];
	cout<<"\nEnter the word to delete :: ";
	cin>>key;
	root1=delete1(root1, key);

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

			root->height = getheight(root);
			return(root);
	}
int main()
{
	avl obj;
	char key[MAX];
	cout<<"\t\t\t\t\tDictionary Facility";
	int choice;
	char c;
	do{
	cout<<"\n\n\t1.Insert\n\t2.Search\n\t3.Modify\n\t4.Delete\n\t5.Ascending\n\t6.Descending";
	cout<<"\nenter your choice\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
		obj.insert1();
		break;
	case 2:
		cout<<"\nEnter the word for search :: ";
		cin>>key;
		if(obj.search(key)==1)
			cout<<"\nWord present ";
		else
			cout<<"\nWord not present ";
		break;
	case 3:
		cout<<"\nEnter the word for search :: ";
		cin>>key;
		obj.modify(key);
		break;
	case 4:
		obj.delete_call();
		break;
	case 5:
		cout<<endl;
		obj.inorder_display();
		break;
	case 6:
		cout<<endl;
		obj.descending_display();
		break;
	default:
		cout<<"\nInvalid";
		break;
	}
	cout<<"\nPress y to continue ";
	cin>>c;
	cout<<endl;
	}while(c=='y');
	return 0;
}
/*
 * Dictionary Facility
Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: almost

Enter meaning :: nearly

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: branch

Enter meaning :: department

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: idiot

Enter meaning :: foolish

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: smart

Enter meaning :: intelligent

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

almost -> nearly
branch -> department
idiot -> foolish
smart -> intelligent

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending1

   Enter word :: tough

Enter meaning :: difficult

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending6

tough -> difficult
smart -> intelligent
idiot -> foolish
branch -> department
almost -> nearly

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending2

Enter the word for search :: idiot

Word present
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending2

Enter the word for search :: red

Word not present
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending3

Enter the word for search :: idiot

Current meaning :: foolish
Enter new meaning :: silly

Meaning modified
Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

almost -> nearly
branch -> department
idiot -> silly
smart -> intelligent
tough -> difficult

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending4

Enter the word to delete :: smart

Press y to continue y


Press
1.Insert
2.Search
3.Modify
4.Delete
5.Ascending
6.Descending5

almost -> nearly
branch -> department
idiot -> silly
tough -> difficult

Press y to continue n

 *
 */
