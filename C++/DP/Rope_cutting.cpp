#include <bits/stdc++.h>
using namespace std;
 

int max(int a, int b) { return (a > b) ? a : b; }
 
int cutRod(int price[], int index, int n,
           vector<vector<int> >& dp)
{
    // base case
    if (index == 0) {
        return n * price[0];
    }
    if (dp[index][n] != -1)
        return dp[index][n];
  
    int notCut = cutRod(price, index - 1, n,dp);
    int cut = INT_MIN;
    int rod_length = index + 1;
 
    if (rod_length <= n)
        cut = price[index]
              + cutRod(price, index, n - rod_length,dp);
 
    return dp[index][n]=max(notCut, cut);
    
}

int main()
{
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int> > dp(size,
                            vector<int>(size + 1, -1));
    cout << "Maximum Obtainable Value is "
         << cutRod(arr, size - 1, size, dp);
    getchar();
    return 0;
}
