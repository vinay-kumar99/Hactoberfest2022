#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long c(int n, int r)
{
    if(n == r || r == 0)
    return 1;
    else
    return c(n-1,r-1) + c(n-1,r);
}
int main()
{
    int n,r;
    cout<<"Enter N and r respectively for nCr : ";
    cin>>n>>r;
    cout<<"Result is : ";
    cout<<c(n,r);
}
