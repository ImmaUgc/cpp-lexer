#include "lexer.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

int main(int argc, char** argv) {
    std::ifstream file("example.txt");

    if(!file.is_open()) {
        std::cerr << "Cannot open the file.";
        return 1;
    }

    std::string content;

    while(std::getline(file, content));

    char *entry = new char[content.length() + 1];
    strcpy(entry, content.c_str());

    lexer Lexer(entry);

    for(token token_data : Lexer.tokens) {
        std::cout << "Value: " << token_data.value << "\nType: " << token_data.type << '\n';
    }

    delete entry;

    return 0;
}