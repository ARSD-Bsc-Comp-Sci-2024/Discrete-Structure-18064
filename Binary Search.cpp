#include<iostream>
#include<conio.h>
using namespace std;

class Bsearch{
	int n;
	int *a;
	public:
		Bsearch(int size){
			n=size;
			a=new int[n];
		}
		void input(){
			cout<<"\nEnter the elements:";
			for (int i=0; i<n;i++)
				cin>>a[i];
		}
		int search(int num){
			int l=0;
			int r=n-1;
			while(l<=r){
				int mid=l+(r-l) / 2;
				if(a[mid] == num)
					return mid;
				else if(a[mid] < num)
					l=mid+1;
				else
					r=mid-1;
			}
			return -1;
		}
};

int main(){
	clrscr();
	int n, find, res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	Bsearch A(n);
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
