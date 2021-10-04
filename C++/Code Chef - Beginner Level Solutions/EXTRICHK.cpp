#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin>>a>>b>>c;
	if(a+b > c && b+c >a && a+c >b){
	    if(a==b && b==c){
	    cout<<"1";
	    }else if(a==b || b==c || a==c){
	    cout<<"2";
	    }else{
	    cout<<"3";
	    }
    }else{
        cout<<"-1";
    }
	return 0;
}