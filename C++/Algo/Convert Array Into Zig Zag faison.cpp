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
        int *a;
        a = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for(int i = 0; i < n-1; i++)
        {
            // if(i == n-1)
            // {
            //     if(i % 2 != 0 && )
            // }
             if(i % 2 != 0 && a[i] > a[i+1] && a[i] > a[i-1])
            int count = 0;
            else if(i % 2 != 0 && a[i] < a[i+1])
            swap(a[i],a[i+1]);
            else if (a[i] > a[i+1])
            swap(a[i],a[i+1]);

            
        }
        for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// you can use array instead of pointer also that is not a big deal
// execution time just 0.01
// AMAZING
