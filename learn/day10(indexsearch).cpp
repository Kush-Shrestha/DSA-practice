#include<iostream>
using namespace std;

int main() {
    int num[]={1,3,5,7,11,9};
    int n;
    int index= -1;
    cout<<"Enter any number:"<<endl;
    cin>>n;
    int size=sizeof(num)/sizeof(num[0]);

for(int i=0;i<size;i++) {
    if (num[i]==n) {
    index=i;
    }
}
if(index !=-1){ 
 cout<<"Number found at index:"<<index<<endl;
}else{
    cout<<"Number not found"<<endl;
}
return 0;
}