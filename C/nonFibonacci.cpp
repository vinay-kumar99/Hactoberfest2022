#include<iostream>
 using namespace std;
 
 void nonFibonacci(int);
 
 int main()
 {
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	int n;
 	cin>>n;
 	nonFibonacci(n);
 	return 0;
 }
 
 void nonFibonacci(int n)
 {
 	int prevPrev=0,prev=1,curr;
 	while(n>0)
 	{
 		curr=prevPrev+prev;
 		for(int i=prev+1;i<curr;i++)
 		{
 			if(n>0)
 			cout<<i<<" ";
 			n--;
		 }
		 prevPrev=prev;
	 	 prev=curr;
	 }
	 
 }
