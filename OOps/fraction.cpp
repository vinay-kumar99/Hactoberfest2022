/*
 * =====================================================================================
 *
 *       Filename:  fraction.cpp
 *
 *    Description: 
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


        void add(const Fraction &f2){

            int  lcm = denominator * f2.denominator;
            int  x = lcm/denominator;
            int  y = f2.denominator;
            int  num = x * numerator + (y * f2.numerator);

            this->numerator = num;
            this->denominator = lcm;

            simplify();

        }

        void multiply(Fraction const  &F2){
            this->numerator = this->numerator * F2.numerator;
            
            this-> denominator = this->denominator * F2.numerator;

            simplify();

        }

};



int main() {
    Fraction f1(10,2);
    Fraction f2(15, 4);


    f1.print();

    f1.add(f2);
    f1.print();
    f1.multiply(f2);
    f1.print();
    return 0;
}
