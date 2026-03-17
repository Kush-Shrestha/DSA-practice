#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node* next;
    public:
       Node(int data1, Node* next1){
        data=data1;
        next=next1;
       }
    public:
       Node(int data1){
        data=data1;
        next=NULL;
       }
};

Node* convertarr2LL(int arr[], int size){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<size; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    int arr[]={2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    Node* y= new Node(arr[0]);
    cout<<y<<endl;        // for address
    cout<<y->data<<endl;  // for data and its output will be 2
    Node* head = convertarr2LL(arr, size);
    cout<<head->data;
    return 0;
}