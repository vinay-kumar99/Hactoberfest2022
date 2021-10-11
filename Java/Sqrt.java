Sqrt(x)

Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.



class Solution {
    public int mySqrt(int x) {
    int l=1,r=x/2,ans=0;
    if(x==1)
        return 1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if((long)mid*mid<=x)
        { ans=mid;
         l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
}
   
