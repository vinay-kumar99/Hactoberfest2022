#include <iostream>
using namespace std;
class demo
{
public:
    demo()
    {
        cout << "I AM DEMO" << endl;
    }
    string denomane = "iamdemo";
};

class demoson : public demo
{
public:
    demoson()
    {
        cout << "I AM DEMO SON" << endl;
    }
};

int main()
{
    demoson d1;
    cout << "THIS ACCESED BY DEMOSON OBJ " << d1.denomane;

    return 0;
}