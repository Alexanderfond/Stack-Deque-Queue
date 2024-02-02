#include "stack.h"
#include <iostream>
#include <fstream>

Stack::Stack() : data(nullptr), size(0), top(-1) {
    // ������������� ������� � ��������� ���������
}

Stack::Stack(int stackSize) : size(stackSize), top(-1) {
    size = stackSize;
    data = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int value) {
    if (top < size - 1) {
        data[++top] = value;
    }
    else {
        std::cout << "���� ����������" << std::endl;
    }
}

// �������� �������� �������� �� �����
int Stack::pop() {
    if (top >= 0) {
        return data[top--];
    }
    else {
        std::cout << "���� ����" << std::endl;
        return -1; // ���������� �������� �� ���������
    }
}

// ������� ��� ������ ������� ������� � ���������� ���������
void Stack::swapFirstAndLast() {
    if (top >= 1) {
        int temp = data[0];
        data[0] = data[top];
        data[top] = temp;
    }
}

// ������� ��� ��������� �����
void Stack::reverse() {
    int* temp = new int[size];
    for (int i = 0; i <= top; i++) {
        temp[i] = data[top - i];
    }
    delete[] data;
    data = temp;
}

// ������� ��� �������� ������� ������� ��������
void Stack::removeEverySecond() {
    if (top >= 0) {
        for (int i = 1; i <= top; i += 2) {
            for (int j = i; j < top; j++) {
                data[j] = data[j + 1];
            }
            top--;
        }
    }
}

// ������� ��� ������� 0 ����� ������������� ��������
void Stack::insertAfterMax(int user_value) {                                      ///////////////
    int maxIndex = 0;
    int maxValue = data[0];
    for (int i = 1; i <= top; i++) {
        if (data[i] > maxValue) {
            maxIndex = i;
            maxValue = data[i];
        }
    }
    if (top + 1 < size) {
        for (int i = top + 1; i > maxIndex; i--) {
            data[i] = data[i - 1];
        }
        data[maxIndex + 1] = user_value;
        top++;
    }
}

// ������� ��� �������� ������������ ��������
void Stack::removeMin() {
    if (top >= 0) {
        int minIndex = 0;
        int minValue = data[0];
        for (int i = 1; i <= top; i++) {
            if (data[i] < minValue) {
                minIndex = i;
                minValue = data[i];
            }
        }
        for (int i = minIndex; i < top; i++) {
            data[i] = data[i + 1];
        }
        top--;
    }
}

// ������� ��� �������� ���� ���������, ����� �������
void Stack::removeAllExceptFirst() {
    for (int i = top; i > 0; i--) {
        pop();
    }
}

// ������� ��� �������� ���� ���������, ����� ����������
void Stack::removeAllExceptLast() {
    if (top > 0) {
        int lastElement = data[top];
        top = 0;
        data[0] = lastElement;
    }
}

// ����� ����������� �����
void Stack::display() {
    for (int i = 0; i <= top; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::writeToFile() {
    std::ofstream outputFile("StackResults.txt");

    if (!outputFile.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������!" << std::endl;
        return;
    }

    for (int i = 0; i <= top; i++) {
        outputFile << data[i] << " ";
    }

    outputFile.close();
    std::cout << "��� ��������� � ���� StackResults.txt " << std::endl;
}