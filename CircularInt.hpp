#pragma once
#include <iostream>
using namespace std;

class CircularInt
{
    int _start, _end;
    int _curr;// the current number

    public:
    CircularInt(int s, int e);
    CircularInt()  :  _start(0),_end(0),_curr(0) {}
    //copy constructor
    CircularInt(const CircularInt& other);
    void setStart(int s) {_start=s;}
    void setEnd(int e)   {_end=e;}
    void setCurr(int c)  {_curr=c;}

    CircularInt& operator+=(const int number);
    CircularInt& operator+=(const CircularInt& c);
    CircularInt& operator*=(const int number);
    CircularInt& operator*=(const CircularInt& c);
    CircularInt& operator/=(const int number);
    CircularInt& operator-=(const int number);
    CircularInt& operator-=(const CircularInt& c);
    CircularInt& operator=(const int number);
    CircularInt& operator++(int);
    CircularInt& operator--(int);
    
    friend bool operator>(const CircularInt& c, int number);
    friend bool operator>(int number,const CircularInt& c);
    friend bool operator>(const CircularInt& c1,const CircularInt& c2);    
    friend bool operator<(const CircularInt& c, int number);
    friend bool operator<(int number,const CircularInt& c);
    friend bool operator<(const CircularInt& c1,const CircularInt& c2); 
    friend bool operator>=(const CircularInt& c, int number);
    friend bool operator>=(int number,const CircularInt& c);
    friend bool operator>=(const CircularInt& c1,const CircularInt& c2); 
    friend bool operator<=(const CircularInt& c, int number);
    friend bool operator<=(int number,const CircularInt& c);
    friend bool operator<=(const CircularInt& c1,const CircularInt& c2); 
    friend bool operator==(const CircularInt& c, int number);
    friend bool operator==(int number,const CircularInt& c);
    friend bool operator==(const CircularInt& c1,const CircularInt& c2);
    friend bool operator!=(const CircularInt& c, int number);
    friend bool operator!=(int number,const CircularInt& c);
    friend bool operator!=(const CircularInt& c1,const CircularInt& c2);
    friend CircularInt operator/(const CircularInt& c, const int num);
    friend CircularInt operator/(const int num,const CircularInt& c);
    friend CircularInt operator/(const CircularInt& c1, const CircularInt& c2);
    friend CircularInt operator-(const int num, const CircularInt& c);
    friend CircularInt operator-(const CircularInt& c, const int num);
    friend CircularInt operator-(const CircularInt& c1, const CircularInt& c2);
    friend CircularInt operator-(const CircularInt& c);
    friend CircularInt operator+(const CircularInt& c,const int num);
    friend CircularInt operator+(const CircularInt &c1,const CircularInt &c2);
    friend CircularInt operator+ (const int num, const CircularInt& c);
    friend CircularInt operator*(CircularInt const &c1,CircularInt const &c2);
    friend CircularInt operator*(CircularInt const &c1, const int num);
    friend CircularInt operator*(const int num,const CircularInt& c);
    friend ostream& operator<<(ostream& os, const CircularInt& c);
    friend istream& operator>>(istream& is,const CircularInt& c);
    
};

inline CircularInt operator/(const CircularInt& c, const int num)
{
    CircularInt temp{c};
    temp/=num;
    return temp;
}

inline CircularInt operator/(const CircularInt& c1, const CircularInt& c2)
{
    CircularInt temp {c1};
    temp /= c2._curr;
    return temp;
}

inline CircularInt operator/(const int num,const CircularInt& c)
{
    CircularInt temp{c};
    temp /= c._curr;
    return temp;
}

inline CircularInt operator-(const CircularInt& c, const int num)
{
    CircularInt temp {c};
    temp-=num;
    return temp;
}

inline CircularInt operator-(const CircularInt& c1, const CircularInt& c2)
{
    return c1-c2._curr;
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

inline CircularInt operator+ (const int num, const CircularInt& c)
{
    return c + num;
}

inline ostream& operator<<(ostream& os,const CircularInt& c)
{
    os << c._curr;
    return os;
}

inline istream& operator>> (istream& is, CircularInt& c)  
{  
    int num;
    is>>num;
    c=num; 
    return is;  
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

inline CircularInt operator* (const int num,const CircularInt& c)
{
    return c * num;
}

inline bool operator==(const CircularInt& c, int number)
{
    return c._curr == number;
}

inline bool operator==(int number,const CircularInt& c)
{
    return number == c._curr;
}

inline bool operator==(const CircularInt& c1,const CircularInt& c2)
{
    return c1==c2._curr;
}

inline bool operator!=(const CircularInt& c, int number)
{
    return c._curr != number;
}

inline bool operator!=(int number,const CircularInt& c)
{
    return number != c._curr;
}

inline bool operator!=(const CircularInt& c1,const CircularInt& c2)
{
    return c1!=c2._curr;
}

inline bool operator>(const CircularInt& c, int number)
{
    return c._curr>number;
}

inline bool operator>(int number,const CircularInt& c)
{
    return number>c._curr;
}   

inline bool operator>(const CircularInt& c1,const CircularInt& c2)
{
    return c1>c2._curr;
}
inline bool operator<(const CircularInt& c, int number)
{
    return c._curr<number;
}

inline bool operator<(int number,const CircularInt& c)
{
    return number<c._curr;
}

inline bool operator<(const CircularInt& c1,const CircularInt& c2)
{
    return c1<c2._curr;
}

inline bool operator>=(const CircularInt& c, int number)
{
       return c._curr>=number;
}

inline bool operator>=(int number,const CircularInt& c)
{
    return number>=c._curr;
}
inline bool operator>=(const CircularInt& c1,const CircularInt& c2)
{
    return c1>=c2._curr;
}

inline bool operator<=(const CircularInt& c, int number)
{
    return c._curr<=number;
}

inline bool operator<=(int number,const CircularInt& c)
{
    return number<=c._curr;
}

inline bool operator<=(const CircularInt& c1,const CircularInt& c2)
{
    return c1<=c2._curr;
}

