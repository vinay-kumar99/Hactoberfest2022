#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	map<string,int> phn;
	map<string,int>::iterator itr;
	string a,c;
	int b;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>b;
		cin.ignore();
		phn[a]=b;
	}
	while(getline(cin,c))
	{
		if(phn.find(c)!=phn.end())
		{
		cout<<c<<"="<<phn[c]<<endl; 	
		}
		else
		{
		cout<<"Not found"<<endl;	
		}	
	}
	return 0;
}
