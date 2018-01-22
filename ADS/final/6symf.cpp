#include <iostream>
#include<string.h>
using namespace std;

class symbol{
    int id;
    char name[30];
    char initial[30];
    char type[10],scope[10];
    int line[10],cnt,flag;

public:
    symbol(){
        id=0;

        //initial=0.0;

        cnt=0,flag=0;
    }
    void create();
    void display();
    friend class table;
};
class table{
    int cntr;
    symbol s[20];
public:
    void tcreate();
    void tdisplay();
    void search();
    void modify();
    void insert();
    void deleter();
};

void symbol::create(){
    char y;
    int i=0;
   // cout<<"Enter name :"<<endl;
   // cin>>name;
    cout<<"Enter initial value :"<<endl;
    cin>>initial;
    cout<<"Enter the type of variable :"<<endl;
    cin>>type;
    cout<<"Enter the scope of variable :"<<endl;
    cin>>scope;
    id=1;
    do{
        cout<<"Enter line number :"<<endl;
        cin>>line[i];
        i++;
        cout<<"Do you want to add another line? "<<endl;
        cin>>y;
    }while(y=='y'||y=='Y');
    cnt=i;
}

void symbol::display(){

 	   char s[15];
    	 //name
    	for(int i=0;i<strlen(name);i++){
    	    s[i]=name[i];
    	}
    	for(int i=strlen(name);i<15;i++) {
    	    s[i]= ' ';
    	}
    	cout<<s;

    	 //initial
    	for(int i=0;i<strlen(initial);i++){
    	    s[i]=initial[i];
    	}
    	for(int i=strlen(initial);i<15;i++) {
    	    s[i]=' ';
    	}
    	cout<<s;

    	 //type
    	for(int i=0;i<strlen(type);i++){
    	    s[i]=type[i];
    	}
    	for(int i=strlen(type);i<15;i++) {
    	    s[i]=' ';
    	}
    	cout<<s;
         //scope
    	for(int i=0;i<strlen(scope);i++){
    	    s[i]=scope[i];
    	}
    	for(int i=strlen(scope);i<15;i++) {
    	    s[i]=' ';
    	}
    	cout<<s;


    	for(int i=0;i<cnt-1;i++){
    	    cout<<line[i]<<" ";
    	}
    	cout<<line[cnt-1]<<endl<<endl;
}

void table::tcreate(){
    static int i=0;
    int flag=0;
    char n[30];
    char y;
    do{
        cout<<"Enter the name to be inserted:"<<endl;
    	cin>>n;
    	for(int j=0;j<i;j++){

         	   if(strcmp(s[j].name,n)==0)
            	{
            		//duplicate entry testcase
            		cout<<"Entry is already present"<<endl;
                	flag=1;
                	break;
          		}

    	}

    	if(flag==0) {

                for(int x=0;x<strlen(n);x++)
    		         s[i].name[x] = n[x];
        		s[i].create();
        		i++;

        }
        else
        	flag=0;
		cout<<"Do you want to add another entry? "<<endl;
        cin>>y;

    } while(y=='y'||y=='Y');
    cntr=i;
}

void table::tdisplay(){

    cout<<"Name           Value          Type           Scope          Lines"<<endl;
    //total characters =15
    for(int i=0;i<cntr;i++){
        if(s[i].id!=-1)
        {
            s[i].display();
        }
    }

}
void table::search(){
    char n[30];
    int flg=0;
    cout<<"Enter the name to be searched :"<<endl;
    cin>>n;
    for(int i=0;i<cntr;i++){
        if(strcmp(s[i].name,n)==0)
        {
            if(s[i].id!=-1)
            {

           		 cout<<"Name           Value          Type           Scope          Lines"<<endl;
            	 cout<<endl;

            	 s[i].display();
                 flg=1;
            	 break;
            }
            else {
                 cout<<"Entry already deleted"<<endl;
                 flg=1;
            }

        }
    }
    if(flg==0){
        cout<<"Entry not present in the table."<<endl;
    }
}
void table::deleter() {


	char n[30];
	cout<<"Enter the name to be deleted :"<<endl;
	cin>>n;
	int flag=0;
	for(int i=0;i<cntr;i++){
        if(strcmp(s[i].name,n)==0)
        {
            if(s[i].id==1)
            {
                s[i].id=-1;
                cout<<"Entry is deleted"<<endl;
            }
            else
            {
            	//test case for deleted entry
                cout<<"Entry is already deleted"<<endl;
            }
            flag=1;
            break;
        }

    }
  if(flag==0)
    {
        cout<<"Entry DOES NOT EXIST in the table!!"<<endl;
    }
}

void table::modify(){
    char n[30],c;
    int flg=0,ch,i=0,j=0;
    cout<<"Enter the name to be modified :"<<endl;
    cin>>n;
    for(i=0;i<cntr;i++){
        if(strcmp(s[i].name,n)==0)
        {
            if(s[i].id!=-1)
            {
            flg=1;
            do{
         //   cout<<"**************************"<<endl;
            cout<<"Menu :\n 1.Initial value\n 2.Type\n 3.Scope\n 4.Lines"<<endl;
           // cout<<"**************************"<<endl;
            cout<<"Enter choice"<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"Enter the initial value :"<<endl;
                cin>>s[i].initial;
                break;
            case 2:
                cout<<"Enter the type :"<<endl;
                cin>>s[i].type;
                break;
            case 3:
                cout<<"Enter the scope :"<<endl;
                cin>>s[i].scope;
                break;
            case 4:
                char y;
                cout<<"Enter the line numbers :"<<endl;
                do{
                    cin>>s[i].line[j];
                    i++;
                    cout<<"Do you want to add another line? "<<endl;
                    cin>>y;
                }while(y=='y'||y=='Y');
                break;
            default: cout<<"\n Incorrect option";
            }
            cout<<"Do you want to modify any other field? "<<endl;
            cin>>c;
            }while(c=='y'||c=='Y');
            }
            else
                cout<<"Entry cannot be modified as it is already deleted"<<endl;
            flg=1;
            break;
        }
    }
    if(flg==0){
        cout<<"Entry not present in the table."<<endl;
    }
}
void table:: insert()
{char n[30];
    cout<<"Enter the name to be inserted:"<<endl;
    cin>>n;
    for(int i=0;i<cntr;i++){

            if(strcmp(s[i].name,n)==0)
            {
                if(s[i].id!=1)
                     s[i].create();
                else
                    cout<<"Entry is already present"<<endl;
                //duplicate entry testcase
                break;
            }

    }
}
int main()
{
    table tt;
    int choice;
    char ch;
    do
    {
  //  cout<<"======================================"<<endl;
   // cout<<"************* MENU *******************"<<endl;
    //cout<<"======================================"<<endl;

    cout<<"\n\n1)Create Symbol Table\n\n2)Display Symbol Table\n\n3)Search the symbol\n\n4)Modify the symbol\n\n5)Delete the symbol\n\n";
   // cout<<"======================================"<<endl<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
    switch(choice)

    {
    case 1:tt.tcreate();
    break;
    case 2:tt.tdisplay();
    break;
    case 3:tt.search();
    break;
    case 4:tt.modify();
    break;
    case 5:tt.deleter();
    break;
    default:cout<<"Invalid choice"<<endl;
    break;
    }
    cout<<endl<<endl;
    cout<<"Do you want to continue??";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}

/*
 *


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
1
Enter the name to be inserted:
house
Enter initial value :
0
Enter the type of variable :
private
Enter the scope of variable :
int
Enter line number :
100
Do you want to add another line?
y
Enter line number :
50
Do you want to add another line?
n
Do you want to add another entry?
y
Enter the name to be inserted:
house
Entry is already present
Do you want to add another entry?
y
Enter the name to be inserted:
house_type
Enter initial value :
appartment
Enter the type of variable :
string
Enter the scope of variable :
private
Enter line number :
30
Do you want to add another line?
n
Do you want to add another entry?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house          0              private        int            100 50

house_type     appartment     string         private        30



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
3
Enter the name to be searched :
house_num
Entry not present in the table.


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
4
Enter the name to be modified :
house
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines

Enter choice
2
Enter the type :
int
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
3
Enter the type :
String
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines

Enter choice
3
Enter the scope :
private
Do you want to modify any other field?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house          0              String         private        100 50

house_type     appartment     string         private        30



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
4
Enter the name to be modified :
house__
Entry not present in the table.


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
4
Enter the name to be modified :
house
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
1
Enter the initial value :
NULL
Do you want to modify any other field?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house          NULL           String         private        100 50

house_type     appartment     string         private        30



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
1
Enter the name to be inserted:
house_color
Enter initial value :
white
Enter the type of variable :
char array
Enter the scope of variable :
Enter line number :
77
Do you want to add another line?
n
Do you want to add another entry?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house_name     NULL           String         private        100 50

house_type     appartment     string         private        30

house_color    white          char           array          77



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
4
Enter the name to be modified :
house_color
Menu : 
 1.Initial value
 2.Type
 3.Scope
 4.Lines

Enter choice

2
Enter the type :
char_array
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines

Enter choice
3
Enter the scope :
protected
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
5
Enter the line numbers :
12
Do you want to add another line?
n
Do you want to modify any other field?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
3
Enter the name to be searched :
house_color
Name           Value          Type           Scope          Lines

house_color    white          char_arrayprotectedprotected      cted12



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
4
Enter the name to be modified :
house_color
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines

Enter choice
1
Enter the initial value :
white
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
2
Enter the type :
protected
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
3
Enter the scope :
private
Do you want to modify any other field?
y
Menu :
 1.Initial value
 2.Type
 3.Scope
 4.Lines
Enter choice
4
Enter the line numbers :
12
Do you want to add another line?
y
16
Do you want to add another line?
n
Do you want to modify any other field?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
3
Enter the name to be searched :
house_color
Name           Value          Type           Scope          Lines

house_color    white          protected      private        12



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house_name     NULL           String         private        100 50

house_type     appartment     string         private        30

house_color    white          protected      private        12



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
1
Enter the name to be inserted:
m
Enter initial value :
0
Enter the type of variable :
flag
Enter the scope of variable :
local
Enter line number :
111
Do you want to add another line?
n
Do you want to add another entry?
n


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house_name     NULL           String         private        100 50

house_type     appartment     string         private        30

house_color    white          protected      private        12

m              0              flag           local          111



Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
5
Enter the name to be deleted :

d
Entry DOES NOT EXIST in the table!!

Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
5
Enter the name to be deleted :
m
Entry is deleted


Do you want to continue??y


1)Create Symbol Table

2)Display Symbol Table

3)Search the symbol

4)Modify the symbol

5)Delete the symbol

Enter your choice:
2
Name           Value          Type           Scope          Lines
house_name     NULL           String         private        100 50

house_type     appartment     string         private        30

house_color    white          protected      private        12



Do you want to continue??n

 */
