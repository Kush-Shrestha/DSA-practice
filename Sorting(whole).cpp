#include <iostream>
using namespace std;

void BubbleSort(int x[],int size) {

    for (int i = 0; i < size - 1; i++ ) {
        for ( int j = 0; j < size-1-i; j++) {
            if (x[j] < x[j+1]) {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int x[],int size) {
    for (int i = 1; i < size; i++) {
        int temp = x[i];
        int j = i-1;
        while (j >= 0 && x[j] > temp) {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = temp;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout<<endl;
}

void selectionSort(int x[], int size) {
    for (int i = 0; i < size-1; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (x[j] < x[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = x[i];
            x[i] = x[min];
            x[min] = temp;
        }
    }
    cout<<"Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << x[i] <<" ";
    }
    cout << endl;
}

void MergeSort(int a[],int b[],int c[],int asize, int bsize, int csize) {
    int x = 0;      //cursor or index of x(like 0,1,2,3) on a[]  #x vaneko specific indexes that are under array of a[].
    int y = 0;      //cursor or index of y on b[]
    int z = 0;      //cursor or index of z on c[]
    while (x < asize && y < bsize) {
        if (a[x] < b[y]) {
            c[z] = a[x];
            x++;        // x stored vayo so we have to increase x to next index.
        }else {
            c[z]= b[y];
            y++;        // y stored vayo so we have to increase x to next index.
        }
        z++;        // mathi ko condition bata euta na euta c[] ma stored hunxa so we also have to increase z.
    }
    //Mathi ko condition duitai meet huna parxa so for individual which might ignored we have to store that particular data also
    while (x < asize) {
        c[z] = a[x];
        x++;
        z++;
    }
    while (y < bsize) {
        c[z] = b[y];
        y++;
        z++;
    }
    cout<<"Sorted array: ";
    for (int i = 0; i < csize; i++) {
        cout<< c[i] << " ";
    }
    cout << endl;
}

int main() {
    //for Bubble sort
    int arr[] = {5,3,6,4,1,2,};
    int bSize = sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr,bSize);

    //for Insertion sort
    int i[]= {3,5,4,7,1,6};
    int iSize = sizeof(i)/sizeof(i[0]);

    InsertionSort(i,iSize);

    //for Selection sort
    int s[]= {2,4,6,3,5,1};
    int sSize = sizeof(s)/sizeof(s[0]);

    selectionSort(s,sSize);

    //for merge array
    int x[] = {1,3,6,8,9};
    int y[] = {12,14,17,19,21};
    int xSize = sizeof(x)/sizeof(x[0]);
    int ySize = sizeof(y)/sizeof(y[0]);

    int z[10];
    int zSize = sizeof(z)/sizeof(z[0]);

    MergeSort(x,y,z,xSize,ySize,zSize);

    return 0;
}