#pragma once
#include <iostream>
using namespace std;

class CircularInt
{
    int _start, _end;
    int _curr;// the current number

    public:
    CircularInt(int s, int e);
    //copy constructor
    CircularInt(const CircularInt& other);

    CircularInt& operator+=(const int number);
    CircularInt& operator*=(const int number);
    CircularInt& operator/=(const int number);
    CircularInt& operator-=(const int number);
    CircularInt& operator++(int);
    CircularInt& operator--(int);

    CircularInt& operator%=(int number);
    void operator==(int number);
    

    friend CircularInt operator-(const int num, const CircularInt& c);
    friend CircularInt operator-(const CircularInt& c, const int num);
    friend CircularInt operator-(const CircularInt& c);
    friend CircularInt operator/(const CircularInt& c, const int num);
    friend CircularInt operator+(const CircularInt& c,const int num);
    friend CircularInt operator+(const CircularInt &c1,const CircularInt &c2);
    friend CircularInt operator*(CircularInt const &c1,CircularInt const &c2);
    friend CircularInt operator*(CircularInt const &c1, const int num);
    friend ostream& operator<<(ostream& os, const CircularInt& c);
};

inline CircularInt operator/(const CircularInt& c, const int num)
{
    CircularInt temp{c};
    temp/=num;
    return temp;
}
inline CircularInt operator-(const CircularInt& c, const int num)
{
    CircularInt temp {c};
    temp-=num;
    return temp;
}
 
inline CircularInt operator-(const int num, const CircularInt& c)
{
    return -(c-num);
}

inline CircularInt operator+(const CircularInt& c,const int num)
{
    CircularInt temp(c);
    temp+=num;
    return temp;
}

 inline CircularInt operator+(const CircularInt &c1,const CircularInt &c2)
{
   return c1+c2._curr;
}

inline ostream& operator<<(ostream& os,const CircularInt& c)
{
    os << c._curr;
    return os;
}

inline CircularInt operator-(const CircularInt& c)
{
    CircularInt temp {c};
    temp._curr = temp._end-temp._curr;
    return temp;
}

inline CircularInt operator*(CircularInt const& c1,const int num)
{
    CircularInt temp {c1};
    temp*=num;
    return temp;
}

inline CircularInt operator*(CircularInt const& c1,CircularInt const &c2)
{
    return c1*c2._curr;
}