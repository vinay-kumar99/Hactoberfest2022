#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>&arr,int size){
   int mxReach=0;
   for(int i=0;i<size;i++){
       if(i>mxReach){
          return false;
       }
       mxReach=max(mxReach,i+arr[i]);
   }
  return true;
}
int main(){
   int size;
   cin>>size;
   vector<int>arr; 
   for(int i=0;i<size;i++){
      cin>>arr[i];
   }
   bool ans=canJump(arr,size);
   cout<<ans<<endl;
   return 0;
}
