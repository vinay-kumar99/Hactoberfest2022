#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

//function overloading
class result{
    public:
    void func(){
        cout<<"function with no argument"<<endl;
    }
    void func(int a){
        cout<<"function with argument as int"<<endl;
    }
    void func(double a){
        cout<<"function with argument as double"<<endl;
    }
};

//operator overloading
class complex1{
    private:
    int real;
    int img;
    public:
    complex1(){
        //empty
    }
    complex1(int r,int i){
        real=r;
        img=i;
    }

    complex1 operator + (complex1 &a){
        complex1 res;
        res.real= real+a.real;
        res.img= img+a.img;

        return res;
    }

    void print_info(){
        cout<<real<<" +i"<<img<<endl;
    }
};
 
//virtual function
class base{
    public:
    virtual void print(){
        cout<<"In base class print"<<endl;
    }
    void display(){
        cout<<"In base class display"<<endl;
    }
};
class derived : public base{
    public:
    void print(){
        cout<<"In derived class print"<<endl;
    }
    void display(){
        cout<<"In derived class display"<<endl;
    }
};

int main(){
    cout<<"Hello"<<endl;

    // result a;
    // a.func();
    // a.func(3);
    // a.func(2.3);

    // complex1 a(3,5),b(1,2); 
    // a.print_info();
    // b.print_info();
    // complex1 c = (a + b);
    // c.print_info();
    
    base *baseptr;
    derived d;
    baseptr=&d;
    d.print();
    
    d.display();
 return 0;
}
