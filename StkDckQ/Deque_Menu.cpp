#include <iostream>
#include <fstream>
#include "Deque.h"

void Deque_Menu() {
    int dequeSize;
    int choise_key = 999;
    int fillingVariant;
    int value;
    int fileSize = 0, testNum;
    std::ifstream inputFile;

    Deque deque;

    do{
    int choice;
    
    std::cout << "\n\tВыберите действие:"
        << "\nЗаповнити - 1"
        << "\nПеревірити на порожнечу - 2"
        << "\nДодати елемент в початок - 3"
        << "\nДодати елемент в кінець - 4"
        << "\nПрочитати останній елемент - 5"
        << "\nПеревірити задню частину на порожнечу - 6"
        << "\nЗаписати елементи до файлу - 7"
        << "\nВивести на екран - 8"
        << "\nДо головного меню - 0"
        << "\nОберіть: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nЗ клавіатури - 1\nЗ файлу - 2";
            std::cin >> fillingVariant;

            switch (fillingVariant) {
            case 1:
                std::cout << "Введите размер дека: ";
                std::cin >> dequeSize;

                deque = Deque(dequeSize);

                for (int i = 0; i < dequeSize; i++) {
                    std::cin >> value;
                    deque.addToRear(value);
                }
                break;

            case 2:
                inputFile.open("dataSDQ.txt");
                if (!inputFile) {
                    std::cout << "Ошибка открытия файла.\n";
                    return;
                }

                while (inputFile >> testNum) {

                    fileSize += 1;
                }
                inputFile.close();
                
                deque = Deque(fileSize);
                
                inputFile.open("dataSDQ.txt");
                
                while (inputFile >> value) {

                    deque.addToRear(value);
                }
                inputFile.close();

                break;
            }
        

        case 2:
            if (deque.isEmpty()) {
                std::cout << "Дек пуст" << std::endl;
            }
            else {
                std::cout << "Дек не пуст" << std::endl;
            }
            break;
        case 3:
            std::cout << "Введите значение для добавления в начало: ";
            std::cin >> value;
            deque.addToFront(value);
            break;
        case 4:
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> value;
            deque.addToRear(value);
            break;
        case 5:
            if (!deque.isRearEmpty()) {
                std::cout << "Последний элемент: " << deque.readRear() << std::endl;
            }
            break;
        case 6:
            if (deque.isRearEmpty()) {
                std::cout << "Задняя часть дека пуста" << std::endl;
            }
            else {
                std::cout << "Задняя часть дека не пуста" << std::endl;
            }
            break;
        case 7:
            deque.saveToFile();
            break;
        case 8:
            deque.display();
            break;
        
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choise_key != 0);
}
