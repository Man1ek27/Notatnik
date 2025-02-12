#include "../include/Notes.hpp"


Notes::Notes(std::string file_name): _file_name{file_name}{
    std::ifstream File("../../" + _file_name);
    if(File.fail()){
        std::cout << "ERROR: opening file" <<std::endl;
        return;
    }

    std::string line;
    while(std::getline(File, line )){
        _text.push_back(line);
    }
}

void Notes::Print()const{
    for(const std::string& line : _text){
        std::cout << line << std::endl;
    }
}
