#include<iostream>
#include<conio.h>
using namespace std;

class Lsearch{
	int n;
	int *a;
	public:
		Lsearch(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		int search(int num){
			for(int i=0; i<n; i++){
				if(a[i]==num)
					return i;
			}
			return -1;
		}
};

int main(){
	clrscr();
	int n, find, res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	Lsearch A(n);
	A.input();
	cout<<"\nEnter the element to be searched: "<<endl;
	cin>>find;
	res=A.search(find);
	if (res<0){
		cout<<"\nElement not found in the array."<<endl;
	} else{
		cout<<"\nElement found at index "<<res<<" in the array."<<endl;
	}
	getchar();
	return  0;
}
