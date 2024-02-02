#include "stack.h"
#include <iostream>
#include <fstream>

Stack::Stack() : data(nullptr), size(0), top(-1) {
    // Инициализация объекта в начальное состояние
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
        std::cout << "Стек переполнен" << std::endl;
    }
}

// Удаление верхнего элемента из стека
int Stack::pop() {
    if (top >= 0) {
        return data[top--];
    }
    else {
        std::cout << "Стек пуст" << std::endl;
        return -1; // Возвращаем значение по умолчанию
    }
}

// Функция для обмена местами первого и последнего элементов
void Stack::swapFirstAndLast() {
    if (top >= 1) {
        int temp = data[0];
        data[0] = data[top];
        data[top] = temp;
    }
}

// Функция для разворота стека
void Stack::reverse() {
    int* temp = new int[size];
    for (int i = 0; i <= top; i++) {
        temp[i] = data[top - i];
    }
    delete[] data;
    data = temp;
}

// Функция для удаления каждого второго элемента
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

// Функция для вставки 0 после максимального элемента
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

// Функция для удаления минимального элемента
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

// Функция для удаления всех элементов, кроме первого
void Stack::removeAllExceptFirst() {
    for (int i = top; i > 0; i--) {
        pop();
    }
}

// Функция для удаления всех элементов, кроме последнего
void Stack::removeAllExceptLast() {
    if (top > 0) {
        int lastElement = data[top];
        top = 0;
        data[0] = lastElement;
    }
}

// Вывод содержимого стека
void Stack::display() {
    for (int i = 0; i <= top; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::writeToFile() {
    std::ofstream outputFile("StackResults.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return;
    }

    for (int i = 0; i <= top; i++) {
        outputFile << data[i] << " ";
    }

    outputFile.close();
    std::cout << "Дані збережено у файл StackResults.txt " << std::endl;
}