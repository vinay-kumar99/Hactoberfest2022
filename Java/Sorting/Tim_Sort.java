import java.util.Arrays;

public class TimSort {
    static final int RUN = 32;

    // This function sorts array from left index to to right index which is of size atmost RUN
    private static void insertionSort(int[] arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = arr[i];
            int j = i - 1;

            while (j >= left && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    // This function merges sorted runs
    private static void merge(int[] arr, int left, int mid, int right) {
        int len1 = mid - left + 1;
        int len2 = right - mid;

        int[] leftArray = new int[len1];
        int[] rightArray = new int[len2];

        System.arraycopy(arr, left, leftArray, 0, len1);
        System.arraycopy(arr, mid + 1, rightArray, 0, len2);

        int i = 0, j = 0;
        int k = left;

        while (i < len1 && j < len2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k++] = leftArray[i++];
            } else {
                arr[k++] = rightArray[j++];
            }
        }

        while (i < len1) {
            arr[k++] = leftArray[i++];
        }

        while (j < len2) {
            arr[k++] = rightArray[j++];
        }
    }

    // This function sorts array of size n using TimSort
    public static void timSort(int[] arr) {
        int n = arr.length;

        // Sort individual subarrays of size RUN
        for (int start = 0; start < n; start += RUN) {
            int end = Math.min(start + RUN - 1, n - 1);
            insertionSort(arr, start, end);
        }

        // Start merging from size RUN (or 32). It will merge to form size 64, then 128, and so on.
        for (int size = RUN; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min((left + 2 * size - 1), (n - 1));

                // Merge only if there is a run to merge
                if (mid < right) {
                    merge(arr, left, mid, right);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 21, 7, 23, 19};
        timSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
