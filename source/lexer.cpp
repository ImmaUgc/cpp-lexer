#include "lexer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

lexer::lexer(char *content) {
    current_char = content;

    while(current_char) {
        if(*current_char == '\0') break;

        while(isspace(*current_char)) ++current_char;

        token current_token;
        current_token.value = *current_char;
        current_token.type = UNKNOWN;

        /* Number */
        if(isdigit(*current_char)) {
            current_token.value = "";
            current_token.type = NUMBER;

            while(isdigit(*current_char)) {
                current_token.value += *current_char;
                ++current_char;
            }
        }
        /* String */
        else if(*current_char == '"') {
            current_token.value = "";
            current_token.type = STRING;

            ++current_char;

            while(*current_char != '"' && *current_char != '\n') {
                current_token.value += *current_char;
                ++current_char;
            }

            ++current_char;
        }
        /* Single-character */
        else {
            switch(*current_char) {
                case '+':
                    current_token.type = ADD;
                    ++current_char;
                    break;
                case '-':
                    current_token.type = SUB;
                    ++current_char;
                    break;
                case '*':
                    current_token.type = MUL;
                    ++current_char;
                    break;
                case '/':
                    current_token.type = DIV;
                    ++current_char;
                    break;
                case '(':
                    current_token.type = L_PAREN;
                    ++current_char;
                    break;
                case ')':
                    current_token.type = R_PAREN;
                    ++current_char;
                    break;
            }
        }

        if(current_token.type != UNKNOWN) tokens.push_back(current_token);
    }
}