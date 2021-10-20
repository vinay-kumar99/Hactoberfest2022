#include <iostream>
using namespace std;

int roated(int a[], int n)
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

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << roated(a, n) << endl;
}