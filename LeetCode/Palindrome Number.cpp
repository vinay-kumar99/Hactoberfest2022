// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/


class Solution {
public:
    bool isPalindrome(int x) {
        long long int temp1=x,temp2=0;
        
        while(temp1>0){
            long long int rem=temp1%10;
            temp2=10*temp2+rem;
            temp1=temp1/10;
        }
        
        int y=temp2;
        if(y==x) return true;
        else return false;
    }
};
