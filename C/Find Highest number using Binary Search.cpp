#include<iostream>
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
            cin>>a[i];
        //int k = 0;
        int left = 0,right = n-1;
        while(left<=right)
        {
           int mid = (left + right)/2;
           if(left == right)
           {
               cout<<a[left]<<endl;
               break;
           }
            if(a[mid] > a[mid+1] && a[mid] > a[mid-1])
              {  cout<<a[mid]<<endl;
                break;
              }
            else if(a[mid]< a[mid-1])
                right = mid - 1;
            else
            {
                left = mid  + 1;
            }
            
        }
    }
}
