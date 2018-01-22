//============================================================================
// Name        : graphs.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stack>
#include <queue>
#include <iostream>

#define max 10
using namespace std;

class list {
	list * next ;
	int node;
	int visited;
public:

	list() {
		next=NULL;
	    node = 0;
	    visited=0;
	}
	void accept(int node);
	void display();
friend class graph;
};

class graph {
int adMax[max][max],edges,vertices;
list adList[max];
public:
graph() {
	for (int i=0;i<max;i++) {
		for(int j=0;j<max;j++) {
		  adMax[i][j]=0;

		}
	}
	edges=0,vertices=0;
}

void in_adMax(int r,int c);
void in_adList();
void readGraph();
void display_adMax();
void display_adList();
void resetVisited();   // make visited[]=0
void bfs_adList(int start);
void dfs_adList(int start);

};

void graph::resetVisited() {

	for(int i=0;i<vertices;i++) {
		adList[i].visited=0;
	}
}
void graph::bfs_adList(int start) {

	
	    queue<int> q;
        int data;
       
        q.push(start);
        adList[start].visited=1;
                     
        

    	while(!q.empty()){

	    	data=q.front();
	    	q.pop();
	    	cout<< adList[data].node<<" ";
    	
	    		for(int j=0;j<vertices;j++) {
	    		
	    		  if(adList[j].visited!=1 && adMax[data][j]==1) {
	    	     	q.push(j);
	           	    adList[j].visited=1;
	                	
	              }

	            }

	    }
	resetVisited();
	cout<<endl;
   

}


void graph :: dfs_adList(int start)
{
    int data;
	stack<int> s;

	    s.push(start);
  
   
        while(!s.empty()) {
          
          data=s.top();
          if(   adList[data].visited==0) {
             cout<<adList[data].node<<" " ;
             adList[data].visited=1;
          }
          s.pop();
       
          for(int i=0;i<vertices;i++) {
           
          	if(adList[i].visited==0 && adMax[data][i]==1) {
          		s.push(i);
          	}
          }
        

        }
        resetVisited();
  
}
void list::accept(int data) {
	node=data;
}
void graph :: in_adMax(int r,int c) {

		adMax[r][c]=1;
		adMax[c][r]=1;


}
void graph:: readGraph() {
    int r,c;
	cout<<"\nEnter the number of vertices in the graph :\n";
	cin>>vertices;
    cout<<"\nEnter the number of edges in the graph :\n";
	cin>>edges;
	for(int i=0;i<edges;i++) {
		cout<<"Enter the vertices joining of edge number :"<<'e'<<i+1<<endl;
		cout<<"Starting vertex : \n ";
		cin>>r;
		cout<<"Ending vertex : \n";
		cin>>c;
		in_adMax(r-1,c-1);
	}

}
void graph::in_adList() {
    list *temp,*ptr;
    for(int i=0;i<vertices;i++) {
    	   cout<<"\nEnter data for vertex :"<<i+1<<endl;
           cin>>adList[i].node;
    }
	for(int i=0;i<vertices;i++) {
		ptr=&adList[i];
		for(int j=0;j<vertices;j++){

			if(adMax[i][j] == 1) {
			   temp=new list();
               temp->accept(adList[j].node);
               ptr->next=temp;
               ptr=ptr->next;
			}
		}
	}
}
void graph :: display_adList() {
	list *ptr;
	cout<<"List is: "<<endl;
	for(int i=0;i<vertices;i++) {
	    ptr=&adList[i];
		while(ptr!=NULL) {
	    	cout<<ptr->node<<" ";
	    	ptr=ptr->next;
	    	if(ptr!=NULL) {
	    		cout<<" -> ";
	    	}

	    }
		cout<<endl;
	}
}
void graph :: display_adMax() {
	cout<<"Adjacency matrix is :"<<endl<<endl;
	for(int i=0;i<vertices;i++) {
		for(int j=0;j<vertices;j++) {
			cout<<adMax[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
    int choice,s;
    char ch;
    graph g1;
    do {
    	cout<<"\n\nEnter operation: \n\n1.Accept graph\n2.Display AdMax\n3.Accept node data"
    		   "\n4.Display links\n5.Display bfs\n6.Display dfs\n";
    	cin>>choice;
    	switch(choice) {
    	case 1:g1.readGraph();
    		   break;
    	case 2:g1.display_adMax();
    		   break;
    	case 3:g1.in_adList();
    	       break;
    	case 4:g1.display_adList();
    	       break;
    	case 5:cout<<"Enter starting vertex"<<endl;
    	       cin>>s;
    	       g1.bfs_adList(s);
    	       break;
     	case 6:cout<<"Enter starting vertex"<<endl;
    	       cin>>s;
     		   g1.dfs_adList(s);
     		   break;
    	default:cout<<"\nIncorrect choice, please re-enter";
    	}
    	cout<<"\n\nDo you wish to continue? y/n\n";
    	cin>>ch;
    }while(ch=='y');
	return 0;
}

/*

Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
1

Enter the number of vertices in the graph :
10

Enter the number of edges in the graph :
11
Enter the vertices joining of edge number :e1
Starting vertex : 
 1
Ending vertex : 
2
Enter the vertices joining of edge number :e2
Starting vertex : 
 1
Ending vertex : 
4
Enter the vertices joining of edge number :e3
Starting vertex : 
 2
Ending vertex : 
3
Enter the vertices joining of edge number :e4
Starting vertex : 
 4
Ending vertex : 
5
Enter the vertices joining of edge number :e5
Starting vertex : 
 4
Ending vertex : 
6
Enter the vertices joining of edge number :e6
Starting vertex : 
 5
Ending vertex : 
9
Enter the vertices joining of edge number :e7
Starting vertex : 
 6
Ending vertex : 
7
Enter the vertices joining of edge number :e8
Starting vertex : 
 3 
Ending vertex : 
8
Enter the vertices joining of edge number :e9
Starting vertex : 
 10
Ending vertex : 
7
Enter the vertices joining of edge number :e10
Starting vertex : 
 10
Ending vertex : 
8
Enter the vertices joining of edge number :e11
Starting vertex : 
 10
Ending vertex : 
9


Do you wish to continue? y/n
y


Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
3

Enter data for vertex :1
11

Enter data for vertex :2
12

Enter data for vertex :3
13

Enter data for vertex :4
14

Enter data for vertex :5
15

Enter data for vertex :6
16

Enter data for vertex :7
17

Enter data for vertex :8
18

Enter data for vertex :9
19

Enter data for vertex :10
20


Do you wish to continue? y/n
y


Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
4
List is: 
11  -> 12  -> 14 
12  -> 11  -> 13 
13  -> 12  -> 18 
14  -> 11  -> 15  -> 16 
15  -> 14  -> 19 
16  -> 14  -> 17 
17  -> 16  -> 20 
18  -> 13  -> 20 
19  -> 15  -> 20 
20  -> 17  -> 18  -> 19 


Do you wish to continue? y/n
y


Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
5
Enter starting vertex
0
11 12 14 13 15 16 18 19 17 20 


Do you wish to continue? y/n
y


Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
0

Incorrect choice, please re-enter

Do you wish to continue? y/n
y


Enter operation: 

1.Accept graph
2.Display AdMax
3.Accept node data
4.Display links
5.Display bfs
6.Display dfs
6
Enter starting vertex
0
11 14 16 17 20 19 15 18 13 12 

Do you wish to continue? y/n
n

*/