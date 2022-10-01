class Solution(object):
    
    def change(self, amount, coins):
        
        dp=[[0 for i in range(amount+1)] for j in range(len(coins)+1)]
  
        for i in range(0,len(coins)+1):
            dp[i][0]=1
        for i in range(1,len(coins)+1):
            for j in range(1,amount+1):
                if j>=coins[i-1]:
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j]

                else:
                    dp[i][j]=dp[i-1][j]
       
        return(dp[len(coins)][amount])
