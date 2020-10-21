//[https://practice.geeksforgeeks.org/problems/stickler-theif/0]
// The link to problem youc can go and read about the problem 
// I am adding the solution to the problem 
//Hope you will like it

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int sum = 0,sum1 = 0;
        for(int i = 0; i < n; i+=2)
        {
            sum = sum + a[i];
            if(i == n-1)
            break;
            sum1 = sum1 + a[i+1];
        }
        if(sum > sum1)
        cout<<sum<<endl;
        else 
        cout<<sum1<<endl;
    }
}
