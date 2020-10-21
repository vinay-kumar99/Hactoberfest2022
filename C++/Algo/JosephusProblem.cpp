//Josephus problem 
//Problem Statement  : Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
//The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.
//Input : 5 3 // Output : 4
//Input : 3 2 // Output : 2

#include <bits/stdc++.h>
using namespace std;


int jos(int n, int k)
{
   if(n==1)
   return 0;
   else
   return (jos(n-1,k)+k)%n;
 }
int josephus(int n,int k)
{
    int ans=jos(n,k);
    return ans+1;
}

int main()
{
	int n,k;
	cin>>n>>k;
		
		//calling josephus() function
		cout<<josephus(n,k)<<endl;
	
	return 0;
}

