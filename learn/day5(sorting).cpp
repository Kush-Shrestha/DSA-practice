#include <iostream>
using namespace std;
int main() {

   int x[] ={28,30,1,2,46,19,33,4,28,48};
    int size = sizeof(x)/sizeof(x[0]);

    cout<<"UnSorted array: "<<endl;
    for (int i=0;i<size;i++) {
        cout<<x[i]<<" ->";
    }
    cout<<endl;

    int minIndex =0;
    for (int i=0;i<size-1;i++) {
         minIndex =i;

        for (int j=i+1;j<size;j++ ) {

  
           if (x[minIndex] > x[j]) {
              minIndex = j;
          }
        }
        // minIndex = 2
        // minValue = 1;

       int temp = x[i];
        x[i] = x[minIndex];
        x[minIndex] = temp;
    }

    cout<<"Sorted array: "<<endl;
for (int i=0;i<size;i++) {
    cout<<x[i]<<" ->";
}

    return 0;

}