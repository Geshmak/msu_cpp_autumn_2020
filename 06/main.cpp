#include <iostream>
#include "format.hpp"
#include <string.h>
#include <vector>

#include "format.hpp"
using namespace std;


void UTAll(int& flag){
    string test = "-23emptys   6.5 5a5";
    if (test != format("{3}empty{4}   {2} {1}{0}{1}", "a", 5 ,6.5, -23,'s')){
        flag = 1;
        cout<<"UTAll fail"<<endl;
    }
    else cout<<"UTAll Succes"<<endl;
}

void UTNothing(int& flag){
    string test = "nothing";
    if (test != format("nothing")){
        flag = 1;
        cout<<"UTNothing fail"<<endl;
    }
    else cout<<"UTNothing Succes"<<endl;
}

void UTOne(int& flag){
    string test = "test|blank|testtesttestone";
    if (test != format("{0}|blank|{0}{0}{0}one","test")){
        flag = 1;
        cout<<"UTOne fail"<<endl;
    }
    else cout<<"UTOne Succes"<<endl;
}


int main(){

    try{
        int flag = 0;
        UTAll(flag);
        UTNothing(flag);
        UTOne(flag);
        if (!flag){
            cout<<"+++++Nice+++++"<<endl;
        }
    }
    catch(const char *a){
        cout<<a<<endl;
    }
}//