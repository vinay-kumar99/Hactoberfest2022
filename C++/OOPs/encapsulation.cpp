#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
class members
{
private:
    int a;
    void funcA(){
        cout<<"In function a"<<endl;
    }
public:
    int b;
    void funcB(){
        cout<<"In function b"<<endl;
    }
protected:
    int c;
    void funcC(){
        cout<<"In function c"<<endl;
    }
};
// only public acces modidiers can be called from outside the class
int main(){
    // access modifiers - private , public , protected

 return 0;
}
