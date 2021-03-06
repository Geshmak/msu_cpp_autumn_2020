#include <iostream>
#include <stdio.h>
#include <string>
#include "parcer.hpp"

using namespace mypars;


void TokenParser::Get(const string &str){
    c=str[i++];
}
TokenParser::TokenParser(){
    c = ' ';
    i = 0;
    flag = 1;
    start = nullptr;
    digit = nullptr;
    strin = nullptr;
}
string TokenParser::Parse(const string &str){
    std::string res = "";
    std::string buf = "";
    i = 0;
    if (start != nullptr){
        res += start();
    }
    Get(str);
    
    while (i <= str.length()){
        flag = 1;
        buf = "";
        while(isspace(c)){
            Get(str);
            if (i > str.length()) break;
        }
        while(!isspace(c)){
            if (!isdigit(c))
                flag = 0;
            buf += c;
            Get(str);
            if (i > str.length()) break;
        }
        if (flag){
            if (digit != nullptr){
                res += digit(stoi(buf));
            }
        }
        else{
            if (strin != nullptr){
                res += strin(buf);
            }
        }
    }
    return res;
}
void TokenParser::SetStartCallback(const typestart &newstart ){
    start = newstart;
}
void TokenParser::SetDigitTokenCallback(const typedigit &newdigit){
    digit = newdigit;
}
void TokenParser::SetStringTokenCallback(const typestrin &newstrin){
    strin = newstrin;
}
