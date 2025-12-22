#include<iostream>
using namespace std;
int main(){
    int searchvalue;
    cout<<"Enter the search value "<<endl;
    cin>>searchvalue;
    int foundindex=-1,upper=4,lower=0,mid;
    int arr[]={10,20,30,40,50};
    while(lower<=upper){
        mid=lower+(upper-lower)/2;
    if(arr[mid]==searchvalue){
        foundindex=mid;

    }
    if(searchvalue<arr[mid]){
        upper=mid-1;
    }
    else{
        lower=mid+1;
    }
}
cout<<"index is found at "<<foundindex<<endl;
return 0;
}