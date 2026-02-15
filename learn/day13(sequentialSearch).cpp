#include <iostream>
using namespace std;

// Function to perform sequential search
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return index if element is found
        }
    }
    return -1;  // Return -1 if element is not found
}

int main() {
    int n, key;
    
    // Accept number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    
    // Read n integers from user
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    // Accept key value to search
    cout << "\nEnter the element to search: ";
    cin >> key;
    
    // Perform sequential search
    int result = sequentialSearch(arr, n, key);
    
    // Display result
    if (result != -1) {
        cout << "\nElement " << key << " found at position " << (result + 1);
        cout << " (index " << result << ")" << endl;
    } else {
        cout << "\nElement not found" << endl;
    }
    
    return 0;
}