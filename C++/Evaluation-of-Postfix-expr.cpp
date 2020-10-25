#include <bits/stdc++.h>
using namespace std;

int formexpression(int x,int y,char c){
    int answer;
    switch(c){
        case '+': answer=x+y;break;
        case '-': answer=x-y;break;
        case '*': answer=x*y;break;
        case '/': answer=x/y;break;
    }
    return answer;
}

int evaluate(stack<int>&stk,string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57){
            stk.push((int)s[i]-48);
        }
        else{
            int y=stk.top();stk.pop();
            if(stk.empty()){
                return y;
            }
            else{
                int x=stk.top();stk.pop();
                stk.push(formexpression(x,y,s[i]));
            }
        }
    }
    return stk.top();
}

int main() {
	//code
	int testcases;cin>>testcases;
	while(testcases--){
	    string postfix;
	    cin>>postfix;
	    stack<int>s;
	    cout<<evaluate(s,postfix)<<endl;
	}
	return 0;
}