//C++ Program
// input: {[()]}  output : balanced // input: {[}] output: not balanced
// if the entered sequence of brackets is ordered then output is balanced otherwise not balanced

#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
     stack<char>st;
    for(char c : x)
    {
        if(c=='(' || c=='{' || c=='[')
        st.push(c);
        
        else
        {
            if(st.empty())
            return false;
           if((c==')' && st.top()=='(') ||  (c=='}' && st.top()=='{') || (c==']' && st.top()=='['))
           st.pop();
           else
           return false;
            
        }
    }
    if(st.empty())
    return true;
    
    return false;
    
}


int main()
{
   
   string a;
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   
}  

