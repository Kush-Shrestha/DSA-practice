//Circular queue
#include<iostream>
using namespace std;
class Queue{
    public:
    int front=0;
    int rear=0;
    int numbers[3];

    bool isFull(){
        return (rear+1)% (sizeof(numbers)/ sizeof(numbers[0]))==front;
    }
    int Enqueue(int data){
        if (isFull(){
            cout<<"Queue is full"<<endl;
            return;
        }
        numbers[rear]=data;
        rear=(rear+1)% (sizeof(numbers)/ sizeof(numbers[0]));
    }
    bool isEmpty(){
        return front==rear;
    }
    int Dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data=numbers[front];
        front=(front+1)% (sizeof(numbers)/ sizeof(numbers[0]));
        return data;
    }
    void print(){
        for(int i=0;i<sizeof(numbers)/sizeof(numbers[0]);i++){
            cout<<numbers[i]<<endl;
        }
    }


};
int main(){
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Enqueue(20); 
    cout<<"dequeued element is "<<q.Dequeue()<<endl;
    cout<<"After dequeuing the front element is "<<q.Dequeue()<<endl;
    q.print();
    return 0;
}
