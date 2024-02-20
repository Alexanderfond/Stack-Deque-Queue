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
            << "\t ��������� - 1\n"

            << "\t ������� ������ ������ �� ������� �������� - 2\n"
            << "\t ���������� - 3\n"
            << "\t �������� ����� ������ ������� - 4\n"
            << "\t �������� ����� ������� ���� ������������� - 5\n"
            << "\t �������� ��������� ������� - 6\n"
            << "\t �������� ��� ���� ������� �������� - 7\n"
            << "\t �������� ��� ���� ���������� �������� - 8\n"
            << "\t ������� �� ����� - 9 \n"
            << "\t �������� � ���� - 10\n";

        std::cout << "Your choise: ";
        std::cin >> choise_key;

        unsigned int testNum;   ///
        int fileSize = 0;

        switch (choise_key) {
            case 1:
                
                std::cout << "\t"
                          << "\n � ��������� - 1"
                          << "\n � ����� - 2"
                          << "\n\t ������ ������: ";
                std::cin >> fillingVariant;

                switch (fillingVariant) {
                case 1:
                    std::cout << "������� ������ �����: ";
                    std::cin >> stackSize; 
                    stack = Stack(stackSize);

                    for (int i = 0; i < stackSize; i++) {
                        int value;
                        std::cout << "������ ������� " << i << ": ";
                        std::cin >> value;
                        stack.push(value);      // ������ ������
                    }
                    break;

                case 2:

                    inputFile.open("dataSDQ.txt");
                    if (!inputFile) {
                        std::cout << "������ �������� �����.\n";
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
                std::cout << "�������� ����: " << std::endl;
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