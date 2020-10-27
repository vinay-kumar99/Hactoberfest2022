#include<stdio.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");

    int c, d, a[10][10], b[10][10], n, temp;
    printf("\nEnter the dimension of the matrix: \n\n");
    scanf("%d", &n);

    printf("\nEnter the %d elements of the matrix: \n\n",n*n);
    for(c = 0; c < n; c++)
        for(d = 0; d < n; d++)
            scanf("%d", &a[c][d]);

    for(c = 0; c < n; c++)
        for(d = 0; d < n; d++)
            b[d][c] = a[c][d];

    printf("\n\nThe original matrix is: \n\n");
    for(c = 0; c < n; c++) 
    {
        for(d = 0; d < n; d++)
        {
            printf("%d\t", a[c][d]);
        }
    printf("\n");
    }

    printf("\n\nThe Transpose matrix is: \n\n");
    for(c = 0; c < n; c++)
    {
        for(d = 0; d < n; d++)
        {
            printf("%d\t", b[c][d]);
        }
        printf("\n");
    }

    for(c = 0; c < n; c++)
    {
        for(d = 0; d < n; d++)
        {
      
            if(a[c][d] != b[c][d]) 
            {
                printf("\n\nMatrix is not Symmetric\n\n");
                exit(0);
            }
        }
    }
    printf("\n\nMatrix is Symmetric\n\n");
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}