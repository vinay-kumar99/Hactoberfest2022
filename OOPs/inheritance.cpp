#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
class A{
        public:
        void fun(){
            cout<<"IN class A"<<endl;
        }
    };
    class B: public A{ //public & procted part of A goes in piblic part of B
        public:
        void fun(){
            cout<<"IN class B"<<endl;
        }
    };
    // class B: public A            //single inheritance
    // class B: public A,public C   //multiple inheritance
int main(){
    //single inheritance , multiple, multi level , hybrid, hierarchical
    int n;
    cout<<"Hello"<<endl;

    
 return 0;
}
