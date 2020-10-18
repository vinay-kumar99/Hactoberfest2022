/*
 * =====================================================================================
 *
 *       Filename:  studentclass.cpp
 *
 *    Description: create a class of students 
 *
 *        Version:  1.0
 *        Created:  03/09/20 09:42:31 AM IST
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


class Student{
    private:

    string name;
    int age;

    public:
    
    Student(string name , int age){
        this-> name = name;
        this->age = age;


    }

    void display(){
        cout << "name is :" << name << endl;
        cout << "age is :" << age << endl;


    }

};


int  main() {
    string name = "Ranveer";
    Student s1(name , 10);

    s1.display();

    name = "raju";

    Student s2(name, 20);

    s2.display();

    s1.display();


return 0;

}
