// Start from destination then add number of way while moving left or right
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
	ll t,n;
	cin>>t;
	vector<string> v(t);
	ll aa[t][t];
	ll a,co=0,c=0,d=0,b=0,k,x=0,y=0;
	f(i,0,t)
	{
		cin>>v[i];
	}
	f(i,0,t)
	{
		f(j,0,t)
		{
			aa[i][j]=0;
		}
	}
	
	aa[0][0]=1;
	f(i,0,t)
	{
		f(j,0,t)
		{
			if(v[i][j]=='.'){
			if(i>0)
			{
				if(v[i-1][j]=='.')
				{
					aa[i][j]=((aa[i][j]%mod)+(aa[i-1][j]%mod))%mod;
				}
			}
			if(j>0)
			{
				if(v[i][j-1]=='.')
				{
					aa[i][j]=((aa[i][j]%mod)+(aa[i][j-1]%mod))%mod;
				}
			}
			}
		}
	}
	if(t==1 && v[0][0]=='*')
	{
		cout<<"0\n";
	}
	else
	{
		cout<<aa[t-1][t-1];
	}
	
	
   return 0;
}