#include <stdio.h>

int sum (int,int);

int main ()
{
	int a[3][3],b[3][3],c[3][3],i,j,n;
	printf ("Enter the order of matrices : ");
	scanf ("%d",&n);

    //Getting inputs for the first matrix
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("Enter (%d,%d) element of first matrix: ",i+1,j+1);
			scanf ("%d",&a[i][j]);
		}
	}

    //Getting inputs for the second matrix
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("Enter (%d,%d) element of second matrix: ",i+1,j+1);
			scanf ("%d",&b[i][j]);
		}
	}

    //Calculating the sum of the two matrices
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			c[i][j]=sum (a[i][j],b[i][j]);
		}
	}

    //Printing the resultant matrix
	printf ("The sum of two matrices is :\n");
	for (i=0;i<n;i++){
		printf ("  ");
		for (j=0;j<n;j++){
			printf ("%d\t",c[i][j]);
		}
		printf ("\n\n");
	}
	return 0;
}

int sum (int a,int b)
{
    //function to sum two integers
	int c,i,j;
	c=a+b;
	return c;
}
