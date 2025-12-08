#include <iostream>
using namespace std;
int main() {
    // int x[] = {1,3,2,6};
    // merge(x,1,1,2);
    // x = 3
    int x[] = {1,2,8,18,20};
    int y[] = {3,6,10,14,22};

    /**
     i =4
     j= 5
     z [1 2 3 6 8 10 14 17 18 20]
    **/
    int z[10]; // 1 2 8 12 18 3 6 10
    // x array ko cursor
    int i =0;
    // y array ko cursor
    int j =0;
    // z ko cursor
    int k =0;
    int xSize = sizeof(x)/sizeof(x[0]);
    int ySize = sizeof(y)/sizeof(y[0]);
    int zSize = sizeof(z)/sizeof(z[0]);
    while (i<xSize && j<ySize) {
        if (x[i]<y[j]) {
            z[k]=x[i];
            i++;
        }else {
            z[k]=y[j];
            j++;
        }
        k++;
    }
    while (i<xSize) {
        z[k]=x[i];
        k++;
        i++;
    }
    while (j<ySize) {
        z[k]=y[j];
        k++;
        j++;
    }

    for (int b = 0;b<zSize;b++) {
        cout<<z[b]<<" ";
    }
    return 0;

}