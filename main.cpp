#include <iostream>
#include "include/Notes.hpp"
#include <windows.h>
#include <conio.h>


int main(int argc, char* argv[]){
    
    
    SetConsoleOutputCP(CP_UTF8);
    if(argc >1){
        Notes file(argv[1]);
        std::cout << "File: " << argv[1] << std::endl;
        
        
        while(true){
            system("cls");
            file.Print();
            file.Kursor_print();
            
            while(_kbhit()){
                //std::cout << static_cast<int>(_getch()) << std::endl;
                file.Operation(static_cast<int>(_getch()));
                file.Kursor_move();
             }
            Sleep(300);

         }

         //std::cout << znak << std::endl;

    }
    return 0;
}