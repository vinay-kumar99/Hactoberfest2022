//c takes from B , B takes from A
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
class b:public a
{
    public:
    b()
    {
        cout<<"I AM B level 2 "<<endl;
    }
};
class c:public b
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