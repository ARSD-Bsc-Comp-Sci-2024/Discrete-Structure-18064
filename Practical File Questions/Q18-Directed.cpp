//Given a graph G, Write a Program to find the number of paths of length n between the source and destination entered by the user. 

// This program takes directed graph as its adjacency matrix. The graph must not be pseudograph i.e. with loops.Logic: using an adjacency matrix A of the graph, the number of path of length n between i and j can be found by calculating A^n, then A^n[i][j] will give the number of paths.

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h> 

using namespace std;

class Graph
{
  private:
	int v;
	int **a, **copy;

  public:
     int **res;
	Graph(int ver)
	{
		v = ver;
		a = new int *[v];
		copy = new int *[v];
		for (int i = 0; i < v; i++)
		{
			// Creating matrix a, its copy matrix and matrix to hold the result of same size
			a[i] = new int[v];
			copy[i] = new int[v];
			res[i] = new int[v];
		}
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				a[i][j] = 0;
			}
		}
	}
	
	void input(){
			int e;
			cout<<"Enter the no of edges: ";
			cin>>e;
			int i,j;
			cout<<"\nEnter vertices of edge like v1 to v2 \nSyntax: (v1<space>v2)"<<endl;
			for (int k=1; k<=e; k++){
				cout<<"Enter the vertices of edge "<<k<<" : ";
				cin>>i>>j;
				if(i<=v && j<=v){
					a[i-1][j-1]=1;
				}else{
					cout<<"\nVertex index out of bound";
					cout<<"\n\nTerminating the program..."<<endl;
					exit(0); // exiting the program if vertex does not match
				}
			}
		for (int i = 0; i < v; i++){
				for (int j = 0; j < v; j++){
					copy[i][j]=a[i][j];// Copying values of matrix a to copy matrix
				}
			}
	}
	
	void power(int **a )
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				res[i][j] = 0; // Initializing result matrix with 0
			}
		}
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
				for (int k = 0; k < v; ++k){
					res[i][j] += a[i][k] * copy[k][j];
				}
				
		for (int i = 0; i < v; i++){
				for (int j = 0; j < v; j++){
					a[i][j]=res[i][j];
				}
			}
	}
	
	void output(int s, int d){
		cout<<"\nNumber of path: "<<a[s][d];
	}
	
	void FindPath( int s, int d, int p)
	{
		for (int k=0; k<p-1;++k)
		{
			power(a);
		}
		output(s,d);
		cout<<endl;
	}
};

int main()
{
	clrscr();
	int v, src, des, len;
	cout << "Enter the number of vertices: ";
	cin >> v;
	Graph A(v);
	A.input();
 	cout<<"\nEnter the source: ";
	cin>>src;
	cout<<"Enter the destination: ";
	cin>>des;
	cout<<"Enter the length of path: ";
	cin>>len;
	A.FindPath(src-1, des-1, len);
	getchar();
	return 0;
}
