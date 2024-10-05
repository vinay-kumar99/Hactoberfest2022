#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void MatrixChainMultiplication(int p[], int n) {
    int m[n][n];
    int s[n][n];

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           m[i][j]=0;
        }
     }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           s[i][j]=0;
        }
    }
   

int j,q,min;
     for(int d=1;d<n-1;d++){  // The number of matrices to be multiplied
        for(int i=1;i<n-d;i++){ // Starting matrix
            j=i+d; // Ending Matrix
            min=INT_MAX; // Setting minimum as a random large value to compare
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; // Formula for MCM
                if(q<min){ // Comparing the number of multiplications with the current minimum
                    min=q;
                    s[i][j]=k; // Assigning values in the K matrix to specify the way in which matrices are multiplied
                }
            }
            m[i][j]=min; // Assigning the m matrix the minimum number of mulitplications possible value
        }
     }
    // Display the M matrix
    printf("M matrix:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Display the S matrix
    printf("S matrix (split positions):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

printf("\nMinimum number of multiplications is: %d\n\n ",m[1][n-1]);
}

int main() {
    int n;
    printf("Enter the number of matrices you want to multiply: ");
    scanf("%d", &n);

    int d[n + 1];
    printf("Enter dimensions for each matrix(d1,d2,...,dn):\n");
    for (int i = 0; i < n + 1; i++) {
        printf("Enter dimension #%d: ", i + 1);
        scanf("%d", &d[i]);
    }

    MatrixChainMultiplication(d, n + 1);

    return 0;
}