#include <iostream>
#define MAX_DIM 100
using namespace std;

void solutions(int *arr, int size,
             int *temp, int l, int start,
             int s, int &c)
{
  for (int i = 0; i < size; i++)
  {
    temp[start] = arr[i];
    if (start == l)
    {
      int sum = 0;
      for (int j = 0; j < start + 1; j++)
        sum += temp[j];
      if (sum == s)
      {
        cout << "[ ";
        for (int k = 0; k < start + 1; k++)
          cout << temp[k] << " ";
        cout << "] ";
        c++;
      }
    }
    else
      solutions(arr, size, temp, l, start + 1, s, c);
  }
}

int main()
{
  int n, s, c = 0;
  cout << "Equation: x1+x2+x3+......+xn=C";
  cout << "\nEnter the number of terms (n): ";
  cin >> n;
  int arr[11];
  for (int i = 0; i <= 10; i++)
    arr[i] = i;
  cout << "Enter the sum (C<=10): ";
  cin >> s;
  cout << "\nPossible Solutions= \n";
  int temp[MAX_DIM] = {0};
  solutions(arr, 11, temp, n - 1, 0, s, c);
  cout << "\n\nNumber of solutions found: " << c;
  return 0;
}
