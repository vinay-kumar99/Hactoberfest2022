/*
    Program to find the first n terms in fibonacci series.
*/

#include<iostream>
using namespace std;

int Fib(int n)
{
    int f[n + 2];

    f[0] = 0;
    f[1] = 1;
    int i;
 
    for(i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    
    return f[n];
}

int main(){
    int n,j=0;
    cout << "Enter the total number of terms:";
    cin >> n;

    for(int i=1; i<=n; i++, j++)
    {
        int r = Fib(j);
        cout << r << " ";
    }
}
