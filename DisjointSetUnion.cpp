#include<bits/stdc++.h>
using namespace std;

vector<int> par, size;
    
int find(int i) {
    if(i != par[i])
        par[i] = find(par[i]);
    return par[i];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        if(size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += size[u];  /*Rankwise: size table init by 0 & if(size[v] == size[u]) size[v]++;*/
    }
}

void init(int n) {
	par.clear();
	par.resize(n);
    size.resize(n, 1);
    for(int i = 0; i < n; i++) par[i] = i;
}

int main() {
	int n;
	cin >> n;
	init(n);
	/* use it now according to the question */
}
