import java.io.*;
import java.util.*;
class LinearSearch{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		//Taking input for size of an array

		System.out.println("Enter the size of an array");
		int n = sc.nextInt();

		// Taking input elements in array

		int []arr = new int[n];		
		System.out.println("Enter "+n+" element");

		for(int i=0; i<n; i++){
			arr[i] = sc.nextInt();
		}
	
		// Taking input for key to search

		System.out.println("Enter the key to search");
		int key = sc.nextInt();
		
		// Calling th e function Linear Search
		linearSearch(arr,key);
	}

	public static void linearSearch(int [] arr, int key){
		boolean isfound = false;
		for(int i=0; i<arr.length; i++){
			if(arr[i] == key){
				isfound = true;
				System.out.println("The " +key+" is present at index " + i );
				break;
			}
		}
		if(!isfound){
			System.out.println("The " +key+ " is not presnet.");
		}
	}
}
