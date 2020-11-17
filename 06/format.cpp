#include <iostream>
#include "format.hpp"
#include <string.h>
#include <vector>

using namespace std;

string AuxFormat(const char *line, vector<string> &var){
    string res = "";
    for (int i = 0; line[i] != '\0'; i++){
        if (line[i] == '{'){
            if (line[++i] == '}'){
                throw "mistake empty {}";
            }
            int index = 0;
            while(line[i] != '}'){
                if (isdigit(line[i])){
                    index = 10 * index + line[i++] - '0';
                }
                else
                    throw "mistake not digit";
            }
            
            if (index >= var.size()){
                throw "mistake out of range";
            }
            //cout<<var[index]<<endl;
            res += var[index];
        }
        else if (line[i] == '}')
            throw "mistake expected {";
        else
            res += line[i];
    }
    return res;
}