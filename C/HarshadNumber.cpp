#include<iostream>
 using namespace std;
 
 int main()
 {
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	int num,temp;
 	cin>>num;
 	temp=num;
 	int sum=0;
 	while(temp!=0)
 	{
 		int x=temp%10;
 		sum=sum+x;
 		temp/=10;
	 }
	 if(num%sum==0)
	 {
	 	cout<<"Harshad Number";
	 }
	 else
	 	cout<<"Not a Harshad NUmber";
	 return 0;
 }
