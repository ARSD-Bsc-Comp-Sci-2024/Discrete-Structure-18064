/*Write a Program to implement Tower of Hanoi using recursion.*/
#include <iostream>
using namespace std;

int Hanoi(int n,char strt,char dest,char spare, int &c)
{
    if(n == 0)
    {
        return c;
    }
    Hanoi(n-1, strt, spare, dest,c);
    cout<<"Moving disk "<<n<< " from "<<strt<<" to "<<dest<<endl;
    c++;
    Hanoi(n-1, spare, dest, strt,c);
}

int main()
{
    int num, c=0;
    char start, destination, spare;
    cout<<"Enter the number of disk(s) :";
    cin>>num;
    cout<<"\nEnter the start rod :";
    cin>>start;
    cout<<"Enter the destination rod :";
    cin>>destination;
    cout<<"Enter the spare rod :";
    cin>>spare;
    cout<<endl;
    int res=Hanoi(num, start, destination, spare, c);
    cout<<"\nNumber of Shifting: "<<res;
    return 0;
}
