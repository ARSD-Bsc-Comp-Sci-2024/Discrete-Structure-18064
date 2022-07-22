#include<iostream>
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
            cout<<"Sorted array: ";
            for (int i=0; i<n;i++)
                cout<<a[i]<<" ";
        }
        int search(int num, int s, int end){
            if(s<=end){
                int mid=(s+end) / 2;
                if(a[mid] == num){
                    return mid;
                }else if(a[mid] < num){
                        search(num, mid+1, end);
                }else if(a[mid] > num){
                        search(num, s, mid-1);
                }
            }else{
                    return -1;
            }
        }
};

int main(){
    int n, find, res;
    cout<<"Enter the size of the array: ";
    cin>>n;
    Bsearch A(n);
    A.input();
    A.sort();
    cout<<"\nEnter the element to be searched: "<<endl;
    cin>>find;
    res=A.search(find,0,n-1);
    if (res<0){
        cout<<"\nElement not found in the array."<<endl;
    } else{
        cout<<"\nElement found at index "<<res<<" in the array."<<endl;
    }
    getchar();
    return  0;
}
