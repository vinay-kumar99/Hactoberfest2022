#include<stdio.h>
#include<string.h>

int main() {

    char str1[100];
    char str2[200];
    int len1, len2, c = 0;
    int j, i;

    printf("Enter first string:");
    scanf("%[^\n]%*c", str1); 

    printf("Enter second string:");
    scanf("%[^\n]%*c", str2); 


    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 == len2) {
        for (i = 0; i < len1; i++) {
            j = 0;
            while (str2[j] != '\0') {
                if (str1[i] == str2[j]) {
                    c++;
                    break;
                }
                j++;
            }
        }
    }

    if (len1 == c) {
        printf("Strings are Anagram");
    } else {
        printf("Strings are not Anagram");
    }

    return 0;
}
