//c takes from B ,and from A
#include <iostream>
using namespace std;

class a
{
    public:
    a()
    {
        cout<<"I AM A level 1"<<endl;
    }
};
class b
{
    public:
    b()
    {
        cout<<"I AM B level 2 "<<endl;
    }
};
class c:public a,public b
{ 
    public:
    c()
    {
        cout<<"I AM C level 3"<<endl;
    }
};

int main()
{
    c obj;
    
    return 0;
}