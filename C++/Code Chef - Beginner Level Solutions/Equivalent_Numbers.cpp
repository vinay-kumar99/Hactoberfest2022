// Equivalent Numbers problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool is_rational(long double x) {
    x = abs(x);
    for (int i = 0; i < 20; ++i) {
        const auto a = floor(x);
        if (x - a < 1e-8)
            return true;
        x = 1 / (x - a);
    }
    return false;
}

int main() {
    
	int t;
	cin>>t;
	while(t--)
	{
	    ll a, b; cin >> a >> b;
        long double temp = log(a) / log(b);
        cout << (is_rational(temp) ? "YES\n": "NO\n");
	    
	}
	return 0;
}
