/*
 * =====================================================================================
 *
 *       Filename:  dynamicArray.cpp
 *
 *    Description: Dynamic Array class 
 *
 *        Version:  1.0
 *        Created:  08/09/20 04:10:13 PM IST
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

class DynamicArray{
    private:
        int *data;
        int nextIndex;
        int size;

    public:
        DynamicArray(){
            data = new int[5];
            nextIndex = 0;
            size = 5;
        }

        void add(int element){
            if(nextIndex == size){
                int *newData = new int[2*size];
                for(int i =0; i<nextIndex; i++){
                    newData[i] = data[i];

                }
                delete [] data;
                data = newData;
                size *= size;
        }

        data[nextIndex] = element;
        nextIndex++;
        }

        int  get(int idx){
            if(idx > nextIndex){
                return -1;
            }
            else{
                return data[idx];
            }
        }

        void add(int idx , int element){
            //add element at given index
            if(idx < nextIndex){
                data[idx] = element;
            }
            else if(idx == nextIndex){
                add(element);
            }
            else {
                return;
            }

        }



        void print() {
            for(int i =0; i<nextIndex; i++){
                cout << data[i] << "  ";
            }

            cout << endl;
        }

        //copy constructer to avoid shallow copy 
        DynamicArray(DynamicArray const &d){
            this->data = new int[d.size];
            for(int i =0; i<nextIndex; i++){
                this->data[i] = d.data[i];

            }

            this->nextIndex = d.nextIndex;
            this->size = d.size;


        }

        //copy assignment operator 
        
        void operator=(DynamicArray const &d){
            this->data = new int[d.size];
            for(int i =0; i<nextIndex; i++){
                this->data[i] =d.data[i];
            }
            this->nextIndex = d.nextIndex;
            this->size = d.size;


        }

};


int main() {

    DynamicArray arr1;

    arr1.add(10);
    arr1.add(60);
    arr1.add(444);
    arr1.add(20);
    arr1.add(20);

    arr1.print();


    arr1.add(2,55);

    arr1.print();

    DynamicArray arr2(arr1);
    arr2.print();


    DynamicArray arr3 = arr1;

    arr3.print();


    return 0;




}
