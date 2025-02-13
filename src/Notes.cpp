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
    _line = static_cast<int>(_text.size()) -1;
    _text.push_back("");
}

void Notes::Print()const{
    for(const std::string& line : _text){
        std::cout << line << std::endl;
    }
}

void Notes::Kursor(){
    char kursor;
    if(check){
        kursor = '|';
    }
    else{
        kursor = ' ';
    }
    check = !check;

    _text[_line][_position] = kursor;
}

void Notes::Operation(int key){
    if(key == 75){//left
        
        _position--;
    }
    if(key == 77){//right
        
        _position++;
    }
    if(key == 72){//up
        
        _line--;
    }
    if(key == 80){//down
        
        _line++;
    }


}


