#include <stdio.h>
int main() {
    int n, i;
    unsigned long long fact = 1;
l1:    printf("Enter an integer for which you want to find factorial: ");
    scanf("%d", &n);

    // shows error if the user enters a negative integer
    if(n<0){
        printf("Factorial of negative number does not exist\nEnter positive number.\n");
        goto l1;
    }
    else{
        for(i=1;i<n;++i){
            fact*=i;
        }
    }
    printf("Factorial of %d = %llu", n, fact);
    return 0;
}
