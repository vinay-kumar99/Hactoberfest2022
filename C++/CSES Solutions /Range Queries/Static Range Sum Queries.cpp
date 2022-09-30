#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define gcd __gcd
#define endl "\n"
#define int long long int
#define intmax INT_MAX
#define intmin INT_MIN
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define inp(x) int x ; cin>>x ;
#define need_for_speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rfor(i,a,b) for(int i=a;i>=b;i--)
#define prauto(arr) for(auto it:arr) cout<<it<<" "; cout<<"\n";
#define forauto(it,arr) for(auto it:arr)
#define all(x) x.begin(),x.end()
const int N=2*1e5 +10;
vi v(N) ,pre(N) ;
 
signed main()
{
    need_for_speed;
    inp(n);  inp(q); for(int i=1;i<=n;i++) cin>>v[i];
    loop(i,1,n+1) pre[i]=pre[i-1]+v[i];
    while (q--)
    {
        inp(l) ; inp(r);
        cout<<pre[r]-pre[l-1]<<"\n";
    }
    
}