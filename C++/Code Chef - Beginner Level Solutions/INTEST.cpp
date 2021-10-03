#include<iostream>
using namespace std;
int main(){
 
  int n,k,count=0;
  cin>>n>>k;

  for(int i=0;i<n;i++){
      if(i%k==0){
          count += 1;
      }
    cout<<count;
  }
 
  return 0;
}