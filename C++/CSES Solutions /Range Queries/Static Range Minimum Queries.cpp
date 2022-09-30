#include <bits/stdc++.h>
//#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int,int>
#define gcd __gcd
#define endl "\n"
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define ip(x) int x; cin>>x;
#define ll long long int
#define intmax INT_MAX
#define intmin INT_MIN
#define need_for_speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rfor(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define forauto(it,arr) for(auto it:arr)
#define prauto(arr) for(auto it:arr) cout<<it<<" "; cout<<"\n";
#define pt(x) cout<<x<<"\n";
using namespace std;
 
const int N=2*1e5;
int ar[4*N+2];
vi v(N);
 
void build_tree( int cur ,  int l ,int r)
{
    if(l==r)
    {
        ar[cur]=v[l] ;
        return;
    }
    int md = (l+r)/2 ;
    build_tree(2*cur+1, l, md) ;
    build_tree(2*cur+2, md+1, r) ;
    ar[cur] = min( ar[2*cur + 1] , ar[2*cur+2]) ;
}
 
int func(int l ,int r, int s, int e , int cur)
{
    int md=(s+e)/2;
    if( l<=s && r>=e ) return ar[cur] ;
    if(l>e || r<s) return intmax;
    else return min( func(l, r, s , md, 2*cur+1) , func(l, r,md+1,e, 2*cur+2) );
}
 
using namespace std;
signed main()
{
    ip(n) ; ip(q) ; loop(i,1,n+1) cin>>v[i];
    build_tree(0,1,n);
//    cout<<"store array for ST = " ;loop(i,0,2*n-1) cout<<ar[i]<<" "; cout<<"\n" ;
    while(q--)
    {
        ip(l) ; ip(r) ; l--; r--;
        cout<<func(l, r,0,n-1,0)<<"\n";
    }
    return 0 ;
}