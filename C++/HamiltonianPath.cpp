#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
        ll u, v;
	cin >> n >> m;
	vector<vector<bool>> adj(n, vector<bool> (n, false));
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
	}
	bool ans = false;
	vector<vector<bool>> dp(n, vector<bool> (1<<n, false));
	for(int i = 0; i < n; i++) dp[i][1<<i] = true;
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				for(int k = 0; k < n; k++) {
					if((i&(1<<k)) && adj[k][j] && k != j && dp[k][i^(1<<j)]) {
						dp[j][i] = true;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dp[i][(1<<n)-1]) {
			ans = true;
			break;
		}
	}
	cout << (ans ? "YES" : "NO");
}
