#include<iostream>
using namespace std;

class Complex{
private:
	int real;
	int img;

public:

	Complex(int x ,int y){
		real = x;
		img = y;
	}



	void plus(const Complex &s2){
		real = this->real + s2.real;
		img = this->img + s2.img;
	}

	void print(){
		cout << real  << "+" << img << "i" << endl;
	}

	void multiply(const Complex &s2){
		real = this->real * s2.real;
		img = this->img * s2.img;


	}


};



int main() {
	int real1,img1,real2,img2;

	cin >> real1 >> img1;;
	cin >> real2  >> img2;


	Complex c1(real1,img1);
	Complex c2(real2,img2);


	int choice;
	cin >> choice;

	if(choice == 1){
		c1.plus(c2);
		c1.print();
	}

	else if(choice == 2){
		c1.multiply(c2);
		c1.print();
	}
	else {
		return 0;
	}


	return 0;
}
