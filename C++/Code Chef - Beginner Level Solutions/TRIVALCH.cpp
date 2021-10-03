#include<iostream>
using namespace std;
int main(){
 
  int l,b,h;
  cin>>l>>b>>h;

  if(((l+b)>h) && ((b+h)>l) &&((l+h)>b) ){
      cout<<"YES";
  }
  else{
      cout<<"NO";
  }
 
  return 0;
}