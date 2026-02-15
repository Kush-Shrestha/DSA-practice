#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;


};
class linkedlist {
public:
    Node* head ;
    Node* tail;

    linkedlist() {

        head = nullptr;
        tail = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* node=new Node();
        node->data=value;
        if (head==nullptr) {
            head=tail=node;

        }else {
            node ->next=head;
            head=node;


        }
    }
    void insertAtLast(int value) {
        Node* node=new Node();
        node->data=value;
        node->next=nullptr;

        if (head==nullptr) {
            head=tail=node;

        }else{
            tail->next=node;
            tail=node;
        }
    }

    void popAtHeed() {
        if (head==nullptr) {
            cout<<"node is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
        cout<<"sucessfully poped at head"<<endl;
    }
    void popAtTail() {
        if (head==nullptr) {
            cout<<"node is empty"<<endl;
            return;
        }
        Node *temp=head;
        while (temp->next!=tail) {
            temp=temp->next;
        }


        delete tail;
        tail=temp;
        temp->next=nullptr;
        cout<<"sucessfully poped at tail"<<endl;
    }
    void print() {
        Node* temp = head;
        while (temp!=nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main() {
    linkedlist l;
     l.insertAtBeginning(10);
    l.insertAtBeginning(20);
   l.insertAtLast(21);
    l.popAtHeed();
    l.popAtTail();
    l.print();
    return 0;
}
