#include <iostream>

#include "Bigint.hpp"
using namespace std;


void UTDef(int& flag){
    Bigint a = 1;
    Bigint b("123456789012345678901234567890");
    Bigint c = a * b + 2;
    Bigint d;
    d = std::move(c);
    a = d + b;
    if (!(a == "246913578024691357802469135782")){
        flag = 1;
    }
    return;
}
void UTDif(int& flag){
    Bigint test1("-12345670000012345");
    Bigint test2("-7654321");
    Bigint res = test1 - test2;
    if (!(res == "-12345669992358024")){
        flag = 2;
        
    }
    return;
}
void UTUnMinus(int& flag){
    Bigint test3("838403");
    Bigint test4("-1243");
    Bigint res1 = -test3;
    Bigint res2 = -test4;
    if (!(res1 == "-838403")){
        flag = 3;  
    }
    if (!(res2 == "1243")){
        flag = 4;  
    }
    return;
}

void UTMinus(int& flag){
    Bigint test5("128399942378");
    Bigint test6("10000777");
    Bigint res = test6 - test5;
    if (!(res == "-128389941601")){
        flag = 5;  
    }
}


void UTMul(int& flag){
    Bigint a("96307395017402837409");
    Bigint b("123456789012345678901234567890");
    Bigint c = a * b;
    if (!(c == "11889801746992133600703433061058453504360042197010")){
        flag = 6;  
    }
}

void UTMulZ(int& flag){
    Bigint a("0");
    Bigint b("123456789012345678901");
    Bigint c = a * b;
    Bigint d = b * a;
    if (!((c == "0") && (d == "0"))){
        flag = 7;  
    }
}

int main(){
    try{


        /**/
        int flag = 0;
        
        UTDef(flag);
        if (flag == 0)
            cout<<"Def Succes"<<endl;
        else
            cout<<"Def Fail"<<endl;
        
        
        UTDif(flag);
        if (flag == 0)
            cout<<"Dif Succes"<<endl;
        else
            cout<<"Dif Fail"<<endl;
        
        
        

        UTUnMinus(flag);
        if (flag == 0)
            cout<<"UnMinus Succes"<<endl;
        else
            cout<<"UnMinus Fail"<<endl;
        

        
        UTMinus(flag);
        if (flag == 0)
            cout<<"Minus Succes"<<endl;
        else
            cout<<"Minus Fail"<<endl;
        if (flag == 0)

        UTMul(flag);
        if (flag == 0)
            cout<<"Mul Succes"<<endl;
        else
            cout<<"Mul Fail"<<endl;

        UTMulZ(flag);
        if (flag == 0)
            cout<<"MulZ Succes"<<endl;
        else
            cout<<"MulZ Fail"<<endl;
        
        if (flag == 0)
            cout<<"++Nice++"<<endl;
        
        
    }
    catch(char* c){
        cout<<c<<endl;
    }
}