#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

class Notes{
    std::vector<std::string> _text;
    std::string _file_name;

    public:
        Notes() = default;
        Notes(std::string);

        void Print()const;

};
