import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {

	public static int arrayEquilibriumIndex(int[] arr){  
		 
        int totalSum=0;
        
        for(int i=0; i<arr.length; i++){
            totalSum+=arr[i];
        }
        
        int leftSum=0,rightSum;
        
        int i=0;
        while(i<arr.length){
            
            rightSum=totalSum-leftSum-arr[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum=leftSum+arr[i];
            
            i++;
        }
        
        return -1;
        
	}
}



public class Equilibrium {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[] takeInput() throws IOException {
        int size = Integer.parseInt(br.readLine().trim());
        int[] input = new int[size];

        if (size == 0) {
            return input;
        }
        
        String[] strNums; 
        strNums = br.readLine().split("\\s");
        

        for (int i = 0; i < size; ++i) {
            input[i] = Integer.parseInt(strNums[i]);
        }

        return input;
    }

    public static void printArray(int[] arr) {
        for (int element : arr) {
            System.out.print(element + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int t = Integer.parseInt(br.readLine().trim());

        while(t > 0) {

            int[] arr = takeInput();
            System.out.println(Solution.arrayEquilibriumIndex(arr));

            t -= 1;
        }
    }
}
