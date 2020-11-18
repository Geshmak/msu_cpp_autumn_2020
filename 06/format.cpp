#include <iostream>
#include "format.hpp"
#include <string.h>
#include <vector>

using namespace std;

Error::Error(string ms, int pl){
    message = ms;
    place = pl;
}
void Error::Show(){
    cout<<message<<"  ("<<place<<")  "<<endl;
}

string AuxFormat(const string line, vector<string> &var){
    string res = "";
    for (int i = 0; line[i] != '\0'; i++){
        if (line[i] == '{'){
            if (line[++i] == '}'){
                throw Error("mistake empty {}", i);
            }
            int index = 0;
            while(line[i] != '}'){
                if (isdigit(line[i])){
                    index = 10 * index + line[i++] - '0';
                }
                else
                    throw Error("mistake not digit", i);
            }
            
            if (index >= var.size()){
                throw Error("mistake out of range", i);
            }
            //cout<<var[index]<<endl;
            res += var[index];
        }
        else if (line[i] == '}')
            throw Error("mistake expected {", 1);
        else
            res += line[i];
    }
    return res;
}

