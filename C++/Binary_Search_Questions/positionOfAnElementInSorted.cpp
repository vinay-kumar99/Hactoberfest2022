#include <iostream>
using namespace std;

int pos(int a[], int n, int key)
{
    int st = 0;
    int end = 1;
    while (key > a[end])
    {
        st = end;
        end = end * 2;
    }
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
    cout << pos(a, n, key) << endl;
}