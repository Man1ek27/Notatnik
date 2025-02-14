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
                int key = static_cast<int>(_getch());
                if(key == 224 ){
                    file.Kursor_move(static_cast<int>(_getch()));
                }
                else{
                    file.Operation(key);
                }
             }
            Sleep(300);

         }

         //std::cout << znak << std::endl;

    }
    return 0;
}