#include <bits/stdc++.h>
using namespace std; 

int main() {

    int t; 
    cin >> t; 
    while(t--) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        int c = 0;
    
        for (int i = 0; i < n; i++) {

            c += (b[i] == 'H') ? 1 : (b[i] == 'T') ? -1 : 0;
            if (c > 1 || c < 0) break;
        }

        cout << ((c == 0) ? "Valid\n" : "Invalid\n");
    }

    return 0; 
}
