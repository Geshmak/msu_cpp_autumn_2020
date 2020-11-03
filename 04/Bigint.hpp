#ifndef BIGINT_H
#define BIGINT_H

using namespace std;
class Bigint{
    private:
        int* Number;
        int Size;
    public:
        //Bigint();
        Bigint(const string& str  = "0", int sizenum = 0);
        Bigint(const Bigint& copy);
        Bigint(Bigint&& other);
        Bigint(int num);
        ~Bigint();
        Bigint& operator=(const Bigint& num);
        Bigint& operator=(Bigint&& num);

        bool operator==(const string& str) const;

        Bigint operator+(const Bigint& num) const;
        Bigint operator-(const Bigint& num) const;
        Bigint operator-() const;
        Bigint operator*(const Bigint& num) const;
        bool operator==(const Bigint& num) const;
        bool operator!=(const Bigint& num) const;
        bool operator>(const Bigint& num) const;
        bool operator<(const Bigint& num) const;
        bool operator>=(const Bigint& num) const;
        bool operator<=(const Bigint& num) const;
        friend ostream& operator<<(ostream& Out,const Bigint& num);
};























#endif