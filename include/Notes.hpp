#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

class Notes{
    std::vector<std::string> _text;
    std::string _file_name;
    unsigned int _line =0;
    unsigned int _position = 0;
    bool check = true;
    char kursor = '|';


    public:
        Notes() = default;

        //Insterts path to file
        Notes(std::string);

        //Gives kursor animation 
        void Kursor_print();

        //Moving kursor (up, down, left, right)
        //parm int - inserts asci of key
        void Kursor_move(int);

        //other opertaions
        //parm int - inserts asci of key
        void Operation(int);

        //Prints menu
        void Print_menu()const;
        
        //Saving to file
        void Save();

        //Wypisywanie na ekran tekstu
        void Print()const;
        

};
