#include <iostream>
using namespace std;
// mid break into two sorted array
// [1 5 7 8 mid 2 3 6 10 ]
// Merge function to combine two sorted subarrays
//                         0         3        7
void merge(int arr[], int left, int mid, int right) {
    // 3-0+1 =4 size1 = 4  
    int size1 = mid - left + 1;
    // 7-3 = 4
    int size2 = right - mid;

    int leftArray[size1];
    int rightArray[size2];

    int i = 0;
    int j = 0;

    for (; i < size1; i++) {
        leftArray[i] = arr[left+i];
    }
    for (; j < size2; j++) {
        rightArray[j] = arr[mid+1+j];
    }
   // reset to run from starting of left and right array
    i=0;
    j=0;
    // k will point to left for now its zero but it has to take care if we sort from middle of array
    int k = left;


    while (i < size1 && j < size2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < size1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < size2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}


// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {1,5,7,19,2,4,6,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: " << endl;
    printArray(arr, n);

    
    merge(arr, 0,3, n - 1);

    cout << "\nSorted array: " << endl;
    printArray(arr, n);

    return 0;
}