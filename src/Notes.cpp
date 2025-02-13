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
    _line = static_cast<int>(_text.size());
    _text.push_back(" ");
}

void Notes::Print()const{
    
    for(const std::string& line : _text){
        std::cout << line << std::endl;
    }
}

void Notes::Kursor_print(){
    if(check){
        kursor = '|';
    }
    else{
        kursor = ' ';
    }
    check = !check;
    _text[_line][_position] = kursor;

}
void Notes::Kursor_move(){

    _text[_line].insert(_position,1, kursor);

}


void Notes::Operation(int key){
    switch (key)
    {
    case 75: //left
        _text[_line].erase(_position, 2);
        if(_position >0){
            _position--;
        }
        else{
            if(_line > 0){
                _line--;
                _position = static_cast<int>(_text[_line].size());
            }
        }
        
    break;
    
    
    case 77: // right
        _text[_line].erase(_position, 2);
        if(_position < static_cast<unsigned int>(_text[_line].size())){
            _position++;
        }
        else{
            if(_line < static_cast<unsigned int>(_text.size()) -1){
                _line++;
                _position = 0;;
            }
        }

    break;

    
    case 72: // up
        _text[_line].erase(_position, 2);
        if(_line >0){
            if(_position <= _text[_line-1].size()){
                _line--;
            }
            else{
                _position = static_cast<unsigned int>(_text[_line-1].size());
                _line--;
            }
        }
    break;
    case 80: // down
        _text[_line].erase(_position, 2);
        if(_line < static_cast<unsigned int>(_text.size()-1)){
            if(_position <= _text[_line+1].size()){
                _line++;
            }
            else{
                _position = static_cast<unsigned int>(_text[_line+1].size());
                _line++;
            }
        }
    break;
    default:
        break;
    }


}


