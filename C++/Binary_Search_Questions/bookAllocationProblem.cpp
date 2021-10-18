#include "bits/stdc++.h"
using namespace std;

bool isvalid(int a[], int n, int k, int mx)
{
    int sum = 0;
    int st = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (sum > mx)
        {
            st += 1;
            sum = a[i];
        }
        if (st > k)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int st = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        st = max(st, a[i]);
        end = end + a[i];
    }
    int res = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isvalid(a, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << res << endl;
}