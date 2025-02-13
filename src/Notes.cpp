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
    switch (key)
    {
    case 75: //left
        if(_position >0){
            _position--;
        }
        else{
            if(_line > 0){
                _line--;
                _position = _text[_line].size()-1;
            }
        }
    break;
    
    
    case 77: // right
        if(_position < _text[_line].size() -1){
            _position++;
        }
        else{
            if(_line < _text.size() -1){
                _line++;
                _position = 0;;
            }
        }
    break;

    default:
        break;
    }
    if(key == 72){//up
        
        _line--;
    }
    if(key == 80){//down
        
        _line++;
    }


}


