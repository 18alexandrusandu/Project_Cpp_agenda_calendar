#ifndef ARIA UNUI POLIGON_H
#define ARIA UNUI POLIGON_H
#include<iostream>
using namespace std;
///P este o lista de puncte in ordinea in care formeaza figura
template<typename T>
float Aria(T P,int n)
{


   float sa=0;
   for(int i=1;i<n;i++)
        {

           sa+=P[i].x*P[i+1].y-P[i].y*P[i+1].x;

        }
sa+=P[n].x*P[1].y-P[1].x*P[n].y;

return sa/2;

}

///pentru Llist
template<typename T>
float Aria(T P)
{

   float sa=0;
   for(int i=1;i<P.nr;i++)
        {


           sa+=P[i].x*P[i+1].y-P[i].y*P[i+1].x;
        }
sa+=P[P.nr].x*P[1].y-P[1].x*P[P.nr].y;

return sa/2;

}

///pentru Llist


float Aria(float x1,float y1,float x2,float y2)
{
   float sa=(x1*y2-x2*y1)/2;
   return sa;
}

///eroare 1
float Aria(float x1,float y1,float x2)
{
  return 0;
}

///eroare 2
float Aria(float x1,float y1)
{
  return 0;
}

///eroare 3
float Aria(float x1)
{
  return 0;
}

///eroare 4
float Aria()
{
  return 0;
}

template<typename... T>
float Aria(float x1,float y1,float x2,float y2,T... v)
{
   float sa=(x1*y2-x2*y1)/2;
   return sa+Aria(v...);

}






#endif // ARIA UNUI POLIGON_H
