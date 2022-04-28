#include<iostream>
#include<conio.h>
using namespace std;

class sinkSort{
	int n;
	int *a;
	public:
		sinkSort(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		void sort(){
			int temp;
			int count= 0;
			for (int i=n-1; i>=0 ; i--)
				for (int j=n-1; j>n-i-1; j--)
					if (a[j]<a[j-1]){
						temp=a[j];
						a[j]=a[j-1];
						a[j-1]=temp;
						count ++;
					}
			cout<<"\n\nNumber of comparisons: "<<count<<endl;
		}
		void print(){
			for (int i=0; i<n;i++)
				cout<<a[i]<<endl;
		}
};

int main(){
	clrscr();
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	sinkSort B(n);
	B.input();
	cout<<"\nBefore sorting: \n Array="<<endl;
	B.print();
	B.sort();
	cout<<"\nAfter sorting: \n Array="<<endl;
	B.print();
	getchar();
	return  0;
}
