//Josephus problem 
//Problem Statement  : Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
//The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.
//Input : 5 3 // Output : 4
//Input : 3 2 // Output : 2

#include<bits/stdc++.h>
using namespace std;

int joseph(int n,int k){
    if(n==1){
        return 0;
    }

    int x=joseph(n-1,k);
    int y=(x+k)%n;
    return y;
}

int main(){
    int n;int k;
    cin>>n>>k;
    cout<<joseph(n,k);
    return 0;
}
