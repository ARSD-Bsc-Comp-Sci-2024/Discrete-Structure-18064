/*Write a Program that generates all the permutations of a given set of digits, with or without repetition.*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
void permutation(vector<int> a,vector<int> r, int index){
    for (int i=0; i<a.size(); i++)
    {
        r[index]=a[i];
        if(index==a.size()){
            result.push_back(r);
            return;
        }else{
            permutation(a,r,index+1);
        }
    }
}
int main(){
    cout<<"Enter the number of digits: ";
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a){
        cout<<"Enter digit: ";
        cin>>i;
    }
    vector<int> r(n);
    permutation(a,r, 0);
    cout<<"\nPermutations:"<<endl;
    for(auto v: result){
        cout<<"(";
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<") ";
    }
}
