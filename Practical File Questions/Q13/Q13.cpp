/*Write a Program to accept the truth values of variables x and y, and print the truth table of the following logical operations:
a) Conjunction,  b) Disjunction,  c) Exclusive OR,  d) Conditional,  e) Bi-conditional,  f) Exclusive NOR, 
) Negation, 
) NAND,  i) NOR
*/

#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

class TruthTable{
	int size;
	int *a, *b;
	public:
		void input(){
			cout<<"Enter the number of truth values: ";
			cin>>size;
			a=new int[size];
			b=new int[size];
			cout<<"Enter truth values of x: ";
			for (int i=0; i<size; i++)
				cin>>a[i];
			cout<<"Enter truth values of y: ";
			for (int i=0; i<size; i++)
				cin>>b[i];
		}
		char convert(int num){
			if(num==1)
				return 'T';
			else
				return 'F';
		}
		
		void conjunction(){
			int conj[size];
			for (int i=0; i<size; i++)
				conj[i]=a[i]*b[i];
			cout<<"\nConjunction: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x∧y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(conj[i])<<endl;
		}
		void disjunction(){
			int disj[size];
			for (int i=0; i<size; i++){
				disj[i]=a[i]+b[i];
				if(disj[i]>1)
					disj[i]=1;
			}
			cout<<"\nDisjunction: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x∨y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(disj[i])<<endl;
		}
		
		void negation(){
			int neg_a[size];
			int neg_b[size];
			for (int i=0; i<size; i++){
				if(a[i]==1)
					neg_a[i]=0;
				else
					neg_a[i]=1;
				if(b[i]==1)
					neg_b[i]=0;
				else
					neg_b[i]=1;
			}
			cout<<"\nNegation: "<<endl;
			cout<< "\nx" <<setw(4)<< "¬x"<<setw(8)<<"y"<< setw(4)<<"¬y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(neg_a[i])<<setw(7)<<convert(b[i]) <<setw(3) <<convert(neg_b[i])<<endl;
		}
		
		void exclusive_or(){
			int exor[size];
			for (int i=0; i<size; i++){
				exor[i]=a[i]+b[i];
			}
			cout<<"\nExclusive OR: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x⊕y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(exor[i])<<endl;
		}
		
		void nand(){
			int nand[size];
			for (int i=0; i<size; i++)
				if(a[i]*b[i]>0)
					nand[i]=0;
				else
					nand[i]=1;
			cout<<"\nNand: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x↑y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(nand[i])<<endl;
		}
		
		void nor(){
			int nor[size];
			for (int i=0; i<size; i++)
				if(a[i]+b[i]==0)
					nor[i]=1;
				else
					nor[i]=0;
			cout<<"\nNOR: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x↓y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(nor[i])<<endl;
		}
		void xnor(){
			int xnor[size];
			for (int i=0; i<size; i++)
				if(a[i]+b[i]==1)
					xnor[i]=0;
				else
					xnor[i]=1;
			cout<<"\nExclusive NOR: "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(12)<< "(x⊕y)'"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(xnor[i])<<endl;
		}
		
		void conditional(){
			int cond[size];
			for (int i=0; i<size; i++){
				if(a[i]==0){
					cond[i]=1+b[i];
				}else{
					cond[i]=b[i];
				}
				if(cond[i]>1)
					cond[i]=1;
			}
			cout<<"\nConditional(¬x∨y): "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x→y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(cond[i])<<endl;
		}
		
		void biconditional(){
			int bicond[size] , b1[size], b2[size];
			for (int i=0; i<size; i++){
				if(a[i]==0){
					b1[i]=1+b[i];
				}else{
					b1[i]=b[i];
				}
				if(b1[i]>1)
					b1[i]=1;
			}
			for (int i=0; i<size; i++){
				if(b[i]==0){
					b2[i]=1+a[i];
				}else{
					b2[i]=a[i];
				}
				if(b2[i]>1)
					b2[i]=1;
			}
			for (int i=0; i<size; i++)
				bicond[i]=b1[i]*b2[i];
			cout<<"\nConditional(x→y∧y→x): "<<endl;
			cout<< "\nx" <<setw(4)<<"y"<< setw(8)<< "x⇔y"<<endl;
			for (int i=0; i<size; i++)
				cout<<convert(a[i])<<setw(3)<< convert(b[i]) <<setw(6)<<convert(bicond[i])<<endl;
		}
};

int main(){
	clrscr();
	TruthTable t;
	t.input();
	t.conjunction();
	t.disjunction();
	t.exclusive_or();
	t.conditional();
	t.biconditional();
	t.xnor();
	t.negation();
	t.nand();
	t.nor();
	return 0;
}
