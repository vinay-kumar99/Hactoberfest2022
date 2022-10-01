#include<bits/stdc++.h>

using namespace std;
  
void reverse(string s)
{

  //create an empty string stack

  stack<string> stc;
 

  //create an empty temporary string

  string temp="";
 

  //traversing the entire string

  for(int i=0;i<s.length();i++)

  {

    if(s[i]==' ')

    {

       

      //push the temporary variable into the stack

      stc.push(temp); 

       

      //assigning temporary variable as empty

      temp="";          

    }

    else

    {

      temp=temp+s[i];

    }
 

  }
 

  //for the last word of the string

  stc.push(temp);
 

  while(!stc.empty()) {
 

    // Get the words in reverse order 

    temp=stc.top();

    cout<<temp<<" ";

    stc.pop();

  }

  cout<<endl;
}
 

int main()
{

  string s="I Love To Code";

  reverse(s); 

  return 0;
}
