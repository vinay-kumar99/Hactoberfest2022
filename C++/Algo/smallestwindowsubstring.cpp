#include <iostream>
#include <algorithm>
#include <cstring>
#include<bits/stdc++.h> 
using namespace std; 

const int no_of_char = 256;
//Function to find smallest windows substring 
string findsubstr(string str, string pat){
    int len1 = str.length();
    int len2 = pat.length();

    //egde cases if str is less that pat 
    //Ex - pat = "abc" , str = "ab"
    if (len1< len2){
        cout << "No such window exists";
        return "";

    }
    //Intiatiate two hash tables 
    int hash_pat[no_of_char] = {0};
    int hash_str[no_of_char] = {0};


    //store occurence of char in pat
    for (int i = 0; i < len2; i++){
        hash_pat[pat[i]]++;

    }

    int start = 0 , start_index = -1, min_len = INT_MAX;
 
    //start traversing the string and count the chars
    int count = 0;
    for(int j = 0; j < len1; j++){
        hash_str[str[j]]++;

        if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
        count++;

        //if all chars are matched 
        if (count == len2){
            while (hash_str[str[start]] > hash_pat[str[start]] ||
            hash_pat[str[start]]== 0){
                 
                 if (hash_str[str[start]] > hash_pat[str[start]]){
                     hash_str[str[start]]--;
                     start++;
                 }

                 //Updating the window size
                 int len_win = j - start +1;
                 if (min_len > len_win){
                     min_len = len_win;
                     start_index = start;

                 }
            }
        }
    }

    //No window Found
    if (start_index == -1){
        cout << "No window exsits";
        return "";
    }

    //return substring 
    return str.substr(start_index,min_len);


}

int main() {
    string str = "this is a test string";
    string pat = "tist";
    cout<< "Smallest windows is "<< findsubstr(str,pat);
    return 0;
}

