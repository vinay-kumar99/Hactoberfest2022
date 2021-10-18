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

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << peakElement(a, n) << endl;
}