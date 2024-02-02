#include <iostream>
#include <Windows.h>
#include "stack.h"
#include "Queue.h"
#include "Deque.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    int userChoise = 99;
    
    do {
        
        std::cout  
            << "\nСтек - 1"
            << "\nЧерга - 2"
            << "\nДека - 3"
            << "\n\tОберіть: ";

        std::cin >> userChoise;
        switch (userChoise)
        {
        case 1:
            Stack_Menu();
            break;

        case 2:
            Queue_Menu();
            break;
        case 3:
            Deque_Menu();
            break;
        default:
            //return 0;
            break;
        }
    } while (userChoise != 0);
    

    return 0;
}
