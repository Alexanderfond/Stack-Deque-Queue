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

//�������� �� �������
bool Deque::isEmpty() {
    return front == -1 && rear == -1;
}

//�������� ����� �� �������
bool Deque::isRearEmpty() {
    return rear == -1;
}



void Deque::AddSize() {
    size += 1;
}

//�������� ������� � ������
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


//�������� ������� � �����
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

//��������� ��������� �������
int Deque::readRear() {
    if (!isRearEmpty()) {
        return data[rear];
    }
    else {
        std::cout << "������ ����� ���� �����" << std::endl;
        return -1;
    }
}

//������� ����
void Deque::display() {
    if (isEmpty()) {
        std::cout << "��� ����" << std::endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    
}

//��������� � ����
void Deque::saveToFile() {
    std::ofstream file("data_Deque.txt");
    if (file.is_open()) {
        for (int i = front; i <= rear; i++) {
            file << data[i] << " ";
        }
        file.close();

        std::cout << "��� ��������� � ���� data_Deque.txt";
    }
    else {
        std::cout << "�� ������� ������� ���� ��� ������" << std::endl;
    }
}
