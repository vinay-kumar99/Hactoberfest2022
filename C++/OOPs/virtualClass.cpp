#include <iostream>
using namespace std;
class B
{
public:
    int b;
};

class D1 : virtual public B
{
public:
    int d1;
};

class D2 : virtual public B
{
public:
    int d2;
};

class D3 : public D1, public D2
{
public:
    int d3;
};

int main()
{
    D3 obj;

    obj.b = 40;
    obj.b = 30;

    obj.d1 = 60;
    obj.d2 = 70;
    obj.d3 = 80;

    cout << "\n B : " << obj.b;
    cout << "\n D1 : " << obj.d1;
    cout << "\n D2 : " << obj.d2;
    cout << "\n D3 : " << obj.d3;
}