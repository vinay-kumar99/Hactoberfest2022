#include <iostream>
using namespace std;

int minDiff(int a[], int n, int key)
{
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == key)
        {
            return key;
        }
        else if (a[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    int x = abs(key - a[st]);
    int y = abs(key - a[end]);
    if (y < x)
    {
        return a[end];
    }
    return a[st];
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
    cout << minDiff(a, n, key) << endl;
}