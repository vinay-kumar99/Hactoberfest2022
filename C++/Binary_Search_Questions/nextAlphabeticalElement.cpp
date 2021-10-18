#include <iostream>
using namespace std;

char nextElement(char a[], int n, char key)
{
    int st = 0;
    int end = n - 1;
    char res = '#';
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (a[mid] == key)
        {
            st = mid + 1;
        }
        else if (a[mid] > key)
        {
            res = a[mid];
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
    char a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    char c;
    cin >> c;
    cout << nextElement(a, n, c) << endl;
}