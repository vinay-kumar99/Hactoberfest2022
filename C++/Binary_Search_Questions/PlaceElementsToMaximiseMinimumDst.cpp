#include "bits/stdc++.h"
using namespace std;

bool isFeasible(int mid, int a[], int n, int k)
{
    int pos = a[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - pos >= mid)
        {
            pos = a[i];
            elements += 1;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int maximiseMinimumDst(int a[], int n, int k)
{
    sort(a, a + n);
    int st = 1;
    int end = a[n - 1];
    int res = -1;
    while (st < end)
    {
        int mid = (st) + (end - st) / 2;
        if (isFeasible(mid, a, n, k))
        {
            res = max(res, mid);
            st = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;
    cout << maximiseMinimumDst(a, n, k) << endl;
}