import java.util.*;
import java.lang.*;
import java.io.*;
class reverse
   {
	public static void main (String[] args)
   {
       Scanner in=new Scanner(System.in);
       int n=in.nextInt();
       int a[]=new int[n];
       for(int i=0;i<n;i++){
           a[i]=in.nextInt();
       }
       int temp;
       int sta=0;
       int end=n-1;
       while(sta<end){
           temp=a[sta];
           a[sta]=a[end];
           a[end]=temp;
           sta++;
           end--;
       }
   for(int i=0;i<n;i++){
       System.out.print(a[i]+" ");
   }

    }
 }
