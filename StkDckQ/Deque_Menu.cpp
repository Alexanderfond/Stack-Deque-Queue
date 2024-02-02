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
    
    std::cout << "\n\t�������� ��������:"
        << "\n��������� - 1"
        << "\n��������� �� ��������� - 2"
        << "\n������ ������� � ������� - 3"
        << "\n������ ������� � ����� - 4"
        << "\n��������� ������� ������� - 5"
        << "\n��������� ����� ������� �� ��������� - 6"
        << "\n�������� �������� �� ����� - 7"
        << "\n������� �� ����� - 8"
        << "\n�� ��������� ���� - 0"
        << "\n������: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\n� ��������� - 1\n� ����� - 2";
            std::cin >> fillingVariant;

            switch (fillingVariant) {
            case 1:
                std::cout << "������� ������ ����: ";
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
                    std::cout << "������ �������� �����.\n";
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
                std::cout << "��� ����" << std::endl;
            }
            else {
                std::cout << "��� �� ����" << std::endl;
            }
            break;
        case 3:
            std::cout << "������� �������� ��� ���������� � ������: ";
            std::cin >> value;
            deque.addToFront(value);
            break;
        case 4:
            std::cout << "������� �������� ��� ���������� � �����: ";
            std::cin >> value;
            deque.addToRear(value);
            break;
        case 5:
            if (!deque.isRearEmpty()) {
                std::cout << "��������� �������: " << deque.readRear() << std::endl;
            }
            break;
        case 6:
            if (deque.isRearEmpty()) {
                std::cout << "������ ����� ���� �����" << std::endl;
            }
            else {
                std::cout << "������ ����� ���� �� �����" << std::endl;
            }
            break;
        case 7:
            deque.saveToFile();
            break;
        case 8:
            deque.display();
            break;
        
        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choise_key != 0);
}
