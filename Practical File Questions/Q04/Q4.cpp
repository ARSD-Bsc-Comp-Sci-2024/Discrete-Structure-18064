/*Use the functions defined in Q 3 to find check whether the given relation is:
a) Equivalent, or
b) Partial Order relation, or
c) None*/
#include <iostream>
using namespace std;
class RELATION{
    private:
        int **a;
        int n;
        int chk1, chk2, chk3;
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
                    chk1=0;
                    return;
                }
            }
            cout<<"\n\n***Relation is reflexive.";
            chk1=1;
        }
        void symmetric(){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(a[i][j]==1 && a[j][i]!=1){
                        cout<<"\n\n***Relation is anti-symmetric.";
                        chk2=0;
                        return;
                    }
                }
            }
            cout<<"\n\n***Relation is symmetric.";
            chk2=1;
        }
        void transitive(){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        if(a[i][j]==1 && a[j][k]==1 && a[i][k]!=1){
                            cout<<"\n\n!!!Relation is not transitive.";
                            chk3=0;
                            return;
                        }
                    }
                }
            }
            cout<<"\n\n***Relation is transitive.";
            chk3=1;
        }
        void check(){
            if(chk1==1 && chk2==1 && chk3==1){
                cout<<"\n\n**This is an equivalent relation.";
            }else if(chk1==1 && chk2==0 && chk3==1){
                cout<<"\n\n**This is a partially ordered relation.";
            }else{
                cout<<"\n\n!!!This relation is neither equivalent not partially ordered!!!";
            }
            cout<<endl;
        }
};

int main(){
    RELATION r;
    r.input();
    r.reflexive();
    r.symmetric();
    r.transitive();
    r.check();
    return 0;
}
