/*
 * =====================================================================================
 *
 *       Filename:  fraction.cpp
 *
 *    Description: operator overloading
 *
 *
 *
 *        Version:  1.0
 *        Created:  03/09/20 03:25:01 PM IST
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
        int numerator;
        int denominator;

    public:

        Fraction(int x , int y){
           this-> numerator = x;
            this->denominator = y;

        }

        void print() {
            cout << this->numerator << " /  " << this->denominator << endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min(this->numerator , this->denominator);
            for(int i = 1; i<= j; i++ ){
                if(this->numerator % i == 0 && this->denominator % i == 0){
                    gcd = i;
                }
            }
            this->numerator = this->numerator / gcd;
            this->denominator = this->denominator / gcd;

        }

        //to use opeartor overloading we use operator+ for + 
        //or operator== for equal and so on 

        Fraction operator+(const Fraction &f2){

            int  lcm = denominator * f2.denominator;
            int  x = lcm/denominator;
            int  y = lcm/ f2.denominator;
            int  num = x * numerator + (y * f2.numerator);

            Fraction fNew(num,lcm);
            fNew.simplify();
            return fNew;


        }

        Fraction  operator*(Fraction const  &f2){
            int n = numerator * f2.numerator;
            int d = denominator * f2.denominator;

            Fraction fNew(n,d);
            fNew.simplify();
            return fNew;
            


        }

        bool operator==(const Fraction &f2){
            return (numerator == f2.numerator && denominator == f2.denominator);

        }


};



int main() {
    Fraction f1(10,2);
    Fraction f2(15, 4);

    

    f1.print();
    f2.print();

    Fraction f3 = f1 + f2;

    f3.print();

    Fraction f4 = f1 * f2;
    f4.print();

    if(f1 == f2){
       cout << "equal" << endl;

    }
    else {
        cout << "NOT Equal" << endl;
    }
    return 0;
}
