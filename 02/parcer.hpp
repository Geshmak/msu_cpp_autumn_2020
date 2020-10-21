#ifndef Parcer_H
#define Parcer_H
#include <iostream>
#include <string>
#include <functional>
using namespace std;


namespace mypars{
using typestart = function<string()>;
using typedigit = function<string (int)>;
using typestrin = function<string (const string&)>;



    class TokenParser{
            private:
                char c;
                unsigned int i;
                int flag;
                
                typestart start;
                typedigit digit;
                typestrin strin;
                
            public:
                void Get(string &st);
                TokenParser();
                void SetStartCallback(const typestart &newstart );
                void SetDigitTokenCallback(const typedigit &newdigit);
                void SetStringTokenCallback(const typestrin &newstrin);
                string Parse(string &st);           
        };
}

#endif