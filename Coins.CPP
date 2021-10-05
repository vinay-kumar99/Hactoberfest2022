#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;

map <ll,ull> mymap;
ull max(ll x, ull y)
{
	return ((x>y)?x:y);
}
ull findc(ll n)
{
	if(n==0)
	return 0;
	ull a=mymap[n];
	if(a==0)
	{
		a=max(n,(findc(n/2)+findc(n/3)+findc(n/4)));
		mymap[n]=a;
	}
	return a;
	
}

int main() {

	ll n;
	// findc();
	mymap.clear();
	while(cin>>n)
	{
		// cout<<mymap[n];
		cout<<findc(n)<<"\n";
	}
	return 0;
}
