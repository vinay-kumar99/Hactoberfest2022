// Problem Statement : You are given a number n. You need to find the digital root of n.
//DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.
// Input : 1 outpot : 1
// Input : 99999 output : 9  
/* Sum of digits of 99999 is 45
which is not a single digit number, hence
sum of digit of 45 is 9 which is a single
digit number. */

#include <iostream>
using namespace std;

int digitalRoot(int n)
{
    int count=0;
    while(n>0)
    {
        count=count+(n%10);
        n=n/10;
    }
    
    if(count<10)
    return count;
    return digitalRoot(count);
    
}

int main() {
    
	 int n;
	 cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    cout<<digitalRoot(n)<<endl;
	    
	  
	return 0;
}  
