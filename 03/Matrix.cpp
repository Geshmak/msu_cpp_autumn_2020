#include <iostream>
#include "Matrix.hpp"

using namespace std;


Matrix::Matrix(int RowNum ,int ColNum){
    Row = RowNum;
    Col = ColNum;
    Matr = new int*[Row];
    for (int i = 0; i < Row; i++){
        Matr[i] = new int[Col];
    }
}
Proxy Matrix::operator[](int RowNum){
    if (Row <= RowNum) {
        throw out_of_range("matrix1");
    }
    return Proxy(Matr[RowNum], Col);
}
const Proxy Matrix::operator[](int RowNum) const{
    if (Row <= RowNum) {
        throw out_of_range("matrix2");
    }
    return Proxy(Matr[RowNum], Col);
}
Matrix::~Matrix(){
    for (int i = 0; i < Row; i++){
       
        delete[] Matr[i];
    }  
    
    delete[] Matr;
    
}
int Matrix::GetCol() const{
    return Col;
}
int Matrix::GetRow() const{
    return Row;
}

Matrix& Matrix::operator*=(int Number){
    for (int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            Matr[i][j] *= Number;
        }
    }
    return *this;
}
ostream& operator<<(ostream& Out,const Matrix& matrix){
    for (int i = 0; i < matrix.Row; i++){
        for (int j = 0; j < matrix.Col; j++){
            Out << matrix[i][j] << " ";
        }
        Out << endl;
        
    }
    
    return Out;
}
Matrix Matrix::operator+(const Matrix& matrix){
    if ((Row != matrix.Row)||(Col != matrix.Col)){
        throw "wrong sizes summ";
    }
    Matrix NewMatrix = Matrix(Row, Col);
    for (int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            NewMatrix[i][j] = Matr[i][j] + matrix[i][j];
        }
    }
    return NewMatrix;
    
    
}

Matrix& Matrix::operator=(const Matrix &matrix){
    for (int i = 0; i < Row; i++){
        delete[] Matr[i];
    }  
    delete[] Matr;

    Col = matrix.Col;
    Row = matrix.Row;

    Matr = new int*[Row];
    for (int i = 0; i < Row; i++){
        Matr[i] = new int[Col];
    }
    for (int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            Matr[i][j] = matrix[i][j];
        }
    }
    return *this;
}

Matrix::Matrix(const Matrix& copy){
    Col = copy.Col;
    Row = copy.Row;
    Matr = new int*[Row];
    for (int i = 0; i < Row; i++){
        Matr[i] = new int[Col];
    }
    for (int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            Matr[i][j] = copy[i][j];
        }
    }
}
bool Matrix::operator==(const Matrix& matrix) const{
    if ((matrix.Row != Row) || (matrix.Col != Col))
        return false;
    
    for (int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            if (Matr[i][j] != matrix[i][j])
                return false;
        }
    }
    
    return true;
}
bool Matrix::operator!=(const Matrix& matrix) const{
    bool result = !(matrix == *this);
    return result;
}




Proxy::Proxy(int* OneRowNew,int LengthNum){
    OneRow = OneRowNew;
    Length = LengthNum;
}
int& Proxy::operator[](int ColNum){
    if (Length <= ColNum) {
        throw out_of_range("proxy1");
    }
    int& Result = OneRow[ColNum];
    return Result;
}
const int& Proxy::operator[](int ColNum) const{
    if (Length <= ColNum) {
        throw out_of_range("proxy2");
    }
    int& Result = OneRow[ColNum];
    return Result;
}
