#include <bits/stdc++.h>
using namespace std;
const int CHARS=26;

int makingAnagrams(string s1, string s2) 
{
  int count[CHARS]={},sum=0;
  for(int i=0;i<s1.length();i++){
      count[s1[i]-'a']++;
  }
  for(int i=0;i<s2.length();i++){
      count[s2[i]-'a']--;
  }
  for(int i=0;i<CHARS;i++){
     sum+=abs(count[i]);
  }
 return sum;
}

int main()
{
    string s1;
    cin>>s1;

    string s2;
    cin>>s2;

    cout<<makingAnagrams(s1,s2);

    return 0;
}
