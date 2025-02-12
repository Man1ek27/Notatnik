#include <iostream>
#include "include/Notes.hpp"

int main(int argc, char* argv[]){
    
    if(argc >1){
        Notes file(argv[1]);
        std::cout << "File: " << argv[1] << std::endl;
        // file.Print();
    }
}