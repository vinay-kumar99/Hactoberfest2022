#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={1,2,5,-1,-1,2,3,4,5};
	int dp[sizeof(arr)/sizeof(arr[0])];
	int size = sizeof(arr)/sizeof(arr[0]);
	loop(i,0,sizeof(arr)/sizeof(arr[0]))
		dp[i]=1;
		
	for(int i=1;i<size;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>=arr[j])
			{
				arr[i]=max(1+dp[j],dp[i]);
			}
		}
	}
	loop(i,0,size)
		cout<<dp[i]<<" ";

	}
