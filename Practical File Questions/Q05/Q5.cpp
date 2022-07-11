/*Write a Program to generate the Fibonacci Series using recursion.*/
#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return (fibonacci(n-1)+ fibonacci(n-2));
    }
}
int main(){
    int num;
    cout<<"Enter the number of terms: ";
    cin>>num;
    cout<<"\n\nFibonacci Series: ";
    for(int i=0; i<num; i++){
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
}
