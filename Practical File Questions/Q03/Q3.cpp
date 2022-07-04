/*Create a class RELATION, use Matrix notation to represent a relation. Include functions to
check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program
to use this class.*/
#include <iostream>
using namespace std;
class RELATION{
    private:
        int **a;
        int n;
    public:
        RELATION(){
            cout<<"Enter the number of elements in the set: ";
            cin>>n;
            a=new int*[n];
			for (int i = 0; i < n; i++)
            {
                a[i]=new int[n];
            }
            for (int i = 0; i < n; i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j]=0;
                }
            }
        }
        void input(){
            int num;
			cout<<"\nEnter the number of relations: ";
            cin>>num;
            cout<<"\nEnter the relations: "<<endl;
			for(int i = 0; i < num; i++){
                int x,y;
				cout<<i+1<<": ";
                cin>>x>>y;
                a[x-1][y-1]=1;
			}
		}
        void reflexive(){
            for(int i=0; i<n; i++){
                if(a[i][i]!=1){
                    cout<<"\n\n!!!Relation is not reflexive.";
                    return;
                }
            }
            cout<<"\n\n***Relation is reflexive.";
        }
        void symmetric(){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(a[i][j]==1 && a[j][i]!=1){
                        cout<<"\n\n***Relation is anti-symmetric.";
                        return;
                    }
                }
            }
            cout<<"\n\n***Relation is symmetric.";
        }
        void transitive(){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        if(a[i][j]==1 && a[j][k]==1 && a[i][k]!=1){
                            cout<<"\n\n!!!Relation is not transitive.";
                            return;
                        }
                    }
                }
            }
            cout<<"\n\n***Relation is transitive.";
        }
};

int main(){
    RELATION r;
    r.input();
    r.reflexive();
    r.symmetric();
    r.transitive();
    return 0;
}
