import java.util.*;
class QuickSort{
	public static void main(String[]args){
		
		Scanner sc = new Scanner(System.in);

		//Taking input for size of an array
		System.out.println("Enter the size of an array");
		int n = sc.nextInt();

		// Taking input elements in array

		int []arr = new int[n];		
		System.out.println("Enter "+n+" element");
		for(int i=0; i<n; i++)
			arr[i] = sc.nextInt();

		quickSorting(arr, 0, n-1);
		
		// Printing the elements of the array
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i] + ", ");	
	}
	public static void quickSorting( int []arr, int lb, int ub){
		int p=0;
		if (lb<ub){
			p = partition(arr, lb, ub);
			quickSorting(arr, lb, p+1);
			quickSorting(arr, p-1, ub); 
		}
	} 
	
	public static int partition(int [] arr,int lb,int ub){
		int start =lb;
		int end =ub;
		int pivot = arr[lb];
		if(lb<ub){
			while(arr[start]<pivot){
				start++;
			}
			while(arr[end]>pivot){
				end--;
			}
			if(lb<ub)
				swap(arr[start], arr[end]);
		}
		swap(arr[lb], arr[end]);
	return end;
	}

	public static void swap(int a, int b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;	
	}
}
