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
    for(int i=_start;i<=_end;i++){
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

CircularInt& CircularInt::operator++(int)
{
    return *this+=1;
}

CircularInt& CircularInt::operator--(int)
{
    return *this-=1;
}

 CircularInt& CircularInt::operator*=(CircularInt const &c)
 {
     *this*=c._curr;
     return *this;
 }

 CircularInt& CircularInt::operator-=(const CircularInt& c)
 {
     *this-=c._curr;
     return *this;
 }
    
  CircularInt& CircularInt::operator=(const int number)
  { 
      _curr = number;
      int diff = _start-_end+1;
      if(number<_start){
          while(!(number>=_start && number<=_end))
          {
              *this+=diff;
          }
      }
      else if(number>_end){
          while(!(number>=_start && number<=_end))
          {
              *this-=diff;
          }
      }
      return *this;
  }

CircularInt& CircularInt::operator+=(const CircularInt& c)
{
    return *this+=c._curr;
}
