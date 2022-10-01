#include<bits/stdc++.h>
using namespace std;
int countAndMerge(int a[],int l,int mid,int r)
{
    int n1=mid-l+1,n2=r-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){  left[i]=a[l+i];   }
    for(int i=0;i<n2;i++){  right[i]=a[mid+1+i];    }
    int res=0,i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j]){   a[k]=left[i];  i++; k++;   }
        else{
            a[k]=right[j];  j++;    k++;    res+=(n1-i);
        }
    }
    while(i<n1) {   a[k]=left[i]; i++;k++;}
    while(j<n2) {   a[k]=right[j]; j++;k++;}
    return res;
}
int countInversion(int a[],int l,int r)
{
    int res=0;
    if(r>l)
    {
        int mid_ind=l+(r-l)/2;
        res+=countInversion(a,l,mid_ind);
        res+=countInversion(a,mid_ind+1,r);
        res+=countAndMerge(a,l,mid_ind,r);
    }
    return res;
}
int main()
{
    cout<<"enter the value of n"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<countInversion(arr,0,n-1);
}
