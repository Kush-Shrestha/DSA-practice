#include <iostream>
using namespace std;

int main(){
int x[]={28,30,1,22,2,54,32};
int size=sizeof(x)/sizeof(x[0]);
   for(int i=0;i<size;i++){
       for(int j=0;j<size-i-1;j++){
	   if(x[j]>x[j+1]){
	   int temp=x[j];
	   x[j]=x[j+1];
	   x[j+1]=temp;
	   }
	   }}
	   cout<<"The sorted will be like ";
    for(int i=0;i<size;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
