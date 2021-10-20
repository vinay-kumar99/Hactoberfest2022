#include <iostream>
using namespace std;

int floor(int a[], int n, int key)
{
    int st = 0;
    int end = n - 1;
    int res = -1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            res = mid;
            st = mid + 1;
        }
    }
    return res;
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
    cout << floor(a, n, key) << endl;
}