class Solution {
public:
    bool static cmp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first<b.first)
            return true;
        else if(a.first==b.first)
            return a.second<=b.second;
        else 
            return false;
            
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n= buildings.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({buildings[i][0],-1*buildings[i][2]});
            arr.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<vector<int>> res;
        multiset<int, greater<int>> ht;
        ht.insert(0);
        int ch=0;
        for(int i=0;i<2*n;i++)
        {
            int h= arr[i].second;
            if(h<0)
            {
                ht.insert(abs(h));
            }
            else
            {
                 ht.erase(ht.find(h));
            }
            int th= *(ht.begin());
            if(ch!=th)
            {
                res.push_back({arr[i].first,th});
                ch= th;
            }
        }
        return res;
    }
};