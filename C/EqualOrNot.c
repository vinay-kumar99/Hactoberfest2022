#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    int *ptr1;
    int *ptr2;
    int equal;
    printf("Enter number of element in 1st array :");
    scanf("%d", &m);
    printf("Enter number of element in 2nd array :");
    scanf("%d", &n);
    ptr1 = (int *)calloc(m, sizeof(int));
    ptr2 = (int *)calloc(n, sizeof(int));
    printf("enter elements of 1st array :\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ptr1[i]);
    }
     printf("enter elements of 2nd array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr2[i]);
    }

    if (m != n)
    {
        printf("Array's are not equal\n");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (ptr1[i] == ptr2[i])
            {
                equal=0;
            }
            else
            {
                equal=1;
                break;
            }
        }
        if (equal)
        {
            printf("Array's are not equal\n");
        }
        else
        {
            printf("Array's are equal\n");
        }
    }

    return 0;
}
