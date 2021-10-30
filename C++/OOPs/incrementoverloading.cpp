/*
 * =====================================================================================
 *
 *       Filename:  incrementoverloading.cpp
 *
 *    Description: operator overloading 
 *
 *        Version:  1.0
 *        Created:  08/09/20 03:21:13 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<iostream>
using namespace std;


class Fraction{
    private:
        int numerator , denominator;

    public:

        //a constructor
        Fraction(int x , int y){
            numerator = x;
            denominator = y;

        }

        void print(){
            cout << this->numerator << "  / " << this->denominator << endl;

        }

        //pre increament operator overloading
        Fraction& operator++(){
            numerator = numerator + denominator;

            return *this;
        }

        //post increment operator overloading
        Fraction operator++(int) {
            Fraction fNew(numerator,denominator);
            numerator = numerator + denominator;
            return fNew;
        }
};

int main() {
    Fraction f1(10,2);
    f1.print();
    ++f1;
    f1.print();

    Fraction f2 =     ++(++f1);

    f1.print();
    f2.print();

    Fraction f3(15,4);
    Fraction f4 = f3++;
    f3.print();
    f4.print();
    return 0;

}
