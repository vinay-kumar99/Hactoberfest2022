#include "bits/stdc++.h"
using namespace std;
long first(vector<long long> a, long n, long long x)
{
    long st = 0;
    long end = n - 1;
    long res = -1;
    while (st <= end)
    {
        long mid = (st) + (end - st) / 2;
        if (a[mid] == x)
        {
            res = mid;
            end = mid - 1;
        }
        else if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return res;
}
long last(vector<long long> a, long n, long long x)
{
    long st = 0;
    long end = n - 1;
    long res = -1;
    while (st <= end)
    {
        long mid = (st) + (end - st) / 2;
        if (a[mid] == x)
        {
            res = mid;
            st = mid + 1;
        }
        else if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return res;
}

int main()
{

    vector<long long> v;
    //  {1, 3, 5, 5, 5, 5, 67, 123, 125}
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(67);
    v.push_back(123);
    v.push_back(125);
    long f = first(v, 9, 5);
    long l = last(v, 9, 5);
    cout << l << " " << f << endl;
}