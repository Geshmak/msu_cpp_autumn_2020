#ifndef Matrix_H
#define Matrix_H
using namespace std;

class Proxy{
    private:
        int Length;
        int* OneRow;
    public:
        Proxy(int* OneRowNew,int LengthNum);

        int &operator[](int ColNum);
        const int &operator[](int ColNum) const;
};



class Matrix{
    private:
        int Row;
        int Col;
        int** Matr;
    public:
        Matrix(int RowNum = 5, int ColNum = 5);
        Matrix(const Matrix& copy);
        ~Matrix();

        Proxy operator[](int RowNum);
        const Proxy operator[](int RowNum) const;

        int GetRow() const;
        int GetCol() const;

        Matrix& operator=(const Matrix &matrix);
        Matrix& operator*=(int Number);
        Matrix operator+(const Matrix& matrix);
        bool operator==(const Matrix& matrix) const;
        bool operator!=(const Matrix& matrix) const;

        friend ostream& operator<<(ostream& Out,const Matrix& matrix);
};























#endif
