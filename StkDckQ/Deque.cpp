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

//Проверка на пустоту
bool Deque::isEmpty() {
    return front == -1 && rear == -1;
}

//Проерить конец на пустоту
bool Deque::isRearEmpty() {
    return rear == -1;
}



void Deque::AddSize() {
    size += 1;
}

//Добавить элемент в начало
void Deque::addToFront(int element) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else if (front == 0) {
        AddSize();
        for (int i = rear; i >= front; --i) {
            data[i + 1] = data[i];
        }
        rear++;
    }
    else {
        front--;
    }
    data[front] = element;
}


//Добавить элемент в конец
void Deque::addToRear(int element) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else if (rear == size - 1) {
        AddSize();
        rear++;
    }
    else {
        rear++;
    }
    data[rear] = element;
}

//Прочитать последний элемент
int Deque::readRear() {
    if (!isRearEmpty()) {
        return data[rear];
    }
    else {
        std::cout << "Задняя часть дека пуста" << std::endl;
        return -1;
    }
}

//Вывести деку
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

//Сохранить в файл
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
