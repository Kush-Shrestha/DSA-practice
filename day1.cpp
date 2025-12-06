#include<iostream>
using namespace std;

class Stack{
    private:
    int top=0;
    int numbers[3];
public:
    int isFull(){
        return top== sizeof(numbers)/ sizeof(numbers[0]);
    }
    int isEmpty(){
        return top==0;
    }

    
    void push(int data){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        numbers[top]=data;
        top=top+1;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        top--;
        return numbers[top];

    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return numbers[top-1];  
    }
    
    void print(){
        for(int i=0;i<sizeof(numbers)/sizeof(numbers[0]);i++){
            cout<<numbers[i]<<endl;
        }
    }
};
int main(){
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20); 
    cout<<"top element is"<<s.peek()<<endl;
    cout<<"popped element is "<<s.pop()<<endl;
    cout<<"After popping the top element is "<<s.peek()<<endl;
    s.print();
    return 0;
}
