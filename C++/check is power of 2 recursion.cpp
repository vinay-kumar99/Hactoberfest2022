#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool ispoweroftwo(int n)
{
  return n && (!(n&n-1));
}

int main()
{
     int n;
     cin >> n;
     if(ispoweroftwo(n))
     {
      cout << "YES\n";
     }
     else{
      cout << "NO\n";
     }
    
   
    return 0;
}