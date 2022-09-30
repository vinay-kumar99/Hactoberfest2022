#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string.h>
using namespace std;
int main()
{
    vector<string>v;
    string s, pattern;
    cin>>pattern;
    cin.ignore();
    cin>>s;
    int flag=0;
    string word="";
    for (auto val:s){
        if (val==' ')
        {
            v.push_back(word);
            word="";
        }
        else
        {
            word.push_back(val);
        }
        
    }
    v.push_back(word);
    if(pattern.size()!=v.size()){
        flag=1;
    }
    unordered_map<char,string>m;
    set<string>st;
    for (int i = 0; i < pattern.size(); i++)
    {
        if(m.find(pattern[i])!=m.end()){
            if(m[pattern[i]]!=v[i]){
                flag=1;
            }
        }
        else
        {
            if(st.count(v[i])>0){
                flag=1;
            }
                m[pattern[i]]=v[i];
                st.insert(v[i]);
            
        }
        
    }
    if (flag==1)
    {
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    
    
    
}
