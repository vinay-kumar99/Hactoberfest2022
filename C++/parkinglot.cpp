#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
int MAX_CAPACITY = 10;
int twowheller_num;
int bus_num;
int fourwheller_num;
class vechile
{
private:
    int licenseplate;
    int spot;
    int type;
    int id;
    int spot_id;

public:
    vechile()
    {
        cout << "Inside vechile\n";
    }
    vechile(int _licenseplate, int _type, int _id)
    {
        licenseplate = _licenseplate;
        type = _type;
        id = _id;
    }
    int getid()
    {
        return id;
    }
    int gettype()
    {
        return type;
    }
    void setparkingspot(int spot)
    {
        spot_id = spot;
    }
};

int get_type_storage(int type)
{
    if (type == 0)
        return 1;
    if (type == 1)
        return 4;
    if (type == 2)
        return 8;
    return 0;
}
class parking
{
private:
    unordered_map<int, int> spots;
    int cap = 0;
    int countvec = 0;

public:
    parking()
    {
        cout << "Inside parking\n";
    }
    void allotment(vechile vec)
    {
        if (cap < MAX_CAPACITY)
        {
            spots[vec.getid()] = countvec;
            cap += get_type_storage(vec.gettype());
            vec.setparkingspot(countvec);
        }
        else
        {
            cout << "The parking lot is full\n";
        }
    }
    void getdata_(vechile C)
    {
        cout << " The Spot ID of vechile " << C.getid() << " is" << spots[C.getid()];
    }
};

void solve()
{
}

int main()
{

    vechile A(110, 0, 1);
    parking p;
    p.allotment(A);
    p.getdata_(A);
}