#include<iostream>
#include<conio.h>
using namespace std;

class insertionSort{
	int n;
	int *a;
	public:
		insertionSort(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		void sort(){
			int temp, j, count=0;
			for(int i=1; i<n; i++){
				temp=a[i];
				j=i;
				while(j>0 && a[j-1]>temp){
					a[j]=a[j-1];
					j--;
					count++;
				}
				a[j]=temp;
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
	insertionSort B(n);
	B.input();
	cout<<"\nBefore sorting: \n Array="<<endl;
	B.print();
	B.sort();
	cout<<"\nAfter sorting: \n Array="<<endl;
	B.print();
	getchar();
	return  0;
}
