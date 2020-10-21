#include <iostream>
#include <stdio.h>
#include <string>

#include "parcer.hpp"
using namespace mypars;


std::string functionStart(){
    return "START---->";
}

std::string functionNum(int num){
    return "[D]" + to_string(num) + " ";
}
std::string functionString(std::string line){
    return "[S]" + line + " ";
}
void UnitTestAll(int &flag){
    TokenParser test;
    test.SetStartCallback(functionStart);
    test.SetDigitTokenCallback(functionNum);
    test.SetStringTokenCallback(functionString);
    std::string a = "\n I \n\t l7i7k7e my 123      229 tests";
    if (test.Parse(a) == "START---->[S]I [S]l7i7k7e [S]my [D]123 [D]229 [S]tests ")
        std::cout<<"Succes UTAll"<<std::endl;
    else{
        std::cout<<"[FAILURE] UTAll"<<std::endl;
        flag = 0;
    }
}

void UnitTestNoCall(int &flag){
    TokenParser test;
    
    std::string a = "\n I \n\t l7i7k7e my 123    sst s eree\nrerer  229 tests";
    if (test.Parse(a) == "")
        std::cout<<"Succes UTNCall"<<std::endl;
    else{ 
        std::cout<<"[FAILURE] UTNCall"<<std::endl;
        flag = 0;
    }
}

void UnitTestNoStart(int &flag){
    TokenParser test;
    
    test.SetDigitTokenCallback(functionNum);
    test.SetStringTokenCallback(functionString);
    std::string a = "\n I \n\t l 3\ny my 123      229 tests";
    if (test.Parse(a) == "[S]I [S]l [D]3 [S]y [S]my [D]123 [D]229 [S]tests ")
        std::cout<<"Succes UTNStart"<<std::endl;
    else{
        std::cout<<"[FAILURE] UTNStart"<<std::endl;
        flag = 0;
    }
}

void UnitTestNoDigit(int &flag){
    TokenParser test;
    test.SetStartCallback(functionStart);
    
    test.SetStringTokenCallback(functionString);
    std::string a = "\n I \n\t l 3\ny my 123      229 tests";
    if (test.Parse(a) == "START---->[S]I [S]l [S]y [S]my [S]tests ")
        std::cout<<"Succes UTNDigit"<<std::endl;
    else{
        std::cout<<"[FAILURE] UTNDigit"<<std::endl;
        flag = 0;
    }
}

void UnitTestNoString(int &flag){
    TokenParser test;
    test.SetStartCallback(functionStart);
    test.SetDigitTokenCallback(functionNum);
    
    std::string a = "\n I \n\t l7i7k7e my 123      229 tests";
    if (test.Parse(a) == "START---->[D]123 [D]229 ")
        std::cout<<"Succes UTNString"<<std::endl;
    else{
        std::cout<<"[FAILURE] UTNString"<<std::endl;
        flag = 0;
    }
}

//std::cout<<test.Parse(a)<<std::endl;
int main(){
    int flag = 1;
    UnitTestAll(flag);
    UnitTestNoCall(flag);
    UnitTestNoStart(flag);
    UnitTestNoDigit(flag);
    UnitTestNoString(flag);
    if (flag){
        std::cout<<std::endl<<"All tests succesful"<<std::endl;
    } 
    return 0;
}
