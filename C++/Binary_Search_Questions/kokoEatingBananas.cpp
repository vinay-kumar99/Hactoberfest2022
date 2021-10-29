#include<bits/stdc++.h>
using namespace std;
#define int long long
int totalTime(vector<int> piles, int k)
{
    int count = 0;
    for(int i=0; i<piles.size(); i++)
    {
        int div = piles[i]/k;
        int rem = piles[i]%k;
            
        if(rem>0)
        {
            div+=1;
        }
        count+=div;
    }
    return count;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
        
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int time = totalTime(piles, mid);
            
        if(time>h)
        {
            start = mid+1;
        }
        else
        {
            ans = min(ans, mid);
            end = mid-1;
        }
            
    }
    return ans;
}
signed main()
{
    int n, hours;
    cin>>n>>hours;
    
    vector<int> piles(n);
    for(int i=0; i<n; i++)
    {
        cin>>piles[i];
    }
    
    int minSpeed =  minEatingSpeed(piles, hours);
    cout<<minSpeed<<endl;
}
