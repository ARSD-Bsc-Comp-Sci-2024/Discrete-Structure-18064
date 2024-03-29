/*Write a Program to create a SET A and determine the cardinality of SET for an input array of elements (repetition allowed) and perform the following operations on the SET: 
a) ismember (a, A): check whether an element belongs to set or not and return value as 
true/false.
b) powerset(A): list all the elements of power set of A*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Set
{
	vector<int> set;
	int size = 0;
  public:
	void input()
	{
		int num;
		cout << "Enter the element (Enter -1 to stop) : ";
		cin >> num;
		int check = 1;
		while (check)
		{
			if (num < 0)
				break;
			set.push_back(num);
			size++;
			cout << "Enter the element (Enter -1 to stop) : ";
			cin >> num;
		}
	}

	void display()
	{
		cout << "\nSet A: { ";
		for (auto i = set.begin(); i != set.end(); ++i)
			cout << *i << " ";
		cout << "}";
		cout << "\nThe cardinality of set is: " << size << endl;
	}
	
	bool ismember(int n, Set A)
	{
		bool c = false;
		for (auto i = set.begin(); i != set.end(); ++i)
		{
			if (*i == n)
				c = true;
		}
		return c;
	}
	
	void powerset(Set A){
		int psize=pow(2, size);
		vector<vector<int>> sub;
		for (int i=0; i<psize; i++){
				vector<int> sub1;
				for (int j=0; j<size; j++){
					if (i & (1<<j))
						sub1.push_back(set[j]);
				}
				sub.push_back(sub1);;	
		}
		for (int i = 0; i < sub.size(); i++) { 
		cout<<"{ ";
			for (int j = 0; j < sub[i].size(); j++) 
				cout << sub[i][j] << " "; 
			cout <<"}"<< endl; 
		}
	}
};

int main()
{
	Set s;
	cout<<"Set A: "<<endl;
	s.input();
	s.display();
	cout<<"\nEnter the element to be searched: ";
	int num;
	cin>>num;
	bool res = s.ismember(num ,s);
	if (res)
		cout << "Element "<<num<<" found in the set.";
	else
		cout << "Element "<< num<<" not found in the set.";
	cout<<"\n\nPower Set: "<<endl;
	s.powerset(s);
	return 0;
}