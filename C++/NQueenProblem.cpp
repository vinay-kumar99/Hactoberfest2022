#include<iostream>
using namespace std;

bool collision(char **arr,int i,int j,int n)
{
    for(int k=0;k<i;k++)
      if(arr[k][j]=='Q') return false;

    for(int k=1;k<n;k++)
    {
        if(i-k>=0 && j-k>=0 && arr[i-k][j-k]=='Q')return false; 
        if(i-k>=0 && j+k<n && arr[i-k][j+k]=='Q')return false;
    }     
  return true;
}
bool queen(char **arr,int row,int n)
{
    if(row>=n)return true;
    for(int col=0;col<n;col++)
    {
        if(collision(arr,row,col,n))
        {
            arr[row][col]='Q';
            if(queen(arr,row+1,n))return true;
            arr[row][col]='*';
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter N :";
    cin>>n;
    cout<<"\n";
    char **arr=new char*[n];
    for(int i=0;i<n;i++)
     arr[i]=new char[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         arr[i][j]='*';
    } 
    if(queen(arr,0,n))cout<<"\nPossible\n\n";
    else cout<<"Not Possible\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         cout<<arr[i][j]<<" ";
         cout<<endl;
    }
    
}