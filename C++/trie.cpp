#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
long long arr[100];
void solve()
{
    long long n, temp, remain, k, x, ans = 0;
    cin >> n >> x;
    ll exp = log2(n);
    bool flag = false;
    if (exp & 1 && pow(2, exp) == n)
    {
        flag = true;
    }
    if (x == 0 && n % 2 == 1)
        cout << -1 << "\n";
    else if (n <= x || flag)
        cout << 1 << "\n";
    else
    {

        
        long long counteven = 0, countodd = 0;
        int count = 0;
        long long ntemp = n;
        string s;
        while (n > 0)
        {
            if (n % 2 == 1)
                s += '1';
            else
                s += '0';
            n = n / 2;
        }

        n = s.length();
        long long sum = 0;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && i % 2 == 1)
            {
                arr[count] = pow(2, i);
                count++;
            }
            else if (s[i] == '1' && i == 0)
            {
                arr[count] = 1;
                count++;
            }
            else if (s[i] == '1' && i % 2 == 0)
            {
                arr[count] = pow(2, i - 1);
                count++;
                arr[count] = pow(2, i - 1);
                count++;
            }
        }
        int k = 0;
        for (int i = 0; i < count; i++)
        {
            sum += arr[i];
            k++;
            if (sum <= x)
                continue;
            else
            {
                k--;
                break;
            }
        }
        if (k == 0)
            cout << count - k << "\n";
        else
            cout << count - k + 1 << "\n";

        // while (x--)
        // {
        //     temp = n - x;
        //     while (temp > 0)
        //     {
        //         if (count % 2 == 1)
        //             counteven++;
        //         else
        //             countodd++;
        //         count++;
        //         temp = temp / 2;
        //     }
        //     count = 2 * counteven + countodd;
        //     ans = min(ans, count);
        //     counteven = 0;
        //     countodd = 0;
        // }
        // cout << ans << "\n";
        // k = int(log2(n));
        // if (k % 2 == 0 && k != 0)
        //     k--;
        // if (exp & 1 && pow(2, exp) == n - x)
        // {
        //     flag = true;
        // }
        // if (flag)
        // {
        //     n = 0;
        //     ans += 2;
        // }
        // temp = pow(2, k);
        // ans += n / temp;
        // remain = n % temp;
        // n = remain;
        // k = int(log2(remain));
        // if (k % 2 == 0 && k != 0)
        //     k--;
        // temp = pow(2, k);
        // while (remain < x)
        // {
        //     remain = remain - temp;
        //     ans++;
        // }
        // ans++;
        // if (remain == 0)
        //     cout << ans << "\n";
        // else
        //     cout << -1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}