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
        std::cout << "Заповнити чергу - 1"
             << "\nРозмір черги - 2"
             << "\nСереднє значення - 3" 
             << "\nМінімальний та максимальний елемент - 4" 
             << "\nЕлемент перед мінімальним елемент - 5" 
             << "\nЗапис до файлу - 6"
             << "\nВивести чергу на екран - 7"
             << "\nДо головного меню - 8"
             << "\nОберіть: ";
    
        std::cin >> choise_key;
        switch (choise_key) {
        case 1:
            std::cout << "1 - from keyboard\n2 - from file\nYour choise: ";
            std::cin >> fillingVariant;
            switch (fillingVariant) {
            case 1:
                std::cout << "Введите размер очереди: ";
                std::cin >> queueSize;
                queue = Queue(queueSize);

                for (int i = 0; i < queueSize; i++) {
                    int value;
                    std::cout << "Введите элемент " << i << ": ";
                    std::cin >> value;
                    queue.enqueue(value);
                }

                break;

            case 2:

                inputFileQ.open("dataQ.txt"); 
                if (!inputFileQ.is_open()) {
                    std::cout << "Не удалось открыть файл для чтения" << std::endl;
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
            std::cout << "Размер очереди: " << queue.sizeQ() << std::endl;
            break;

        case 3:
            std::cout << "Среднее арифметическое: " << queue.average() << std::endl;
            break;

        case 4:
            std::cout << "Минимальный элемент: " << queue.minValue() << std::endl;
            std::cout << "Максимальный элемент: " << queue.maxValue() << std::endl;
            break;

        case 5:
            std::cout << "Элемент перед минимальным: " << queue.elementBeforeMin() << std::endl;
            break;

        case 6:
            queue.saveToFile("data.txt");
            std::cout << "\n\tДані записано\n";
            break;

        case 7:
            std::cout << "Исходная очередь: "; 
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
