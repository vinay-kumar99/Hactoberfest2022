public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the numbers in sorted form space separated");
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        System.out.println("Enter number to be searched");
        int x = Integer.parseInt(br.readLine());
        int res = binarySearch(input,x);
        if(res==-1)
        {
            System.out.println("Number not found");
        }
        else
        {
            System.out.println("Number found at "+ (res+1)+" position");
        }
        
    }
    static int binarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
            if (arr[m] == x) 
                return m; 
            if (arr[m] < x) 
                l = m + 1; 
            else
                r = m - 1; 
        } 
        return -1; 
    } 
}