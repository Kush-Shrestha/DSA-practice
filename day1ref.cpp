#include <iostream>
using namespace std;
class Stack{
    private:
    int top =0;
    int numbers[6];



public:
    int isFull()
    {
        return top== sizeof(numbers)/ sizeof(numbers[0]);
    }

    void push(int data)
    {
       
         if(isFull())
        {
           cout<<"Stack is full ";
            return;
        }

     numbers[top] = data;
     top = top +1;
    }

    int pop()
    {
         // TODO: remove element from top of stack decrement top
         // TODO: create new method isEmpty to check if stack is empty

        return 1;
    }


    void print() {
        for (int i = 0; i < sizeof(numbers)/ sizeof(numbers[0]); i++)
        {
         cout<<numbers[i]<<endl;
        }
    }

};

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.print();


}