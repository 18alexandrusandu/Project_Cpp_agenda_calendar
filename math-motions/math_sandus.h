
#ifndef MATH_SANDUS_H
#define MATH_SANDUS_H
#include<math.h>
#include<iostream>
#include<fstream>
#include<windows.h>
//#include"C:/Users/andercou/Desktop/mysqlheaders/mysql.h"
#include<string.h>
#include<typeinfo>
#include<limits>
#include<typeinfo>
#include"Llist.h"
#include"enumeration_operator.h"
using namespace std;
const long double e=2.718281828;
const long double em=0.5772156649;
const double pi=3.141592;
const double phi=1.618033;
const double Feigenbaum=4.699;
const double alpha_FSC=0.00729927;
const double c_lightspeed=299792458;
const double Planck=6.62607015e-34;
const double Grav_Constant=6.67408e-11;
const double e_charge=1.602176634e-19;
const double avogadro=6.02214076e23;
const double Cs_frequency=9192631770;
const double Boltzmann=1.380648e-23;

 struct prototype ;

template<typename r1,typename T>
void make_el(int i,int j,int n,int m,r1** mat,T a)
{
   mat[i][j]=a;

}


template<typename r1>
void make_el(int i,int j,int n,int m,r1** mat)
{
cout<<"nu e bueno"<<endl;
}

template<typename t1,typename T,typename...arg>
void make_el(int i,int j,int n,int m,t1** mat,T a,arg...r)
{
      if(i<n && j<=m)
      {
          mat[i][j]=a;
      }

      if(i==n && j<m)
      {
          mat[i][j]=a;

      }

     if(i<n)
     {
        if(j<m)
        make_el(i,j+1,n,m,mat,r...);

         if(j==m)
        make_el(i+1,1,n,m,mat,r...);
     }

       if(i==n)
     {
        if(j<m)
        make_el(i,j+1,n,m,mat,r...);
     }


}







template<typename T1,typename T,typename...arg>
T1** make_mat(int n,int m,T a,arg...r)
{
   T1** res;
   res=new T1*[n+5];

   for(int i=0;i<=n;i++)
   res[i]=new T1[m+5];

   make_el(1,1,n,m,res,a,r...);

   return res;

}



struct math_Sandu
{

 template<typename T>
    T absinth(T );

    int abso(int);

    int nr(int n);

    void trans(char [],int,int);

    int tre(char [],int );

    int search_( char [],char []);

    template<typename T>
    bool  includ(T a[],T b,int n) ;

    int dw(double );

    float up ( float );
    template<typename T>
    int ap(T );
    template<typename T>
    float aps(T );
    template<typename T>
    float apss(T f);
    template<typename T>
    float rf(T,int);
    double sigmoid(double x,int y);

    float neg (float);

template<typename T>
    int sign(T);


    template<typename T>
    int removefa(T [],T,int );

    template<typename T>
    int slice( T [],int,int );

    template<typename T>
    int slice(T [],int [],int,int);

    template<typename T>
    int delq(T [],int&);

    template<typename T>
    int pop(T [],int&);

    template<typename T>
    T pop_out(T a[],int& n);
    template<typename T>
    T*  pop_out(T* a[],int& n);

    template<typename T>
    T* pofarr(T a[],int& n);


    template<typename T>
    int push(T[],T,int&);
    template<typename T,typename R>
    int push2(T*,R,int&);


    long double powe(long double,int);
    float lon(float,int);
    float lb(float,float);
   long double expo(double,long);
    template<typename T>
    float sqr(T,float);
    int sqri(float,float);
    float poc(float,int );

    long long int fact (int n);
  long long int subfact (int n);
    int comb(int,int );

    int arg (int,int );







   template<typename T,size_t M>
   void scas2d( T[][M],int ,T dex=0);

    template<typename T>
   int cma(T [],int,T);

    int cm(char [],int,char );

    template<typename T>
    int len(  T [],T );

    template<typename T>
    int len(const T [],T);

    bool comp3(char [],char [],int);

    bool comp2(char[],const char [],int);

    int  comp1(char [],char [],int,char );
    int  comp(char [],char [],int,char );

    template<typename T>
    bool compa (T [],T[],int,T);


    float pi_angle(float n);

   double cosa(double,int);

   double sina(double,int);

    float tana(double);
    float arctan(float,int,float);
//template<size_t M,size_t N>






    template<typename T>
    int  map_scale(T,T,T, T,T [],T);

    template<typename T>
    T map1(T,T,T,T, T,T);


    template<typename T>
    T mparray(T [],T,T,T, T,int,T);


   template<typename T>
    void apvec(T a,int nr)
    {
       for(int i=1;i<=nr;i++)
      {

       a[i].x=ap(a[i].x);
       a[i].y=ap(a[i].y);
       a[i].z=ap(a[i].z);
      }

    }
 template<typename T>
    void apv(T a,int nr)
    {
       for(int i=1;i<=nr;i++)
      {
       a[i]=ap(a[i]);

      }

    }


prototype* a;
struct proto *b;

}Math;

template<typename T>
void switchy(T& a,T& b,void (*f2)(T a,T b)=NULL)
{
   T c;

   if(f2!=NULL)
   {
      f2(c,a);
      f2(a,b);
      f2(b,a);
   }
   else
   {
      c=a;
      a=b;
      b=c;
   }

}




template<typename T>
T math_Sandu ::  absinth (T a)
{

        if(a<0)
         a=a-2*a;

        return a;

}
template<typename T>
T abs2(T a)
{
    if(a<0)
        a=a-2*a;

   return a;

}




template<typename T>
void replacea(T a[],T b,T c,int n)
{

   for(int i=1;i<=n;i++)
   if(a[i]==b)a[i]=c;

}



template <typename T,typename R>
int x_inrange(T k,R b1,R b2)
{
if(k>=min(b1,b2) &&  k<=max(b1,b2))return 1;
return 0;


}











int math_Sandu :: abso (int b)
{

    if(b<0)
        b=b-2*b;
    return b;
}






int math_Sandu::nr(int n)
{
    int  de=0;
    if(n<=0)de=1;

    while(n!=0)
    {
        n=n/10;//cout<<n<<endl;
        de++;
    }

}

void math_Sandu:: trans(char b[30],int a,int d=0)
{
    int x=a,y=a,s=0,n=0;
    if(d==0)
        while(y!=0)
        {
            y=y/10;
            n++
            ;
        }
    if(d==0)b[0]=n;
    if(a<0)
    {
        b[0]++;
        n++;
        s=1;
        b[1]='-';
    }
    while(abso(x)>0 && n>s)
    {
        if(x%10==0)b[n]=48;
        if(x%10!=0)
        {
            b[n]=48+abso(x%10);;
        }
        x=x/10;
        n--;
    }
}
float randf(float mini,float maxi)
{
   return mini+(float)rand()/(RAND_MAX/(maxi-mini));


}
template<typename T>
T randa(T a[],int n)
{

int index=1+rand()%n;

return a[index];

}













int math_Sandu :: tre(char a[],int n)
{
    int o=0;
    int  p=1;
    for(int i=n-2; i>=0; i--)
    {

        cout<<(int)a[i]<<endl;
        o=o+p*((int)a[i]-48);

        p=p*10
          ;

    }


    return o;
}



void cl(int a ,int b,int c)
{
    if(a==b)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
float r,g,b2;

///for global value r , g and b2 choose random values
void pickcolor()
{
   r=randf(0,255);
     g=randf(0,255);
     b2=randf(0,255);

}







template<typename T>
void sca(T a[],int k,int w=1,int tu=1)
{

    for(int u=1;u<=k;u++)
   {

   cout<<a[u];
    if(w==1)
    cout<<" ";
   }
   if(tu==1) cout<<endl;

}


template<typename T>
void scac(T a[],int k,char d=',',int w=1,int tu=1)
{
///w stands for spaces, tu stands for endl
    for(int u=1;u<=k;u++)
   {
   cout<<a[u];
    if(w==1)
    cout<<d;
   }
    if(tu==1)cout<<endl;

}


void sca( char a[],int k,int w=1,int tu=1)
{
///w stands for spaces, tu stands for endl
    for(int u=1;u<=k;u++)
   {
   cout<<a[u];
    if(w==1)
    cout<<" ";
   }
    if(tu==1)cout<<endl;

}



void scar( char a[],int k,int u=1 ,int w=1,int tu=1)
{
    for(;u<=k;u++)
   {
   //cout<<u<<endl;
   cout<<a[u];
    if(w==1)
    cout<<" ";
   }
    if(tu==1)cout<<endl;

}

template<typename T>
void scap( T a[],int k,int u=1 ,int w=1,int tu=1)
{
    for(;u<=k;u++)
   {
   //cout<<u<<endl;
   cout<<a[u];
    if(w==1)
    cout<<" ";
   }
    if(tu==1)cout<<endl;

}



template<typename T>
void scar2d( T** a,int k,int ku,int u=1 ,int w=1,int tuu=1)
{ int tu=1;

   int h=u;
    for(tu=1;tu<=k;tu++)
   {
      u=h;
    for(;u<=ku;u++)
    {
   cout<<a[tu][u];

    if(w==1)
    cout<<" ";
   }
     if(tuu==1)cout<<endl;
   }


}

template<typename T>
void scan2d( T** a,int k,T des ,int u=1 ,int w=1,int tuu=1)

{ int tu=1;
 int h=u;

    for(tu=1;tu<=k;tu++)
   {
   u=h;
   while(a[tu][u]!=des)
    {
   cout<<a[tu][u];
    u++;
    if(w==1)
    cout<<" ";
   }
     if(tuu==1)cout<<endl;
   }


}
template<typename T,size_t M>
void scan2d( T a[][M],int k,T des ,int u=1 ,int w=1,int tuu=1)

{
   int tu=1;

    for(tu=1;tu<=k;tu++)
   {
   u=1;
   while(a[tu][u]!=des)
    {
   cout<<a[tu][u];
    u++;
    if(w==1)
    cout<<" ";
   }
     if(tuu==1)cout<<endl;
   }


}





template<typename T,size_t M>
void math_Sandu::scas2d( T a[][M] ,int k,T des)
{ int tu=1;

    for(tu=1;tu<=k;tu++)
   {
      int u=0;
   do{
      u++;
      cout<<a[tu][u];

   }while(a[tu][u]!=des);
cout<<endl;

}
}


void concat(char a[],char b[],char des,int n,int m)
{

int i=0;
do{

i++;

}
while((a[i]!=des)||(n!=0 && n<=i));

int j=0;

do{

j++;
a[i+j]=b[j];

}while((b[j]!=des||(m!=0 && j<=m)));

}
template<typename T>
T* concata(T* a,T* b,int n,int m)
{
   if(b!=NULL)
   {
   T* p=new T[(m+n)*2];
   for(int i=1;i<=n;i++)
   p[i]=a[i];

    for(int i=n+1;i<=n+m;i++)
   p[i]=b[i-n];
   a=p;
   return p;
   }

}







template<typename T,size_t M>
void sca2d(T a[][M],int n,int m,int u=1)
{ int i,j;
int it=rand()%16*16+3;
cout<<endl;
    for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
        {
          cout<<a[i][j];

       if(u==1) cout<<" ";
        cl(1,1,7);
        }

        cout<<endl;
      }




}


template<typename T>
void sca2d(T** a,int n,int m,int u=1)
{ int i,j;
cout<<endl;

    for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
        {

        cout<<a[i][j];
       if(u==1) cout<<" ";
        //cl(1,1,7);
        }

        cout<<endl;
      }




}
template<typename T>
void sca2dh(T** a,int n,int m,int p,int h ,int u=1)
{ int i,j;
cout<<endl;


    for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
        {
        cl(p,a[i][j],h);
        cout<<a[i][j];
       if(u==1) cout<<" ";
       cl(1,1,7);
        //cl(1,1,7);
        }

        cout<<endl;
      }




}








int math_Sandu:: search_(char ch[],char gh[])
{
    int yu=0;
    string r;
    ifstream ifile;
    ifile.open(gh);

    while(getline(ifile,r,'\n'))
    {
        //cout<<r<<endl;

        for(int i=0; i<=strlen(r.c_str()); i++)
            // cout<<r.c_str()[i]
            ;
        //cout<<endl;
        //cout<<strlen(r.c_str());
        //cout<<strlen(ch);
        //cout<<endl;

        // for(int i=0; i<=strlen(r.c_str())+1; i++)
        //cout<<ch[i];
        //cout<<endl;

        if(strcmp(ch,r.c_str())==0)
        {

            getline(ifile,r,'\n');
            int pop=strlen(r.c_str());

            char to[180];
            for(int e=0; e<=pop+1; e++)
            {
                to[e]=r.c_str()[e];
                // cout<<to[e];
            }

            yu=1;
            cout<<tre(to,pop+1)<<endl;
            return tre(to,pop+1);

            break;
            // cout<<endl;



        }


    }

}

template<typename T>
bool math_Sandu::includ(T a[],T b,int n)
{

for(int i=1;i<=n;i++)
{


    if(b==a[i])
        return true;

}

}









template<typename T>
int math_Sandu::cma(T a[] ,int n,T des)
{ int  i=0;
T g;
cout<<"create vector/string: "<<endl;

  do
    {
       i++;
       cin>>g;
       a[i]=g;



    }
  while((a[i]!=des && n==0) ||(n!=0 && i<n));

a[i+1]=des;

return i;

}

template<typename T>
cman(T a[] ,int n=0,T des=NULL)
{ int  i=0;
T g;


  do
    {
       i++;
       cin>>g;
       a[i]=g;


    }
  while((a[i]!=des && n==0) ||(n!=0 && i<=n));

a[i+1]=des;

return i;

}
template<typename T>
 cmas(T a[] ,int n=0,T des=NULL,int st=0)
{ int  i=st;
T g;

cout<<"new vector:"<<endl;
  do
    {
       i++;
       cin>>g;
       a[i]=g;


    }
  while((a[i]!=des && n==0) ||(n!=0 && i<n));

a[i+1]=des;

return i;

}

float fmodu(double a,double b)
{

   float u=a-(int)(a/b)*b;

   return u;

}


float fractional(double a)
{
   return a-(int)a;

}






template<typename T,typename T2>
void insert_inarray(T* A,int i,T2 a)
{
   A[i]=a;
}




template<typename T,typename T2,typename... arg>
void insert_inarray(T* A,int i,T2 a,arg... ag)
{
   A[i]=a;
   insert_inarray(A,i+1,ag...);


}




int math_Sandu::cm(char a[] ,int n=0,char des=0)
{ int  i=0;
char  g;
cout<<"create vector/string: "<<endl;

    do
    {

 i++;


cin>>g;

a[i]=g;
if(g=='-')
a[i]=' ';
    else
      if(g=='/')
a[i]='-';
else
a[i]=g;

    }while((a[i]!=des && n==0) || (n!=0 && i<=n));


a[i+1]=NULL;
return i;

}

int cmt(char a[] ,int n=0,char des=0)
{ int  i=-1;
auto g='a';
cout<<"create vector/string: "<<endl;

    do
    {

 i++;

cin>>g;
char gi=g;
a[i]=g;
if(g=='-')
a[i]=' ';
    else
if(g=='/')
a[i]='-';

else
a[i]=g;

    }while((a[i]!=des && n==0) || (n!=0 && i<=n));


a[i+1]=NULL;
return i;

}





















template<typename T,size_t M>
void cm2d(T a[][M],int n,int m=0,T des=0)

{ cout<<"des"<<des<<endl;

    int i,j;
    if(m==0)
      m=n;


cout<<"new matrix:"<<endl;


cout<<n<<" "<<m<<endl;
    for(i=1;i<=n;i++)
   { j=0;
   cout<<"i"<<i<<endl;

     do{

   j++;

    cin>>a[i][j];

    if(a[i][j]=='_')
      a[i][j]=' ';
      cout<<"j"<<j<<" ";
      cout<<"des"<<des<<" ";

     }while((a[i][j]!=des && des!=0) || j<m);

}



}





template<typename T>
void cm2d(T** a,int n,int m=0,T des=0)

{ cout<<"des"<<des<<endl;

    int i,j;
    if(m==0)
      m=n;


cout<<"new matrix:"<<endl;


cout<<n<<" "<<m<<endl;
    for(i=1;i<=n;i++)
   { j=0;
   cout<<"i"<<i<<endl;

     do{

   j++;

    cin>>a[i][j];

    if(a[i][j]=='_')
      a[i][j]=' ';
      cout<<"j"<<j<<" ";
      cout<<"des"<<des<<" ";

     }while((a[i][j]!=des && des!=0) || j<m);

}



}





















template<typename T>
int math_Sandu:: len(  T a[],T des)
{ int i=0;
    do{
        i++;
    }while(a[i]!=des)
;

return i;


}

template<typename T,typename P>
int len(  T a[],P des=NULL)
{ int i=0;
    do{
        i++;
    }while(a[i]!=des)
;

return i;

}





template<typename T>
int math_Sandu:: len(   const T a[],T des)
{ int i=0;
    do{
        i++;
    }while(a[i]!=des)
;

return i;


}
template<typename T>
bool math_Sandu::compa(T a[],T b[],int n,T des)
{ int i;
cout<<des<<endl;
cout<<len(a,des)<<" "<<len(b,des)<<endl;
if(n==0)
if(len(a,des)==len(b,des))
{


for(i=1;i<=len(a,des);i++)
    {cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])return false;
    }

return true;

}

if(n!=0)
{

for(i=1;i<=n;i++)
{

cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])return false;
}
return true;
}
return false;

}


template<typename T>
bool b_comp(T a ,T b)
{
if(a>b)return true;

return false;

}

template<typename T>
bool s_comp(T a ,T b)
{
if(a<b)return true;

return false;

}






template<typename T>
void sortare(T a[],int n,bool b(T ab,T bc)=b_comp)
{

int inv=0;
do{

   inv=0;
   for(int i=1;i<n;i++)
   if(b(a[i],a[i+1]))
      {
      T aux;
      aux=a[i];a[i]=a[i+1];a[i+1]=aux;inv=1;
      }


}while(inv!=0);



;}













bool math_Sandu::comp3(char a[],char b[],int n=0)
{ int i;
cout<<len(a,'.')<<" "<<len(b,'.')<<endl;
if(n==0)
if(len(a,'.')==len(b,'.'))
{


for(i=1;i<=len(a,'.');i++)
    {cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])return false;
    }

return true;

}

if(n!=0)
{

for(i=1;i<=n;i++)
{

cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])return false;
}
return true;
}
return false;

}

bool math_Sandu::comp2(char a[],const char b[],int n=0)
{ int i;
cout<<len(a,'.')<<" "<<len(b,'.')<<endl;
if(n==0)
if(len(a,'.')==len(b,'.'))
{


for(i=1;i<=len(a,'.');i++)
{
cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])
    return false;
}

return true;

}

if(n!=0)
{


for(i=1;i<=n;i++)
{
    cout<<a[i]<<" "<<b[i]<<endl;
    if(a[i]!=b[i])return false;
}
return true;
}

return false;

}






int math_Sandu::comp1(char a[],char b[],int n=0,char des='.')
{ int i;
if(n==0)
if(len(a,des)==len(b,des))
{
for(i=1;i<=len(a,des);i++)
{ cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return -1;
if(a[i]<b[i])return 2;
}

}else
{

   for(i=1;i<=min(len(a,des),len(b,des));i++)
{
cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return -1;
if(a[i]<b[i])return 2;
}

if(len(a,des)>len(b,des))
return -1;
else return 2;



}



if(n!=0)



for(i=1;i<=n;i++)
{
if(a[i]>b[i])return 2;
if(a[i]<b[i])return -1;
}


return 1;

}

int math_Sandu::comp(char a[],char b[],int n=0,char des='.')
{

int i;
if(n==0)
if(len(a,des)==len(b,des))
{
for(i=1;i<=len(a,des);i++)
{ cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;
}

}else
{

   for(i=1;i<=min(len(a,des),len(b,des));i++)
{
cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;
}

if(len(a,des)>len(b,des))
return 0;
else return 0;

}
if(n!=0)

for(i=1;i<=n;i++)
{
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;

}
return 1;

}





template<typename T>
void shuf(T a[],int i, int j)
{
    T aux=a[i];
    a[i]=a[j];
    a[j]=aux;

}






int comp4(char a[],char b[],int n=0,char des='.')
{
math_Sandu st;
int i;
if(n==0)
if(len(a,des)==len(b,des))
{
for(i=1;i<=len(a,des);i++)
{ cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;
}

}else
{

   for(i=1;i<=min(len(a,des),len(b,des));i++)
{
cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;
}

if(len(a,des)>len(b,des))
return 0;
else return 0;



}



if(n!=0)

for(i=1;i<=n;i++)
{
if(a[i]>b[i])return 0;
if(a[i]<b[i])return 0;

}




return 1;

}

int comp5(char a[],char b[],int n=0,char des='.',int te=1)
{
math_Sandu st;
int i;
if(n==0)
if(len(a,des)==len(b,des))
{
for(i=te;i<=len(a,des);i++)
{ //cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 2;
if(a[i]<b[i])return -1;
}

}else
{

   for(i=te;i<=min(len(a,des),len(b,des));i++)
{
//cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]>b[i])return 2;
if(a[i]<b[i])return -1;
}

if(len(a,des)>len(b,des))
return 0;
else return 0;



}



if(n!=0)

for(i=te;i<=n;i++)
{
if(a[i]>b[i])return 2;
if(a[i]<b[i])return -1;

}




return 1;

}



















int  math_Sandu::dw(double n)
{
    int i=0;
    if(n>=0)
    {
        while(n-i>0.99)
        {
            i++;
        }

            ;

    }

    ;
    if(n<0)
    {


        i=-dw(-n);

    }

    return i;

}

float math_Sandu:: up(float r)
{
    if(r-dw(r)!=0)
        return dw(r)+1;

    else
        return dw(r)
               ;
}
template<typename T>
int math_Sandu::ap(T f)
{
    if(f>=dw(f)+0.47)
      f=up(f);
    if(f<dw(f)+0.47)
    f=dw(f);

    return f
           ;




}

template<typename T>
float math_Sandu::aps(T f)
{
   // cout<<f<<endl;
    if(f>=dw(f)+0.80)f=up(f);
    if(f<dw(f)+0.2)f=dw(f);
    //cout<<dw(f)<<endl;
    //cout<<f<<endl;
    return f
           ;

}

template<typename T>
float math_Sandu::apss(T f)
{
   // cout<<f<<endl;
   if(f>=dw(f)+0.999)f=up(f);
   if(f>=dw(f)-0.999)f=up(f);

    if(f<dw(f)+0.09)f=dw(f);
    if(f<dw(f)-0.09)f=dw(f);

    //cout<<dw(f)<<endl;
    //cout<<f<<endl;
    return f;

}

















template<typename T>
float math_Sandu::rf(T a,int b)
{ int p=10;
p=powe(p,b);
    float s;
    float A=a*p;
    A=(float)ap(A);
    s=A-dw(A);
    return (A-s)/p;


}



float math_Sandu:: poc(float  p,int n)
{
    float s=1;
    for(int i=0; i<n; i++)
        s=s*(p+i);
    return s;

}



float math_Sandu::pi_angle(float n)
{
    //cout<<"dw"<<dw(n)<<endl;
    if(n>360 || n<-360) n= dw(n) % 360;
//cout<<"n="<<n<<endl;
    return (n*pi)/180;

}

float deg_angle(float n)
{
   math_Sandu d;

    return (n*180)/pi;

}





long double math_Sandu:: powe(long double a,int b)
{
//if(b<0) return 1.0/pow(a,-b);
    if(b==0)return 1;
    if(b%2==0 && b>=0) return powe(a*a,b/2);
    if(b%2==1 && b>=0) return a*powe(a,b-1);
    if(b<0)return 1.0/powe(a,-b);

}
float math_Sandu:: neg(float x)
{
    return x-2*x;
}
long long int  math_Sandu::fact (int n)
{

   if(n==0)return 1;
    if(n==1)return 1;


   //cout<<n<<" "<<n*fact(n-1)<<endl;
//Sleep(1000);
   return n*fact(n-1);


}


long long  Fibonacii(int n)
{
    int F[n+1]={[0]=1,[1]=1};

for(int i=2;i<=n;i++)
        if(F[i]==0)
      F[i]=F[i-1]+F[i-2];

return  F[n];
}

long long nr_triangularion(int n)
{
    long long T[100];
    T[2]=1;T[3]=1;

    for(int k=4;k<=n;k++)
    {
        for(int i=3;i<=k;i++)
           T[k]=T[i-1]*T[k-i+2];
    }
    return T[n];
}



















long long int  math_Sandu::subfact (int n)
{

   if(n==1)return 0;
    if(n==2)return 1;


   //cout<<n<<" "<<n*fact(n-1)<<endl;
//Sleep(1000);
   return (n-1)*(subfact(n-1)+subfact(n-2));

}


int math_Sandu:: arg (int n,int k)
{
    return fact(n)/fact(n-k)
           ;
}









int math_Sandu:: comb (int m,int y)
{
    return  fact(m)/(fact(m-y)*fact(y));

}

float math_Sandu::lon(float x,int n=5000)
{
    int i;
    float s=0;


    if(x<=2 && x>0)
    {

        for(i=1; i<=n; i++)
        {
            if(i%2==0)s=s+powe(x-1,i)/i;
            if(i%2!=0)s=s-((powe(x-1,i))/i);

        }
        s=-s;
    }

    if(x>2 || x<0)
    {
      s=lon(x-1);
        for(i=1; i<=n; i++)
        {
            if(i%2==0)
                s=s-1/(i*powe(x-1,i));
            if(i%2!=0)
                s=s+1/(i*powe((x-1),i));

        }


    }

//cout<<s<<endl;
    return s;

}



float math_Sandu::lb(float baza,float arg)
{
    return lon(arg)/lon(baza);

}







float Relu(float x)
{

   return max((float)0,x);

}
double Relu(double x,int n)
{

   return max((double)0,x);

}










long double math_Sandu :: expo (double x,long n=1000)
{
   //if(x>n)
      //n=x;

long double   s=1;


if(x<0)
return 1.0/expo(-x);

    for(long i=n-1;i>0; i--)
    {
       s=1+x*s/i;

    }
    return s;
}

 double expor (float x,int n=13)
{
double   s=1;

for(int i=1;i<=x;i++)
s*=e;


if(x<0)
return 1/expor(-x);

return s;
}




double ClipbyValue(double x,double Max,double Min)
{

if(x>=Min && x<=Max)return x;
   if(x>Max)return Max;
   if(x<Min)return Min;

}



double merf(double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;

    double p  =  0.3275911;

    // Save the sign of x
    int signa = Math.sign(x);
    x = abs(x);

    // A&S formula 7.1.2

    double t = 1.0/(1.0 + p*x);

    double y = 1.0 - exp(-x*x)*t*(((((a5*t + a4)*t) + a3)*t + a2)*t + a1);

    return signa*y;
}

double  fact2(int x,int par=0)
{
   if(x==1)
   {

   if(par==0)  return 1;
   if(par==1)return 2;
   }
   else
   {

    if(par==0)
      return (2*x-1)*fact2(x-1,par);
   if(par==1)
      return (2*x)*fact2(x-1,par);
   }

}










double math_Sandu:: sigmoid(double x,int y=0)
{

return 1.0/(1+exp(-x));


}

double sigmoid(double x,int y=0)
{
math_Sandu d;
return 1.0/(1+exp(-x));



}


double softplus(double x)
{

return Math.lon(Math.expo(x)+1);


}


double logSig(double x)
{

   return -softplus(-x);


}

double log1pe(double x)
{
   return Math.lon(x+1);

}
double step(double x,double alp=1)
{

return (x > 0 ? 1 : alp * x);


}
double square_diference(double a,double b)
{
   return (a-b)*(a-b);
}


double prelu(double x,double alpha)
{

   return (x < 0 ? alpha * x : x);
}
double srelu(double x,double alpha,double scale)
{
return x < 0 ? scale * alpha * (Math.expo(x) - 1) : x;

}



double reciprocal(double x)
{
   if(x==0)return numeric_limits<double>::infinity();
   return 1.0/x;
}




double Elu(double x,double alpha=1.0)
{
   if(x<0)return alpha*(Math.expo(x)-1);
   if(x>=0) return x;
}

double leakyRelu(double x,double alpha=1)
{

   if(x<0)return alpha*(Math.expo(x)-1);
if(x>0)return x;
}

double expm1m(double x)
{
return Math.expo(x)-1;
}

double threshold(double x,double thet)
{
   if(x>thet)return x;
   else return 0;
}



template<typename T>
float math_Sandu:: sqr(T x, float y)
{  //cout<<y<<endl;
    return exp(y*log(x));
}


long  double sqrm(long double x,float y=0.5)
{


math_Sandu st;
int p=1;

if(y<0)
  return sqrm(1.0/x,-y);


if(x<0)
{
float y1=1.0/y ;

if(fmodu(y,2)!=0 && fmodu(y1,2)!=0 )p=-1;
else
cout<<"numar complex cu parte imaginara"<<endl;
x=-x;
}

if(x==0)
return 0;




if(x>10000)
   return sqrm(x/10000)*sqrm(10000);


  return p*st.expo(y*st.lon(x));

}

long double sqrr(float x,int n=10,int k=-1)
{

if(k==-1)k=n;

if(k==0)
 {
    return 6*10*10;
 }

if(k>0)
{

return (sqrr(x,n,k-1)+x/sqrr(x,n,k-1))/2;

}

;
}



float sqrmf(float x,float y=0.5)
{
math_Sandu st;
//cout<<y<<" "<<x<<endl;

    return st.expo(y*st.lon(x));
    //st.aps



}





double erfm(double x)
{

   const double pis=1.77245385;
   double part1=Math.expo(-x*x)/(pis);
   double a1=-0.5;
   double a2=0.75;
   double a3=-1.875;
   double a4=6.56;

return 1.0-part1*(sqrm(x,-1)+a1*sqrm(x,-3)+a2*sqrm(x,-5)+a3*sqrm(x,-7)+a4*sqrm(x,-9));


}



template<typename T>
int  math_Sandu :: sign (T a)
{
    if(a>=0)return 1;
    if(a<0)return -1;

}


float fmodm(double x,double y)
{
   int dx=x;
   int dy=y;
   float fm=dx%dy;

      return fm;
}


///in degrees
double math_Sandu::cosa(double x,int n=10)

{ //cout<<"cosa "<<x<<endl;

   if(x>360)x=fmodm(x,360);

if(x<0)return cosa(-x);


    if(x>=270 && x<360) return cosa(360-x);


    if(x>=180 && x<270) return neg(cosa(x-180));



    if(x>90 && x< 180 ) return neg(cosa(180-x));


    x=pi_angle(x);
//cout<<"x="<<x<<endl;
    float s=0;

    for(int i=0; i<=n; i++)
    {
        if(i!=0)
        {
            //cout<<"i"<<i<<" "<<pow(-1,i)<<" "<<pow(x,2*i)<<" "<<fact(2*i)<<endl;
            s=s+pow(-1,i)*(pow(x,2*i)/fact(2*i));

        }
        else s=s+1;
//cout<<s<<endl;}

}
//cout<<"rec"<<s<<endl;

    return s;
}









///in degress
double math_Sandu:: sina(double x,int n=10)
{ //cout<<"sina "<<x<<endl;


   if(x>360)x=fmodm(x,360);
   if(x<-360)x=fmodm(x,360);
    if(x>=270 && x<360)
    {
        float t=neg(360-x);

        return sina(t);

    }
    if(x>=180 && x<270)
    {
        float t=neg(x-180);

        return sina(t);
    }
    if(x>90 && x < 180 )
    { //cout<<180-x<<endl;
        return sina(180-x);

    }
    //x=pi_angle(x);
//cout<<"xs"<<x<<endl;
    float s=0;
    /*d;

    for(int i=0; i<=n; i++)
    {
        d=1+2*i;
        s=s+pow(-1,i)*(pow(x, d)/fact(d));
        ;
    }
    */

    return cosa(90-x);
}
///in degress
float math_Sandu:: tana (double x)
{
    float y;
    float m=0;
    if(x==90 || x==-90)
    {
        //cout<<"aici";
        return m ;
    }
    else
    {
        y=x;
        return sina(y)/cosa(y);
    }
}
///in degress
double ctg(double x)
{

   if((int)x%180!=0)
     {
        return Math.cosa(x)/Math.sina(x);
     }
     else return 0;

}



int gcd(int x,int y)
{
int r=x%y;

while(r!=0)
{

   x=y;
   y=r;

   r=x%y;
}

return y;


}




///in degress
double seca(double x)
{
   math_Sandu d;
return (1.0)/d.cosa(x);
}


///in degress

double coseca(double x)
{
   math_Sandu d;
return (1.0)/d.cosa(x);
}


long double sinha(float x)
{
   math_Sandu sh;
  long  double r=sqrm(e,2*x)-1;

   r/=(2*sqrm(e,x));

return r;
}


long double cosha(float x)
{
   math_Sandu sh;
   long double r=sqrm(e,2*x)+1;

   r/=(2*sqrm(e,x));

return r;
}


double secha(double x)
{
   math_Sandu d;
return (1.0)/cosha(x);
}

double arcsecha(double x)
{
      math_Sandu d;
      if(x>0 && x<=1)
   return d.lon((1+sqrm(1-x*x))/x);

  return -INFINITE;
}


double cosecha(double x)
{
   math_Sandu d;
return (1.0)/sinha(x);
}


double arccosecha(double x)
{
      math_Sandu d;
      if(x!=0)
   return d.lon(1.0/x+sqrm(1.0/(x*x)+1));
  return -INFINITE;
}



double* xpowi(double x,double a=0,double b=1)
{

math_Sandu d;

double* t=new double[3];

t[1]=d.powe(x,a)*d.cosa(d.lon(x));
t[2]=d.powe(x,a)*d.sina(d.lon(x));

return t;
}


long double tanha(float x)
{

return sinha(x)/cosha(x);

}


long double arcsinha(float x)
{
   math_Sandu sh;
  long  double r=sh.lon(x+sqrm(x*x+1));

return r;

}


long double arctanh(float x)
{
   math_Sandu sh;

  long  double r=sh.lon((x+1)/(1-x));
return r/2;

}






float math_Sandu::arctan(float x,int deg=0,float n=30)

{

    float s=0;
    int p=1;


   if(x==1 || x==-1)
{

if(x==-1)p=-1;
s=p*pi/4;

if(deg==1)s=s/pi*180;
   return s;

}

    float use;


    if( x>1 || x<-1)
        use=1.0/x;
    else use=x;


    for(float i=0;i<=n;i++)
    {
        s=s+(pow(-1,i)*pow(use,2*i+1)/(2*i+1));

    }

if( x>1 || x<-1)
s=(pi*sqrt(x*x))/(2*x)-s;

if(deg==1)s=s/pi*180;


return s;
}

float arctan2(float x,int deg=0,float n=2000)
{ math_Sandu d;

    float s=0;
    int p=1;

    float use;

    if( x>1 || x<-1)
        use=1.0/x;
    else use=x;

    for(float i=0;i<=n;i++)
    {
        s+=(d.powe(-1,i)*d.powe(use,2*i+1)/(2*i+1));

    }

if( x>1 || x<-1)
s=pi/2-s;


if(deg==1)s=s/pi*180;


return s;
}

double arctan3(double x,double y)
{
   double u=y/x;

   if(x>0)
   return Math.arctan(u);


   if(x<0 && y>=0)
     return Math.arctan(u)+pi;

     if(x<0 && y<0)
     return arctan2(u)-pi;

     if(x=0 && y<=0)
     return -pi/2;

     if(x=0 && y>=0)
     return pi/2;

}








double hypo(double x,double y,int ang=90)
{
math_Sandu d;
long double r=sqrm(-2*x*y*d.cosa(ang)+x*x+y*y);
return r;

}


float arcsina(float x,int deg=0)
{
math_Sandu d;
int p=1;

if(x<0)
{p=-1;
x=abs(x)
;}
   float a=x/sqrm(1-x*x);
return p*arctan2(a,deg);

}


float arccosa(float x,int deg=0)
{

math_Sandu d;
int p=0;

if(x<0)p=1;

x=abs(x);

float a=sqrm(1-x*x)/x;

float u;

u= arctan2(a,deg);


if(p==1 && deg==0)u=pi-u;

if(p==1 && deg==1)u=180-u;


   return u;


}



double  arcseca(double x)
{
   return arccosa(1.0/x);

}



double  arccoseca(double x)
{
   return arcsina(1.0/x);

}


double arcctg(double x)
{
return pi/2-Math.arctan(x);
}





template<typename T,typename P>
void move_d(T a,P b,int n)
{
    for(int i=1;i<=n;i++)
          a[i]=b[i];


}

template<typename T,typename P>
void move_dr(T& a,P b,int n)
{
    for(int i=1;i<=n;i++)
          a[i]=b[i];

}



template<typename T,typename P>
void move_sd(T a,P b,int n,int i=1,int j=1)
{

    for(;i<=n;i++)
    {
       a[i]=b[j];
       j++;
    }



}

template<typename T>
void move_12(T**b ,T*a,int m,int t)
{
   int x=1;
   for(int i=1;i<=m;i++)
    for(int j=1;j<=t;j++)
      a[(i-1)*t+j]=b[i][j];

   a[0]=m*t;


}

template<typename T>
void move_21(T*a ,T**b,int m,int n)
{
 int x=1;
 int i=0;
   while(x<n)
   {
     i++;
      for(int j=1;j<=m;j++)
      if(x<n){b[i][j]=a[x];x++;}
   }

}


template<typename T>
vert_move21(T** a,T*b ,int n)
   {
      for(int i=1;i<=n;i++)
       a[i][1]=b[i];
   }

template<typename T>
vert_move12(T** a,T*b ,int n,int m)
   {


      for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
      b[(j-1)*n+i]=a[i][j];
      b[0]=n*m;

   }






template<typename T,typename P,size_t M,size_t S>
void move_2d(T a[][M],P b[][S],int n)
{
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
          a[i][j]=b[i][j];


}


template<typename T,size_t M>

void move_pd(T a[][M],T** b,int n,T des=NULL)
{

 int j=0;
    for(int i=1;i<=n;i++)
    {
       j=0;
       do{
         j++;
         a[i][j]=b[i][j];

       }while(b[i][j]!=des);
    }



}


template<typename T>

void move_pp(T** a,T** b,int n,int m)
{

 int j=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         a[i][j]=b[i][j];


}

template<typename T>
void move_pp2(T** a,T** b,int n)
{

 int j=0;
    for(int i=1;i<=n;i++)
         a[i]=b[i];

}

double diff(double n,double mid,double bs=3)
{ math_Sandu d;
    if (n > (d.powe(mid,bs)))
        return (n-d.powe(mid,bs));
    else
        return (d.powe(mid,bs)- n);

}


double sqrb(double n,double bs=3)
{ math_Sandu d;
    // source:https://www.geeksforgeeks.org/find-cubic-root-of-a-number/
    double start = 0, end = n;


    double ee = 0.0000001;

    while (true)
    {
        double mid = (start + end)/2;
        double error = diff(n, mid,bs);

        // If error is less than e then mid is
//cout<<n<<" "<<start<<" "<<d.powe(mid,bs)<<" "<<error<<endl;
        // our answer so return mid
        if (error <= ee)
            return mid;


        if ((d.powe(mid,bs)) >= n)
            end = mid;

        else
            start = mid;
    }

}







template<typename T>
int   math_Sandu::slice(T a[],int j,int n)
{
    int i;
    for(i=j; i<=n; i++)
    {
        a[i]=a[i+1];
    }

    n=n-1;
    return n;

}


template<typename T>
int math_Sandu::slice(T a[],int b[],int n,int m)
{ int i,j;
    for(i=1;i<=n;i++)
    {
       // sca(a,m);
     m=slice(a,b[i],m);

        for(j=i;j<=n;j++)
       if(b[j]>=b[i] )
           b[j]=b[j]-1;


    }

return m;

}
template<typename T>
int revers(T a[],int n)
{
T aux;


for(int i=1;i<=n/2;i++)
    {
        aux=a[i];
        a[i]=a[n-i+1];
        a[n-i+1]=aux;

    }


return 1;
}
template<typename T>
int atend(T a[],T b[],int n,int m)

{ int i;
int k=-1;
for(i=1;i<=m;i++)
{ k++;
a[n+k]=b[i];
}

return n+m-1;

}





template<typename T>
T* splice(T a[],int leng,int start,int wm=0)
{

if(wm==leng)wm=leng-start;

int i,j;

T* gn=new T [100];

int k=0;

    for(i=start;i<=start+wm;i++)
    {
        k++;
        gn[k]=a[i];
    }



    if(start+wm+1<=leng)
    {
    for(j=start+wm+1;j<=leng;j++)
    {
     a[j-wm]=a[j];
    }

   //for(j=leng-wm;j<=leng;j++)
    // a[j]=NULL;

    }
    else
    {
       // for(j=start;j<=start+wm;j++)
           // a[j]=NULL;

    }


return gn ;

}

template<typename T>
T* splicer(T a[],int& leng,int start,int wm=0)
{



if(wm==0)wm=leng-start;



int i,j;

T* gn=new T [100];

int k=0;




    for(i=start;i<=start+wm;i++)
    {
        k++;
        gn[k]=a[i];
    }


    if(start+wm+1<=leng)
    {

    //cout<<"pizza"<<endl;

    for(j=start+wm;j<=leng;j++)
    {
     a[j-wm]=a[j];
    }
   for(j=leng-wm;j<=leng;j++)
     a[j]=NULL;

    }
    else
    {
        for(j=start;j<=start+wm;j++)
            a[j]=NULL;

    }


return gn ;
}











template<typename T>
int math_Sandu:: removefa(T a[],T b,int n)
{

    for(int i=n;i>=1;i--)
    {


          if(a[i]==b)
           n=slice(a,i,n);

    }

    return n;



}

template<typename T>
T removefe(T a[],T b,int n)
{


    for(int i=n;i>=1;i--)
    {
          if(b==a[i])
          {

           return a[i];

          }
;

    }



    ;

}

template<typename T>
T*  pofarr(T a[],int n,int u=1)
{

T* B=new T [n+10];

for(int i=u;i<=n;i++)
B[i]=a[i];

return B;

}
template<typename T>
 T math_Sandu::pop_out(T a[],int& n)
{
    T be=a[n];
    a[n]=NULL;
    n--;
    return be;
}


template<typename T>
 T* pop_out(T** a,int& n)
{
    T* be=a[n];
    a[n]=NULL;
    n--;
    return be;
}

template<typename T,size_t M>
 T* pop_out(T a[][M] ,int& n)
{
    T* be=a[n];
    a[n]=NULL;
    n--;
    return be;
}



template<typename T>
T reduce2(T a[],int n,T& i_v,int i=1,void (*g)(T&,T)=NULL)
{

for(;i<=n;i++)
{
if(g==NULL)
i_v+=a[i];

else
   g(i_v,a[i]);

a[i]=0;

}

return i_v;

}

template<typename T>
T reduce3(T a[],int n,T& i_v,int i=1,void (*g)(T&,T)=NULL)
{

for(;i<=n;i++)
{
if(g==NULL)
i_v+=a[i];

else
   g(i_v,a[i]);

}
return i_v;
}


char reducec (char a[],char n,char& i_v,int i=1,void(*g)(char&,char)=NULL)
{

for(;a[i]!=n;i++)
{
if(g==NULL)
i_v+=a[i];

else
   g(i_v,a[i]);

a[i]=0;

}

return i_v;

}
char reducec2(char a[],char n,char& i_v,int i=1,void(*g)(char&,char)=NULL)
{

for(;a[i]!=n;i++)
{
if(g==NULL)
i_v+=a[i];

else
   g(i_v,a[i]);

}

return i_v;

}








template<typename T>
int math_Sandu:: delq(T a[],int& n)
{
    for(int i=1; i<n; i++)
        a[i]=a[i+1];
    a[n]=NULL;
    n--;
    return n;

}

template<typename T>
T shift(T a[],int& n)
{
math_Sandu se;

T b=a[n];

n=se.delq(a,n);


return b;

}


template<typename T>
int math_Sandu:: push( T a[],T b,int& n)
{

    n++;
    a[n]=b;
    return n;

};

template<typename T,typename R>
int math_Sandu:: push2(T* a, R b,int& n )
{
    n++;
    a[n]=b;
    return n;

};
template <typename T,typename R>
void addall(T a[],R b,int nr)
{
   for(int i=1;i<=nr;i++)
   a[i]+=b;




}
template <typename T,typename R>
void multall(T a[],R b,int nr)
{
   for(int i=1;i<=nr;i++)
   a[i]*=b;


}





template<typename T>
int math_Sandu :: map_scale(T MIN,T MAX,T mini, T maxi,T e[], T rd)
{
    float r;
    int n;
    if(rd==1)
    {
        n=ap(MAX-MIN);
    }
    else
    {

        n=(MAX-MIN)/rd+1;
    }

    r=(maxi-mini)/(n-1);

    float i=mini;

    for(int j=1; j<=(int)n; j++)
    {
        e[j]=roundf(i*100)/100;
        i=i+r;
    }


    return (int)n;
}


template<typename T>
T  math_Sandu :: map1( T f,T MIN,T MAX,T mini, T maxi, T rd)
{
    float r;

    float n;
    float n1;

    if(rd==1)
    {
        n=MAX-MIN+1;
    }
    else
    {

        n=(MAX-MIN)/rd+1;

    }

    r=(float)(maxi-mini)/n;


    T fo=f;

    n1=(fo-MIN)/rd;

//
    f=(float)mini+(float)(n1-1)*r;

    return f;

}

template<typename T>
float m1ratio(T f,T MIN,T MAX,T mini, T maxi, T rd=1)
{
   float r;

    float n;


    if(rd==1)
    {
        n=MAX-MIN+1;
    }
    else
    {

        n=(MAX-MIN)/rd+1;

    }

    r=(float)(maxi-mini)/n;


return r;

}

template<typename T>
 T map11( T f,T MIN,T MAX,T mini, T maxi)
{

   float b,a;


   a=(maxi-mini)/(MAX-MIN);


   b=((mini+maxi)-a*(MIN+MAX))/2;

   return f*a+b;

}
template<typename T>
 T map12( T f,T MIN,T MAX,T mini, T maxi)
{

   float b,a;


   a=(maxi-mini)/(MAX-MIN);


   b=((mini+maxi)-a*(MIN+MAX))/2;

   return f*a+b;

}


template<typename T>
 T map15(T f,T MIN,T MAX,T mini, T maxi)
{
   float b,a;


   a=(maxi-mini)/(MAX-MIN);



   b=(-MIN*a + mini);

   return f*a+b;
}

template<typename T,typename T2,typename T3,typename T4,typename T5>
 T map17(T f,T2 MIN,T3 MAX,T4 mini, T5 maxi)
{
   float b,a;


   a=(maxi-mini)/(MAX-MIN);



   b=(-MIN*a + mini);

   return f*a+b;
}





template<typename T>

 T* map13(T arr[],int n_e,T bol(T))

{
size_t si=n_e+10;

T* fin=new T[si];

for(int i=1;i<=n_e;i++)
{
fin[i]=bol(arr[i]);

}

 return fin
 ;

}






 void setintv(void a(),int nr)
{

   a();
Sleep(nr);


}












template<typename T>
 T* filter(T arr[],int& n_e, bool bol(T))

{

size_t si=n_e+10;

T* fin=new T[si];

int k=0;

for(int i=1;i<=n_e;i++)
{

if(bol(arr[i]))
{ k++;
   fin[k]=arr[i];
}

}
n_e=k;

 return fin
 ;

}



template<typename T>

T reduce( T ar[] ,int& n_e, T bol(T,T))

{

size_t si=n_e+10;

T* fin=new T[si];

int k=0;

for(int i=1;i<n_e;i++)
{
if(i==1)
   fin[i]=bol(ar[1],ar[2]);
else
   fin[i]=bol(ar[i-1],ar[i+1]);
}
n_e=k;

 return fin[n_e-1];

}

int nr_div(int j)
{
   int n_d=0;
for(int i=1;i<=j;i++ )
if(j%i==0)
   n_d++;

return n_d;


}

int prim(int j)
{
   int n_d=0;
for(int i=2;i<=j/2;i++ )
if(j%i==0)
   n_d++;

if(n_d)
return 0;
else
return 1;

}
template<typename T,typename P>
T reduce_python(T* a,int n,P fun,int sp=0)
{   T d=a[sp];
    for(int i=sp+1;i<n+sp;i++)
      d=fun(d,a[i]);
  return d;
}


int cmdc(int a,int b)
{
   int r=0;


   do
   { if(b!=0)
      r=a%b;
       a=b ;
       b=r;

}while(r!=0);

return a;

}

bool primie(int a,int b)
{
if(cmdc(a,b)==1)
   return true;
return false;


}
int perfect(int a)
{
   int d=0;
   for(int i=2;i<=a/2;i++)
   if(a%i==0)
       d++;
      if(d%2==1)
   return 1;
   return 0;
}


int palindrom(int a)
{
   int op=0;
   int aux=a;
   while(a!=0)
   {
      op=op*10+a%10;
      a=a/10;
   }
   if(op==aux)
    return 1;


}




int sum_gauss(int i)
{

   int p=0;

   for(int j=1;j<=i;j++)
   p=p+j;

return p;

}


template<typename T>
int partion(T* A,int (*f)(T,T),int st,int en)
{
   T pivot=A[en];
   int i=st-1;

   for(int j=st;j<=en-1;j++)
   {
      if(f(A[j],pivot))
      {

         i++;
         T aux=A[j];
         A[j]=A[i];
         A[i]=aux;
      }

   }
       T aux=A[en];
         A[en]=A[i+1];
         A[i+1]=aux;

   return i+1;

}

template<typename T>
void quick_sort(T* A,int (*f)(T,T),int st,int en)
{
   if(st<en)
   {

      int pai=partion(A,f,st,en);

      quick_sort(A,f,st,pai-1);
      quick_sort(A,f,pai+1,en);
   }

}














template<typename T>
T  math_Sandu :: mparray( T f[],T MIN,T MAX,T mini, T maxi, int nr_e,T rd)
{
    float r;
    int n;
    int n1;

    if(rd==1)
    {
        n=ap(MAX-MIN);
    }
    else
    {

        n=(MAX-MIN)/rd+1;
    }

    r=(maxi-mini)/(n-1);

    cout<<"r"<<r<<endl;

    T nsa=NULL;

    for(int i=1; i<=nr_e; i++)
    {
        T fo=*f[i];

        n1=(fo-MIN)/rd+1;

        *f[i]=roundf(mini+(n1-1)*r*100)/100
              ;
        nsa=nsa+f[i];
    }


    return nsa/nr_e;

}


template<typename T,typename R>
T  mparray2( T f[],int n,R g=0,T(*b)(T,R)=NULL)
{

for(int i=1;i<=n;i++)
{
if(b!=NULL)
f[i]=b(f[i],g);
}


}







template<typename T>
T* ind_btk(T v[],int n,int k=0)
{

int lI=-1;
for(int i=1;i<n;i++)
{

if(v[i]<v[i+1])
lI=i;

}
if(lI==-1)
{
cout<<"finished";
return NULL;
}
int lj=-1;
for(int j=1;j<=n;j++)
{

if(v[j]>v[lI])
lj=j;

}
if(lj==-1)
{
cout<<"finished";
return NULL;

}
else
shuf(v,lI,lj);
//cout<<"shuj:"<<endl;
//sca(v,5);

T* gh=new T[100];

gh=splice(v,n,lI);

//cout<<"sky:"<<endl;

//sca(v,5);

//sca(gh,n-lI+2);


revers(gh,n-lI);

//sca(gh,n-lI+1);

atend(v,gh,lI+1,n-lI+1);

T* result=new T[100];

result=v;

return result;

;}






template<typename T>
fill(T* u,int n,T v,int i=1)
{
fill(u+i,u+n+1,v);
}







int inv_nr(int a)
{
int p=0;
while(a!=0)
{
   p=p*10+a%10;
   a/=10;

}
return p;
}

int nr_c(int a)
{
int i=0;
while(a!=0)
{
i++;a/=10;
}

return i;
}




int nr_f(double a,int& p)
{
   int b=a;
   int i=0;
   while(i<5)
   {
   i++;
   b=a*10;
   a=a*10;

cout<<a<<" "<<b<<endl;
   }
p=i;
return b;

}









template<typename T,size_t M>
T** give_ref2d(T** b,T a[][M] ,int m)
{
b=new T*[m+5];

for(int i=0;i<=m;i++)
b[i]=a[i];



return b;

}


long double gamma(float z,int n=10)
{ ;
   math_Sandu d;

long double s=1;
long double s1=1;
long double s2=1;
double en=0.5;




s1=en*log(2*pi)+(z-en)*log(z)-z+z*en*log(z*sinha(1.0/z));


s=d.expo(s1,10000);


return s;
}









template<typename T>
int indexOf(T a[],T b,int n,int (*f)(T,T)=NULL)
{
   int inx=0;
   for(int i=1;i<=n;i++)
   {
      if(f==NULL){  if(a[i]==b) inx=i;}
         else
     if(f(a[i],b)==1)inx=i;
   }

   return inx;


}









/*

long double erfm(float x,int n=300)
{
   math_Sandu d;

  long double s=0;
  long double p=1;



  if(x<=3 && x>=-3)
  {
   for(int i=0;i<=n;i++)
   {

   p=1;
   double o=0;

     o=x/(2*i+1);

  for(int j=1;j<=i;j++)
   p*=-(x*x)/(j);

   s+=o*p;

   ;
  }
  s*=(2.0/sqrr(pi));
  }
  else
   if(x<-3)return -1;
    if(x>3)return 1;
return s;

}
double erfcm(double x,int n=300)
{
return 1-erfm(x,n);
}

*/



union li_al_sandu
{
    template<typename T,size_t M>

    void mult(T [][M],T,int,int);

    template<typename T>
    void mult(T**,T,int,int);


    template<typename T,size_t M>
    void mult2(T [][M],T [][M],int,int);

    template<typename T,size_t M>
    void add (T [][M],T,int,int );

    template<typename T,size_t M>

    void  add2(T[][M],T[][M],int,int);

    template<typename T,size_t M>
    void dotp(T [][M],T[][M],int,int,int);


    union matrix
    {
        int rows;
        int colums;
        template<typename R>
        struct arr
        {
            R a[100];

        };

        arr<int> mat[100];
        void Matrix(int,int);
        template<typename T>
        void add(T n);
        template<typename T>
        void mult(T n);

    };


}LI_al;

template<typename T,size_t M>
void li_al_sandu::mult (T a[][M],T b,int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]*b;

}
template<typename T>
void li_al_sandu::mult (T** a,T b,int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]*b;

}
template<typename T,size_t M>
void li_al_sandu::mult2 (T a[][M],T b[][M],int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]*b[i][j];

}



void li_al_sandu::matrix::Matrix(int i,int j)
{
    rows=i;
    colums=j;


}
template<typename T,size_t M>
void li_al_sandu::add (T a[][M],T b,int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]+b;

}
template<typename T,size_t M>
void li_al_sandu:: add2 (T a[][M],T b[][M],int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]+b[i][j];

}



template<typename T>
void li_al_sandu::matrix::add(T n)
{
    for(int i=1; i<=rows; i++)
        for(int j=1; j<=colums; j++)
            mat[i].a[j]=mat[i].a[j]+n;





}

template<typename T>

void li_al_sandu::matrix::mult(T n)
{
    cout<<typeid(n).name()<<endl;
    if (typeid(n).name()=="matrix")
    {
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=colums; j++)
                mat[i].a[j]=mat[i].a[j]*n.mat[i].a[j];
    }
    else
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=colums; j++)
                mat[i].a[j]=mat[i].a[j]*n;
}



template<typename T>
T relu(T a,int b=0)
{
if(a>b)return a;
else return 0;

}
template<typename T,typename R>
T multn(T d,R r=1)
{
   return d*r;

}


template<typename T>
void apm(T** a,int n,int m)
{
   math_Sandu d;

   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   a[i][j]=d.ap(a[i][j]);


}
template<typename T>
void opm(T** a,int n,int m,T nr,int op=1)
{
   math_Sandu d;

   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
        if(op==1)a[i][j]+=nr;
        if(op==2)a[i][j]*=nr;
        if(op==3)a[i][j]/=nr;
        if(op==4)a[i][j]=d.sina(a[i][j]);
        if(op==5)a[i][j]=d.cosa(a[i][j]);
        if(op==7)a[i][j]=d.cosa(a[i][j]);
        if(op==8)a[i][j]=relu(a[i][j],nr);


   }



}
template<typename T>
void mult2 (T** a,T** b,int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=a[i][j]*b[i][j];

}

template<typename T>
T** mult2p (T** a,T** b,int n,int m)
{
T** result=new T*[n+2];
for(int i=0;i<=n+1;i++)result[i]=new T[m+2];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            result[i][j]=a[i][j]*b[i][j];

return result;
}









template<typename T>
void add2 (T** a,T** b,int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
           a[i][j]+=b[i][j];

}




template<typename T>
T* dota(T** mat,T*arr,int ln,int colm,int isd=0)
{

  T* p_arr=new T[colm+1];
  for(int i=1;i<=colm;i++)
   p_arr[i]=arr[i];



   arr=new T[ln+1];


   for(int i=1;i<=ln;i++)
   {
      arr[i]=0;
     for(int j=1;j<=colm;j++)
     {
      arr[i]+=mat[i][j]*p_arr[j];
   cout<<mat[i][j]<<" "<<p_arr[j]<<" "<<arr[i]<<endl;
     }
    cout<<arr[i]<<endl;

   }
   delete[] p_arr;
   return arr;
}






 template<typename T,size_t M>
    void dotp(T a[][M],T b[][M],int row,int colm,int com)
    {  T c[][M]={NULL};
        int i,j,k;
        for(i=1;i<=row;i++)
          for(j=1;j<=colm;j++)
             for(k=1;k<=com;k++)
           {
             c[i][j]=c[i][j]+a[i][k]*c[k][j];

           }
       for(i=1;i<=row;i++)
        for(j=1;j<=colm;j++)
         a[i][j]=c[i][j];

    }

template<typename T,typename P>
T abs_diff(T a,P b)
{
return abs(a-b);

}


template<typename T,typename P,typename R,typename U>
T distances(T a,P b,R c,U d)
{
return sqrm( (a-c)*(a-c)+(b-d)*(b-d));


}


 template<typename T>
 void dotpp(T** a, T** b,int row1,int colm1,int rows2,int colm2=0)
    {
   int com;

   if(colm2==0)colm2=colm1;
     else
     {
      if(rows2!=colm1){cout<<"not matching"<<endl;return;}
     }

   T** c=new T*[row1+1];

   for(int i=0;i<=row1;i++)
   c[i]=new T[colm2+1];

      int i,j,k;


      {
         com=rows2;
        for(i=1;i<=row1;i++)
          for(j=1;j<=colm2;j++)
          {
          c[i][j]=0;
             for(k=1;k<=com;k++)
           {
             c[i][j]+=a[i][k]*b[k][j];

           }

          }
       for(i=1;i<=row1;i++)
        for(j=1;j<=colm2;j++)
         a[i][j]=c[i][j];
      }
delete[]c;

    }

     template<typename T>
 T** dotppp(T** a, T** b,int row1,int colm1,int rows2,int colm2=0)
    {

   // sca2d(a,row1,colm1);
   // sca2d(b,rows2,colm2);
   int com;
   if(colm2==0)colm2=colm1;
     else
     {
      if(rows2!=colm1){cout<<"not matching"<<endl;return NULL;}
     }

T** c=new T*[row1+4];


   for(int i=0;i<=row1+1;i++)
   c[i]=new T[colm2+4];

      int i,j,k;
      {
         c[1][0]=row1;
         c[2][0]=colm2;


         com=rows2;


        for(i=1;i<=row1;i++)
          for(j=1;j<=colm2;j++)
          {

            c[i][j]=0;
             for(k=1;k<=com;k++)
           {
             c[i][j]+=a[i][k]*b[k][j];
           }



          }
         return c;
   }
      //delete [] c;
   return NULL;
    }

template<typename T,size_t M>
void randomizem(T a[][M],int n,int m ,float r=10)
{

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
   a[i][j]=(int)(randf(0,1)*r);

}

template<typename T>
void randomizem(T** a,int n,int m ,float r=10)
{

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
   a[i][j]=(int)(randf(0,1)*r);

}

template<typename T>
void randomizem2(T** a,int n,int m ,float r1,float r2)
{
for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
   a[i][j]=(int)(randf(r1,r2));

}




template<typename T,typename R>
void mapm(T** a,int n,int m ,R d,T(*b)(T,R))
{

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
   a[i][j]=b(a[i][j],d);


}
template<typename T,typename R>
T** mapmp(T** a,int n,int m ,R d,T(*b)(T,R))
{


T** a2=new T*[n+4];
for(int i=0;i<=n+4;i++)
   a2[i]=new T[m+4];

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
   a2[i][j]=b(a[i][j],d);

a2[1][0]=n;
a2[2][0]=m;

   return a2;
}

int between(double a,double b,double n)
{

if( n>=a &&  n<=b)return 1;
return 0;
}




template<typename T,size_t M>
T det(int n,T a[][M])
{
   T detr=0;

    if(n==2)
    detr=a[1][1]*a[2][2]-a[1][2]*a[2][1];

    if(n==3)
    {


        T det1,det2,det3;

    det1=a[1][1]*(a[2][2]*a[3][3]-a[3][2]*a[2][3]);
    det2=a[1][2]*(a[2][1]*a[3][3]-a[3][1]*a[2][3]);
    det3=a[1][3]*(a[2][1]*a[3][2]-a[3][1]*a[2][2]);

    detr=det1-det2+det3;


}

return detr
;}
template<typename T>
T det(int n,T** a)
{
   T detr;
   detr=0;

    if(n==2)
    detr=a[1][1]*a[2][2]-a[1][2]*a[2][1];

    if(n==3)
    {

        T det1,det2,det3,dp1,dp2,dp3;


         dp1=(a[2][2]*a[3][3]-a[3][2]*a[2][3]);
    det1=a[1][1]*dp1;


         dp2=(a[2][1]*a[3][3]-a[3][1]*a[2][3]);
    det2=a[1][2]*dp2;



         dp3=((a[2][1]*a[3][2])-(a[3][1]*a[2][2]));

    det3=a[1][3]*dp3;


    detr=det1-det2+det3;


}




return detr
;}
template<typename T>
T detm(T** a,int n)
{

math_Sandu sd;
//sca2d(a,n,n);

if(n==1)
return a[1][1];

if(n==2)
return det(n,a);

if(n==3)
{

return det(n,a);


}

  if(n>3)
  {
     T dete;
     dete=0;

     for(int i=1;i<=n;i++)
   {

      T fi[50][50];
      T** f;
         f=give_ref2d(f,fi,n);

// cout<<"aici"<<i<<" / "<<n<<endl;




        int x=0,y=1;

        for(int l=2;l<=n;l++)
        {
          x++;y=0;
           for(int k=1;k<=n;k++)
            {
               if(k!=i)
               {y++;
               f[x][y]=a[l][k];
               }
            }
        }


      a[1][i]*sd.powe(-1,i+1);

       // cout<<"aici again"<<a[1][i].pol.nr<<endl;

       // for(int ii=1;ii<=a[1][i].pol.nr;ii++)
        //cout<<a[1][i].pol[ii]<<" ";

        //cout<<endl;





 dete=dete+detm(f,n-1)*(a[1][i]);






   }
return dete;
  }
 // imag b;b.r=0;
 // b.i=0;
 T dos;
 dos=0;


return dos ;
}

template<typename T>
T** transp(T** a,int n,int m=0)
{
   if(m==0)m=n;

   T** res=new T*[m+5];


   for(int i=0;i<=m+3;i++)
    res[i]=new T[n+5];


   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
      res[j][i]=a[i][j];
   }

res[1][0]=m;
res[2][0]=n;

return res;

}


int is_det_zero(double r)
{

   if(abs(r)<0.001)


     return 1;
   return 0;



}


template<typename T>
T* Ecuatie_Cramer(T** mate,T* sol,int n)
{

T* b=new T[n+5];
T a[50];

T vader=detm(mate,n);

if(!is_det_zero(vader))



{

for(int i=1;i<=n;i++)
{
   for(int j=1;j<=n;j++)
    a[j]=mate[j][i];

   for(int j=1;j<=n;j++)
    mate[j][i]=sol[j];

b[i]=detm(mate,n)/vader;

   for(int j=1;j<=n;j++)
    mate[j][i]=a[j];

}
return b;


}
else
{
cout<<"no bueno"<<endl;
return NULL;

}


}

template<typename T,typename T2>
T** inversa(T**a,int n,T2& c)
{
   math_Sandu d;
  T darth=detm(a,n);
 printf("darth %f\n",darth);
  if(darth!=0)
 c=darth;

 else
 { cl(1,1,12);
    cout<<"matice neinversabila"<<endl;
 cl(1,1,7);
   return NULL;

 }

 T** res=new T*[n+2];

for(int i=0;i<=n+1;i++)
 res[i]=new T[n+2];


  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
{

   T f[50][50];
   T** fi;

   fi=give_ref2d(fi,f,n);


   int x=0,y=0;


T** f2=transp(a,n,n);

   for(int l=1;l<=n;l++)
   {

      if(l!=i)x++;
      y=0;
    for(int k=1;k<=n;k++)
   {
      if( l!=i && k!=j)
      {y++;fi[x][y]=f2[l][k];}
   }}

   res[i][j]=d.powe(-1,i+j)*detm(fi,n-1);




}
return res;


}


template<typename T>
Llist<T**> division_mat(T** A,T** B,int n1)
{

Llist<T**> res;

sca2d(A,n1,n1);
cout<<endl<<endl;
sca2d(B,n1,n1);
cout<<endl;


   T d=detm(B,n1);

   try
   {

if(d==0)

   throw d;

   }
catch(double d)
{

   cout<<"B is not an invertible matrix"<<endl;

exit(1);

}
   if(d!=0)
   {
  T r;

        T** m2=inversa(B,n1,r);

        opm(m2,n1,n1,d,3);


        sca2d(m2,n1,n1);



  T** m4=dotppp(B,m2,n1,n1,n1,n1);

  cout<<"check:"<<endl;
sca2d(m4,n1,n1);
  cout<<endl;




       T** m3;

m3=dotppp(A,m2,n1,n1,n1,n1);
  m3[0][1]=n1;

 res.add(m3);

   m3[0][1]=n1;

      m3=dotppp(m2,A,n1,n1,n1,n1);
   m3[0][1]=n1;

res.add(m3);

   delete m2;

   return res;


   }

  else
  {


     cout<<"inversabila";
     return res;
  }


}








template<typename T>
double* ecuatie_grad2(T a,T b,T c)
{
double* r=new double[5];
double arp=b*b-4*a*c;

double delt=sqrm(arp);
if(arp<0)
{

r[1]=-b/(2*a);
r[2]=delt/(2*a);

r[3]=-b/(2*a);
r[4]=-delt/(2*a);

}
else
{
r[1]=(-b+delt)/(2*a);
r[3]=(-b-delt)/(2*a);
r[2]=0;
r[4]=0;

}
return r;

}


template<typename T>
double inv_ecuatie_grad_2(T a,T b,T c,T y)
{
   double delt=b*b-4*a*c;
   double mg=-delt/(4*a);
  double mg2;

   if((a>0 && y>=mg)||(a>0 && y<=mg))
   {

     return mg2=(float)(-b+sqrm(b*b-4*a*c+4*a*y))/(2*a);

   }

}
template<typename T>
double lim_pol(T** a,int n,int m,double x,int inf=0)
{
math_Sandu d;
double ps=0,pj=0;

//scan2d(a,n,(float)0,0);


if(inf==0)
{

for(int i=0;i<=n;i++)
ps+=a[1][i]*d.powe(x,i);

for(int i=0;i<=m;i++)
pj+=a[2][i]*d.powe(x,i);

if(pj!=0)return ps/pj;


if(ps==0 && pj==0)
{

while(ps==0 && pj==0)
{


   T ax[50]={0};
   T ax2[50]={0};


   for(int i=n;i>=1;i--)
   {
       ax[i-1]=x*ax[i]+a[1][i];

   }

    for(int i=m;i>=1;i--)
    {
        ax2[i-1]=x*ax2[i]+a[2][i];

    }


     ps=0;pj=0;

    for(int i=n-1;i>=0;i--)
    {;

      ps+=ax[i]*d.powe(x,i);


    }

    for(int i=m-1;i>=0;i--)
    pj+=ax2[i]*d.powe(x,i);

move_sd(a[1],ax,n,0,0);
move_sd(a[2],ax2,n,0,0);




//system("pause");

}
return ps/pj;
}

if(pj==0)
{


ps=0;pj=0;

double ps1=0,pj1=0;
double inc1=x+0.1;
double inc2=x-0.1;


for(int i=0;i<=n;i++)
ps+=a[1][i]*d.powe(inc1,i);


for(int i=0;i<=n;i++)
ps1+=a[1][i]*d.powe(inc2,i);


for(int i=0;i<=m;i++)
pj+=a[2][i]*d.powe(inc1,i);

for(int i=0;i<=m;i++)
pj1+=a[2][i]*d.powe(inc2,i);


ps=d.sign(ps)*d.sign(pj);
pj=d.sign(ps1)*d.sign(pj1);

double inf=numeric_limits<double>::infinity();
if(ps==pj)
{

  return inf*ps;
}



cout<<"fara limita ";
return NULL;


}
}
else
{
if(inf<0)
if(n>m)return -numeric_limits<double>::infinity();
else
if(n==m)
return - a[1][n]/a[2][m];
else
return 0;

if(inf>0)
if(n>m)return -numeric_limits<double>::infinity();
else
if(n==m)
return - a[1][n]/a[2][m];
else
return 0;
}
return NULL;



}

template<typename T,typename R>
T** concat2d_line(T** a,R b[],int& n,int m,int r)
{
T** an=new T*[n+1+2];
   for(int i=0;i<=n+2;i++)
    an[i]=new T[max(m,r)+2];

    for(int i=1;i<=n;i++)
    { if(i!=1)an[i][0]=m;
    for(int j=1;j<=m;j++)
    {
    an[i][j]=a[i][j];
    }
    }
   n++;
   an[1][0]=n;

   for(int i=1;i<=r;i++)
   an[n][i]=b[i];
an[n][0]=r;
return an;

}


template<typename T,typename R>
T** concat2d_orz(T** a,R** b,int n,int m,int n2,int m2)
{
int nn=max(n,n2);
T** nm=new T*[nn+5];



for(int i=0;i<=nn+1;i++)
   nm[i]=new T[m+m2+3];

   for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
       nm[i][j]=a[i][j];
     // if(i!=1)nm[i][0]=m;
    }
   for(int i=1;i<=n2;i++)
   {
      for(int j=1;j<=m2;j++)
        nm[i][j+m]=b[i][j];
  // if(i!=1)nm[i][0]=m+m2;
   }
//nm[1][0]=nn;
return nm;
}

template<typename T,typename R>
T** concat2d_vertd(T** a,R** b,int n,int m,int n2,int m2)
{
int nn=n+n2;
T** nm=new T*[nn+5];

for(int i=0;i<=nn+1;i++)
   nm[i]=new T[max(m,m2)+3];

   for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
       nm[i][j]=a[i][j];
      if(i!=1)nm[i][0]=m;
    }

   for(int i=1;i<=n2;i++)
   {
     for(int j=1;j<=m2;j++)
        nm[i+n][j]=b[i][j];
   if(i!=1)nm[i][0]=m2;
   }
nm[1][0]=nn;
return nm;

}
template<typename T,typename R>
T** concat2d_vertu(T** a,R** b,int n,int m,int n2,int m2)
{
int nn=n+n2;
T** nm=new T*[nn+5];

for(int i=0;i<=nn+1;i++)
   nm[i]=new T[max(m,m2)+3];

   for(int i=1;i<=n2;i++)
    {
      for(int j=1;j<=m2;j++)
       nm[i][j]=a[i][j];
      if(i!=1)nm[i][0]=m2;
    }
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
        nm[i+n2][j]=b[i][j];

   }
nm[1][0]=nn;
return nm;

}



template<typename T>
T* diag(T** u,int n,int m)
{
   T* f=new T[max(n,m)];
   int k;

   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   if(i==j)f[k]=u[i][j];
   return f;

}





template<typename T,typename R>
T** sumam(T** a,R**b)
{
   T**c=new T*[max(a[1][0],b[1][0])+1];
   for(int i=0; i<=max(a[1][0],b[1][0]);i++)
   c[i]=new T[max(a[2][0],b[2][0])+1];

  T** p;int  o=0;

  if(a[1][0]*a[2][0]>=b[1][0]*b[2][0])
  {p=a;o=1;}
  else {p=b;o=2;}
  move_2d(c,p,p[1][0],p[2][0]);


  for(int i=1;i<=min(a[1][0],b[1][0]);i++)
    for(int j=1;j<=min(a[1][0],b[1][0]);j++)
    {
       if(o==1)c[i][j]+=b[i][j];
       if(o==2)c[i][j]+=a[i][j];
    }

   return c;

}
template<typename T>
T suma(T* a,int n)
{
   T b=NULL;
for(int i=1;i<=n;i++)
   b+=a[i];
return b;
}




template<typename T,typename R>
T** diffm(T** a,R**b)
{

   T**c=new T*[max(3,(int)max(a[1][0],b[1][0])+1)];

   for(int i=0; i<=max(3,(int)max(a[1][0],b[1][0]));i++)
   c[i]=new T[max(3,(int)max(a[2][0],b[2][0])+1)];


  T** p;int  o=0;

  p=a;

  move_pp(c,p,(int)p[1][0],(int)p[2][0]);

c[1][0]=a[1][0];
c[2][0]=a[2][0];

  for(int i=1;i<=min(a[1][0],b[1][0]);i++)
    for(int j=1;j<=min(a[2][0],b[2][0]);j++)
    {
       c[i][j]-=b[i][j];
    }

   return c;

}
template<typename T>
void gauss_jordan(T** a,int n,int m)
{

int im[10]={1};

T mina;

int k=0;

for( k=1;k<=n && k<=m-1;k++)
{

mina=0;
int con;

for(int t=1;t<=n;t++)
{
   con=1;
for(int u=1;u<k;u++)
if(t==im[u])
   con=0;

if(a[t][k]!=0 && con && (a[t][k]<mina|| mina==0) ){mina=a[t][k] ;im[k]=t;}
}
if(mina==0)
   mina=1;

for(int i=1;i<=m;i++)
a[im[k]][i]/=mina;

for(int i=1;i<=n;i++)
{
if(i!=im[k])
{
double f=0;
if(a[im[k]][k]!=0 && a[i][k]!=0)f=-a[i][k]/a[im[k]][k];

for(int j=1;j<=m;j++)
{
a[i][j]+=a[im[k]][j]*f;
if(Math.ap(a[i][j])==-0)a[i][j]=0;
}
}
}

;
}
cout<<"dupa"<<endl;
int con=0;

for(int u=1;u<=n;u++)
{
   int con2=0;
for(int p=1;p<=m-1;p++)
if(a[u][p]!=0)con2++;

if(con2==0 && a[u][m]!=0)con=1;


}
if(con)cout<<"sistem incompatibil"<<endl;
sca2d(a,n,m);
}

template<typename T>
void gauss_jordan2(T** a,int n,int m)
{

int im[10]={1};

T mina;

int k=0;

for( k=1;k<=n && k<=m-1;k++)
{

mina=0;
int con;

for(int t=1;t<=n;t++)
{
   con=1;
for(int u=1;u<k;u++)
if(t==im[u])
   con=0;

if(a[t][k]!=0 && con && (a[t][k]<mina|| mina==0) ){mina=a[t][k] ;im[k]=t;}
}
if(mina==0)
   mina=1;


for(int i=1;i<=n;i++)
{
if(i!=im[k])
{
double f=0;
if(a[im[k]][k]!=0 && a[i][k]!=0)
   f=-a[i][k]/a[im[k]][k];

for(int j=1;j<=m;j++)
{
a[i][j]+=a[im[k]][j]*f;
if(Math.ap(a[i][j])==-0)
a[i][j]=0;
}
}
}

;
}
cout<<"dupa"<<endl;
int con=0;

for(int u=1;u<=n;u++)
{
   int con2=0;
for(int p=1;p<=m-1;p++)
if(a[u][p]!=0)con2++;

if(con2==0 && a[u][m]!=0)
con=1;


}
if(con)cout<<"sistem incompatibil"<<endl;
sca2d(a,n,m);
}


template<typename T>
void gauss_jordan3(T** a,int n,int m)
{

int k=0;

for(int t=1;t<n;t++)
{

for(int i=t+1;i<=n;i++)
{

double f=0;

if(t!=i)
{
   if(!(a[t][t]>0 && a[t][t]<0.009 || a[t][t]<0 && a[t][t]>-0.009))
   f=-a[i][t]/a[t][t];


for(int j=1;j<=m;j++)
{
a[i][j]+=a[t][j]*f;

if(a[i][j]>0 && a[i][j]<0.009 || a[i][j]<0 && a[i][j]>-0.009)
a[i][j]=0;
}

}

}
}

int con=0;

for(int u=1;u<=n;u++)
{
   int con2=0;

for(int p=1;p<=m-1;p++)
if(a[u][p]!=0)con2++;

if(con2==0 && a[u][m]!=0)
con=1;

}






if(con)
{cout<<"sistem incompatibil"<<endl;
sca2d(a,n,m);
}
}


template<typename R>
R** copym(R**b,int n,int m,int i=1,int j=1)
{
   R** nm=new R*[n+2];
   for(int i=0;i<=n;i++)
   nm[i]=new R[m+2];


for(;i<=n;i++)
for(;j<=m;j++)
   if(nm[i][j]=b[i][j])

   return nm;
}


///makes a matrix with the average number of a and b
template<typename T>
 T** matrix(int n,int m,int a=2,int b=2)
{

T** ma=new T*[n+2];
for(int i=1;i<=n;i++)
   ma[i]=new T[m+2];


   for(int i=1;i<=n;i++)
   {

   for(int j=1;j<=m;j++)
   {
       ma[i][j]=(a+b)/2;
      // cout<<ma[i][j];
   }
//cout<<endl;
   }

   //cout<<"gata"<<endl;
return ma;

}












///special matrix without first column and line
template<typename T>
T** spm1(T** a,int n,int m)
{

   T** u;
   u=new T*[n+2];

   for(int i=1;i<=n;i++)
   u[i]=new T[m+2];

   for(int i=2;i<=n;i++)
   for(int j=2;j<=m;j++)
     u[i-1][j-1]=a[i][j];

   u[1][0]=n-1;
   u[2][0]=m=1;


return u;

}
///special matrix without first column and

template<typename T>
T** spm2(T** a,int n,int m)
{
   T** u;
   u=new T*[n+1];

   for(int i=1;i<=n;i++)
   u[i]=new T[m+1];


   for(int i=1;i<=n;i++)
   for(int j=2;j<=m;j++)
     u[i][j-1]=a[i][j];

   u[1][0]=n;
   u[2][0]=m=1;


return u;

}




template<typename T>
int rankm(T** a,int n,int m=0)
{
   if(m==0)m=n;
   int  maxi=0;
   T maxv=0;

   T** p=copym(a,n,m);




   for(int i=1;i<=n;i++)
    if(abs(a[i][1])>=maxv){maxv=abs(a[i][1]);maxi=i;}


    for(int i=1;i<=m;i++)
    {
       T aux=a[1][i];
        a[1][i]=a[maxi][i];
        a[maxi][i]=aux;
    }

    sca2d(a,n,m);


   if(n==1 || m==1)
      if(maxv)return 1;
   else return 0;

    if(maxv)
      {

         for(int i=2;i<=n;i++)
         {
            T u=a[i][1];

         for(int j=1;j<=m;j++)
         {
            a[i][j]-=u*(a[1][j]/a[1][1]);
         }

         }

        return 1+rankm(spm1(a,n,m),n-1,m-1);
      }
        else
         {
         return rankm(spm2(a,n,m),n,m-1);
        }



}

int* tripy(int a,int b)
{
   int* sol=new int[4];



   sol[1]=a*a-b*b;
   sol[2]=2*a*b;

   sol[3]=a*a+b*b;

return sol;
}


struct geom_prb
{

   double p,MAX=500,MIN=0;
   double* probs;


  void prob(double o)
  {
     if(o>1)p=1;
     if(o<0)p=0;
     else
     p=o;
  }

  double prob()
  {

     return p;



  }

  ///chance to happen something k times out of n given a probabilty for a given prob.


  double biom(int n,int k)
  {
     return Math.comb(n,k)*sqrm(p,k)*sqrm(1.0-p,n-k);
  }


   ///chance to happen something k times out of n given a probabilty for a given prob.
  ///(probability change power)
   double biom(int n,int k,double pe)
  {
     p=pe;
     return Math.comb(n,k)*sqrm(p,k)*sqrm(1.0-p,n-k);
  }


  ///probability of the k try to be the first success
  double geom(double k)
{
  return sqrm(1-p,k-1)*p;
}

///probability of the k try to be the first success
///(probability change power)


double geom(double k,double pe)
{
  p=pe;
  return sqrm(1-p,k-1)*p;

}






double operator()()
{
int i=randf(MIN,MAX);
return geom(i,p);
}


double rand_biom(int n,int pe=-1)
{
   if(pe>=0 && pe<=1)p=pe;

   int fi=1+rand()%n;
   double pr=biom(n,fi);

   double y=MIN+pr*(MAX-MIN);
   return y;
}


double rand_biom3(int n,int pe=-1)
{
   if(pe>=0 && pe<=1)p=pe;

   int fi=1+rand()%n;
   double pr=biom(n,fi);

   double prs=2;
   do{
   prs=randf(0,1);
   }
   while(prs>pr);

   double y=MIN+prs*(MAX-MIN);
   return y;
}



double cumulative_plus_prob(double* t,int n,int j)
{

   probs=new double[n+1];
   move_d(probs,t,n);

   p=1;

   for(int i=1;i<=n;i++)
   p*=t[i];
   return geom(n,p);
}



double cumulative(int i)
{
   double s;
   for(int j=1;j<i;j++)
   s+=geom(j,p);
   return s;
}




double com3(double n,double sd)
{

   p=1;
   for(int i=0;i<=n;i++)
   p*=((sd-i)/sd);
   return geom(n,p);


}



double mean()
{
   return 1.0/p;
}


double exp_value1(double freq[],int many[],int n)
{
   double c=0;
   for(int i=1;i<=n;i++)
   c+=freq[i]*many[i];
   return c;

}

double mean2(double(*f)(double),double a,double b,double dx=1)
{
   int c=0;
   for(double i=a;i<=b;i+=dx)
   c+=f(i);
   c=c/abs(b-a)*dx;
   return c;



}




double exp_value1(double (*f)(double),int a,int b,double dx=1)
{
   double c=0;
   for(double i=a;i<=b;i+=dx)
      {
         c+=f(i)*i;
      }
   return c;
}


double variancen( double (*f)(double),int n=2,int a=-100,int b=100,double dx=1)
{



   double c=0;
   for(double i=a;i<=b;i+=dx)
    c+=Math.powe(i-exp_value1(f,a,b,dx),n);

return c;


}

double variancen2( double (*f)(double),int n=2,int a=-100,int b=100,double dx=1)
{
   double c=0;
   for(double i=a;i<=b;i+=dx)
    c+=Math.powe(i-mean2(f,a,b,dx),n);

return c;


}





};

template<typename T>
int is_essential_zero(T z)
{
   if((z>=0 && z<0.09) ||(z<=0 && z>-0.09))
    return 1;

    return 0;

}


template<typename T>
void essentialize(T z,int nr)
{
   for(int k=1;k<=nr;k++)
   if((z[k]>=0 && z[k]<0.001) ||(z[k]<=0 && z[k]>-0.001))
   z[k]=0;

}

template<typename T>
void essentialize(T& z)
{

   if((z>=0 && z<0.001) ||(z<=0 && z>-0.001))
   z=0;

}



template<typename T>
T* horner(T a[],int n,int& k)
{
   T* t=new T[n+2];
   int c=1;

   T* copye;

   copye=new T[n+2];



   for(int i=-a[1];i<=a[1];i++)
   {


   cout<<"a[1]"<<a[1]<<endl<<endl;

      if (i!=0 && (int)a[1]%i==0)

      {

   for(int o=1;o<=n+1;o++)
   copye[o]=a[o];


   cout<<"i:"<<i<<endl;

   copye[n+1]=0;


   sca(copye,n);

      for(int j=n;j>=1;j--)
       copye[j]=copye[j+1]*i+copye[j];

sca(copye,n);


if(copye[1]==0)
{
   cout<<"solutie"<<endl;
   k++;t[k]=i;
}
   }


}

   return t;

}

template<typename T>
T* horner3(T a[],int n,int& k)
{
   T* t=new T[n+2];

   int c=1;
k=0;

   T* copye;

   copye=new T[n+2];

   for(int i=-abs(a[1]);i<=abs(a[1]);i++)
   {

      if (i!=0 && (int)a[1]%i==0  )
      {


   for(int o=1;o<=n+1;o++)
   copye[o]=a[o];

   copye[n+1]=0;

      for(int j=n;j>=1;j--)
   copye[j]=copye[j+1]*i+copye[j];


      if( (copye[1]>=0 && copye[1]<0.001) ||(copye[1]<=0 && copye[1]>-0.001))
       {
          copye[1]=0;

           k++;t[k]=i;
       }

}


}

if(a[n]!=1 && a[n]!=-1)
{

for(int i=-abs(a[1]);i<=abs(a[1]);i++)
{

for(int j=-abs(a[n]);j<=abs(a[n]);j++)
{


   int nr=i;
   int nm=j;
   if(nm!=1 && nm!=0 && cmdc(i,j)==1 && (int)a[1]%i==0 && (int)a[n]%j==0)
   {


   for(int o=1;o<=n+1;o++)
   copye[o]=a[o];

   copye[n+1]=0;

      for(int l=n;l>=1;l--)
       copye[l]=(copye[l+1]*nr)/nm+copye[l];


 if( (copye[1]>=0 && copye[1]<0.001) ||(copye[1]<=0 && copye[1]>-0.001))
       {
          copye[1]=0;
           k++;t[k]=(float)nr/nm;
       }



   }
   if(k==n-1)
break;
}
   if(k==n-1)
break;
}

}



   return t;

}



template<typename T>
T* horner2(T a[],int n,double k)
{
   int c=1;

   T* copye;

   copye=new T[n+3];


   for(int o=1;o<=n+1;o++)
   copye[o]=a[o];

   copye[n+1]=0;

      for(int j=n;j>=1;j--)
      {
          copye[j]=copye[j+1]*k+copye[j];

      }

   return copye;

}










template<typename T>
void softmaxss(T a[],int n)
{ double d=0;

   for(int i=1;i<=n;i++)
   d+=Math.expo(a[i]);
    for(int i=1;i<=n;i++)
    a[i]=Math.expo(a[i])/d;

}

template<typename T>
double catcrossent(T b[],T c[],int n)
{ double sum=0;
   for(int i=1;i<=n;i++)
   sum-=b[i]*Math.lon(c[i]);


}












double radical(double x,double rate=1.0)
{

   double md=0;
   if(x>0)
   while(md*md<x)md=md+rate;
   return md;


}


double radical_n(double x,int n,double pas=1,int k=1,double i=1)
{
   if(k==n)
      return i;

  if(k==1)
  {

      double res=i*radical_n(x,n,pas,k+1,i);
    if(x==res)
    {
      return i;
    }
   else
    if(res<x)
      return radical_n(x,n,pas,1,i+pas);
      else
        return i-pas;
  }
  else
   if(k<n)
   return i*radical_n(x,n,pas,k+1,i);



}
template<typename T>
int coliniari(int nr,T* a,T* b)
{
   T c=a[0]/b[0];
   for(int i=0;i<nr;i++)
    if(Math.aps(a[i]/b[i])!=Math.aps(c))
     return 0;

    return 1;





}







struct derivate{

    double f(double x){return  exp(x);}

    double (*f3)(double x);

    double df(double x,double h=0.01){
   return (4*f3(x+h)-3*f3(x)-f3(x+2*h))/(2*h);}


 double Df(double x,double h=0.01){
   return (4*f(x+h)-3*f(x)-f(x+2*h))/(2*h);}





    double df_partiala( int xk,double* x,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.01)
   {

     // cout<<"res:"<<h<<" "<<f2(x)<<" "<<f2(x+h)<<" "<<f2(x+2*h)<<endl;
       double xh[nr+1],xh2[nr+1];
       for(int i=0;i<nr;i++)
         xh[i]=x[i];
         xh[xk-1]+=h;

      for(int i=0;i<nr;i++)
         xh2[i]=x[i];
         xh2[xk-1]+=2*h;

   return (4*f2(xh,nr)-3*f2(x,nr)-f2(xh2,nr))/(2*h)
   ;}

     double df_partiala2( int xk,double x1,double y1,double (*f2)(double x,double y),int l=0,double h=0.01)
   {

       double xh,yh,xh2,yh2;

         xh=x1;
         yh=y1;
         xh2=x1;
         yh2=y1;
         if(xh==1)
         {
             xh+=h;
             xh2+=2*h;
         }
         else
         {   yh+=h;
             yh2+=2*h;

         }


   return (4*f2(xh,yh)-3*f2(x1,y1)-f2(xh2,yh2))/(2*h)



   ;}






  double divergence(double* a,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.01)
   { double sum=0;
       for(int i=0;i<nr;i++)
       sum=sum+df_partiala(i+1,a,nr,f2,l,h);
       return sum;
   }

  double divergence_vector_fild(double* a,int nr,double (*f2[])(double* x,int nr),int l=0,double h=0.01)
   { double sum=0;
       for(int i=0;i<nr;i++)
       sum=sum+df_partiala(i+1,a,nr,f2[i],l,h);
       return sum;
   }
  double* gradient(double* a,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.01)
{

    double* Grad=(double*)(malloc(nr*sizeof(double)));
      for(int i=0;i<nr;i++)
       Grad[i]=df_partiala(i+1,a,nr,f2,l,h);
    return Grad;
}

double* rotor_vector_field(double* a,int nr,double (*f2[3])(double* x,int nr),int l=0,double h=0.01)
{
    double* Rotor=(double*)(malloc(3*sizeof(double)));
    Rotor[0]=df_partiala(2,a,nr,f2[2],l,h)-df_partiala(3,a,nr,f2[1],l,h);
    Rotor[1]=df_partiala(3,a,nr,f2[0],l,h)-df_partiala(1,a,nr,f2[2],l,h);
    Rotor[2]=df_partiala(1,a,nr,f2[1],l,h)-df_partiala(2,a,nr,f2[0],l,h);
return Rotor;
}

double* rotor(double* a,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.01)
{
    double* Rotor=(double*)(malloc(3*sizeof(double)));
    Rotor[0]=df_partiala(2,a,nr,f2,l,h)-df_partiala(3,a,nr,f2,l,h);
    Rotor[1]=df_partiala(3,a,nr,f2,l,h)-df_partiala(1,a,nr,f2,l,h);
    Rotor[2]=df_partiala(1,a,nr,f2,l,h)-df_partiala(2,a,nr,f2,l,h);
    return Rotor;

}
double diferential(double* in_point,double*x,int nr,double (*f2)(double*  x,int nr),int l=0,double h=0.01)
    {
        int sum=0;
        for(int i=0;i<nr;i++)
        sum+=df_partiala(i+1,in_point,nr,f2,l,h)*x[i];

        return sum;
    }



   double df(double x,double (*f2)(double x),int l=0,double h=0.01)
   {
      if(l==1)f3=f2;

     // cout<<"res:"<<h<<" "<<f2(x)<<" "<<f2(x+h)<<" "<<f2(x+2*h)<<endl;


   return (4*f2(x+h)-3*f2(x)-f2(x+2*h))/(2*h)
   ;}

  double dfn_partiale(int n,int* xks,double* x,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.001)
   {
             if(n<=0)
                return f2(x,nr);

       double xh[nr+1],xh2[nr+1];
       for(int i=0;i<nr;i++)
         xh[i]=x[i];
         xh[xks[0]-1]+=h;

      for(int i=0;i<nr;i++)
         xh2[i]=x[i];
         xh2[xks[0]-1]+=2*h;

      if(n==1)
      {

          return (4*f2(xh,nr)-3*f2(x,nr)-f2(xh2,nr))/(2*h);
      }
      else
      {

         double d1=dfn_partiale(n-1,xks+1,xh,nr,f2,l,h),

         d2=dfn_partiale(n-1,xks+1,x,nr,f2,l,h),

         d3=dfn_partiale(n-1,xks+1,xh2,nr,f2,l,h);


         return (4*d1-3*d2-d3)/(2*h);

      }

   }


  double Laplacian(double* a,int nr,double (*f2)(double* x,int nr),int l=0,double h=0.01)
   { double sum=0;

       for(int i=0;i<nr;i++)
       {
           int ord_der[2]={i+1,i+1};
              sum=sum+dfn_partiale(2,ord_der,a,nr,f2,l,h);

       }
      return sum;
   }

  double Laplacian_vector_fild(double* a,int nr,double (*f2[])(double* x,int nr),int l=0,double h=0.01)
   { double sum=0;
       for(int i=0;i<nr;i++){
       int ord_der[2]={i+1,i+1};
              sum=sum+dfn_partiale(2,ord_der,a,nr,f2[i],l,h);
              }
       return sum;
   }


double diferential_n(int n,int* order,double* in_point,double*x,int nr,double (*f2)(double*  x,int nr),int k=0,int l=0,double h=0.01)
    {
        if(k==n)
    {
    double prod=1,dif;
    for(int i=0;i<n;i++)
       prod*=x[order[i]-1];
        dif=dfn_partiale(n,order,in_point,nr,f2,l,h);

        return prod*dif;
    }
    else
    { double sum=0;

         for(int i=0;i<nr;i++)
      { order[k]=i+1;

          sum+=diferential_n(n,order,in_point,x,nr,f2,k+1,l,h);
      }

        return sum;
    }

    }

 double dfn(double x,double (*f2)(double x),int n,int l=0,double h=0.01)
   {

      if(n==1)
       return  (4*f2(x+h)-3*f2(x)-f2(x+2*h))/(2*h);

      else
      {
               cout<<n<<endl;
         double d1=dfn(x+h,f2,n-1,l,h),
         d2=dfn(x,f2,n-1,l,h),
         d3=dfn(x+2*h,f2,n-1,l,h);

         return (4*d1-3*d2-d3)/(2*h);

      }


   }

   float* Maclaurin(int n,double (*f2)(double x),int l=0,double h=0.01)
   {

      float* mac=new float[n+5];

      mac[1]=f2(0);

      for(int i=2;i<=n+1;i++)
      mac[i]=dfn(0,f2,i-1)/Math.fact(i-1);


      return mac;
   }

   float* Taylor(int a,int n,double (*f2)(double x),int l=0,double h=0.01)
   {

      float* mac=new float[n+5];

      mac[1]=f2(a);

      for(int i=2;i<=n+1;i++)
      mac[i]=dfn(a,f2,i-1)/Math.fact(i-1);


      return mac;
   }

double* Taylor_multi(int nt,double* a,double* in_point,int n,double (*f2)(double* x,int nr),int l=0,double h=0.01)
   {

      double* mac=(double*)malloc((nt+2)*sizeof(double));



      double nx[n+1];
      for(int i=0;i<n;i++)
        nx[i]=a[i]-in_point[i];



      mac[0]=f2(a,n);



      for(int i=0;i<nt;i++)
      {
          int order[i+2];

          mac[i+1]= diferential_n(i+1,order,in_point,nx,n,f2,0,l,h)/Math.fact(i+1);
      }

      return mac;
   }
double aprox_Taylor_multi(int nt,double* a,double* in_point,int n,double (*f2)(double* x,int nr),int l=0,double h=0.01)
{
    double* T= Taylor_multi( nt, a, in_point,n,f2,l, h);
    int sums=0;
    for(int i=0;i<nt;i++)
    sums+=T[i];
    return sums;



}

double** hesian(double (*f)(double* x,int nr),double* in_point,int n)
{  double**H=(double**)malloc(n*sizeof(double*));

for(int i=0;i<n;i++)
  H[i]=(double*)malloc(n*sizeof(double));


    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
    {
       int order[2]={i+1,j+1};
      H[i][j]=dfn_partiale(2,order,in_point,n,f,1);


    }
    return H;
}
double** jacobian(double (*f[])(double* x,int nr),int m,double* in_point,int n)
{  double**J=(double**)malloc(m*sizeof(double*));
   for(int i=0;i<m;i++)
   J[i]=(double*)malloc(n*sizeof(double));

    for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
    {
        double p=df_partiala(j+1,in_point,n,f[i],1);
      J[i][j]=p;

    }
    return J;
}

double Lagrangean(double (*f[])(double* x,int nr),int m,double* in_point,int n,double* L)
{
    double rez=0;
    rez=f[0](in_point,n);
    for(int i=1;i<m;i++)
    rez+=L[i-1]*f[i](in_point,n);
    return rez;


}

double df_implicit(double (*f)(double* x,int nr),double* in_point,int n)
{
    double dx=df_partiala(1,in_point,n,f,1);
    double dy=df_partiala(2,in_point,n,f,1);


    if(dy)
    return dx/dy;
    else
    printf("nu exista derivata pt functia implicita\n");

}






};

struct Slope
{
   char descrip[100];
   int seted=0;
   double f(double x);

   double (*f1)(double x);
   float m;

  float xo,fxo;


double t(double x0,double (*f)(double),double x=1,int save=0)
{
derivate dx;
int fx=f(x0);
double Dx=dx.df(x0,f);

if(x0>=0 && fx>=0 && Dx>=0)
cout<<"t: y - "<<fx<< " - " <<Dx<<"*( x - "<<x0<< ") = 0"<<endl;

//000
if(x0<0 && fx<0 && Dx<0)
cout<<"t: y + "<<-fx<<" + "<<-Dx<<"*( x + "<<-x0<<" ) = 0"<<endl;
//110
if(x0>=0 && fx>=0 && Dx<0)
cout<<"t: y - "<<f(x0)<<" + "<<Dx<<"*( x -"<<x0<<" ) = 0"<<endl;
//101
if(x0>=0 && fx<0 && Dx>=0)
cout<<"t: y + "<<f(x0)<<" - "<<Dx<<"*( x - "<<x0<<" ) = 0"<<endl;

//011
if(x0<0 && fx>=0 && Dx>=0)
cout<<"t: y - "<<f(x0)<<" - "<<Dx<<"*( x + "<<-x0<<" ) = 0"<<endl;

// 001
if(x0<0 && fx<0 && Dx>=0)
cout<<"t: y + "<<-f(x0)<<" - "<<Dx<<"*( x + "<<-x0<<" ) = 0"<<endl;
//010
if(x0<0 && fx>=0 && Dx<0)
cout<<"t: y -"<<f(x0)<<" + "<<-Dx<<"*( x + "<<-x0<<" ) = 0"<<endl;

//100
if(x0>=0 && fx<0 && Dx<0)
cout<<"t: y +"<<-f(x0)<<" + "<<-Dx<<"*( x - "<<x0<<" ) = 0"<<endl;

if(save==1)
{m=Dx;xo=x0;fxo=fx;seted=1;}
   return Dx*(x-x0)+f(x0);


}


double t_y(double x)
{

return m*(x-xo)+fxo;

}


double solution(double y)
{
return (y-fxo)/m+xo;

}


void afisare_t()
{

   if(xo>=0 && fxo>=0 && m>=0)
cout<<"t: y - "<<fxo<< " - " <<m<<"*( x - "<<xo<< " ) = 0"<<endl;

//000
if(xo<0 && fxo<0 && m<0)
cout<<"t: y + "<<-fxo<<" + "<<-m<<"*( x + "<<-xo<<" ) = 0"<<endl;
//110
if(xo>=0 && fxo>=0 && m<0)
cout<<"t: y - "<<fxo<<" + "<<m<<"*( x -"<<xo<<" ) = 0"<<endl;
//101
if(xo>=0 && fxo<0 && m>=0)
cout<<"t: y + "<<fxo<<" - "<<m<<"*( x - "<<xo<<" ) = 0"<<endl;

//011
if(xo<0 && fxo>=0 && m>=0)
cout<<"t: y - "<<fxo<<" - "<<m<<"*( x + "<<-xo<<" ) = 0"<<endl;

// 001
if(xo<0 && fxo<0 && m>=0)
cout<<"t: y + "<<-fxo<<" - "<<m<<"*( x + "<<-xo<<" ) = 0"<<endl;
//010
if(xo<0 && fxo>=0 && m<0)
cout<<"t: y -"<<fxo<<" + "<<-m<<"*( x + "<<-xo<<" ) = 0"<<endl;

//100
if(xo>=0 && fxo<0 && m<0)
cout<<"t: y +"<<-fxo<<" + "<<-m<<"*( x - "<<xo<<" ) = 0"<<endl;


}







};


int divide_by_2(int x)
{
   return x>>1;

}


double* fxp=NULL;

double function_poli(double x)
{

   double s=0;

   if(fxp)
   {
      int n=fxp[0];
      for(int i=1;i<=n;i++)
      s+=fxp[i]*pow(x,i-1);
   }

   return s;
}




double Newton_Raphson(double (*f)(double),int& gs, double aprx=0)
{
   derivate d;
   double b=aprx;
   double b2;

      b2=b-f(b)/( d.df(b,f));

int nr_steps=0;
   while(abs(b2-b)>0.0009 && nr_steps<500)
       {

          b=b2;
          b2=b-(f(b)/( d.df(b,f)));

            //cout<<b2<<" "<<b<<endl;
          nr_steps++;

       }

gs=1;

    if(nr_steps==500)
      {b2=0;
      gs=0;}

return b2;

}
double* diference_vectors(double* a,double*b,int nr)
{

    double* c=(double*)malloc(nr*sizeof(double));

    for(int i=0;i<nr;i++)
    c[i]=a[i]-b[i];

    return c;

}
double* sum_vectors(double* a,double*b,int nr)
{

    double* c=(double*)malloc(nr*sizeof(double));

    for(int i=0;i<nr;i++)
    c[i]=a[i]+b[i];

    return c;

}
void prod_s_v(double q,int nr,double* a)
{
    for(int i=0;i<nr;i++)
    a[i]=q*a[i];
}
double norma(double* a,int nr)
{

    double sum=0;
    for(int i=0;i<nr;i++)
    sum+=a[i]*a[i];

    sum=sqrt(sum);
    return sum;
}





double* Newton_Raphson(int nr,double (*f)(double*,int),int& gs, double* aprx=NULL)
{
   derivate d;

   double* b=aprx;
   if(b==NULL)
   {
       b=(double*)malloc(sizeof(double)*nr);
       for(int i=0;i<nr;i++)
        b[i]=0;
   }



   double* b2;




int nr_steps=0;
do{

   double* gr=d.gradient(b,nr,f);
   printf("merge gradientul\n");

   for(int i=0;i<2;i++)
   printf("%f ",gr[i]);
   printf("\n");


   double v_norm=norma(gr,nr);



   prod_s_v(f(b,nr)*1.0/v_norm,nr,gr);









  free(b2);
  b2=diference_vectors(b,gr,nr);
  free(gr);
  free(b);
  b=b2;

 for(int i=0;i<2;i++)
   printf("%f ",b[i]);
   printf("\n");

       nr_steps++;

 printf("merge si asta\n");








       }while(nr_steps<500 && abs(f(b,nr))>0.001) ;



return b2;

}

double** shift_matrix(double** A,int n)
{
double ** B=(double**)malloc(sizeof(double*)*(n+2));

for(int i=0;i<=n;i++)
B[i]=(double*)malloc(sizeof(double)*(n+2));

for(int i=0;i<n;i++)
for(int j=0;j<=n;j++)
B[i+1][j+1]=A[i][j];

return B;


}

double* multiply_arr_f_matrix(double (*f[])(double*,int),double** matx,double*x ,int nr)
{
    double* y=(double*)malloc(sizeof(double)*nr);
    for(int i=0;i<nr;i++)
    y[i]=0;

    for(int i=1;i<=nr;i++)
        for(int j=1;j<=nr;j++)
    y[i-1]=y[i-1]+matx[i][j]*f[j-1](x,nr);

    return y;

}

double* multiply_arr_matrix(double* vx,double** matx ,int nr)
{
    double* y=(double*)malloc(sizeof(double)*nr);
    for(int i=0;i<nr;i++)
    y[i]=0;

    for(int i=1;i<=nr;i++)
        for(int j=1;j<=nr;j++)
    y[i-1]=y[i-1]+matx[i][j]*vx[j-1];

    return y;

}


double* Newton_Raphson(int nr,double (*f[])(double*,int),int& gs, double* aprx=NULL)
{
   derivate d;


   double* b=aprx;
   if(b==NULL)
   {
       b=(double*)malloc(sizeof(double)*nr);
       for(int i=0;i<nr;i++)
        b[i]=0;
   }





   double* b2;


int t;

int nr_steps=0;
do{
        t=1;
 double c=0;


  double** jac=shift_matrix(d.jacobian(f,nr,b,nr),nr);
  printf("jacobian\n");
  sca2d(jac,nr,nr,1);
  double** inv_j=inversa(jac,nr,c);

  printf("c=%f\n",c);
  printf("inversa\n");
  sca2d(inv_j,nr,nr,1);





  double* d=NULL;
  d=multiply_arr_f_matrix(f,inv_j,b,nr);
if(d!=NULL)
   {
       sca(d,nr,0,0);
       printf("aici1\n");
   prod_s_v(c,nr,d);
   printf("aici2\n");



  b2=diference_vectors(b,d,nr);
 free(b);
 free(d);
 free(inv_j);
 free(jac);
 b=b2;


 for(int i=0;i<nr;i++)
   printf("%f ",b[i]);
   printf("\n");
   }
       nr_steps++;

 printf("merge si asta\n");



for(int i=0;i<nr;i++)
   if(abs(f[i](b,nr))>0.0001)
        t=0;


       }while(nr_steps<500 && t==0);


return b2;

}




double* find_extremes_mv(int nr,double (*f)(double*,int),int& gs, double* aprx=NULL)
{
   derivate d;


   double* b=aprx;
   if(b==NULL)
   {
       b=(double*)malloc(sizeof(double)*nr);
       for(int i=0;i<nr;i++)
        b[i]=0;
   }





   double* b2;


int t;

int nr_steps=0;
do{
        t=1;
 double c=0;

  double* gr=d.gradient(b,nr,f);
  double** jac=shift_matrix(d.hesian(f,b,nr),nr);
  jac=transp(jac,nr);
  printf("hesian\n");
  sca2d(jac,nr,nr,1);
  double** inv_j=inversa(jac,nr,c);

  printf("c=%f\n",c);
  printf("inversa\n");
  sca2d(inv_j,nr,nr,1);





  double* d=NULL;
  d=multiply_arr_matrix(gr,inv_j,nr);
if(d!=NULL)
   {
       scap(d,nr-1,0);
       printf("aici1\n");
   prod_s_v(c,nr,d);
   scap(d,nr-1,0);
   printf("aici2\n");



  b2=diference_vectors(b,d,nr);

// free(b);
// free(d);
// free(inv_j);
// free(jac);
 b=b2;
printf("nu asta\n");

 for(int i=0;i<nr;i++)
   printf("%f ",b[i]);
   printf("\n");
   }
       nr_steps++;

 printf("merge si asta\n");
 derivate der;

  gr=der.gradient(b,nr,f);
for(int i=0;i<nr;i++)
   if(abs(gr[i])>0.0001)
        t=0;


       }while(nr_steps<500 && t==0);


return b;

}











double (*Lf)(double x)=NULL;





double lf(double x)
{

if(Lf)
return Math.lon(Lf(x));
return NULL;

}







struct integrala
{

double a,b,x,n;
double f(double x);
double (*f3)(double x);

    double S(double a2,double b2,int l=0,int n2=400)
    {  while(b2-a2 >n2)n2=n2*10;
double d=(b2-a2)/n2,s=0;
       // cout<<d<<endl;
        s+=f(a2)+f(b2);
       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
    s+=2*f(a2+i*d);

    if(l==1){a=a2;b=b2;n=n2;}
       // cout<<s<<endl;}
        s=s*(d/2);
        return s;

}
template<typename T>
double S(double a2,double b2,T f2,int l=0,int n2=400)
    {





       if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;


      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;
       // cout<<d<<endl;
        s+=f2(a2)+f2(b2);
       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        s+=2*f2(a2+i*d);
        //cout<<s<<endl;}
        s=s*(d/2);
        return s;

}
template<typename T>
double Sr(double a2,double b2,T f2,int l=0,int n2=400)
    {





       if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;


      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;
       // cout<<d<<endl;
        s+=f2(a2)+f2(b2);


       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        { float ist=randf(a2+i*d-d,a2+i*d);
            s+=2*f2(ist);
        }

        //cout<<s<<endl;}
        s=s*(d/2);
        return s;

}
double Area(double a2,double b2,double (*f2)(double x) ,int l=0,int n2=400)
{

       if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;


      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;
       // cout<<d<<endl;
        s+=abs(f2(a2))+abs(f2(b2));
       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        s+=2*abs(f2(a2+i*d));

        s=s*(d/2);
        return s;




}
















double Arc_lenght(double a2,double b2,double (*f2)(double),int l=0,int n2=400)
{

     while((b2-a2)*100>n2)
              n2=n2*10;
      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;


   derivate dx;

   dx.f3=f2;

    double dx0=dx.df(a2);
    double dxn=dx.df(b2);

       // cout<<d<<endl;


        s+=sqrt(1+dx0*dx0)+sqrt(1+dxn*dxn);

      for(int i=1;i<n2;i++)
{
   double dx1=dx.df(a2+i*d);
   s+=2*sqrt(1+dx1*dx1);

}
        s=s*(d/2);
        return s;

}





double Arc_lenght(double a2,double b2,int n2=400)
{
     while((b2-a2)*100>n2)
              n2=n2*10;

double d=(b2-a2)/n2,s=0;

   derivate dx;

   dx.df(5,f3,1);

    double dx0=dx.df(a2);
    double dxn=dx.df(b2);

       // cout<<d<<endl;

      s+=sqrt(1+dx0*dx0)+sqrt(1+dxn*dxn);
      for(int i=1;i<n2;i++)
{
   double dx1=dx.df(a2+i*d);
   s+=2*sqrt(1+dx1*dx1);

}
        s=s*(d/2);
        return s;

}

double Volume_r(double a2,double b2,double (*f2)(double x) ,int l=0,int n2=400)
{
         if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;

      if(l==1){a=a2;f3=f2;b=b2;n=n2;}
double d=(b2-a2)/n2,s=0;

       // cout<<d<<endl;
        s+=f2(a2)*f2(a2)+f2(b2)*f2(b2);
       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        s+=2*f2(a2+i*d)*f2(a2+i*d);
        //cout<<s<<endl;}
        s=s*(d/2);
        s=s*pi;


        return s;
}

double Volume_r2(double a2,double b2,int l=0,int n2=400)
{
         if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;

     // if(l==1){a=a2;f3=f2;b=b2;n=n2;}
double d=(b2-a2)/n2,s=0;

       // cout<<d<<endl;
        s+=f(a2)*f(a2)+f(b2)*f(b2);
       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        s+=2*f(a2+i*d)*f(a2+i*d);
        //cout<<s<<endl;}
        s=s*(d/2);
        s=s*pi;


        return s;
}



double Volume_rl(double a2,double b2,double r1,double r2,int l=0,int n2=400)
{
         if(n2<(b2-a2)*10)
         do{
              n2=n2*10;
         } while((b2-a2)*100>n2);

double d=(b2-a2)/n2,s=0;


   double p=(r2-r1)/(b2-a2);
   double bi=r1;




        s+=(bi)*(bi)+((b2-a2)*p+bi)*((b2-a2)*p+bi);

        for(int i=1;i<n2;i++)
        s+=2*(((i*d)*p+bi)*((i*d)*p+bi));


        s=s*(d/2);
        s=s*pi;


        return s;

}


double Surface_aria(double a2,double b2,double (*f2)(double),int l=0,int n2=400)
{
    while((b2-a2)*100>n2)
              n2=n2*10;
      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;

   derivate dx;

   dx.f3=f2;

    double dx0=dx.df(a2);
    double dxn=dx.df(b2);

        s+=f2(a2)*sqrt(1+dx0*dx0)+f2(b2)*sqrt(1+dxn*dxn);

      for(int i=1;i<n2;i++)
{
   double dx1=dx.df(a2+i*d);
   s+=2*f2(a2+i*d)*sqrt(1+dx1*dx1);

}



        s=s*(d/2);
        s=s*2*pi;
        return s;
}

double Surface_aria(double a2,double b2,int n2=400)
{
     while((b2-a2)*100>n2)
              n2=n2*10;

double d=(b2-a2)/n2,s=0;

   derivate dx;

   dx.df(5,f3,1);

    double dx0=dx.df(a2);
    double dxn=dx.df(b2);

       // cout<<d<<endl;

      s+=f3(a2)*sqrt(1+dx0*dx0)+f3(b2)*sqrt(1+dxn*dxn);
      for(int i=1;i<n2;i++)
{
   double dx1=dx.df(a2+i*d);
   s+=2*f3(a2+i*d)*sqrt(1+dx1*dx1);

}
        s=s*(d/2);
        s=s*2*pi;
        return s;

}


double Volume_sqpyr(double h,double bl,double bL,double y=0,int n2=400)
{
   double d=(h-x)/n2;

   double wc=bl/h;
   double lc=bL/h;
   double ing;
   double vs=0;
   double as;
   as=y*y*wc*lc;
   vs+=as;

   as=h*h*wc*lc;
   vs+=as;

   for(y=y+d;y<h;y+=d)
   {
    ing=wc*lc*(h-y)*(h-y);
    as=2*ing;
     vs+=as;
   }

   vs=vs*d/2;

   return vs;


}

double Volume_trpyr(double H,double ba,double h,double y=0,int sd=-1,int n2=400)
{
   while(n2<(H-y)*10)
      n2=n2*20;

double d=(H-y)/n2;

   double wc=ba/H;
   double lc=h/H;
   double ing;
   double vs=0;
   double as;

   as=y*y*wc*lc;
   vs+=as;

   as=H*H*wc*lc;
   vs+=as;


   for(int i=1;i<n2+sd;i++)
   {
      y+=d;
    ing=wc*lc*(y)*(y);
    as=ing;
     vs+=as;
   }
   vs=vs*d/2;

   return vs;


}


double Volume_sphere(double r,double y=0,int n2=400)
{
    while(n2<(r-y)*10)
      n2=n2*20;

   double d=(r-y)/n2;


   double ing;
   double vs=0;
   double as=0;
   as=r*r-y*y;
   vs+=as;


   for(int i=1;i<=n2;i++)
   {

      y+=d;

    ing=r*r-y*y;

    as=2*ing;
     vs+=as;

   }

   vs=vs*d;
  vs=pi*vs;
   return vs;


}







double Area_circle(double r,double x=0,int n2=400)
{
   while(n2<(r-x)*100)
      n2*=10;

   double d=(r-x)/n2;


   double vs=0;

   vs+=2*pi*r;

   for(int i=1;i<n2;i++)
   {
      x=x+d;
      double intg=2*pi*x;
      vs+=2*intg;
   }

   vs=vs*d/2;
   return vs;


}

double Area_between_curves(double a2 ,double b2,double(*fa)(double),double(*fb)(double),int l=1,int n2=400)
{


    if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;

double d=(b2-a2)/n2,s=0;





if(fa(a2)-fb(a2)>fb(a2)-fa(a2))
      s+=fa(a2)-fb(a2);
else
   s+=fb(a2)-fa(a2);



if(fa(b2)-fb(b2)>0)
   s+=fa(b2)-fb(b2);
   else
   s+=fb(b2)-fa(b2);

        for(int i=1;i<n2;i++)
        {



           if(fa(a2+i*d)-fb(a2+i*d)>0)
            s+=2*(fa(a2+i*d)-fb(a2+i*d));
            else
            s+=2*(fb(a2+i*d)-fa(a2+i*d));
        }

        s=s*(d/2);
        return s;

}





double Surface_3d_rounded(double a2 ,double b2 ,double (*f2)(double),int l=1,int n2=400)
{
       if(n2<b2-a2)
       while((b2-a2)*100>n2)
              n2=n2*10;

              derivate D;

      if(l==1){a=a2;f3=f2;b=b2;n=n2;}

double d=(b2-a2)/n2,s=0;

double df=D.df(a2,f2);

// cout<<f2(a2)*df<<endl;
        s+=f2(a2)*sqrt(1+df*df);

        df=D.df(b2,f2);
         //cout<<f2(b2)*df<<endl;

        s+=f2(b2)*sqrt(1+df*df);

       // cout<<s<<endl;
        for(int i=1;i<n2;i++)
        {


        df=D.df(a2+i*d,f2);

        // cout<<a2+i*d<<" "<<f2(a2+i*d)<<" "<<df<<endl;

         s+=2*f2(a2+i*d)*sqrt(1+df*df);
        }


        s=s*(d/2);
        s=s*2*pi;
        return s;



}
























double product_integral(double a2,double b2,double(*f5)(double),int sv=0)
{

Lf=f5;
return exp(S(a2,b2,lf,sv));








}












double mv(double a2,double b2,double(*f5)(double),int sv=0)
{
   if(a2>b2)
switchy(b2,a2);

  double raw=S(a2,b2,f5,sv);
  return raw/(b2-a2);

}










template<typename ...arg>
double multiple_integral(double (*f2)(double*),double* x,int l=1,int n2=400,double a2=0,double b2=0)
{




while(n2<(b2-a2)*100)n2=n2*10;

double d=(b2-a2)/n2;
double s=0;




x[l]=a2;

s+=f2(x);


x[l]=b2;


s+=f2(x);

for(int i=1;i<n2;i++)
{

   double c=a2+i*d;

x[l]=c;




   s+=2*f2(x);



}

s=s*d/2;


return s;

}




template<typename ... art>
double multiple_integral(double (*f2)(double*),double* x,int l=1,int n2=400,double a2=0,double b2=0,art... t)
{
while(n2<(b2-a2)*100)n2=n2*10;

double d=(b2-a2)/n2;

double s=0;

x[l]=a2;
s+=multiple_integral(f2,x,l+1,n2,t...);


x[l]=b2;
s+=multiple_integral(f2,x,l+1,n2,t...);


for(int i=1;i<n2;i++)
{
   double c=a2+i*d;

   x[l]=c;

   s+=2*multiple_integral(f2,x,l+1,n2,t...);

}

s=s*d/2;


return s;
}



} ;


double erfS(double x)
{
    integrala a;
    if(x<-3.7)
        return -1;
    if(x>3.7)
        return  1;

    return a.S(0,x,[](double x)->double{ return 2.0/sqrt(pi)*Math.expo(-x*x);} );

}



double gammaS(double z,double aprox=100,double n2=1000)
{

      z=z;
   double a2=0, b2=aprox;

    double d=1.0/n2,s=0;

    double f=pow(b2,z)*exp(-b2);
    s+=f;

int i=1;
double ia=1;
   while(i*d<b2)
      {

        ia=2;
         s+=ia*pow(i*d,z)*exp(-i*d);

         i++;
      }

    s=s*d;
    return s;

}

double bethaS(double a,double b,double n2=15500)
{

     double a2=0, b2=1.0;
     double d=1.0/n2,s=0;
    int i=0;
    while(i*d<=b2)
    {
         if(i*d!=0 && 1.0-i*d!=0)
        s+=pow(i*d,a-1)*pow(1.0-i*d,b-1);
        i++;
    }

    s=s*d;

    return s;





return (gammaS(a)*gammaS(b))/gammaS(a+b);
}












double betaS(double x,double y,double n2=100)
{

    double d=1.0/n2,s=0;

    for(float i=0;i<=1.0-d;i+=d)
           s+=2*pow(i,x-1)*pow(1.0-i,y-1)*d;

    s=s*(d/2);
    return s;
}








///returns 1 or 0
int same_chars(char* s1,char* s2)
{
   if(strlen(s1)!=strlen(s2))
    return 0;

    char c1,c2;
    for(int i=0;i<strlen(s1);i++)
    {

        if(s1[i]>='A' && s1[i]<='Z')
       c1=s1[i]+'a'-'A';
       else
       c1=s1[i];

         if(s2[i]>='A' && s2[i]<='Z')
       c2=s2[i]+'a'-'A';
          else
       c2=s2[i];

       if(c1!=c2)
       return 0;

    }

return 1;

}


void Caps_off(char* s1)
{
  int n=strlen(s1);

   for(int i=0;i<n;i++)
   {



  if(s1[i] >='A' && s1[i]<='Z')
   s1[i]=s1[i]+('a'-'A');

   }



}





void Caps_on(char* s1)
{
   for(int i=0;i<strlen(s1);i++)
   if(s1[i]>='a' && s1[i]<='z')
   s1[i]=s1[i]-('a'-'A');

}







int shortcuts_chars(char* sh,char* com)
{
   char* temp=new char[strlen(com)+1];

   for(int i=0;i<strlen(sh);i++)
   temp[i]=com[i];

   temp[strlen(sh)]='\0';

   return same_chars(sh,temp);
}


int derived_chars(char* sh,char* com)
{
   char* temp;

   if(strlen(com)>=strlen(sh))
   {
   temp=new char[strlen(com)+1];
   for(int i=0;i<strlen(sh);i++)
   temp[i]=com[i];

   temp[strlen(sh)]='\0';


         return same_chars(sh,temp);
   }
   else
   {

   temp=new char[strlen(sh)+1];
   for(int i=0;i<strlen(com);i++)
   temp[i]=sh[i];

   temp[strlen(com)]='\0';

         return same_chars(com,temp);

   }



}



int too_manyless_letters (char* s1,char* s2)
{
   char* aux1=new char[strlen(s1)+1];
   char* aux2=new char[strlen(s1)+1];

   Caps_off(s1);
   Caps_off(s2);

   int k1=0,k2=0;

   char now1=s1[0],now2=s2[0];

   k1++;
   k2++;

   aux1[0]=now1;
   aux2[0]=now2;

   for(int i=0;i<=strlen(s1);i++)
   {
      if(s1[i]!=now1)
      {
         k1++;aux1[k1-1]=s1[i];
      now1=s1[i];
      }
   }
aux1[k1]='\0';


      for(int i=0;i<=strlen(s2);i++)
   {
      if(s2[i]!=now2)
      {
         k2++;aux2[k2-1]=s2[i];
      now2=s2[i];
      }

   }
aux2[k2]='\0';

cout<<aux1<<" "<<aux2<<endl;



      if(k1!=k2)
   return 0;


   for(int i=0;i<k1;i++)
   if(aux1[i]!=aux2[i])




      return 0;

   delete aux1;
   delete aux2;

return 1;


}

int too_manyless_letters_bigsmall (char* s1,char* s2)
{

   char* aux1=new char[strlen(s1)+1];
   char* aux2=new char[strlen(s1)+1];

Caps_off(s1);
Caps_off(s2);

   int k1=0,k2=0;


   char now1=s1[0],now2=s2[0];

   k1++;
   k2++;

   aux1[0]=now1;
   aux2[0]=now2;

   for(int i=0;i<=strlen(s1);i++)
   {
      if(s1[i]!=now1)
      {
         k1++;aux1[k1-1]=s1[i];
      now1=s1[i];
      }
   }
aux1[k1]='\0';

      for(int i=0;i<=strlen(s2);i++)
   {
      if(s2[i]!=now2 )
      {

         k2++;
         aux2[k2-1]=s2[i];
      now2=s2[i];
      }
   }

aux2[k2]='\0';

cout<<aux1<<" "<<aux2<<endl;


   if(k1!=k2)
   return 0;



return same_chars(s1,s2);

}
struct Fourier_helper
{

    int n;
    double (*f)(double);




}FourierH;

void Fourier_coeficients(int n,double (*fun)(double),float* an,float* bn)
{


FourierH.n=n;
FourierH.f=fun;



    integrala ig;
   *an=(1.0/pi)*ig.S(-pi,pi,[](double x)
         {
            return FourierH.f(x)*Math.cosa(deg_angle(FourierH.n*x));

         });
    *bn=(1.0/pi)*ig.S(-pi,pi,[](double x)
         {
            return FourierH.f(x)*Math.sina(deg_angle(FourierH.n*x));

         });




}



































struct{

private:
template<typename T>
double help_Levenshtein(T s1,T s2,int len1,int len2)
{

   int cost=0;
   int** d;

   d=new int*[len2+3];

   for(int i=1;i<=len2+1;i++)
{

d[i]=new int[len1+3];

d[i][1]=i-1;
d[1][1]=0;

 for(int j=2;j<=len1+1;j++)
 {
    if(i==1)
    d[1][j]=j-1;
      else
    d[i][j]=0;
 }


}


       for(int i=2;i<=len2+1;i++)
     for(int j=2;j<=len1+1;j++)
   {
if(s2[i-2]==s1[j-2])
      cost=0;
      else
      cost=1;

      d[i][j]=min(
               (int)min(d[i-1][j]+1,   //deletion
                   d[i][j-1]+1     //insertion
                  ),
                    d[i-1][j-1]+cost
               );
   }


double dr=d[len2+1][len1+1];


   delete d;
return dr;

}

template<typename T>
double help_Levenshtein2(T s1,T s2,int len1,int len2,double c1=2,double c2=1)
{

   double cost=0,c;
   double** d;

   d=new double*[len2+3];

   for(int i=1;i<=len2+1;i++)
{

d[i]=new double[len1+3];

d[i][1]=i-1;
d[1][1]=0;

 for(int j=2;j<=len1+1;j++)
 {
    if(i==1)
    d[1][j]=j-1;
      else
    d[i][j]=0;
 }


}


       for(int i=2;i<=len2+1;i++)
     for(int j=2;j<=len1+1;j++)
   {

if(s2[i-2]==s1[j-2])
      cost=0;
      else
         {

            int off=1+len1%2;

            if(j<=len1/2+off)
              {cost=c1;
            c=c1
            ;
            }
              else
              {cost=c2;c=c2;}

          }


      d[i][j]=min(
               (double)min(
                   d[i-1][j]+c,   //deletion
                   d[i][j-1]+c     //insertion
                  ),
                    d[i-1][j-1]+cost //substitution
               );

cout<<"simms:"<<len1<<" "<<" "<<i<<" "<<j<<" "<<s1[j-2]<<" "<<s2[i-2]<<" "<<cost<<" "<<d[i][j]<<endl;

   }


double dr=d[len2+1][len1+1];


   delete d;

   cout<<"this matrix"<<endl;
  // sca2d(d,len2+1,len2+1);



return dr;

}


public:


template<typename T>
double Levenshteing(T s1,T s2,int n,int m)
{
return help_Levenshtein(s1,s2,n,m);
}


double Levenshtein(char* s1,char* s2)
{

return help_Levenshtein(s1,s2,strlen(s1),strlen(s2));


}

double Levenshtein2(char* s1,char* s2,double mxc=2,double mic=1)
{
return help_Levenshtein2(s1,s2,strlen(s1),strlen(s2),mxc,mic);
}

double improved_Levensthein(char* s1,char* s2)
{

  double Lh=Levenshtein(s1,s2);

   cout<<"l:"<<Lh<<" "<<0.8*Math.absinth(strlen(s2)-strlen(s1))<<endl;

 return Lh-0.8*(double)Math.absinth(strlen(s2)-strlen(s1));




}



template<typename T>
double improved_Levenstheing(T s1,T s2,int n,int m)
{
 return Levenshteing(s1,s2,n,m)-0.8*abs(n-m);
}



template<typename T>
double Hammingish(T A[],T B[], int n)
{

   double hamm=0;

    for(int i=1;i<=n;i++)
    if(A[i]!=B[i])
    hamm++;
   return hamm;
}




   template<typename T>
double Euclid(T A[],T B[], int n)
{

   double eucld=0;

    for(int i=1;i<=n;i++)
   eucld=(A[i]-B[i])*(A[i]-B[i]);

    eucld=sqrt(eucld);
   return eucld;
}


   template<typename T>
double Manhattan(T A[],T B[], int n)
{

   double mnhd=0;
    for(int i=1;i<=n;i++)
   mnhd+=abs(A[i]-B[i]);
   return mnhd;
}



   template<typename T>
double similarity(T A[],T B[], int n)
{
   double dp=0,da=0,db=0;
   for(int i=1;i<=n;i++)
   {
      dp+=A[i]*B[i];

      da+=A[i]*A[i];

      db+=B[i]*B[i];
   }

   da=sqrt(da);
   db=sqrt(db);

   return dp/(da*db);
}

template<typename T>
double cosine_dist(T A[],T B[], int n)
{
   return 1.0-similarity(A,B,n);

}
template<typename T>
double angular_distance(T A[],T B[], int n)
{
return arccosa(similarity(A,B,n))/pi;

}

template<typename T>
double angular_similarity(T A[],T B[], int n)
{
return 1.0-angular_distance(A,B,n);
}
template<typename T>
double Tanimoto(T A[],T B[], int n)
{
   double dp=0,da=0,db=0;
   for(int i=1;i<=n;i++)
   {
      dp+=A[i]*B[i];

      da+=A[i]*A[i];

      db+=B[i]*B[i];
   }


   return dp/(da+db-dp);

}

double cataloque(char* c,char A[],char B[], int n)
{
if(same_chars(c,"levenshtein"))
    return Levenshtein(A,B);

  if(same_chars(c,"imprv_levenshtein"))
return improved_Levensthein(A,B);

if(same_chars(c,"euclid"))
     return Euclid(A,B,n);

if(same_chars(c,"manhattan"))
     return Manhattan(A,B,n);


if(same_chars(c,"cos_distance"))
     return cosine_dist(A,B,n);

if(same_chars(c,"angular_distance"))
   return angular_distance(A,B,n);


if(same_chars(c,"hamming"))
     return Hammingish(A,B,n);



if(same_chars(c,"tanimoto"))
     return Tanimoto(A,B,n);


if(same_chars(c,"cos_similarity"))
     return similarity(A,B,n);



if(same_chars(c,"angular_similarity"))
   return angular_similarity(A,B,n);


}

template<typename T>
double cataloque(char* c,T A,T B,int n)
{

   if(same_chars(c,"levenshtein"))
      return Levenshteing(A,B,n,n);

  if(same_chars(c,"imprv_levenshtein"))
return improved_Levenstheing(A,B,n,n);

if(same_chars(c,"euclid"))
     return Euclid(A,B,n);

if(same_chars(c,"manhattan"))
     return Manhattan(A,B,n);


if(same_chars(c,"cos_distance"))
     return cosine_dist(A,B,n);

if(same_chars(c,"angular_distance"))
   return angular_distance(A,B,n);



if(same_chars(c,"hamming"))
     return Hammingish(A,B,n);



if(same_chars(c,"tanimoto"))
     return Tanimoto(A,B,n);


if(same_chars(c,"cos_similarity"))
     return similarity(A,B,n);



if(same_chars(c,"angular_similarity"))
   return angular_similarity(A,B,n);


}















}Metric;



double prob_char1(char* s1,char* s2)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double avg=(n+m)/2;

   double heust= Metric.Levenshtein(s1,s2);

   return 1-heust/avg;
}


double prob_char11(char* s1,char* s2,double mxc=2,double mic=1)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double avg=(n+m)/2;

       avg=(mxc+mic)/2*avg;

   double heust= Metric.Levenshtein2(s1,s2,mxc,mic);

   return 1-heust/avg;

}

double prob_char13(char* s1,char* s2,double mxc=2,double mic=1)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double avg=(n+m)/2;

       avg=(mxc+mic)/2*avg;

   double heust= Metric.Levenshtein2(s1,s2,mxc,mic);

   return 1-heust/avg;
}



double prob_char2(char* s1,char* s2)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double maxi=max(n,m);

   double heust= Metric.Levenshtein(s1,s2);

   return 1-heust/maxi;
}


double prob_char21(char* s1,char* s2,double mxc,double mic)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double maxi=max(n,m);

     maxi=(mxc+mic)/2*maxi;

   double heust= Metric.Levenshtein2(s1,s2);

   return 1-heust/maxi;
}


double prob_char3(char* s1,char* s2)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double heust= Metric.Levenshtein(s1,s2);

   return 1-heust/m;
}

double prob_char4(char* s1,char* s2)
{
   int n=strlen(s1);

   int m=strlen(s2);

   double heust= Metric.Levenshtein(s1,s2);

   return 1-heust/n;
}

double prob_char5(char* s1,char* s2)
{
   int n=strlen(s1);

   int m=strlen(s2);
   double mini=min(n,m);


   double heust= Metric.Levenshtein(s1,s2);

   return 1-heust/mini;
}





double word_similarity(char* s1,char* s2)
{
   char* aux1=new char[strlen(s1)+1];
   char* aux2=new char[strlen(s2)+1];



Caps_off(s1);
Caps_off(s2);



   int k1=0,k2=0;

   char now1=s1[0],now2=s2[0];

   k1++;
   k2++;

   aux1[0]=now1;
   aux2[0]=now2;

   for(int i=0;i<=strlen(s1);i++)
   {
      if(s1[i]!=now1)
      {
         k1++;aux1[k1-1]=s1[i];
      now1=s1[i];
      }
   }
aux1[k1]='\0';

      for(int i=0;i<=strlen(s2);i++)
   {
      if(s2[i]!=now2 )
      {

         k2++;
         aux2[k2-1]=s2[i];
      now2=s2[i];
      }
   }

aux2[k2]='\0';


return prob_char1(aux1,aux2);

}

double word_similarity2(char* s1,char* s2,double max_cost=2,double min_cost=0.5)
{

   char* aux1=new char[strlen(s1)+1];
   char* aux2=new char[strlen(s2)+1];
 cout<<"intra"<<endl;


Caps_off(s1);
Caps_off(s2);

cout<<"nu asta"<<endl;


   int k1=0,k2=0;

   char now1=s1[0],now2=s2[0];

   k1++;
   k2++;

   aux1[0]=now1;
   aux2[0]=now2;

   for(int i=0;i<=strlen(s1);i++)
   {
      if(s1[i]!=now1)
      {
         k1++;aux1[k1-1]=s1[i];
      now1=s1[i];
      }
   }
aux1[k1]='\0';

      for(int i=0;i<=strlen(s2);i++)
   {
      if(s2[i]!=now2 )
      {

         k2++;
         aux2[k2-1]=s2[i];
      now2=s2[i];
      }
   }

aux2[k2]='\0';

cout<<aux1<<" "<<aux2<<endl;

//if(shortcuts_chars(aux1,aux2))
//return 1;

return prob_char11(aux1,aux2,max_cost,min_cost);

}

char* replace_paran(char* s,int&n,char c1='(',char c2=')',char* txt=" p")
{
   char* res=NULL;
   int p1=-1,p2=-1,np=0;

for(int i=0;i<strlen(s);i++)
   {
      if(p2==-1)
      {
          if(p1==-1 && s[i]==c1)
      {

          p1=i;np++;
      }
      else
      if(s[i]==c1)
      np++;
      else
      if(s[i]==c2 && np>1)
      {
          np--;
      }
      else
      if(s[i]==c2)
      {
              p2=i;
      }


      }

   }
      if(p2>=0 && p1>=0)
      {

      res=new char[p2-p1+3];
   int k=0;

   for(int i=p1+1;i<p2;i++)
      {res[k]=s[i];k++;}
         res[k]='\0';

         char* temp;

         temp=new char[strlen(s)+1];
         strcpy(temp,s+p2+1);

         strcpy(s+p1,txt);
         k=strlen(s);

         n++;
         int aux=n;
         int p=1;

         while(aux>9)
         {
            p=p*10;aux=aux/10;
         }
         while(p>=1)
            {s[k]=(n/p)%10+'0' ;k++;p=p/10;}
            s[k]=' ';

         strcpy(s+k+1,temp);

      }

      return res;
   }


char* replace_ghilimele(char* s,int&n,char c1='"',char* txt=" w")
{
   char* res=NULL;
   int p1=-1,p2=-1,np=0;

for(int i=0;i<strlen(s);i++)
   {

      if(p2==-1)
      {
         if(p1==-1 && s[i]==c1)
      {

          p1=i;
      }
      else
      if(s[i]==c1)
      {
      p2=i;
      }

     }}

  // cout<<"p12:"<<p1<<" "<<p2<<endl;

      if(p2>=0 && p1>=0)
      {

      res=new char[p2-p1+3];
   int k=0;

   for(int i=p1+1;i<p2;i++)
      {res[k]=s[i];k++;}
         res[k]='\0';

         char* temp;

         temp=new char[strlen(s)+1];
         strcpy(temp,s+p2+1);

         strcpy(s+p1,txt);
         k=strlen(s);

         n++;
         int aux=n;
         int p=1;

         while(aux>9)
         {
            p=p*10;aux=aux/10;
         }
         while(p>=1)
            {s[k]=(n/p)%10+'0' ;k++;p=p/10;}
            s[k]=' ';

         strcpy(s+k+1,temp);


      }

      return res;
   }












Llist<char*> replace_all_paran(char* s1,int&n,char c1='(',char c2=')',char* txt=" p")
   {

      Llist<char*> paran;


      char* des=NULL;

do{


   des=replace_paran(s1,n,c1,c2,txt);

   if(des!=NULL)
paran.add(des);

}while(des!=NULL);

return paran;

}

Llist<char*> replace_all_word(char* s1,int&n,char* txt=" w")
   {

      Llist<char*> paran;

      char* des=NULL;

      char s[50]="'";



char c1=s[0];


do{

   des=replace_ghilimele(s1,n,c1,txt);
if(des!=NULL && s1!=NULL)
  // cout<<des<<" "<<s1<<endl;


   if(des!=NULL)
paran.add(des);



}while(des!=NULL);

//cout<<s1<<endl;

return paran;

}






char* take_operation(char*s ,int& no,char op='+',char* others="/+-*^%)(=,;")
   {

       char* res=NULL;
   int p1=-1,f=-1,g=0;


for(int i=0;i<strlen(s);i++)
   {
       if(p1==-1 && s[i]==op)
      {
         p1=i;
         f=i-1;
         g=i+1;

         while(f>=0 && !strchr(others,s[f]))
            f--;
         while(g<strlen(s) && !strchr(others,s[g]))
            g++;
      }
   }
      if(p1!=-1)
      {
         no++;

         res=new char[ p1-f+ g-p1+10];

         int k=0;

         for(int i=f+1;i<p1;i++)
         {res[k]=s[i];k++;}

         res[k]=' ';k++;
         res[k]=op ;k++;
         res[k]=' ';k++;

          for(int i=p1+1;i<g;i++)
         {res[k]=s[i];k++;}
            res[k]='\0';

         char* temp=new char[strlen(s)+1];

         strcpy(temp,s+g);



       strcpy(s+f+1," op");


         k=strlen(s);


         int aux=no;
         int p=1;

         while(aux>9)
         {
            p=p*10;aux=aux/10;
         }
         while(p>=1)
            {s[k]=(no/p)%10+'0' ;k++;p=p/10;}
            s[k]=' ';

         strcpy(s+k+1,temp);


      }
      return res;
   }



char* take_operation2(char*s ,int& no,char* op="^*/%",char* others="/+-*^%)(=,;")
   {

       char* res=NULL;
   int p1=-1,f=-1,g=0;
int op1;


for(int i=0;i<strlen(s);i++)
   {
       if(p1==-1 && strchr(op,s[i]))
      {
         op1=s[i];
         p1=i;
         f=i-1;
         g=i+1;

         while(f>=0 && !strchr(others,s[f]))
            f--;
         while(g<strlen(s) && !strchr(others,s[g]))
            g++;
      }
   }
      if(p1!=-1)
      {
         no++;

         res=new char[ p1-f+ g-p1+10];

         int k=0;

         for(int i=f+1;i<p1;i++)
         {res[k]=s[i];k++;}

         res[k]=' ';k++;
         res[k]=op1 ;k++;
         res[k]=' ';k++;

          for(int i=p1+1;i<g;i++)
         {res[k]=s[i];k++;}
            res[k]='\0';

         char* temp=new char[strlen(s)+1];

         strcpy(temp,s+g);



       strcpy(s+f+1," op");


         k=strlen(s);


         int aux=no;
         int p=1;

         while(aux>9)
         {
            p=p*10;aux=aux/10;
         }
         while(p>=1)
            {s[k]=(no/p)%10+'0' ;k++;p=p/10;}
            s[k]=' ';

         strcpy(s+k+1,temp);


      }
      return res;
   }


Llist<char*> take_all_operations(char* s1,int&n,char op='+',char* others="/+-*^%)(=,;")
{

      Llist<char*> ops;

      char* des=NULL;
do{

   des=take_operation(s1,n,op,others);

   if(des!=NULL)
ops.add(des);

}while(des!=NULL);

return ops;

}






Llist<char*> take_all_operations3(char* s1,int&n,char* op="^*/%",char* others="/+-*^%)(=,;")
{

      Llist<char*> ops;

      char* des=NULL;
do{

   des=take_operation2(s1,n,op,others);

   if(des!=NULL)
ops.add(des);

}while(des!=NULL);

return ops;

}










Llist<char*>  take_all_operations2(char* s1,int&n,char* op="^*/%",char* others="/+-*^%)(=,;")
{
   Llist<char*> final_res,res;


   res=take_all_operations(s1,n,op[0]);

   for(int j=1;j<=res.nr;j++)
      final_res.add(res[j]);

   res=take_all_operations3(s1,n,op,others);

   for(int j=1;j<=res.nr;j++)
      final_res.add(res[j]);
   return final_res;
}





char* next_word(char* s,char* spdes="+*/%^-=")
{

   int p1=-1,p2=-1,
   i=0;
      if(s[i]==' ' && i<strlen(s))
      {

      while(i<strlen(s) && (s[i]==' ' ||  s[i]==',' || s[i]==';'))
      i++;

      if(i<strlen(s))
      p1=i;

      }
      else
      {
     if(i<strlen(s))
      p1=i;
      }

   if(strchr(spdes,s[i]))
      {
       i++;
       p2=i;
      }
       else
       {
      while(i<strlen(s) && s[i]!=' ' &&  s[i]!=',' && s[i]!=';' && !strchr(spdes,s[i]))
      i++;
      p2=i;
       }

 while(i<strlen(s) && (s[i]==' ' ||  s[i]==',' || s[i]==';' ))
      i++;

      if(p1!=-1 && p2!=-1)
      {
         char* nword=new char[p2-p1+3];


      int k=0;

       for(int j=p1;j<p2;j++)
    { nword[k]=s[j];
    k++
    ;}

       nword[k]='\0';

       strcpy(s,s+i);

       return nword;
      }

      return NULL;

}

int takes_number(char* s,int i=0, char* sep=" ,+-=*/^%")
{

   int n=0;
      while(strchr(sep,s[i]))
      i++;

  while(i<strlen(s) && !strchr(sep,s[i]))
  {
     if(strchr("0123456789",s[i]))
        n=n*10+s[i]-'0';
        i++;
  }

return n;
}

double takes_real(char* s,int i=0,char* sep=" ,+-=*/^%")
{
   double n=0;
   int p=1;
   int of=10;

    while(strchr(sep,s[i]))
      i++;

  while(i<strlen(s) && !strchr(sep,s[i]))
  {
     if(strchr("0123456789",s[i]))
        {
            n=n*of+(double)(s[i]-'0')/p;

            if(p!=1)
            p=p*10;

        }
        else
        if(s[i]=='.')
        {p=10;
        of=1;}
i++;
  }
  return n;

}


int take_bin_oper(char* s,char* p=" +-*/^%")
{
   for(int i=0;i<strlen(s);i++)
   {
      if(strchr(p+1,s[i]))
      {
         for(int j=1;j<strlen(p);j++)
            {

                 if(s[i]==p[j])
                     return j;



            }
      }
   }

return 0;
}

int take_log_oper(char* s,char* p=" =|&<>")
{
   for(int i=0;i<strlen(s);i++)
   {
      if(strchr(p+1,s[i]))
      {
         if(s[i]=='<' )
          if(s[i+1]=='=')
         return 7;

           if(s[i]=='>' )
          if(s[i+1]=='=')
         return 8;



         for(int j=1;j<strlen(p);j++)
            {


                 if(s[i]==p[j])
                     return j;



            }
      }
   }

return 0;
}














int check_oper(char* s,int i,char* c2="op",char* sep=" ,+-=*/^%")
{
   int k=0;
   int c=1;

   while(strchr(sep,s[i]) && i<strlen(s))
      i++;

   for(k=0;k<strlen(c2);k++)
{
   if(i+k<strlen(s))
   {
   if(s[i+k]!=c2[k])
      c=0;
   }
   else
      c=0;
}

if(c==1)
{

k=k+i;
if(k<strlen(s))
 if(!strchr("0123456789",s[k]))
         c=0;

   while(k<strlen(s) && !strchr(sep,s[k]))
   {
       if(!strchr("0123456789",s[k]))
         c=0;
       k++;
   }
}
return c;
}



char* take_next_oper(char*s,int& t,char* c2="op",char* sep=" ,+-=*/^%")
{

   char* res=next_word(s,sep);
   t=0;

   if(check_oper(res,0,c2,sep))
   {
       t=takes_number(res,0);
       return NULL;
   }


   return res;
}

int sir_prin_null(char* s,char* sep=" ,.;")
{

   int c=1;

   for(int i=0;i<strlen(s);i++)
   if(!strchr(sep,s[i]))
        c=0;


return c;

}

char* newchar(char* a)
{
   char* s=new char[strlen(a)+2];
   strcpy(s,a);

   return s;


}







//#include"special_arrays.h"
#include"complex.h"

template<typename T>
imag* equa2(T a,T b,T c)
{
   double delta;

   delta=b*b-4*a*c;

   imag* r=new imag[3];
   if(delta>=0)
   {

      r[1].r=(-b+sqrt(delta))/(2*a);
      r[2].r=(-b-sqrt(delta))/(2*a);
   }
   else
   {
      r[1].r=(-b/(2*a));
      r[2].r=(-b/(2*a));


      r[1].i=sqrt(-delta)/(2*a);

      r[2].i=-sqrt(-delta)/(2*a);
   }

 return r;

}








int floorSqrt(int x)
{
   if(x<0)
      x=-x;

   if(x==0)
      return 0;
      if(x==1)
         return 1;

          int start=1,ends=x,mid=1,ans;

          while(start<=ends)
          {

             mid=(start+ends)/2;

             if(mid*mid==x)
              return mid;

             if(mid*mid<x)
             {
                start=mid+1;
                ans=mid;
             }
             if(mid*mid>x)
             {
                ends=mid-1;

             }
   }

   return ans;
}


int floorSqrt2(int x,int st=1,int ends=-1)
{
   if(x==0)
    return 0;

   if(x==1)
    return 1;
    if(x<0)
      x=-x;
if(ends==-1)
   ends=x;
   int ans=0;

   if(st<=ends)
   {

     int mid=(st+ends)/2;

      if(mid*mid==x)
        return mid;

      if(mid*mid<x)
      {
        ans=mid;
       if(floorSqrt2(x,mid+1,ends)!=0)
             ans=floorSqrt2(x,mid+1,ends);
      }

    else
       return floorSqrt2(x,st,mid-1);
   }

   return ans;

}
template<typename T,typename T2,typename T3>
int in_range(T c,T2 a,T3 b)
{
   if(c>=a && c<=b)
   return 1;
   return 0;


}


double square_n_root(float x,int n,int prec=6)
{
    float aprox=1;
    while(prec)
    {aprox=aprox/10;
    prec--;
    }
//printf("%f\n",aprox);
   double start=1,end=x,mid=0;

    while(end-start>=0.e6 && fabs(x-pow(mid,n))>aprox)
    {
        mid=(start+end)/2;



         if(pow(mid,n)>=x)
            end=mid;
            else
            start=mid;


            // printf("S %f E %f\n",start,end);
    }





    return mid;


}

double media_geometrica(float* f,int n)
{

    double s=0,prod=1;
 for(int i=0;i<n;i++)
    {

              prod=prod*f[i];

    }
//printf("%f\n",prod);

    return square_n_root(prod,n,6);


}

double media_aritmetica(float* f,int n)
{

    double s=0,prod=0;
 for(int i=0;i<n;i++)
    {

              prod=prod+f[i];

    }


    return prod/n;


}
double media_armonica(float* f,int n)
{

    double s=0,prod=0;
 for(int i=0;i<n;i++)
    {

              prod=prod+1.0/f[i];

    }


    return n/prod;


}


double u_intesect(double x1,double x2,double y1,double y2,double x3,double x4,double y3,double y4)
{
   double den=(x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
   double den2=-((x1-x2)*(y1-y3)-(y1-y2)*(x1-x3));

   if(den)
return den2/den;

return 0;



}
double t_intesect(double x1,double x2,double y1,double y2,double x3,double x4,double y3,double y4)
{
   double den=(x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
   double den2=((x1-x3)*(y3-y4)-(y1-y3)*(x3-x4));

if(den)
return den2/den;
return 0;

}


float* abc_intersect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

float a1=x2-x1;
float a2=x4-x3;
float b1=y2-y1;
float b2=y4-y3;

float c1=a1*y1-b1*x1;
float c2=a2*y3-b2*x3;

   float* res=NULL;

   if(a2*b1-a1*b2!=0)
   {
      float d1=a2*c1-a1*c2;
      float d2=a1*b2-a2*b1;
      float d3=c2*b1-c1*b2;
      res=new float[4];

      res[1]=d1/d2;
      res[2]=d3/d2;
     if(res[1]>=min(x3,x4) && res[1]<=max(x3,x4)
        &&
        res[2]>=min(y3,y4) && res[2]<=max(y3,y4)
        )
      res[0]=1;
      else
      res[0]=-1;
   }

   return res;

}



float* abc2_intersect(float b1,float a1,float c1,float b2,float a2,float c2)
{

   float* res=NULL;

   if(a2*b1-a1*b2!=0)
   {
      float d1=a2*c1-a1*c2;
      float d2=a1*b2-a2*b1;
      float d3=c2*b1-c1*b2;
      res=new float[4];

      res[1]=d1/d2;
      res[2]=d3/d2;
   }
   return res;

}

float* abc3_intersect(float b1,float a1,float c1,float b2,float a2,float c2,float x3,float y3,float x4,float y4)
{

   float* res=NULL;

   if(a2*b1-a1*b2!=0)
   {
      float d1=a2*c1-a1*c2;
      float d2=a1*b2-a2*b1;
      float d3=c2*b1-c1*b2;
      res=new float[4];

      res[1]=d1/d2;
      res[2]=d3/d2;
       if(res[1]>=min(x3,x4) && res[1]<=max(x3,x4)
        &&
        res[2]>=min(y3,y4) && res[2]<=max(y3,y4)
        )
      res[0]=1;
      else
      res[0]=-1;


   }
   return res;

}

int in_arcsector(float x,float y,float rad,float sa,float ea,float cx=0,float cy=0)
{
x=x-cx;
y=y-cy;

float mg=sqrm(x*x+y*y);

float ang=arctan3(x,y);

if(mg<=rad && ang<=ea && ang>=sa)
return 1;

return 0;

}

///return the number of binary trees with n nodes

float Catalan_number(int n)
{

   float den=Math.fact(2*n);
   float num=Math.fact(n)*Math.fact(n+1);
   return den/num;




}

template<typename T,typename Rule>
void UniqueL(T& a,int& nr,Rule t)
{

   int i=1;
   while(i<nr)
  {

     if(t(a[i],a[i+1]))
     {

        for(int j=i+1;j<nr;j++)
        a[j]=a[j+1];


        nr--;
     }
     else
      i++;


  }


}


#include"aria unui poligon.h"
template<typename T,typename Y>
void ifreduce(T& A,int& nr,Y ck)
{

   int i=1;
   while(i<=nr && nr>0)
   {

      if(ck(A[i]))
      {
         for(int j=i;j<nr;j++)
       A[j]=A[j+1];

        nr--;
      }
      else
        i++;

   }

}


long long Stirling(int n,int k)
{
if(k==1)
    return 1;
if(k==n)
    return 1;
return Stirling(n-1,k-1)+k*Stirling(n-1,k);

}

int nr_zaruri(int identice,int n)
{  if(identice==1)
  return  Math.comb(n+5,5);
    else
  return pow(6,n);


}
float Fib(float  val)
{

    return (pow(phi,val)-Math.cosa(deg_angle(pi*val))*(1.0/pow(phi,val)))/sqrt(5);


}
struct diferential_equations
{
    template<typename T>
    float Euler_method(float u,T a,float x0,float y0,float h=0.1)
    {

          float yn1;
          float x1=x0+h;
          float ys,xs;

        while(!(x0<=u && x1>=u))
        {
            x1=x0+h;
            float F=a(x0,y0);
            yn1=y0+h*F;
            ys=y0;
            xs=x0;
            x0=x1;
            y0=yn1;
        }

         if(xs!=x0)
         return ys+ ((ys-y0)/(xs-x0))*(u-x0);
            else
        return y0;

    }





    template<typename T>
    float Taylor_method2(float u,T a,float x0,float y0,float h=0.1)
    {

          float yn1;
          float x1=x0+h;
          float ys,xs;

        while(!(x0<=u && x1>=u))
        {
            x1=x0+h;
            float F=a(x0,y0);
            derivate D;
           float f1=D.df_partiala2(1,x0,y0,a);
           float f2=D.df_partiala2(2,x0,y0,a);

            yn1=y0+h*F+ 0.5*h*h*(f1 +F*f2);
            ys=y0;
            xs=x0;
            x0=x1;
            y0=yn1;
        }

         if(xs!=x0)
         return ys+ ((ys-y0)/(xs-x0))*(u-x0);
            else
        return y0;

    }













    template<typename T>
    float Ruge_Kutta2(float u,T a,float x0,float y0,float h=0.1)
    {

          float yn1;
          float x1=x0+h;
          float ys,xs;

        while(!(x0<=u && x1>=u))
        {
            x1=x0+h;
            float k1=a(x0,y0);
            float k2=a(x0+h,y0+k1*h);
            float F=(k1+k2)/2;

            yn1=y0+h*F;
            ys=y0;
            xs=x0;
            x0=x1;
            y0=yn1;
        }

         if(xs!=x0)
         return ys+ ((ys-y0)/(xs-x0))*(u-x0);
            else
        return y0;

    }
     template<typename T>
 float Ruge_Kutta21(float u,T a,float x0,float y0,float h=0.1)
    {

          float yn1;
          float x1=x0+h;
          float ys,xs;

        while(!(x0<=u && x1>=u))
        {
            x1=x0+h;

            float F=a(x0+h/2,h/2*a(x0,y0)+y0);

            yn1=y0+h*F;
            ys=y0;
            xs=x0;
            x0=x1;
            y0=yn1;
        }

         if(xs!=x0)
         return ys+ ((ys-y0)/(xs-x0))*(u-x0);
            else
        return y0;

    }
 template<typename T>
float Ruge_Kutta4(float u,T a,float x0,float y0,float h=0.1)
    {

          float yn1;
          float x1=x0+h;
          float ys,xs;

        while(!(x0<=u && x1>=u))
        {
            x1=x0+h;
            float k1=a(x0,y0);
            float k2=a(x0+h/2,y0+k1*h/2);
            float k3=a(x0+h/2,y0+k2*h/2);
            float k4=a(x0+h,y0+k3*h);
            float F=(k1+2*k2+2*k3+k4)/6;
            yn1=y0+h*F;
            ys=y0;
            xs=x0;
            x0=x1;
            y0=yn1;
        }

         if(xs!=x0)
         return ys+ ((ys-y0)/(xs-x0))*(u-x0);
            else
        return y0;

    }








};



void build_lps(char*s,int* lps,int n)
{
    int i=1;
    int len=0;
    lps[0]=0;
    while(i<n)
    {
    if(s[i]==s[len]){
        len++;
        lps[i]=len;
        i++;

    }
    else
    {
        if(len!=0){

            len=lps[len-1];

        }
        else
        {
            lps[i]=0;
            i++;
        }
    }


    }

}
int  kmp_search(char*s ,char* pat)
{
    int nr_aparitii=0;
    int m=strlen(pat);
    int n=strlen(s);
    int lps[m];
    build_lps(pat,lps,m);
    int i=0,j=0;

    while(i<n){
        if(pat[j]==s[i])
        {
            j++;
            i++;
        }
       if(j==m)
        {nr_aparitii++;
        printf("apare la %d \n",i-j);
          j=lps[j-1];
        }
      if(i<n  && pat[j]!=s[i]){

        if(j!=0)
        j=lps[j-1];
        else
         i=i+1;

      }


    }




}
double** polynomial_regression_matrix(double* x,double*y,int n,int deg)
{

    double** rez=(double**)malloc(sizeof(double*)*(deg+2));
    for(int i=0;i<=deg+1;i++)
    rez[i]=(double*)malloc(sizeof(double)*(deg+2));


    for(int i=0;i<=deg;i++)
    {   rez[i][deg+1]=0;
        for(int k=0;k<n;k++)
         rez[i][deg+1]+=pow(x[k],i)*y[k];



    for(int j=0;j<=deg;j++)
    {
        rez[i][j]=0;

        for(int k=0;k<n;k++)
        rez[i][j]+=pow(x[k],i+j);
    }

}
return rez;
}
template<typename T>
T* arange(T* a,double bg,double en,int stp)
{ int k=0;
    for( double p=bg;p<=en;p+=stp )
    {
        a[k]=p;k++;

    }
  return a;
}

struct nodep{

double x;
nodep* next;

};

void add_node(double k,nodep* m)
{
    nodep*q=m;
   while(m!=NULL)
   {
      q=m;
      m=m->next;
   }
  if(q!=NULL)
  {
    q->next=(nodep*)malloc(sizeof(nodep));
    q->next->x=k;
    q->next->next=NULL;
  }



}


















int peak_detection(double* x,double* y,int n, double* gmax,double*  gmin,nodep* minima,nodep* maxima)
{

    minima->next=NULL;
    maxima->next=NULL;


    double lmin=y[0],lmax=y[0];
    int d=-1;
    double av=y[0];
    double alm=y[0];
    int nm=0;
           printf("here\n");
    for(int i=1;i<n;i++)
    {
        av=y[i];



           if(av>lmin && d==1 )
        {  printf("nm max %f %f %f\n",av,alm,lmax);
             add_node(lmax,maxima);

            lmax=av;
            d=0;
            nm++;
        }


        if (av>lmax && d==0 || d==-1)
        {
            printf("increase\n");
        alm=lmin;
        lmax=av;
        d=0
        ;}

          if(av<lmin && d==1 )
        {
            lmin=av;
            d=1;
            nm++;
        }


        if(av<lmax && d==0)
        {   printf("hole made: min %f %f %f\n",av,alm,lmax);
            d=1;
            add_node(alm,minima);
            alm=lmin;
            lmin=av;

        }
           //  printf("ce se intampla %f %f %f\n",x[i],av,lmin);



    }
        add_node(lmin,minima);
        add_node(lmax,maxima);





return nm;
}
double* Lerp_x_y(double p1x,double p2x,double p1y,double p2y,double amt)
{

    double* g=(double*)malloc(2*sizeof(double));
    g[0]=p1x+(p2x-p1x)*amt;
    g[1]=p1y+(p2y-p1y)*amt;
    return g;

}
double* Lerp_array(double* p1,double* p2,int n,double amt,int sp)
{

    double* g=(double*)malloc((n+sp)*sizeof(double));
   for(int i=sp;i<n+sp;i++)
   g[i]=p1[i]+amt*(p2[i]-p1[i]);

    return g;

}
double* Lerp_array_array(double* p1,double* p2,int n,double* amt,int sp=0)
{

    double* g=(double*)malloc((n+sp)*sizeof(double));
   for(int i=sp;i<n+sp;i++)
   g[i]=p1[i]+amt[i]*(p2[i]-p1[i]);

    return g;

}

double** Lerp_mat(double ** p1,double** p2,int n,double amt,int sp=0)
{

    double** g=(double**)malloc((n+sp)*sizeof(double*));
   for(int i=0;i<n+sp;i++)
    g[i]=(double*)malloc((n+sp)*sizeof(double));

   for(int i=sp;i<n+sp;i++)
    for(int j=sp;i<n+sp;j++)
   g[i][j]=p1[i][j]+amt*(p2[i][j]-p1[i][j]);

    return g;

}

double** Lerp_mat_mat(double ** p1,double** p2,int n,double** amt,int sp=0)
{

    double** g=(double**)malloc((n+sp)*sizeof(double*));
   for(int i=0;i<n+sp;i++)
    g[i]=(double*)malloc((n+sp)*sizeof(double));

   for(int i=sp;i<n+sp;i++)
    for(int j=sp;i<n+sp;j++)
   g[i][j]=p1[i][j]+amt[i][j]*(p2[i][j]-p1[i][j]);

    return g;

}
double logistic_map(int n,double x0,double r)
{
    if(n==0)
        return x0;

        double x=logistic_map(n-1,x0,r);
        return r*x*(1.0-x);

}
double logistic_map2(int n,double x0,double r)
{
    if(n==0)
        return x0;

        double x=logistic_map(n-1,x0,r);
        return r*sin(x);

}

double zero_one(int n,int c=0)
{

    return (1+pow(-1.0,(n+c)))/2;

}
char* itoa(int d)
{
    char* ns;
    int k=1;
    int p=10;

    while(d>=p)
     {p=p*10;
       k++
      ;}



    ns=(char*)malloc(k+2);



    ns[k]=0;
    while(k>=0)
    {   k--;
        ns[k]='0'+d%10;
        d=d/10;

    }



    return ns;

}
char* ctoa(char a,int n)
{
    char* nc=(char*)malloc(sizeof(char)*(n+1));
    nc[0]=a;
    nc[1]=0;
    return nc;



}


template<typename T>
double matrix_norm(T A,int n,int m,int sp=1)
{
    double nm=0;
    for(int i=sp;i<n+sp;i++)
    for(int j=sp;j<m+sp;j++)
    nm+=A[i][j]*A[i][j];

    return sqrt(nm);

}

template<typename T,typename R>
double matrix_norm(T A,R B,int n,int m,int sp=1)
{
    double nm=0;
    for(int i=sp;i<n+sp;i++)
    for(int j=sp;j<m+sp;j++)
    nm+=A[i][j]*A[i][j];

    return sqrt(nm);

}


template<typename T,typename R>
double matrix_scalar_product(T A,R B,int n,int m,int sp=1)
{

    double** Bt= transp(B,n,m);

    double** Rez2=mult2p(A,Bt,n,m);
    double rez=0;

    for(int i=sp;i<n+sp;i++)
        if(i<m)
         rez+=Rez2[i][i];

         return rez;
}
///ra>rb
double lazy_elipse_parameter(int ra,int rb)
{
    return pi*(6.0/5*ra + 3.0/4*rb);
}



template<typename T>
T entropy(T* p,int n,void (*init_elm)(T*) =NULL,int st=0)
{ T sum;
   if(init_elm)
    init_elm(&sum);
    else
    sum=NULL;


    for(int i=st;i<n+st;i++)
    sum=sum-p[i]*log2(p[i]);

    return sum;

}
///T must be a matrix like structure hat contains a field called "type" which is a double
/// for each element which has implemented tipical algebric operations
///
template<typename T,typename G,typename S>
double entropy_from_split(T df, int nr, G val, S feature,int st=0)
{ int nr_ls=0,nr_rs=0;
     for(int i=st;i<nr+st;i++)
        if(df[i][feature]<val)
        nr_ls++;
       else
        nr_rs++;


    double* left_types = new double[nr_ls+1];
    double* right_types = new double[nr_rs+1];
    nr_ls=0;
    nr_rs=0;
    for(int i=st;i<nr+st;i++)
        if(df[i][feature]<val)
       {
           left_types[nr_ls]=df[i][feature].type;
           nr_ls++;
       }else
    {
           right_types[nr_rs]=df[i][feature].type;
           nr_rs++;
    }

    double le=entropy(left_types,nr_ls);
    double re=entropy(right_types,nr_rs);
    return  nr_ls*le+re*nr_rs;

}


double LagrangeP(double* v,double* f, int n, double x)
{
    double L=0;
    for(int i=0;i<n;i++)
   {   double l=f[i];
   double p=1;
       for(int j=0;j<n;j++)
        if(i!=j)
       {

       p=p*(x-v[j])/(v[i]-v[j]);
       }
       l=l*p;
       L+=l;
   }
    return L;

}
double Hermite_interpolation(double* v,double* f,double* df, int n, double x)
{
    //calculam l(x)
    double L1=1;
    for(int i=0;i<n;i++)
    L1=L1*(x-v[i]);

    double L2=0;
    for(int i=0;i<n;i++)
    {
        double l2=1;
         for(int j=0;j<n;j++)
            l2*=x;



    }

return L1;



}

double nsqrt_recursive_n(double f,int n=2, double aprx=1.9/100)
{
    double xn = f;
    while (fabs(pow(xn, n) - f)> aprx)
    {
        xn = (1.0 / n) * ((n - 1) * xn + f * 1.0 / (pow(xn, n - 1)));



    }

}


#endif // MATH SANDU'S_H
