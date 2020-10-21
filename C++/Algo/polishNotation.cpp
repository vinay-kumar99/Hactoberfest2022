// this program will help u to find the reverse polish notation of a given expression
#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int n{};
    cin>>n;
    while(n>0){
    
        string exp{}, stack1{}, stack2{};

        cin>>exp;


        for(int i{}; i<exp.length(); i++){
            if(isalnum(exp[i])){
                stack1.push_back(exp[i]);
            }
            else if(!isalnum(exp[i]) and exp[i]!='(' and exp[i]!=')'){
                stack2.push_back(exp[i]);
            }
            else if (exp[i] == ')'){
                stack1.push_back(stack2.back());
                stack2.pop_back();
            }
        }

        cout<<stack1<<endl;
        n--;
    }


    
    return 0;
    
}
