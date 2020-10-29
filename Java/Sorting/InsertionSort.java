import java.util.*;
class InsertionSort{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		//Taking input for size of an array

		System.out.println("Enter the size of an array");
		int n = sc.nextInt();

		// Taking input elements in array

		int []arr = new int[n];		
		System.out.println("Enter "+n+" element");
		for(int i=0; i<n; i++)
			arr[i] = sc.nextInt();

		InsertionSorting(arr);
		
		// Printing the elements of the array
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i] + ", ");	
	}
	public static void InsertionSorting(int [] arr){
		
		int temp = 0;
		int n = arr.length;
		
		for(int i =1; i<n ; i++){
			temp = arr[i];
			int j = i-1;
			while(j>=0 && arr[j] > temp)
			{
				arr[j+1] = arr[j];
				j--;
			}
		arr[j+1] =  temp;		
		}	
	}
}
