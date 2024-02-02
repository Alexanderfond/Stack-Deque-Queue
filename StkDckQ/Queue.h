#ifndef QUEUE_H
#define QUEUE_H

void Queue_Menu();

class Queue {
public:
    Queue();
    Queue(int queueSize);
    ~Queue();
    void enqueue(int value);
    int dequeue();
    int sizeQ();
    double average();
    int minValue();
    int maxValue();
    int elementBeforeMin();
    void display();
    void saveToFile(const char* filename);

private:
    int* data;
    int size;
    int front;
    int rear;
};

#endif
