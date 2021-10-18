#include <iostream>
using namespace std;

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
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == key)
        {
            cout << mid << endl;
            return 0;
        }
        else if (mid - 1 >= st && a[mid - 1] == key)
        {
            cout << mid - 1 << endl;
            return 0;
        }
        else if (mid + 1 <= end && a[mid + 1] == key)
        {
            cout << mid + 1 << endl;
            return 0;
        }
        else if (a[mid] > key)
            end = mid - 2;
        else
            st = mid + 2;
    }
}