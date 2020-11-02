#include <iostream>
#include "Bigint.hpp"

using namespace std;

Bigint::Bigint(string str, int sizenum){
    int negflag = 0;
    if (str[0] == '-'){
        negflag = 1;
        str.erase(0,1);
    }
    for(int i = str.length()-1; i >= 0; i--){
        if (!isdigit(str[i])) 
            throw "Not Number";
    }
    
    if (!sizenum){
        Size = str.length() / 3 ;
        if (str.length() % 3 != 0)
            Size++;
    }
    else   
        Size = sizenum;
    Number = new int[Size];
    
    for(int k = 0; k < Size;k++){
        Number[k] = 0;
    }
    

    int count = 0;
    int mul = 1;
    int j = 0;
    for(int i = str.length()-1; i >= 0; i--){
        Number[j] += (str[i] - '0') * mul;
        mul *= 10;
        
        if (count >= 2){
            mul = 1;
            j++;
            count = -1;
        }
        count++;
    }
    if (negflag)
        Number[Size -1] *= -1;
    
}
Bigint Bigint::operator+(const Bigint& num) const{
    int flag = 0;
    int sz = 0;
    if (Size >= num.Size){
        sz = Size ;
        flag = 1;
    }
    else{
        sz = num.Size;
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
    if (flag){
        for(int i = 0; i < res.Size; i++ ){
            sum = Number[i];
            if (i <= num.Size)
                sum += num.Number[i];
            res.Number[i] = extr + sum % 1000;
            extr = sum / 1000;
        }
    }
    else{
        for(int i = 0; i < res.Size; i++ ){
            sum = num.Number[i];
            if (i <= Size)
                sum += Number[i];
            res.Number[i] = extr + sum % 1000;
            extr = sum / 1000;
        }
    }
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
    if (Size >= num.Size){
        sz = Size * 2;
    }
    else{
        sz = num.Size * 2;
    }

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
    for(int j = 0; j < num.Size; j++){ 
        extr = 0;
        for(int i = 0; i <= Size; i++ ){
            mul = Number[i] * num.Number[j];
            res.Number[i + j] += extr + mul % 1000;
            extr = mul / 1000;
        }
    }
    for(int k = 0; k < res.Size - 1; k++){   
        extr = res.Number[k] / 1000;
        res.Number[k] = res.Number[k] % 1000;
        res.Number[k+1] += extr;
    }
    int i;
    for(i = res.Size - 1; i >= 0; i--){
        if (res.Number[i] != 0)
            break;
    }
    res.Size = i+1;
    return res;
}
Bigint Bigint::operator-(const Bigint& num) const{
    Bigint res = Bigint();
    int extr = 0;
    int diff = 0;
    int k;
     
    if (*this >= num){
        k = 1;
        res.Size = Size;
    }
    else if (*this < num){
        k = -1;
        res.Size = num.Size;
    }
    for(int i = 0; i < res.Size; i++ ){
        diff = k * (Number[i] - num.Number[i]) - extr;
        extr = 0;
        if ((diff < 0) && (i+1 < Size)){
            extr = 1;
        }
        res.Number[i] = diff + extr * 1000;
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
    int count = 0;
    int tmp = num;
    while (tmp > 0){
        tmp /= 1000;
        count++;
    }
    Number = new int[count];
    Size = count;
    for (int i = 0; i < Size; i++){
        Number[i] = num % 1000;
        num /= 1000;
    }

    
}
bool Bigint::operator==(const Bigint& num) const{
    int sz = 0;
    if (Size >= num.Size){
        sz = Size;
    }
    else{
       sz = num.Size; 
    }
    for (int i = sz - 1; i >= 0;i--){
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
    return true;
}

bool Bigint::operator<=(const Bigint& num) const{
    
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
    return true;
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
            while (tmp.length() < 3){
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

    delete[] Number;
    
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

    delete[] Number;

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