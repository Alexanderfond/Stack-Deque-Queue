#ifndef DEQUE_H
#define DEQUE_H

void Deque_Menu();

class Deque {
public:
    Deque();
    Deque(int dequeSize);
    ~Deque();
    bool isEmpty();
    void addToFront(int value);
    void addToRear(int value);
    int readRear();
    bool isRearEmpty();
    void display();
    void saveToFile();

    void AddSize();
private:
    int* data;
    int size;
    int front;
    int rear;
};

#endif
