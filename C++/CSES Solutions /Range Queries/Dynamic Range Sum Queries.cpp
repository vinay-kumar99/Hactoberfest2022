#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2 * 1e5 + 2;
vector<int> v(N);
vector<int> ar(4 * N);
 
void build_tree(int cur, int s, int e)
{
    int mid = (s + e) / 2;
    if (s == e)
    {
        ar[cur] = v[s];
        return;
    }
    build_tree(2 * cur + 1, s, mid);
    build_tree(2 * cur + 2, mid + 1, e);
    ar[cur] = (ar[2 * cur + 1] + ar[2 * cur + 2]);
}
 
 
int ansdedo(int l,int r,int s,int e,int cur)
{
    if(l<=s && r>=e ) return ar[cur];
    if(l>e || r<s ) return 0;
    else
    {
        int mid=(s+e)/2;
        return ( ansdedo(l,r,s,mid,2*cur+1) + ansdedo(l,r,mid+1,e,2*cur+2) );
    }
}
 
void changekaro(int i, int val ,  int s,int e , int node)
{
    if(i==s && s==e) 
    {
        ar[node]=val;
        return;
    }
    int mid=(s+e)/2;
    if(i<=mid)
    {
        changekaro(i,val,s,mid,2*node+1);
    }else changekaro(i,val,mid+1,e,2*node+2);
    ar[node]=ar[2*node+1]+ar[2*node+2];
}
 
int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build_tree(0, 1, n);
    while (q--)
    {
        int type,x,y; cin>>type>>x>>y;
        if(type==1)
        {
            x--;
            changekaro(x,y,0,n-1,0);
        }else{
        x--;
        y--;
        cout<<ansdedo(x,y,0,n-1,0)<<"\n";
        }
    }
    
}