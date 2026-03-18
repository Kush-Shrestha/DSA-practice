/* pseudo code to insert in the beginning 
   Step 1: create new node 
   Step 2: IF (NEW_NODE == NULL) THEN
             DISPLAY "Memory Overflow"
             EXIT
         ENDIF
    Step 3: Read num    // Get the value to be inserted
    Step 4: SET NEW_NODE.data ← num
         SET NEW_NODE.next ← HEAD   // Link new node to the previous first 
    Step 5: Set Head <- new node // Update HEAD to point to the new node

    Step 6:  DISPLAY "Node inserted at beginning successfully"

Thats all Now the actual code 
*/

#include<iostream>
using namespace std;

class Node {
    public:
     int data;
     Node* next;
     
       Node(int data1, Node* next1){  
         data = data1;
         next = next1;
       }

     Node(int data1){
         data=data1;
         next=NULL; 
     }
};
class LinkedList{
     public:
      Node* InsertAtBeginngin(Node* head, int newData ){
          Node* newNode = new Node(newData,head);
          return newNode;
      }
      void display(Node* head){
           Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
      }
};
int main(){
     LinkedList ll;
      Node* head = new Node(2); // Creating a sample linked list: 2 -> 3
    head->next = new Node(3);
    cout << "Original List: ";
    ll.display(head);

    // Inserting new node at head
    head = ll.InsertAtBeginngin(head, 1);

    cout << "After Insertion at Head: ";
    ll.display(head);

    return 0;
}