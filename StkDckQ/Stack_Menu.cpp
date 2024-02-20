#include <iostream>
#include <fstream>
#include "Stack.h"

void Stack_Menu() {

    int stackSize;
    int fillingVariant;
    std::ifstream inputFile;

    Stack stack;

    int choise_key = 999;

    do {

        std::cout << "\n"
            << "\t Заповнити - 1\n"

            << "\t Поміняти місцями перший та останній елементи - 2\n"
            << "\t Розвернути - 3\n"
            << "\t Видалити кожен другий елемент - 4\n"
            << "\t Вставити новий елемент після максимального - 5\n"
            << "\t видалити мінімальний елемент - 6\n"
            << "\t Видалити все окрім першиго елемента - 7\n"
            << "\t Видалити все окрім останнього елемента - 8\n"
            << "\t Вивести на екран - 9 \n"
            << "\t Зберегти у файл - 10\n";

        std::cout << "Your choise: ";
        std::cin >> choise_key;

        unsigned int testNum;   ///
        int fileSize = 0;

        switch (choise_key) {
            case 1:
                
                std::cout << "\t"
                          << "\n З клавіатури - 1"
                          << "\n З файлу - 2"
                          << "\n\t Оберіть варіант: ";
                std::cin >> fillingVariant;

                switch (fillingVariant) {
                case 1:
                    std::cout << "Введите размер стека: ";
                    std::cin >> stackSize; 
                    stack = Stack(stackSize);

                    for (int i = 0; i < stackSize; i++) {
                        int value;
                        std::cout << "Введіть елемент " << i << ": ";
                        std::cin >> value;
                        stack.push(value);      // запись мусора
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

                    inputFile.open("dataSDQ.txt");

                    stack = Stack(fileSize);

                    unsigned int value;
                    while (inputFile >> value) {
                        stack.push(value);
                    }
                    inputFile.close();
                    break;

                default:
                    return;
                    break;
                }
                
                break;

            case 2:
                std::cout << "swapFirstAndLast" << std::endl;
                stack.swapFirstAndLast();
                stack.display();
                break;

            case 3:
                std::cout << "reverse" << std::endl;
                stack.reverse();
                stack.display();
                break;

            case 4:
                std::cout << "removeEverySecond" << std::endl;
                stack.removeEverySecond(); 
                stack.display();
                break;

            case 5:
                std::cout << "insertAfterMax" << std::endl;
                stack.insertAfterMax();
                stack.display();
                break;

            case 6:
                std::cout << "removeMin" << std::endl;
                stack.removeMin();
                stack.display();
                break;

            case 7:
                std::cout << "removeAllExceptFirst" << std::endl;
                stack.removeAllExceptFirst();
                stack.display();
                break;

            case 8:
                std::cout << "removeAllExceptLast" << std::endl;
                stack.removeAllExceptLast();
                stack.display();
                break;

            case 9:
                std::cout << "Исходный стек: " << std::endl;
                stack.display();
                break;

            case 10:
                stack.writeToFile();
                break;
            default:
                
                break;

        }
    } while (choise_key != 0);
}