class Solution {
public:
    bool isPalindrome(int x) {
        long m=x;
        if(x<0){
            return false;
        }
        else{
          long rem,revNum=0;
          while(x>=10){
             rem=x%10;
             revNum=revNum*10+rem;
             x=x/10;
          }
          revNum=revNum*10+x;
          if(revNum==m){
             return true;
          }else{
             return false;
          }
        }
    }
};
