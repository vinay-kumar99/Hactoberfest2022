#include <iostream>
using namespace std;

int roatedMin(int a[], int n)
{
    int st = 0;
    int end = n - 1;
    while (st < end)
    {
        int mid = (st + end) / 2;
        if (a[mid] < a[end])
        {
            end = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    return st;
}

int binary(int a[], int low, int high, int x)
{
    int st = low;
    int end = high;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
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
    int key;
    cin >> key;
    int idx = roatedMin(a, n);
    int i1 = binary(a, 0, idx - 1, key);
    int i2 = binary(a, idx, n - 1, key);
    if (i1 < 0 && i2 < 0)
    {
        cout << "Element is Not Present" << endl;
    }
    if (i1 >= 0)
    {
        cout << i1;
    }
    else if (i2 >= 0)
    {
        cout << i2;
    }
}