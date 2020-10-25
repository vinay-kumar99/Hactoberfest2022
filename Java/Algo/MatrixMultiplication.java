
import java.util.Scanner;

public class MatrixMultiplication {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter dimension of matrix");
		int n=sc.nextInt();
		
		int a[][]=new int[n][n];//  Matrix 1
		int b[][]=new int[n][n];// Matrix 2
		int c[][]=new int[n][n];// Matrix 3 : Multiplication of Matrix 1 and Matrix 2.
		System.out.println("enter num in matrix a"); 
		for(int i=0;i<=n-1;i++) {
			for(int j=0;j<=n-1;j++) {
				
				a[i][j]=sc.nextInt();
				
			}
			
		}System.out.println("enter num in matrix b");
		for(int i=0;i<=n-1;i++) {
			for(int j=0;j<=n-1;j++) {
				 
				b[i][j]=sc.nextInt();
				}}
		
		for(int i=0;i<=n-1;i++) {
			for(int j=0;j<=n-1;j++) {
				for(int k=0;k<=n-1;k++) {
					c[i][j]+=a[i][k]*b[k][j];
				}}}
		System.out.println("matrix c ="); 
		for(int i=0;i<=n-1;i++) {
			for(int j=0;j<=n-1;j++) {
				System.out.print(c[i][j] + " "); 
				
				}
			System.out.println(); }
		
		
		
	}

}
