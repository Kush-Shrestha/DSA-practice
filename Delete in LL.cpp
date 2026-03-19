/* Now the pseudo code to delete the elements 
 Step 1: START

Step 2: IF HEAD = NULL THEN
            PRINT "List is Empty"
            EXIT
        ENDIF

Step 3: SET TEMP ← HEAD

Step 4: SET HEAD ← HEAD.next

Step 5: FREE TEMP

Step 6: PRINT "First node deleted successfully"

Step 7: STOP


*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     
    public:
        Node(int data1,Node* next1){
            data=data1;
            next= next1;
        }
        Node(int data1){
            data=data1;
            next=NULL;
        }
};
class LinkedList{
    public:
    Node* DeleteFromBeginning
}