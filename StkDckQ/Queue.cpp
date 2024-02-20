#include "queue.h"
#include <iostream>
#include <fstream>

Queue::Queue() : data(nullptr), size(0), rear(-1), front(0){

}

Queue::Queue(int queueSize) {
    size = queueSize;
    data = new int[size];
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int value) {
    if (rear == size - 1) {
        std::cout << "Очередь переполнена" << std::endl;
        return;
    }
    data[++rear] = value;
}

int Queue::dequeue() {
    if (front > rear) {
        std::cout << "Очередь пуста" << std::endl;
        return -1;
    }
    return data[front++];
}

//Количество элементов
int Queue::sizeQ() {
    return rear - front + 1;
}

//Найти и вывести среднее
double Queue::average() {
    double sum = 0;
    int count = 0;
    for (int i = front; i <= rear; i++) {
        sum += data[i];
        count++;
    }
    return count > 0 ? sum / count : 0.0;
}

//Мин значение
int Queue::minValue() {
    int minValue = data[front];
    for (int i = front; i <= rear; i++) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

//Макс значение
int Queue::maxValue() {
    int maxValue = data[front];
    for (int i = front; i <= rear; i++) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}

//Элемент перед минимальным
int Queue::elementBeforeMin() {
    int minimal = minValue();
    int index = front;
    while (index <= rear && data[index] != minimal) {
        index++;
    }
    if (index > front && index <= rear) {
        return data[index - 1];
    }
    return -1;
}

//Вывести очередь
void Queue::display() {
    for (int i = front; i <= rear; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

//Сохранить в файл
void Queue::saveToFile(const char* filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = front; i <= rear; i++) {
            file << data[i] << " ";
        }
        file.close();
    }
    else {
        std::cout << "Не удалось открыть файл для записи" << std::endl;
    }
}
