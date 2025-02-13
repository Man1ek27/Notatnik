#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

class Notes{
    std::vector<std::string> _text;
    std::string _file_name;
    int _line =0;
    int _position = 0;
    bool check = true;

    public:
        Notes() = default;
        Notes(std::string);

        void Kursor();
        void Operation(int);

        void Print()const;


};
