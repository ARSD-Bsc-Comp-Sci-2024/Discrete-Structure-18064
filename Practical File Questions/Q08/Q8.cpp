/*Write a Program to implement Bubble Sort. Find the number of comparisons during each
pass and display the intermediate result. Use the observed values to plot a graph to analyse
the complexity of algorithm.*/
#include<iostream>
#include<conio.h>
using namespace std;

class bubbleSort{
	int n;
	int *a;
	public:
		bubbleSort(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		void sort(){
		    cout<<"\nSorting steps:"<<endl;
			int temp;
			int count= 0;
			for (int i=0; i< n-1; i++){
                int c=0;
                cout<<"Iteration "<<i+1<<endl;
				for (int j=0; j<n-i-1; j++){
					if (a[j]>a[j+1]){
						temp=a[j];
						a[j]=a[j+1];
						a[j+1]=temp;
						count ++;
                        c++;
						print();
					}
				}
				cout<<"Number of comparison: "<<c<<endl;
			}
			cout<<"\nTotal number of comparisons: "<<count<<endl;
		}
		void print(){
			for (int i=0; i<n;i++)
				cout<<a[i]<<" ";
            cout<<endl;
		}
};

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	bubbleSort B(n);
	B.input();
	cout<<"\nBefore sorting: \n Array= ";
	B.print();
	B.sort();
	cout<<"\nAfter sorting: \n Array= ";
	B.print();
	getchar();
	return  0;
}
