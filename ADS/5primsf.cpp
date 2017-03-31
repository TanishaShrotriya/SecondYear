
#include <iostream>
#define max 10
using namespace std;

class prim
{
	int node;
	int admatrix[max][max];
	int edges,no_vertices;
	int visited[max];
public:
	prim()
{
		node=0;
		edges=0;
		no_vertices=0;
		for(int i=0;i<max;i++) {
            for(int j=0;j<max;j++) {		 
		          admatrix[i][j]=0;
	        }	
		}
		
            for(int j=0;j<max;j++) {		 
		          visited[j]=0;
	        }	
		
}
	void insertinadmatrix();
		void displayadmatrix();
		void getcostgraph();
		void algo();
};
void prim::insertinadmatrix()
{ 
    int cost;

	int r,c;
	cout<<"\n Enter the number of vertices:";
	cin>>no_vertices;
	cout<<"\n Enter the number of edges:";
	cin>>edges;
	cout<<endl;
	admatrix[no_vertices][no_vertices]=0;//saving space
	
	for(int i=0;i<edges;i++) {

		cout<<"Consider the vertex numbers are NATURAL numbers only"<<endl<<endl;
		cout<<"Enter the vertices joining the edge number :"<<'e'<<i+1<<endl;
		cout<<"Starting vertex : \n ";
		cin>>r;
		cout<<"Ending vertex : \n";
		cin>>c;
		cout<<"\nEnter the cost of fuel to travel from  "<<r<<" to "<<c<<endl;
		cin>>cost;
		admatrix[r-1][c-1]=cost;
		admatrix[c-1][r-1]=cost;

	}
}

void prim::displayadmatrix()
{
	cout<<endl<<"Admatrix is:"<<endl;
	for(int i=0;i<no_vertices;i++)
		{
		cout<<"\n";
			for(int j=0;j<no_vertices;j++)
			{
				cout<<"\t";
				cout<<admatrix[i][j];

			}
		cout<<"\n";

		}
}
void prim::getcostgraph()
{
	for(int i=0;i<no_vertices;i++)
	{
		visited[i]=0;
		for(int j=0;j<no_vertices;j++)
		{

			if(admatrix[i][j]==0)
			{
				admatrix[i][j]=999;
			}
		}
	}

}
void prim::algo()
{
	int min=0;int total=0;int p=0,q=0;
	visited[0]=1;
	cout<<endl;
	for(int i=0;i<no_vertices-1;i++)//remaining n-1 vertices
	{
		min=999;
		for(int j=0;j<no_vertices;j++)//for all rows in matrix
		{
			if(visited[j]==1) //if row is visited
			{
				for(int k=0;k<no_vertices;k++)//for all columns in matrix
				{
					if(visited[k]==0) //if column is not visited
					{
						if(min>admatrix[j][k])
						{
							min=admatrix[j][k];
							p=k; //column number
							q=j; //row number
						}
					}
				}
			}
		}
		cout<<"column- "<<p+1<<" row- "<<q+1<<" value of min- "<<min<<" "<<endl;
		visited[p]=1;
		total=total+min;
	}
	cout<<"\n total COST:"<<total;
    cout<<endl;
}
/*
 *  0	28	0	0	0	10	0
	28	0	16	0	0	0	14
	0	16	0	12	0	0	0
	0	0	12	0	22	0	6
	0	0	0	22	0	25	24
	10	0	0	0	25	0	0
	0	14	0	6	24	0	0
 */
int main()
{
	prim p;
	p.insertinadmatrix();
	p.displayadmatrix();
	p.getcostgraph();
	p.algo();
}


/*
  Enter the number of vertices:7

 Enter the number of edges:9

Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e1
Starting vertex : 
 1
Ending vertex : 
2

Enter the cost of fuel to travel from  1 to 2
28
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e2
Starting vertex : 
 1
Ending vertex : 
6

Enter the cost of fuel to travel from  1 to 6
10
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e3
Starting vertex : 
 2
Ending vertex : 
3

Enter the cost of fuel to travel from  2 to 3
16
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e4
Starting vertex : 
 2
Ending vertex : 
7

Enter the cost of fuel to travel from  2 to 7
14
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e5
Starting vertex : 
 3
Ending vertex : 
4

Enter the cost of fuel to travel from  3 to 4
12
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e6
Starting vertex : 
 2
Ending vertex : 
5

Enter the cost of fuel to travel from  2 to 5
22
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e7
Starting vertex : 
 4
Ending vertex : 
7

Enter the cost of fuel to travel from  4 to 7
6
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e8
Starting vertex : 
 5
Ending vertex : 
6

Enter the cost of fuel to travel from  5 to 6
25
Consider the vertex numbers are NATURAL numbers only

Enter the vertices joining the edge number :e9
Starting vertex : 
 5
Ending vertex : 
7

Enter the cost of fuel to travel from  5 to 7
24

Admatrix is:

	0	28	0	0	0	10	0

	28	0	16	0	22	0	14

	0	16	0	12	0	0	0

	0	0	12	0	0	0	6

	0	22	0	0	0	25	24

	10	0	0	0	25	0	0

	0	14	0	6	24	0	0

column- 6 row- 1 value of min- 10 
column- 5 row- 6 value of min- 25 
column- 2 row- 5 value of min- 22 
column- 7 row- 2 value of min- 14 
column- 4 row- 7 value of min- 6 
column- 3 row- 4 value of min- 12 

 total COST:89

 */
