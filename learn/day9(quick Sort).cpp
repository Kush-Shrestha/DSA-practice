#include <iostream>
using namespace std;

// MERGE SORT IMPLEMENTATION

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// QUICK SORT IMPLEMENTATION

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Display FUNCTIONS

void displayArray(int arr[], int n, const char* message) {
    cout << message;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// MAIN FUNCTION

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* originalArr = new int[n];
    int* mergeSortArr = new int[n];
    int* quickSortArr = new int[n];
    
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> originalArr[i];
    }
    
    displayArray(originalArr, n, "Original Array: ");
    
    // MERGE SORT
    copyArray(originalArr, mergeSortArr, n);
    
    cout << "MERGE SORT:\n";
    mergeSort(mergeSortArr, 0, n - 1);
    displayArray(mergeSortArr, n, "Sorted Array: ");
    cout << endl;
    
    // QUICK SORT
    copyArray(originalArr, quickSortArr, n);
    
    cout << "QUICK SORT:\n";
    quickSort(quickSortArr, 0, n - 1);
    displayArray(quickSortArr, n, "Sorted Array: ");
    cout << endl;
    
    cout << "Verification: Both algorithms produce ";
    bool identical = true;
    for (int i = 0; i < n; i++) {
        if (mergeSortArr[i] != quickSortArr[i]) {
            identical = false;
            break;
        }
    }
    cout << (identical ? "identical" : "different") << " results.\n";
    
    delete[] originalArr;
    delete[] mergeSortArr;
    delete[] quickSortArr;
    
    return 0;
}