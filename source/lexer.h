#pragma once
#include <vector>
#include <string>

enum token_type {
    UNKNOWN,
    NUMBER,
    STRING,
    ADD,
    SUB,
    MUL,
    DIV,
    ASSIGNMENT,
    L_PAREN,
    R_PAREN,
};

class token {
public:
    std::string value;
    token_type type;
};

class lexer
{
private:
    char *current_char;
public:
    std::vector<token> tokens;
    lexer(char *content);
};
