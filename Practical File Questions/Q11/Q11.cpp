/*Write a Program to calculate Permutation and Combination for an input value n and r using
recursive formula of nCr and nPr .*/
#include <iostream>
using namespace std;

int permutation(int n, int r){
    if(r==0){
        return 1;
    }else if(r>n){
        return 0;
    }
    return permutation(n-1,r)+ r* permutation(n-1,r-1);
}
int combination(int n, int r){
    if(r==0 || r==n){
        return 1;
    }
    return combination(n-1,r)+ combination(n-1,r-1);
}
int main(){
    int n,r;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter r: ";
    cin>>r;
    cout<<"\n(1) Permutation \nAnswer: "<<permutation(n,r);
    cout<<"\n\n(2) Combination \nAnswer: "<<combination(n,r)<<endl;
}
