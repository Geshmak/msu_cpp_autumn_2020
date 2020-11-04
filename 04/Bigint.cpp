#include <iostream>
#include <string>
#include "Bigint.hpp"

using namespace std;

const int base = 3;
const int basemul = 1000;

Bigint::Bigint(const string& str, int sizenum){
    string linetmp = str; 
    int negflag = 0;
    if (linetmp[0] == '-'){
        negflag = 1;
        linetmp.erase(0,1);
    }
    for(int i = linetmp.length()-1; i >= 0; i--){
        if (!isdigit(linetmp[i])) 
            throw "Not Number";
    }
    if (!sizenum){
        Size = linetmp.length() / base ;
        if (linetmp.length() % base != 0)
            Size++;
    }
    else   
        Size = sizenum;
    Number = new int[Size];
    
    for(int k = 0; k < Size;k++){
        Number[k] = 0;
    }
    int count = 0;
    int mul = 1 ;
    int j = 0;
    for(int i = linetmp.length() - 1; i >= 0; i--){
        Number[j] += (linetmp[i] - '0') * mul;
        mul *= 10;
        if (count >= base - 1){
            mul = 1;
            j++;
            count = -1;
            
            
        }  
        count++;
    }
    if (negflag)
        Number[Size -1] *= -1;
    //cout<<"!"<<endl;
    
}
Bigint Bigint::operator+(const Bigint& num) const{
    int szlow = 0;
    int sz = 0;
    if (Size >= num.Size){
        sz = Size + 1;
        szlow = num.Size;
    }
    else{
        sz = num.Size + 1;
        szlow = Size;
    }  
    Bigint res = Bigint("0",sz);

    if ((Number[Size - 1] > 0) && (num.Number[num.Size - 1] < 0)){
        res = *this-(-num);
        return (res);   
    }
    if ((Number[Size - 1] < 0) && (num.Number[num.Size - 1] > 0)){
        res = num-(-*this);
        return (res);   
    }
    if ((Number[Size - 1] < 0) && (num.Number[num.Size - 1] < 0)){
        res = -num+(-*this);
        return -(res);   
    }
    
    int extr = 0;
    int sum = 0;
    res = *this;

    for(int i = 0; i < szlow; i++ ){
        sum = Number[i] + num.Number[i];
        res.Number[i] = extr + sum % basemul;
        extr = sum / basemul;
    }
    res.Number[szlow] += extr;

    int i;
    for(i = res.Size - 1; i >= 0; i--){
        if (res.Number[i] != 0)
            break;
    }
    res.Size = i+1;
    return res;
}

Bigint Bigint::operator-() const{
    Bigint res = Bigint("0", Size);
    for (int i = 0; i<Size - 1; i++){
        res.Number[i] = Number[i];
    }
    res.Size = Size;
    res.Number[Size - 1] = -Number[Size - 1];
    return res;
}

Bigint Bigint::operator*(const Bigint& num) const{
    int sz = 0;
    
    sz = Size + num.Size + 1;
    Bigint res = Bigint("0",sz);
    if ((Number[Size - 1] < 0) && (num.Number[num.Size - 1] < 0)){
        res = -(*this) * -(num);
        return res;
    }
    if ((Number[Size - 1] < 0)){
        res = -(*this) * num;
        return -res;
    }
    if ((num.Number[num.Size - 1] < 0)){
        res = *this * -(num);
        return -res;
    }
    int extr = 0;
    int mul = 0;
    int i,j;
    //cout<<Size<<"  "<<num.Size<<endl;
    for(j = 0; j < num.Size; j++){ 
        for(i = 0; i < Size; i++ ){
            mul = Number[i] * num.Number[j];
            res.Number[i + j] += extr + mul % basemul;
            extr = mul / basemul;
            
        }
        res.Number[i + j] += extr;
        extr = 0;
          
    } 
    for(int k = 0; k < res.Size - 1; k++){   
        extr = res.Number[k] / basemul;
        res.Number[k] = res.Number[k] % basemul;
        res.Number[k+1] += extr;
    }
    
    for(i = res.Size - 1; i > 0; i--){
        if (res.Number[i] != 0)
            break;
    }
    res.Size = i+1;
    return res;
}
Bigint Bigint::operator-(const Bigint& num) const{
    int sz = 0;
    int k;
    if (*this >= num){
        k = 1;
        sz = Size;
    }
    else if (*this < num){
        k = -1;
        sz = num.Size;
    }

    //cout<<k<<endl;
    Bigint res = Bigint("0",sz);

    if ((Number[Size - 1] < 0) && (num.Number[num.Size - 1] < 0)){
        res = -(num) - -(*this)  ;
        return res;
    }
    if ((Number[Size - 1] < 0)){
        res = -(*this) + num;
        return -res;
    }
    if ((num.Number[num.Size - 1] < 0)){
        res = *this + -(num);
        return res;
    }

    int extr = 0;
    int diff = 0;
    
    for(int i = 0; i < res.Size; i++ ){
        if (k == 1){
            if (i < num.Size){
                diff = (Number[i] - num.Number[i]) - extr;
                extr = 0;
            }
            else{
                diff = Number[i] - extr;
                extr = 0;
            }
            if ((diff < 0) && (i+1 < res.Size)){
                extr = 1;
            }
            res.Number[i] = diff + extr * basemul;
        }
        if (k == -1){
            if (i < Size){
                diff = (num.Number[i] - Number[i]) - extr;
                extr = 0;
            }
            else{
                diff = num.Number[i] - extr;
                extr = 0;
            }
            if ((diff < 0) && (i+1 < res.Size)){
                extr = 1;
            }
            res.Number[i] = diff + extr * basemul;
        }
    }
    int i;
    for(i = res.Size - 1; i > 0; i--){
        if (res.Number[i] != 0)
            break;
    }
    res.Size = i+1;
    res.Number[res.Size - 1] *= k;
    return res;
}
Bigint::Bigint(int num){
    string str = to_string(num);
    *this = Bigint(str);
}

bool Bigint::operator==(const Bigint& num) const{
    if (Size != num.Size){
        return false;
    }
    for (int i = Size - 1; i >= 0; i--){
        
        if (Number[i] != num.Number[i])
            return false;
    }
    return true;
}

bool Bigint::operator==(const string& str) const{
    Bigint comp = Bigint(str);
    bool res = *this == comp ;
    return res;
}

bool Bigint::operator!=(const Bigint& num) const{
    bool res = !(num == *this);
    return res;
}

bool Bigint::operator<(const Bigint& num) const{
    
    if (Size > num.Size){
        return false;
    }
    else if (Size < num.Size){
        return true;
    }
    for (int i = Size - 1; i >= 0;i--){ 
        if (Number[i] < num.Number[i]){
            return true;
        }
        else if (Number[i] > num.Number[i]){
            return false;
        }      
    }
    return false;
}

bool Bigint::operator>(const Bigint& num) const{
    
    if (Size < num.Size){
        return false;
    }
    else if (Size > num.Size){
        return true;
    }
    for (int i = Size - 1; i >= 0;i--){ 
        if (Number[i] > num.Number[i]){
            return true;
        }
        else if (Number[i] < num.Number[i]){
            return false;
        }      
    }
    return false;
}

bool Bigint::operator>=(const Bigint& num) const{
    bool res = !(*this < num);
    return res;
}

bool Bigint::operator<=(const Bigint& num) const{
    bool res = !(*this > num);
    return res;

}
ostream& operator<<(ostream& Out, const Bigint& num){
    
    string res; 
    string tmp;
    int flag = 1, flag2 = 0;
    for(int i = num.Size - 1; i >= 0 ; i--){
        if ((num.Number[i] == 0) && (flag) && (i != 0)){ //убрать незначащие нули
            continue;
        } 
        flag = 0;
        if ((flag2)){// значащие нули
            tmp = to_string(num.Number[i]);
            while (tmp.length() < base){
                tmp ="0" + tmp;
            }
            res += tmp;
        }
        else{
            res += to_string(num.Number[i]);
            flag2 = 1;
        }
    }
    Out << res << endl;
    return Out;
}
Bigint& Bigint::operator=(const Bigint& num){
    
    if (num == *this)
        return *this;
    
    Size = num.Size;
    Number = new int[Size];
    for(int i = 0; i < Size; i++){
        Number[i] = num.Number[i];
    }
    return *this;
    
}
Bigint::Bigint(const Bigint& copy){
    Size = copy.Size;
    Number = new int[Size];
    for(int i = 0; i < Size; i++){
        Number[i] = copy.Number[i];
    }
}
Bigint::Bigint(Bigint&& other){
    Number = other.Number;
    Size = other.Size;
    other.Number = nullptr;
    other.Size = 0; 
}
Bigint& Bigint::operator=(Bigint&& num){ 
    
    if (num == *this)
        return *this;
    //cout<<"!"<<endl;
    Size = num.Size;
    Number = num.Number;
    
    num.Size = 0;
    num.Number = nullptr;
    return *this;
}
Bigint::~Bigint(){
    //cout<<"~!"<<endl;
    delete[] Number;
    
}