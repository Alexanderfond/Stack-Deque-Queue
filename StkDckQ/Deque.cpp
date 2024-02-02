#include "deque.h"
#include <iostream>
#include <fstream>

Deque::Deque() : data(nullptr), size(0), front(-1), rear(-1) {

}

Deque::Deque(int dequeSize) {
    size = dequeSize;
    data = new int[size];
    front = -1;
    rear = -1;
}

Deque::~Deque() {
    delete[] data;
}

bool Deque::isEmpty() {
    return front == -1 && rear == -1;
}

void Deque::addToFront(int value) {
    if (isEmpty()) {
        front = rear = 0;
        data[front] = value;
    }
    else if (front > 0) {
        data[--front] = value;
    }
    else {
        std::cout << "Дек переполнен с передней стороны" << std::endl;
    }
}

void Deque::addToRear(int value) {
    if (isEmpty()) {
        front = rear = 0;
        data[rear] = value;
    }
    else if (rear < size - 1) {
        data[++rear] = value;
    }
    else {
        std::cout << "Дек переполнен с задней стороны" << std::endl;
    }
}

int Deque::readRear() {
    if (!isRearEmpty()) {
        return data[rear];
    }
    else {
        std::cout << "Задняя часть дека пуста" << std::endl;
        return -1;
    }
}

bool Deque::isRearEmpty() {
    return rear == -1;
}

void Deque::display() {
    if (isEmpty()) {
        std::cout << "Дек пуст" << std::endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    
}

void Deque::saveToFile() {
    std::ofstream file("data_Deque.txt");
    if (file.is_open()) {
        for (int i = front; i <= rear; i++) {
            file << data[i] << " ";
        }
        file.close();

        std::cout << "Дані збережено у файл data_Deque.txt";
    }
    else {
        std::cout << "Не удалось открыть файл для записи" << std::endl;
    }
}
