#include<iostream>
using namespace std;
 
class Node{
    public:
       int data;
       Node* next;
    public:
       Node(int data1,Node* next1){
        data=data1;
        next=next1;
       }
    public:
       Node(int data1){
        data=data1;
        next=NULL;
       }
};
int main(){
    int arr[]={2,3,4,5,6};
    Node* y= new Node(arr[0]);
    cout<<y;// for address
    cout<<y->data; // for data and its output will be 2
    return 0;
}