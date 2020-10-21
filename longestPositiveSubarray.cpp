#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld     long double
#define YES cout<<"YES"<<"\n";
#define NO cout<<"NO"<<"\n";
#define yes cout<<"yes"<<"\n";
#define no cout<<"no"<<"\n";
#define No cout<<"No"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define f(i,x,a) for(i=x;i<a;i++)
#define fa(i,a) for(auto i:a)
#define out(x) cout<<x<<"\n";
#define o1(x) cout<<x<<" ";
#define pb push_back
#define F first
#define in insert
#define mp make_pair
#define S second
#define sp(n) cout<<fixed<<setprecision(n);
#define      gcd(a,b)    __gcd(a,b)
#define bs            binary_search
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>t;while(t-->0)
const ll Mod = 998244353;
#define mod 1000000007
#define pi 3.14159265358979323846
#define re return 0;
                  
    

int main()
{
      
      fast
      test{
          ll n,i,ma=0;
          cin>>n;
          ll a[n];
         
          f(i,0,n){
               cin>>a[i];
          }
          ll m=0;
          
          f(i,0,n){
              
              if(a[i]>=0){
                  m++;
              }
              if(a[i]<0){
                  if(ma<m)  {
                      ma=m;
                  }         
                  m=0;
              }
          }
          
          if(ma<m){
                      ma=m;
          } 
         out(ma) 
      }
    re
}





