#include<bits/stdc++.h>
//QUES:

// Given an array and q quries in form of L and R.Print GCD of array excluding range L....R
// Find gcd of 1 to l-1 -g1
//      gcf of r+1 to n -g2
//      find gcd(g1,g2) 
//    1 2 3 4 5 6 7 8 9 10
// if we want to exclude range 4 to 7 it means find gcd of 1,2,3 and 8,9,10

using namespace std;


int main(){
    int n,l,r;cin>>l>>r;
    int a[n];
    for(int i=0;i<n;i++)    
        cin>>a[i];
    int pre[n],suf[n];
    pre[0]=0;suf[n]=0;
    for(int i=1;i<=n;i++)
        pre[i]=gcd(pre[i],i)
    
}


//Some Basic Info:
    // (n1+n2)%mod=((n1%mod+n2%mod))%mod;
    //GCD
        // 140=12*11+8 gcd(140,12)
        // 12 =8*1+4   gcd(12,8)
        // 8  =4*2+0   gcd(8,4) 
        //             gcd(4,0)

         
        // int gcd(a,b){
        //     if(b==0)
        //         return a;
        //     else
        //         return gcd(b,a%b);
        // }

