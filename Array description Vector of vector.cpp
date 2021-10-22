#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
# define INF 0x3f3f3f3f 
const int MAX = 1e3 + 7; 
////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll base,ll por)
{
ll res=1;
while(por>1){
if(por%2==1)
{
res*=base;
por--;
}
por/=2;
base*=base;
}
res*=base;
return res;
}


/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    int x;
    cin>>x;
    if(x==0)
    {
        fill(dp[0].begin(),dp[0].end(),1);

    }else
    {
        dp[0][x]=1;
    }
    f(i,1,n)
    {
        cin>>x;
        if(x==0)
        {
            f(j,1,m+1)
            {
                for(int k:{j-1,j,j+1})
                {
                    if(k>=1 && k<=m)
                    {
                        (dp[i][j]+=dp[i-1][k])%=mod;
                    }
                }
            }
        }
        else
        {
            for(int k : {x-1,x,x+1})
            {
                if(k>=1 && k<=m)
                {
                    (dp[i][x]+=dp[i-1][k])%=mod;
                }
            }
        }
        

    }
    int ans=0;
    for(int j=1;j<=m;j++)
    {
        (ans+=dp[n-1][j])%=mod;
    }
    cout<<ans;
   return 0;
}