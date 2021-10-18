#include <iostream>
using namespace std;

int peakElement(int a[], int n)
{
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int mid = (st) + (end - st) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (a[mid] >= a[mid - 1] && a[mid] >= a[mid + 1])
            {
                return mid;
            }
            else if (a[mid + 1] > a[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (mid == 0)
        {
            if (a[0] > a[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (mid == n - 1)
        {
            if (a[mid] > a[mid - 1])
            {
                return mid;
            }
            else
            {
                return mid - 1;
            }
        }
    }
    return -1;
}

int bs(int a[], int st, int end, int key)
{
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
            st = mid + 1;
    }
    return -1;
}

int bsd(int a[], int st, int end, int key)
{
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
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
    int key;
    cin >> key;
    int idx = peakElement(a, n);
    int i1 = bs(a, 0, idx - 1, key);
    int i2 = bsd(a, idx, n - 1, key);
    if (i1 < 0 && i2 < 0)
    {
        cout << "Element is not present" << endl;
    }
    else if (i1 > 0)
    {
        cout << i1;
    }
    else
    {
        cout << i2;
    }
}