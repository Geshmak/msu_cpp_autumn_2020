#ifndef FORMAT_H
#define FORMAT_H
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

class Error{
    private:
        string message;
        int place;
    public:
        Error(string ms,int pl);
        void Show();
};

string AuxFormat(const string line, vector<string> &var);

template<class T>
string AuxFormat(const string line, vector <string> &var, T &&arg) {
    //var.push_back(to_string(arg));
    stringstream temp;
    temp << arg;
    var.push_back(temp.str()  );
    return AuxFormat(line, var);
}

template<class T, class... Args>
string AuxFormat(const string line, vector <string> &var, T &&arg, Args &&... args) {
    //var.push_back(to_string(arg));
    stringstream temp;
    temp << arg;
    var.push_back(temp.str());
    return AuxFormat(line, var, forward<Args>(args)...);
}

template<class... Args>
string format(const string line, Args &&... args) {
    vector <string> var;
    return AuxFormat(line, var, forward<Args>(args)...);
}


#endif



