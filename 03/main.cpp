
#include <iostream>
#include <string.h>
#include "Matrix.hpp"
using namespace std;
void UnitTestDefault(int &flag){
    const size_t rows = 7;
    const size_t cols = 3;

    Matrix m(rows, cols);

    if ((m.GetRow() != 7) || (m.GetCol() != 3))
        flag = 1;

    m[1][2] = 5; // строка 1, колонка 2
    if (m[1][2] != 5)
        flag = 2;
    

    m *= 3; // умножение на число
    if (m[1][2] != 5*3)
        flag = 3;
    

    Matrix m1(rows, cols);

    if (m1 == m){
        flag = 4;
    }
    if (m != m){
        flag = 5;
    }
    Matrix m2 = m1 + m;
    cout << m2 << endl;
}


int main(){
    try{
        int flag = 0;
        UnitTestDefault(flag);
        if (flag == 0){
            cout<<"UTDef Succes"<<endl;
        }
        else{
            cout<<"fail № "<<flag<<endl;
        }  
    }
    catch(out_of_range a){
        cout<<a.what()<<endl;
    }
    catch(const char* error){
        cout<<error<<endl;
    }
    return 0;
}