#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,count=0;
		cin>>n;
		for(int i=5;n/i>=1;i*=5)
		{
			count+=n/i;
		}
		cout<<count<<endl;
		
	}
	
}
