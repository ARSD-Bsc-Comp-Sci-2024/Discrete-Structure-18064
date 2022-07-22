#include <iostream>
#include <cmath>
using namespace std;

class Polynomial{
    private:
        int x;
        int *coeff;
        int *power;
    public:
        Polynomial(){
            cout<<"Enter number of terms in function: ";
            cin>>x;
            coeff= new int[x];
            power= new int[x];
            for(int i=0; i<x; i++){
                cout<<"Term "<<i+1<<endl;
                cout<<"\tCoefficient: ";
                cin>>coeff[i];
                cout<<"\tExponent: ";
                cin>>power[i];
            }
        }
        void print(){
            cout<<"\nFunction f(n): ";
            for(int i=0; i<x; i++){
                if(coeff[i]<0)
                    cout<<" "<<coeff[i]<<"x^"<<power[i];
                else
                    cout<<" +"<<coeff[i]<<"x^"<<power[i];
            }
        }
        void evaluate(int num){
            double result=0;
            for(int i=0; i<x; i++){
                result+= coeff[i]*pow(num, power[i]);
            }
            cout<<"\nResult on evaluation with x="<<num<<" = "<<result;
        }
};
int main(){
    Polynomial p;
    p.print();
    cout<<"\nEnter the value of x: ";
    int x;
    cin>>x;
    p.evaluate(x);
    return 0;
}
