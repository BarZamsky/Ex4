#include <iostream>
#include <string>
#include "CircularInt.hpp"

using namespace std;

CircularInt::CircularInt(int s, int e):_start(s),_end(e),_curr(s){}
CircularInt::CircularInt(const CircularInt& other):_start(other._start),_end(other._end),_curr(other._curr){}

CircularInt& CircularInt::operator+=(const int number) 
{
   int dis = _end-_start +1;
   _curr = ((_curr-_start)+(number%dis))%dis+_start; 
   return *this;
}

CircularInt& CircularInt::operator-=(const int number)
{
    int dis = _end-_start +1;
   _curr = ((_curr-_end)-(number%dis))%dis+_end; 
    return *this;
}

CircularInt& CircularInt::operator*=(const int number)
{
    for(int i=1; i<number;i++)
    {
        *this+=_curr;
    }
    return *this;
}

CircularInt& CircularInt::operator/=(const int number)
{
    CircularInt temp(_start,_end);
    for(int i=_start;i<_end;i++){
        temp._curr = i;
        temp*=number;
        if(_curr==temp._curr){
        _curr=i;
        return *this;
        }
    }
    string s = "There is no number x in {"+std::to_string(_start)+","+std::to_string(_end)+"} such that x*"+std::to_string(number)+"="+std::to_string(_curr);
    throw s;
}

void CircularInt::operator==(int number)
{
    int ans = 0;
    if (_curr == number) ans = 1;
    if(ans == 1) cout << "The number and the hour are equals!"<< endl;
    else  cout << "The number and the hour are not equals!"<< endl;
}

CircularInt& CircularInt::operator++(int)
{
    return *this+=1;
}

CircularInt& CircularInt::operator--(int)
{
    return *this-=1;
}



