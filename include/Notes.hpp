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
        Notes(std::string);

        void Kursor_print();
        void Kursor_move(int);
        void Operation(int);
        void Print_menu()const;
        
        void Save();

        void Print()const;
        

};
