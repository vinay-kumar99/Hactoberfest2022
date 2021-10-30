//C++ program for the famous "Tower of Hanoi Problem".

#include<bits/stdc++.h>
using namespace std;


// utility function over no. of disks left
void recursion(int a ,int b,int c,int n){
    if(n==0){
        return;
    }
    recursion(a,c,b,n-1);
    cout<<a<<" "<<c<<endl;
    recursion(b,a,c,n-1);
}

//main function
int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    recursion(1,2,3,n);
    return 0;
}
