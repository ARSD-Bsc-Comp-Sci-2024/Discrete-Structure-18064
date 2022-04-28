#include<iostream>
#include<conio.h>
using namespace std;

class selectionSort{
	int n;
	int *a;
	public:
		selectionSort(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		void sort(){
			int temp, index;
			int count= 0;
			for (int i=n-1; i>0 ; i--){
				temp=a[0];
				index=0;
				for (int j=1; j<=i; j++)
					if (a[j]>temp){
						temp=a[j];
						index=j;
						count++;
					}
					a[index]=a[i];
					a[i]=temp;			
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
	selectionSort B(n);
	B.input();
	cout<<"\nBefore sorting: \n Array="<<endl;
	B.print();
	B.sort();
	cout<<"\nAfter sorting: \n Array="<<endl;
	B.print();
	getchar();
	return  0;
}
