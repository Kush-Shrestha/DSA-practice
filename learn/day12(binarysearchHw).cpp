#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int searchValue){
int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        // Calculate middle index to divide the array
        int mid = left + (right - left) / 2;
        
        // Check if searchValue is present at mid
        if (arr[mid] == searchValue) {
            return mid;  // if element is found then return index
        }
        
        // If searchValue is greater, it will ignore left half
        if (arr[mid] < searchValue) {
            left = mid + 1;
        }
        // If searchValue is smaller, it will ignore right half
        else {
            right = mid - 1;
        }
    }
    
    //  If Value/Element not found in array
    return -1;
}

int main() {
    int size, searchValue;
    
    // Input: number of elements
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int arr[size];
    
    // Input: array elements (must be in sorted order)
    cout <<" integers in SORTED order:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Enter the value that you want to find
    cout << "Enter the element to search: ";
    cin >> searchValue;

    int result = binarySearch(arr, size, searchValue);
    
    // Output work
    if (result != -1) {
        cout << "Element is found at: " << result << " position (0-based index)" << endl;
        cout << "Element is found at: " << (result + 1) << "position  (1-based index)" << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
    
    return 0;
}