#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Customizable partition function
int partition(vector<int>& arr, int low, int high, function<bool(int, int)> compare) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// Customizable Quick Sort function
void quickSort(vector<int>& arr, int low, int high, function<bool(int, int)> compare) {
    if (low < high) {
        int p = partition(arr, low, high, compare);
        quickSort(arr, low, p - 1, compare);
        quickSort(arr, p + 1, high, compare);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Define a custom comparison function
    auto compareAscending = [](int a, int b) { return a < b; };
    auto compareDescending = [](int a, int b) { return a > b; };

    // Sort in ascending order
    quickSort(arr, 0, arr.size() - 1, compareAscending);
    cout << "Sorted in ascending order: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Sort in descending order
    quickSort(arr, 0, arr.size() - 1, compareDescending);
    cout << "Sorted in descending order: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
