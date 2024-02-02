#include <iostream>
#include <fstream>
#include "queue.h"

void Queue_Menu() {
    int queueSize;
    int fillingVariant = 0;
    int choise_key = 99;
    std::ifstream inputFileQ;
    unsigned int testNum;  
    int fileSize = 1;

    Queue queue;
    

    do {
        std::cout << "��������� ����� - 1"
             << "\n����� ����� - 2"
             << "\n������ �������� - 3" 
             << "\n̳�������� �� ������������ ������� - 4" 
             << "\n������� ����� ��������� ������� - 5" 
             << "\n����� �� ����� - 6"
             << "\n������� ����� �� ����� - 7"
             << "\n�� ��������� ���� - 8"
             << "\n������: ";
    
        std::cin >> choise_key;
        switch (choise_key) {
        case 1:
            std::cout << "1 - from keyboard\n2 - from file\nYour choise: ";
            std::cin >> fillingVariant;
            switch (fillingVariant) {
            case 1:
                std::cout << "������� ������ �������: ";
                std::cin >> queueSize;
                queue = Queue(queueSize);

                for (int i = 0; i < queueSize; i++) {
                    int value;
                    std::cout << "������� ������� " << i << ": ";
                    std::cin >> value;
                    queue.enqueue(value);
                }

                break;

            case 2:

                inputFileQ.open("dataQ.txt"); 
                if (!inputFileQ.is_open()) {
                    std::cout << "�� ������� ������� ���� ��� ������" << std::endl;
                    break;
                }
                while (inputFileQ >> testNum) {
                    
                    fileSize++;
                }
                queue = Queue(fileSize);
                inputFileQ.close();
                inputFileQ.open("dataQ.txt");

                while (inputFileQ >> testNum) {
                    queue.enqueue(testNum);
                    fileSize++;
                }

                queue.display();
                inputFileQ.close();
                break;

            default:
                return;
                break;
            }


            break;

        case 2:
            std::cout << "������ �������: " << queue.sizeQ() << std::endl;
            break;

        case 3:
            std::cout << "������� ��������������: " << queue.average() << std::endl;
            break;

        case 4:
            std::cout << "����������� �������: " << queue.minValue() << std::endl;
            std::cout << "������������ �������: " << queue.maxValue() << std::endl;
            break;

        case 5:
            std::cout << "������� ����� �����������: " << queue.elementBeforeMin() << std::endl;
            break;

        case 6:
            queue.saveToFile("data.txt");
            std::cout << "\n\t��� ��������\n";
            break;

        case 7:
            std::cout << "�������� �������: "; 
            queue.display();
            break;

        case 8:
            
            choise_key = 0;
            break;

        default:
            return;
            break;
        }
        

    } while (choise_key != 0);    

}
