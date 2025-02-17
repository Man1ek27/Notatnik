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
void Notes::Kursor_move(int key){
    switch(key){
        case 75: //left
            _text[_line].erase(_position, 1);
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
            _text[_line].erase(_position, 1);
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
            _text[_line].erase(_position, 1);
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
            _text[_line].erase(_position, 1);
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
        }
        
    _text[_line].insert(_position,1, kursor);

}


void Notes::Operation(int key){
    switch (key)
    {
    case 8: // backspace
        if(_position > 0){
            _text[_line].erase(_position-1, 2);
            _position--;
        }
        else if (_line > 0){
            _text[_line].erase(_position, 1);
            _position = static_cast<int>(_text[_line-1].size()+1);
            _text[_line-1] += _text[_line];
            _text.erase(_text.begin() + _line);
            _line--;
            _position--;
        }
        else{
            _text[_line].erase(_position, 2);

        }
    break;
    case 13: // enter
        _text.insert(_text.begin() + _line + 1, "");
        _text[_line+1] = _text[_line].substr(_position+1);
        _text[_line].erase(_position, _text[_line].size()-_position);
        _line++;
        _position = 0;
        
    break;
    case 19: // save
        _text[_line].erase(_position, 1);
        this->Save();
        return;
    break;
    default:
        _text[_line].insert(_position,1, static_cast<char>(key));
        _text[_line].erase(_position+1, 1);
        _position++;
    break;
    }

    _text[_line].insert(_position,1, kursor);
}

void Notes::Print_menu()const{
    std::cout << "[Ctr + C] - exit,  [Ctr + S] - save, [Ctr + D] - Clear all" <<std::endl;
}

void Notes::Save(){
    std::ofstream File("../../" + _file_name);
    if(!File.good()){
        return;
    }
    for(const std::string line: _text){
        File << line << std::endl;
    }
}



