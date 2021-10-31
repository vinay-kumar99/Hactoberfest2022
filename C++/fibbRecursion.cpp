#include <iostream>
using namespace std;

int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number of which you wanted to find fibbonacci " << endl;
    cin >> n;
    cout << "the value is -" << endl;
    cout << rfib(n) << endl;
}