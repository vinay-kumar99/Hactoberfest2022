//All Anagram in a string
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 256

using namespace std;

bool compare(char arr1[],char arr2[]){

    for (int i = 0; i < MAX; i++){
        if (arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

void search(char *pattern, char *txt){
    int M = strlen(pattern), N = strlen(txt);
    char countP[MAX] = {0}, countW[MAX] = {0};

    for (int i = M; i < N; i++){
        if (compare(countP, countW)){
            cout << "Found at Index " << (i - M)<< endl;

        }
        (countW[txt[i]])++;
        (countW[txt[i-M]])--;

    }
    if (compare(countP,countW)){
        cout << "Found at Index " << (N-M)<< endl;
    }
}

int main(){
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat,txt);
    return 0;
}