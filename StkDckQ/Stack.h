#ifndef STACK_H
#define STACK_H

void Stack_Menu();

class Stack {
public:
    Stack();
    Stack(int stackSize);
    ~Stack();
    void push(int value);
    int pop();
    void swapFirstAndLast();
    void reverse();
    void removeEverySecond();
    void insertAfterMax(int user_value);
    void removeMin();
    void removeAllExceptFirst();
    void removeAllExceptLast();
    void display();
    void writeToFile();

private:
    int* data;
    int size;
    int top;
};

#endif
