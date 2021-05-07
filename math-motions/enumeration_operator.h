#ifndef ENUMERATION_OPERATOR_H
#define ENUMERATION_OPERATOR_H
#include<stdlib.h>
#include<stdio.h>
template<typename T>
struct Enum_array
{   int index;
    T data;
};
struct oper
{

template<typename T>
T sum(T a,T b)
{
    T c=a+b;
    return c;
}
template<typename T>
T prod(T a,T b)
{
    T c=a*b;
    return c;
}

template<typename T>
T div(T a,T b)
{
    T c=a/b;
    return c;
}


int mod(int a,int b)
{
    int c=a/b;
    return c;
}



template<typename T>
T xors(T a,T b)
{
    T c=a^b;
    return c;
}



template<typename T>
Enum_array<T> xors(Enum_array<T> a,Enum_array<T> b)
{
    T c=a.data^b.data;
    return c;
}







   template<typename T>
T diff(T a,T b)
{
    T c=a-b;
    return c;
}

template<typename T>
T andt(T a,T b)
{
    T c=a&b;
    return c;
}








template<typename T>
T ort(T a,T b)
{
    T c=a|b;
    return c;
}


template<typename T>
T nott(T a)
{
    T c=~a;
    return c;
}


template<typename T>
T sr(T a,T b)
{
    T c=a>>b;
    return c;
}
template<typename T>
T sl(T a,T b)
{
    T c=a<<b;
    return c;
}







}op;






















template<typename T>
Enum_array<T>* enumerate(T* a,int n)
{
    Enum_array<T>* nE=(Enum_array<T>*)malloc(sizeof(Enum_array<T>)*(n+1));

    for(int i=1;i<=n;i++)
    { nE[i-1].data=a[i-1];
      nE[i-1].index=i;
    }
    return nE;

}
int** enumerate(int* a,int n)
{
    int** nm=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<=n;i++)
        nm[i]=(int*)malloc(sizeof(int)*3);

        for(int i=1;i<=n;i++)
    {nm[i][1]=i;
      nm[i][2]=a[i-1];
    }
        return nm;

}

template<typename T>
int printf(const char*,Enum_array<int> a)
{

    printf("(%d,%d)\n",a.index,a.data);
}


template<typename T>
int printf(const char*,Enum_array<T> a)
{

    printf("(%d,%f)\n",a.index,a.data);
}

int printf(const char*,Enum_array<char*> a)
{

    printf("(%d,%s)\n",a.index,a.data);
}

int printf(const char*,Enum_array<char> a)
{

    printf("(%d,%c)\n",a.index,a.data);
}

template<typename T>
int printf(const char*,Enum_array<T>* a,int n)
{

   for(int i=0;i<n;i++)
    printf("Enum",a[i]);
}

template<typename T,typename P>
 T reduce_python(Enum_array<T>* a,int n,P fun,int sp=0)
{
    T d=a[sp].data;
   for(int i=sp+1;i<n+sp;i++)
     P(d,a[i].data);
  return d;
}











#endif // ENUMERATION{_OPERATOR_H
