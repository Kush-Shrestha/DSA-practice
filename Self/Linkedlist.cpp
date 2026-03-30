#include<iostream>
using namespace std;

class Node{ 
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
     LinkedList(){
        this->head=NULL;
     }
      bool insertAtBeginnig(int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            return true;
        }
        newnode->next=head;
        head=newnode;
        return true;
      }
      bool insertAtEnd(int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            return true;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        return true;
       }
        insertAtPosition(int data,int pos){
            Node* newnode=new Node(data);
            if(pos==1){
                newnode->next=head;
                head=newnode;
                return true;
            }
            Node* temp=head;
            for(int i=1;i<pos-1;i++){
                if(temp==NULL) return false;
                temp=temp->next;
            }
            if(temp==NULL) return false;
            newnode->next=temp->next;
            temp->next=newnode;
            return true;
        }
        bool deleteatBeginning(){
            if(head==NULL) return false;
            Node* temp=head;
            head=head->next;
            free(temp);
            return true;
        }
        bool deleteatEnd(){
            if(head==NULL) return false;
            if(head->next==NULL){
                free(head);
                head=NULL;
                return true;
            }
            Node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
            return true;
        }
        bool deleteatPosition(int pos){
            if(head==NULL) return false;
            if(pos==1){
                Node* temp=head;
                head=head->next;
                free(temp);
                return true;
            }
            Node* temp=head;
            for(int i=1;i<pos-1;i++){
                if(temp==NULL) return false;
                temp=temp->next;
            }
            if(temp==NULL || temp->next==NULL) return false;
            Node* todelete=temp->next;
            temp->next=temp->next->next;
            free(todelete);
            return true;
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtBeginnig(1);
    ll.insertAtPosition(4,4);
    cout<<"Linked List after insertions: ";
    ll.display();
    ll.deleteatBeginning();
    cout<<"Linked List after deleting from beginning: ";
    ll.display();
    ll.deleteatEnd();
    cout<<"Linked List after deleting from end: ";
    ll.display();
    ll.deleteatPosition(2);
    cout<<"Linked List after deleting from position 2: ";
    ll.display();
    return 0;
}
