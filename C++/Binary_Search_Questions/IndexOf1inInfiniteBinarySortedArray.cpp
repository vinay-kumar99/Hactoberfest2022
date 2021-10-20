#include <iostream>
using namespace std;

int index(int a[], int n, int key)
{
    int st = 0;
    int end = 1;
    while (key > a[end])
    {
        st = end;
        end = end * 2;
    }
    int res = -1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == key)
        {
            res = mid;
            end = mid - 1;
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
    cout << index(a, n, 1) << endl;
}