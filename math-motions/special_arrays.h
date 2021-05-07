#ifndef SPECIAL_ARRAYS_H
#define SPECIAL_ARRAYS_H
//#include"my_image.h"
#include"math_sandus.h"
#include"complex.h"
#include"map_style.h"

struct Special_arrays
{

struct Numb
{

double* mine;
int n_e=0,lim,s_e=0,nr_poz=0,act=0;




double* slice(int& z,int a=0,int n=0)
{


if(a==n)
{
n=n_e;

if(a!=0)a+=abs(s_e);

}
else
{
   n+=abs(s_e);
   a+=abs(s_e);
}

double* y=new double[n-a+2];

int x=-1;
for(int i=a;i<=n;i++)
{
x++;
y[x]=mine[i];
}
z=n-a+1;

return y;
}






void create(int n)
{
mine=new double[n+5];
lim=n;
}

void extent(int m)
{
double* b=new double[n_e+1];
for(int i=0;i<=n_e;i++)
b[i]=mine[i];

delete[] mine;
mine=new double[m+5];
for(int i=0;i<=n_e;i++)
mine[i]=b[i];
delete[] b;

}

double& operator[](int n)
{

if(n<s_e)
{
for(int i=n_e;i>=0;i--)
{
mine[i+abs(s_e-n)]=mine[i];
   mine[i]=0;
}

n_e+=abs(s_e-n);

s_e=n;

;}


if(n>n_e+s_e)
{
n_e+=abs(n_e+s_e-n);


}


if(n_e>lim)
{
cout<<"number of elements to big,plese extent the limit or give up"<<endl;
return mine[0];
}

act=abs(s_e)+n;
return mine[abs(s_e)+n];

}

template<typename T>
void ass(T a[],int b)
{
s_e=b;
for(int i=0;i<=n_e;i++)
mine[i]=0;

for(int i=1;i<=a[0];i++)
   mine[i-1]=a[i];

n_e=a[0];

}
int index_start()
{
return s_e;

}
int index_end()
{

return n_e+s_e;

}






template<typename T>
void insrt(T*b,int n,int p)
{
for(int i=n_e;i>=p+abs(s_e);i--)
{mine[i+n]=mine[i];
mine[i]=0;
}
n_e+=n;
int x=0;
for(int i=p+abs(s_e);i<=p+abs(s_e)+n;i++)
{
x++;
mine[i]=b[x];
}
}
template<typename T>
void paste(T* b,int n,int p)
{
int x=0;
for(int i=p+abs(s_e);i<=p+abs(s_e)+n;i++)
{
x++;
mine[i]=b[x];
}
if(p+abs(s_e)+n>n_e && p+abs(s_e)+n<lim)
   n_e+=abs(n_e-(p+abs(s_e)+n));
}
double operator^(int n)
{
math_Sandu d;
return d.powe(mine[act],n);

}
void operator^=(int n)
{
math_Sandu d;
mine[act]=d.powe(mine[act],n);
}
double operator%(double a)
{

int u=mine[act]/a;

double rez=mine[act]-u*a;

}

void operator%=(double a)
{

int u=mine[act]/a;

mine[act]=mine[act]-u*a;

}




void opn(double f,int op=1,int st=0,int en=0)
{
math_Sandu sd;


if(st==en)
{
en=n_e;
  if(st!=0)st+=abs(s_e);
}
else
{
st+=abs(s_e);
en+=abs(s_e);
}

   for(int i=st;i<=en;i++)
   {
      if(op==1) mine[i]+=f;
      if(op==2)mine[i]-=f;
      if(op==3)mine[i]*=f;
      if(op==4 && f!=0)mine[i]/=f;
      if(op==5)
      {  int y=act;
         act=i;
         operator%=(f);
         act=y;
      }

      if(op==7)mine[i]=abs(mine[i]);
      if(op==8)mine[i]=sd.ap(mine[i]);
      if(op==9)mine[i]=sd.aps(mine[i]);
      if(op==10)mine[i]=sd.sina(mine[i]);
      if(op==11)mine[i]=sd.cosa(mine[i]);
      if(op==12)mine[i]=sd.tana(mine[i]);
      if(op==13)mine[i]=arcsina(mine[i]);
      if(op==14)mine[i]=arccosa(mine[i]);
      if(op==15)mine[i]=sd.arctan(mine[i]);
      if(op==16)mine[i]=sd.powe(mine[i],f);


   }



}
void duo( int st=0,int en=0,int op=1)
{

math_Sandu sd;

st+=abs(s_e);

if(en==st)en=n_e;
else
   en+=abs(s_e);

   {
      if(op==1) mine[st]+=mine[en];
      if(op==2)mine[st]-=mine[en];
      if(op==3)mine[st]*=mine[en];
      if(op==4 && mine[en]!=0)mine[st]/=mine[en];

      if(op==5 && mine[en]!=0)
      {  int y=act;
         act=st;
         operator%=(mine[en]);
         act=y;
      }
   }


}
double duov( int st=0,int en=0,int op=1)
{

double c=0;
math_Sandu sd;

st+=abs(s_e);
if(en==st)en=n_e;
else en+=abs(s_e);


   {
      if(op==1) c=mine[st]+mine[en];
      if(op==2)c=mine[st]-mine[en];
      if(op==3)c=mine[st]*mine[en];
      if(op==4 && mine[en]!=0)c=mine[st]/mine[en];

      if(op==5 && mine[en]!=0)
      {  int y=act;
         act=st;
         c=(operator%(mine[en]));
         act=y;
      }
   }
return c;

}





double ops(int st=0,int en=0,int op=1)
{

math_Sandu sd;
double c;


if(st==en)
{
en=n_e;
  if(st!=0)st+=abs(s_e);
}
else
{
st+=abs(s_e);
en+=abs(s_e);
}


int y=0;
if(op>10)
{
y=op;
op=op-10;
}
c=mine[st];
   for(int i=st+1;i<=en;i++)
   {
      if(op==1) c+=mine[i];
      if(op==2)c-=mine[i];
      if(op==3)c*=mine[i];
      if(op==4 && mine[i]!=0)c/=mine[i];
   }

if(y>10)c/=n_e;


return c;
}
void invers(int st=1,int en=1)
{

if(st==en)
{
 en=n_e;


if(st!=1)st=st+abs(s_e);

}
else
   st=st+abs(s_e);

int u;
int f;

if(en==n_e)
f=en;
else
f=en+abs(s_e);

u=f;

for(int i=st;i<=st+abs(st-f)/2;i++)
{

double aux=mine[i];
mine[i]=mine[u];
mine[u]=aux;
u--;
}

}

double* inversa(int st=0,int en=0)
{
   double* t=new double[n_e+1];

   move_d(t,mine,n_e);

if(st==en)
{
 en=n_e;

if(st!=0)st=st+abs(s_e);

}
else
   st=st+abs(s_e);

int u;
int f;

if(en==n_e)
f=en;
else
f=en+abs(s_e);

u=f;

for(int i=st;i<=st+abs(st-f)/2;i++)
{
char aux=t[i];
t[i]=t[u];
t[u]=aux;
u--;
}
return t;
}




}one,*arr,**mat;

struct Char
{

char* word;
int n=0;
char des='\0';
char** ptt;
int nt=0;










char* slice(int& z,int a=0,int n=0)
{

if(a==n)
{
n=len(word,des);

}

char* y=new char[n-a+2];

int x=-1;

for(int i=a;i<=n;i++)
{

x++;y[x]=word[i];

}

x++;
y[x]=des;
z=x;
return y;
}




void create(int m)
{
word=new char[m+10];
n=m;
}


int operator==(Char b)
{

int i=comp5(word,b.word,0,des,0);

return i;

}

int operator==(char b[])
{
int u=comp5(word,b,0,des,0);

return u;

}

void operator =(char b[])
{
if(len(b,des)>n)
{
   delete[] word;


word=new char [len(b,des)+5];

n=len(b,des);

}

move_sd(word,b,len(b,des),0,0);

}

void operator=(char b)
{
des=b;
}

char* operator+(char b[])
{
   int m;

   n=len(b,des)+len(word,des)+2;

   char* r=new char[n];

   for(int i=0;i<=len(word,des);i++)
   r[i]=word[i];


   for(int i=0;i<=len(b,des);i++)
   r[i+len(word,des)]=b[i];

return r;

}

char* operator-=(char b[])
{


char* r=new char[len(word,des)];


int m=len(word,des)-1;

int o=len(b,des)-1;


while(o!=0 && m!=0)
{

if(word[m]!=b[o])return NULL;

m--;o--;

}
if(m>=0 && o<=0)
{


for(int i=m;i<=len(word,des);i++)
r[i-m]=word[i];



word[m]=des;


return r;

}


}

char* operator+(int n)
{
   char* t=new char[len(word,des)+nr_c(n)+5];

   for(int i=0;i<=len(word,des);i++)
   t[i]=word[i];
   n=inv_nr(n);

  int i=len(word,des);
   do
   {
      t[i]=n%10+48;
      n/=10;
      i++;
   }while(n!=0);

t[i]=des;

   return t;
}


void operator+=(char m)
{
int p=len(word,des);
word[p]=m;
word[p+1]=des;

if(len(word,des)+2>n)
n=len(word,des)+2;


}



void operator+=(int m)
{
char* t;
t=operator+(m);
n=len(word,des)+5;

delete[] word;

word=t;
}

void operator+(double)
{
   cout<<"pizza"<<endl;
}




void operator+=(char b[])
{


char* t=operator+(b);


n=len(word,des)+len(b,des);


delete[] word;

word=t;

}

void operator^=(int n)
{

char* p=new char[len(word,des)+1];

move_sd(p,word,len(word,des),0,0);


for(int i=1;i<=n;i++)
{

word=operator+(p);


;
}

}


char* operator^(int n)
{


char* t=word;

for(int i=1;i<=n;i++)
{

t=operator+(t);

}
return t;

}








float* Extract_number(int& k)
{
k=0;

float* a=new float[len(word,des)/2+2];

for(int i=0;i<=len(word,des);i++)
{
if(word[i]>='0' && word[i]<='9')
{
k++;a[k]=0;
int p=1,f=0;
   while((word[i]>='0' && word[i]<='9')|| word[i]=='.')
{

if(word[i]=='.')
{ f=1;i++ ;}

if(f==1)p*=10;
float g=(float)(word[i]-48)/p;


if(f==0)a[k]=a[k]*10+g;
else
   a[k]+=g;

i++;

}
}}
return a;
}

int how_many(char a[]=" ,.:;'?")
{
int p=0;
int u=1;
for(int i=0;i<=len(word,des);i++)
{
int f=0;

do{
f=0;
for(int j=0;j<=len(a,des);j++)
   if(a[j]==word[i])f=1;
i++;
}while(f!=1);

u++;

}
return u;

}

int how_many_v()
{
int j=0;
for(int i=0;i<len(word,des);i++)
   if(strchr("aeiouAEIOU",word[i])!=0)j++;

return j;
}

int how_many_c(char c)
{
int j=0;
for(int i=0;i<len(word,des);i++)
       if(word[i]==c)j++;

return j;
}


int how_many_num()
{
int j=0;
for(int i=0;i<len(word,des);i++)
   if(word[i]>='0' && word[i]<='9')
{
j++;
   while((word[i]>='0' && word[i]<='9')|| word[i]=='.')i++;
}
return j;
}








int how_many_cC(char c)
{
int y;
if(c>='A' && c<='Z')y=('a'-'A');
if(c>='a' && c<='z')y=-('a'-'A');

int j=0;

for(int i=0;i<len(word,des);i++)
       if(word[i]==c || word[i]==c+y)j++;

return j;
}



int how_many_con()
{
int j=0;
for(int i=0;i<len(word,des);i++)
   if( (word[i]>='A' && word[i]<='Z')||(word[i]>='a' && word[i]<='z'))
       if(strchr("aeiouAEIOU",word[i])==0)j++;

return j;
}

    char** tokens(int& z,char a[]=" ,.:;'?")
    {
        char**s=new char*[how_many(a)+5];
        z=1;
        s[1]=new char[50];

        for(int i=0; i<=len(word,des); i++)
        {

            int f=0;
            int y=0;
            do
            {
                f=0;

                for(int j=0;j<=len(a,des);j++)
                    if(a[j]==word[i])f=1;

                s[z][y]=word[i];
                i++;
                y++;
            }

            while(f!=1);
            y--;i--;
            s[z][y]=des;
            z++;
            y=0;
            s[z]=new char[50];

        }
       z--;
        return s;

    }

int* index_aparitie_s1(char a[],int& z,char v[]="., :;'?! ")
{
int* a2=new int[len(word,des)+5] ; z=0;
for(int i=0;i<=len(word,des);i++)
   {
      int p=-1;
      int f=0;
      int ax=i;
      char b[50]={0};
   do{
     f=0;
     for(int j=0;j<=len(v,des);j++)
        if(word[i]==v[j])f=1;
 if(f==0)
 {
 p++;
 b[p]=word[i];
 ;}

 i++;
 }while(f==0);
 i--;
 p++;
 b[p]=des;

//cout<<b<<endl;
//cout<<endl;
   if(comp5(b,a,0,des,0)==1)
   {
      z++;a2[z]=ax;
   }

}
return a2;
}

int* index_aparitie_s2(char a[],int& z)
{
   int* r=new int[len(word,des)+5];
   z=0;
   for(int i=0;i<=len(word,des);i++)
 {   char b[len(word,des)+5];
    int j;
   for(j=0;j<len(a,des);j++)
   {
      b[j]=word[i+j];
   }
   b[j]=des;
   if(comp5(a,b,0,des,0)==1)
   { z++;
      r[z]=i;
   }
 }
return r;
}

int* index_aparitie_s3(char c,int& z,int u=0)
{
   int* r=new int[len(word,des)+5];
   z=0;
   int y;
  if(c>='A' && c<='Z')y=('a'-'A')*u;
  if(c>='a' && c<='z')y=-('a'-'A')*u;


   for(int i=0;i<=len(word,des);i++)
 {
        if(word[i]==c || word[i]==c+y)
   {
      z++;
      r[z]=i;
   }

 }
return r;
}

int index_end()
{
return len(word,des);
}



char* split(int k)
{

char* g=new char[len(word,des)+1];
move_sd(g,word+k,len(word+k,des),0,0);
word[k]=des;

return g;

}

bool is_next_number(int& k)
{
   int u=0;
while(strchr("1234567890.",word[k+u]))u++;

if(u>0){k=k+u+1;return 1 ;}
return 0;
}



Char* load_Strings(char* s,int& ni,int mi=200)
{
   Char* u=new Char[ni];


   ifstream f(s);
   int z=0;
   while(!f.eof())
   {
      z++;u[z].word=new char[mi+10];
       f.getline(u[z].word,mi);
   }

   ni=z;
return u;
}


void join(Char* u,int ni,char* pluse)
{
   for(int i=1;i<=ni;i++)
   u[i]+=pluse;

}












int* index_aparitie_num(int& z)
{
int* a=new int[len(word,des)/2];

int j=0;
for(int i=0;i<len(word,des);i++)
   if(word[i]>='0' && word[i]<='9')
{
j++;
a[j]=i;
   while((word[i]>='0' && word[i]<='9')|| word[i]=='.')i++;
}

z=j;

return a;

}



char* extents(int a)
{

if(a>n)
{

char*ext=new char[a+1];
n=a;


for(int i=0;i<=len(word,des);i++)
   ext[i]=word[i];



delete [] word;

return ext;

}
return word;

}



void insrt(char a[],int k)
{

  int m_d=len(a,des)+len(word,des)+1;
if(m_d>n)
{
word=extents(m_d);
n=m_d;

}



char* p;

p=new char [len(word,des)+1];






int m=len(word,des)-k;

move_sd(p,word+k,m,0,0);


move_sd(word+k,a,len(a,des),0,0);

move_sd(word+k+len(a,des),p,m,0,0);


if(p!=NULL)delete [] p;

}

void paste(char a[],int k)
{

  int m_d=len(a,des)-k+len(word,des)+1;
if(m_d>n)
{
word=extents(m_d);
n=m_d;

}


int p=0;
if(k+len(a,des)>=len(word,des))p=0;
else p=-1;

move_sd(word+k,a,len(a,des)-1,0,0);



}

char* inm(char a[],int n)
{
char* o=new char[len(word,des)+len(a,des)*(n+1)];



move_sd(o,word,len(word,des),0,0);

for(int i=1;i<=n;i++)
{

int mg=len(word,des)+(i-1)*len(a,des);

move_sd(o+mg,a,len(a,des),0,0);



}
return o;

}

void inmm(char a[],int m)
{


char* u=inm(a,m);

;
cout<<n<<endl;


delete [] word;
word=u;


cout<<n<<endl;


}

void invers(int st=0,int en=0)
{
if(st==en) en=len(word,des)-1;

int u=en;


for(int i=st;i<=st+abs(st-en)/2;i++)
{
char aux=word[i];
word[i]=word[u];
word[u]=aux;
u--;
}

}

char* inversa(int st=0,int en=0)
{
   char* t=new char[len(word,des)+1];

   move_sd(t,word,len(word,des),0,0);

if(st==en) en=len(word,des)-1;


int u=en;


for(int i=st;i<=st+abs(st-en)/2;i++)
{

char aux=t[i];
t[i]=t[u];
t[u]=aux;
u--;
}
return t;
}



void operator<<(int m)
{

if(m==1)
cout<<word<<endl;
if(m==2)
cout<<len(word,des)<<endl;
if(m==3)
cout<<n<<endl;
if(m==4)
cout<<des<<endl;

}

char** words(int& nr,char des2=' ',int maxc=250)
{
   int nw=1;
   for(int i=0;i<strlen(word);i++)
   {

      if(word[i]==des2)
         nw++;



   }

   nw++;


   char** res=new char*[nw+1];
   for(int i=0;i<=nw;i++)
   res[i]=new char[maxc];


    char* aux=new char[strlen(word)];

   strcpy(aux,word);

cout<<"aici sunt"<<aux<<endl;

   int k=0;

   for(int i=0;i<=strlen(aux);i++)
   {
      if(aux[i]==des2)
      {

         k++;
         strncpy(res[k],aux,i);
         res[k][i]='\0';

         while(aux[i]==des2)i++;
          i--;

         strcpy(aux,aux+i+1);
      i=0;
   }

        if(aux[i]=='\0')
      {
         k++;
         strncpy(res[k],aux,i);
         res[k][i]='\0';
   }


   }

   nr=k;
   return res;
}









}stro,*stra,**strm;





struct A_type
{

enum sim{CHAR,STRING,INT,FLOAT,ARRAY_INT,ARRAY_DOUBLE,MATRIX_INT,MATRIX_FLOAT,MATRIX_DOUBLE,MATRIX_CHAR,OTHER,OTHERS,UNDEFINED} type;

void* data;

int index=1;

int total_size=1;
A_type* next=NULL;
A_type* prev=NULL;

int inc=0;
char indef[50]={0};


template<typename T>
A_type(T a,sim tu)
{
type=tu;
data=new T;
}


A_type()
{

}

template<typename T>
 void operator=(T a)
{
data=new T;
data=a;

}

template<typename T>
T& operator()(T a)
{
    return (T&)data;

}


template<typename T>
 T& operator()()
{
    return (T&)data;

}


template<typename T>
A_type& add_elm(T a,sim u)
{
total_size++;
A_type* us;

us=this;

for(int i=1;i<total_size-1;i++)
{
   us->total_size=total_size;
   if(us->next!=NULL)
   us=us->next;
}


us->next=new A_type(a,u);
us->next->prev=this;

us->next->index=total_size;

us->next->total_size=total_size;

return (A_type&)(us->next);
}

template<typename T>
A_type* add_elmp(T a,sim u)
{
total_size++;
A_type* us;
us=this;

for(int i=1;i<total_size-1;i++)
{
   us->total_size=total_size;
   if(us->next!=NULL)
   us=us->next;
}

us->next=new A_type(a,u);
us->next->prev=this;
us->next->index=total_size;
us->next->total_size=total_size;
return us->next;

}

A_type& operator [](int a)
{
A_type* us;
us=this;

if(a>0 && a<=total_size)
{
   for(int i=1;i<a;i++)
   us=us->next;

}

return us[0];
}


A_type& operator [](char* a)
{
A_type* us;
int u=1;
us=this;

if(inc)
{
   while(u<=total_size && comp5(us->indef ,a)!=1)
   {
      us=us->next;u++;
   }
   if(us==NULL)
 {
    int yu;

    us=add_elmp(yu,UNDEFINED);
    move_sd(us->indef,a,len(a,'\0'));
    cl(1,1,12);
    cout<<"new element"<<endl;
    cl(1,1,7);
 }
}
else
{
   move_sd(this->indef,a,len(a,'\0'));
   inc=1;
}
return us[0];
}



template<typename T>
void add_all(T a,sim b)
{
   add_elm(a,b);
   operator()(a)=a;

}




template<typename T>
void add_all(T a)
{
   add_elm(a,UNDEFINED);
   operator()(a)=a;

}

void add_all()
{
;
}

template<typename T,typename...R>
void add_all(T u,sim b ,R... arg)
{
   add_all(u,b);
   add_all(arg...);
}


template<typename T>
void use1(T& a)
{
switch(type)
{
case  STRING :
    a=(char*)data;
break;
case ARRAY_DOUBLE:
   a=(double*)data;
break;
   case ARRAY_INT:
   a=(int*)data;
break;
case MATRIX_DOUBLE :
    a=(double **)data;
break;
case MATRIX_CHAR:
   a=(char**)data;
break;
case MATRIX_INT:
  a=(int**)data;
break;

case FLOAT :
    a=*((double*) data);
break;
case CHAR:
   a=*((char*) data);
break;
case INT:
  a=*((int*) data);
break;

}

}
}tupo,*tupa,**tupm;
;};









template<typename T>
struct Helper
{
   T data;


};








template<typename T1,typename T2,typename T3>
struct C_type
{

private:
int typ;

public:
void* data;
C_type<T1,T2,T3>* sub;


template<typename T>
void operator =(T r)
{
  if(strcmp(typeid(r).name(),typeid(T1).name())==1){typ=1;   data=r;}
  else
if(strcmp(typeid(r).name(),typeid(T2).name())==1){typ=2;   data=r;}
   else
  if(strcmp(typeid(r).name(),typeid(T3).name())==1){typ=3;   data=r;}

}

T1* type1(int& p)
{
   if(typ!=1){p=0;return  NULL;}

   p=1;
   return(T1*)data;

}

T2* type2(int& p)
{
   if(typ!=2){p=0;return  NULL;}
   p=1;
   return(T2*)data;
}

T3* type3(int& p)
{
   if(typ!=3){p=0;return  NULL;}

   p=1;
   return(T3*)data;

}

void data_t(T1& n,T2& m,T3& o,int& u)
{
if(typ==1)
n=(T1)data;
if(typ==2)
m=(T2)data;
if(typ==3)
o=(T3)data;
u=typ;

}

char* type()
{
   if(typ==1)
return typeid(T1).name();
   if(typ==2)
return typeid(T2).name();
   if(typ==3)
return typeid(T3).name();
}


};

template<typename... R>
struct D_type
{

void* data;
int typ=0;
D_type<R...>*sub;


void d_type()
{
typ=0;
sub=new D_type<R...>;
}


D_type<R...>& operator [](int n)
{
   if(n>=1)
   {
   if(n==1)return this[0];
      else
       return sub->operator[](n-1);
   }

}

template<typename T>
void retreve(T& a,R&... arg,int& n)
{
   if(n<typ)
     {
      n=n+1;
      retreve(arg...,n);
     }
     else
     {
        a=(T)data;
     }

}




template<typename T,typename T2,typename...R2>
int help(T a,T2 b,R2...arg)
{
if(typeid(T)!=typeid(T2))
   {
     return 1+help(a,arg...);

   }
else
{
data=(void*)a;
 return 1;
}

}

template<typename T>
 T operator()()
{

return (T)data;
}




};

template<typename T>
struct iterate
{

   int n;int use=0;
   T* me;

   iterate(T* a,int ni)
   {
      n=ni;
      me=a;
   }
   template<typename R>
   iterate(R as)
   {
      me=as.a;
      n=as.n;
   }







  T operator () (int&i )
   {
      if(use==n){use=0;i=0;}
       use++;
       return me[use];


   }


    T& operator  [] (int& i)
   {
      if(use==n){use=0;i=0;}
      use++;
       return me[use];

   }


};















template<typename T=double>
struct infinit_array
{




T* a;

int n;
int number_of_dem;
int use_dim;
int act_nr=0;
int total_size=0;

const char* dtype()
{
return typeid(T).name();
}

int nf=0;
int nr;
int*ui;

int reduse=0;
infinit_array* next=NULL;


   int create(int n,int u)
{
   return 0;

}


template<typename...R>
int create(int now,int ni,int u,R...ai)
{
   number_of_dem=ni;
   use_dim=ni;
   act_nr=now;

   ui=new int[u+2];
if(now==ni)
{
 n=u;
 total_size=n;
 a=new T[u+2];
 return n;

}
else
if(now<ni)
{
 n=u;
next=new infinit_array[u+2];
int c=0;
for(int i=1;i<=u;i++)
total_size+=next[i].create(now+1,ni,ai...);

return total_size;
}

}




int create(int now,int*as,int asn)
{

   number_of_dem=asn;


   use_dim=as[now];
   act_nr=now;

   ui=new int[as[now]+1];


if(now==asn)
{

 n=as[now];
 total_size=as[now];
 a=new T[as[now]+2];
 return n;
}

else
if(now<asn)
{

 n=as[now];

next=new infinit_array[as[now]+2];

int c=0;

for(int i=1;i<=as[now];i++)
total_size+=next[i].create(now+1,as,asn);

return total_size;
}

}























infinit_array<T>& get_end(int i=1)
{
   if(act_nr==number_of_dem)return this[0];
   else
      return next[i].get_end(i);

}












T&  get(int i,int* path)
{
 if(i<number_of_dem)
 {
   // cout<<"p:"<<i<<" "<<path[i]<<endl;
    return next[path[i]].get(i+1,path);
 }
 else
   if(i==number_of_dem)
      {

      //cout<<"pf:"<<i<<" "<<path[i]<<endl;
    return a[path[i]]
     ;}

}



T& get2(int i)
{

return a[0];

}
   template<typename...Ri>
   T& get2(int i,int u,Ri...arg)
   {

    if(i==number_of_dem)
        return a[u];
       else
     return next[u].get2(i+1,arg...);
   }


infinit_array<T>& operator [](int i)
{

if(act_nr==number_of_dem)
return this[0];

return next[i];

}


T& operator ()(int i)
{


   if(act_nr==number_of_dem)
  return a[i];
 else
 {
    if(act_nr<number_of_dem)
    {


    int path[number_of_dem+2];
for(int j=1;j<=number_of_dem;j++)
        path[j]=1;


    path[number_of_dem]=i;

//sca(path,number_of_dem);



    return get(act_nr,path);
 }
 }

}


T& operator ()()
{
   return a[1];
}


void change_ud(int nu)
{
   use_dim=nu;

   if(act_nr<number_of_dem)
    for(int i=1;i<=n;i++)
   next[i].change_ud(nu);

}


T** convertto2d(int& ni,int & m)
{
   if(number_of_dem==2)
   {

      ni=n;
      m=next[1].n;


      T** a=new T*[n+1];

      for(int i=1;i<=n;i++)
      a[i]=new T[next[i].n+1];

      for(int i=1;i<=n;i++)
      for(int j=1;j<=next[i].n;j++)
      a[i][j]=this[0][i](j);
   }

}
/*
infinit_array<double> Fromimage(image u)
{
   infinit_array<double> t;
   t.create(1,3,5,u.height,u.width);
   for(int i=1;i<=u.height;i++)
   for(int j=1;j<=u.width;j++)
   {

     t[1][i](j)=u.reds()[i*(u.height-1)+j];
     t[2][i](j)=u.greens()[i*(u.height-1)+j];
     t[3][i](j)=u.blue()[i*(u.height-1)+j];
     t[4][i](j)=u.alphas()[i*(u.height-1)+j];
   }
return t;
}

*/





infinit_array<T> convertfrom2d(T** u, int& n,int & m)
{
   infinit_array<T> us;
   us.create(1,2,n,m);

   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   us[i](j)=a[i][j];

   return us;

}



void operator =(T** u)
{
   this=&convertfrom2d(u,u[1][0],u[2][0]);
}



T& operator>>(int i)
{
     int c=0;
         for(int j=1;j<=nf;j++)
            if(ui[j]==i)c=1;


      if(c==0){nf++;ui[nf]=i;}


      return operator()(i);
}



void md(T* u,int ni)
{
   if(act_nr==number_of_dem)
{
  if(ni<n)
for(int i=1;i<=ni;i++)
a[i]=u[i];
else
{
   a=new T[ni+1];
 for(int i=1;i<=ni;i++)
a[i]=u[i];
   n=ni;
}
}
 else
 {
    for(int i=1;i<=n;i++)
    next[i].md(u,ni);
 }
}





void mdd(T** u,int ni,int mi)
{

 if(act_nr==number_of_dem-1)
 if(ni<=n)
{
   for(int i=1;i<=ni;i++)
   {
    next[i].md(u[i],mi);
   }


}
else
{
    next=new infinit_array<T>[ni+1];
    for(int i=1;i<=ni;i++)
   {
    next[i]->md(u[i],mi);
   }
}
 else
for(int i=1;i<=n;i++)
   next[i]->md(u,ni,mi);
}


  infinit_array<T>()
{

}








infinit_array<T>(T* u,int ni)
{
   n=ni;
   number_of_dem=1;
   act_nr=1;
   a=new T[ni+5];
   move_d(a,u,ni);

}


infinit_array<T>(T** u,int ni,int mi)
{
   n=ni;
   number_of_dem=2;
    act_nr=1;
next=new infinit_array<T>[ni+2];

for(int i=1;i<=ni;i++)
{
next[i].number_of_dem=2;
next[i].act_nr==2;
next[i].a=new T[mi+2];

for(int j=1;j<=mi;j++)
next[i].a[j]=u[i][j];
}
}


void passed(T* u,int ni,int& k)
{

   //cout<<"k"<<k<<" a "<<act_nr<<" n "<<number_of_dem<<endl;

if(act_nr==number_of_dem)
   {
      int i=0;
    while(i<n && k>0)
    {
    i++;
    k--;
    a[i]=u[ni-k];
    }


   }
   else
{
//cout<<"ki"<<k<<endl;
    if(k>0)
      for(int i=1;i<=n;i++)
       next[i].passed(u,ni,k);
}



}


void myshape(int* ai,int& z)
{



   if(act_nr==number_of_dem)
    {z++;ai[z]=n;}
    else
   if(act_nr<number_of_dem)
     {

        z++;ai[z]=n;
        next[1].myshape(ai,z);
     }


}


void prints()
{
   if(act_nr==number_of_dem)

   { cout<<"[";
      for(int i=1;i<n;i++)
      cout<<a[i]<<",";

      cout<<a[n]<<"]"<<endl;

      ;}
    else
    {
       cout<<"[";
        for(int i=1;i<=n;i++)
          {  next[i].prints();
          }
             cout<<"]"<<endl;
    }

}
void print(int i=0)
{
   cout<<"infinit_array "<<dtype();

   if(i)cout<<" "<<i;
   cout<<endl;

  prints();


}
void print(char*s)
{
   cout<<"infinit_array "<<dtype();

   sca(s,len(s,' '));

  prints();


}




void rand_infinit(double a2=0 ,double b=1)
{
   if(act_nr==number_of_dem)
    for(int i=1;i<=n;i++)
      a[i]=randf(a2,b);
    else
      for(int i=1;i<=n;i++)
        next[i].rand_infinit(a2,b);
}



void redifine(T* dat,int nd,int* shape,int ns)
{
create(1,shape,ns);
int o=nd;
passed(dat,nd,o);
}



void uadd_inf(infinit_array<T>& A,infinit_array<T> b,int op=1)
{

   if(A.act_nr==A.number_of_dem  && b.act_nr==b.number_of_dem)

      for(int i=1;i<=min(A.n,b.n);i++)
      {
         if(op==1)A.a[i]+=b.a[i];
         if(op==2)A.a[i]-=b.a[i];
         if(op==3)A.a[i]*=b.a[i];
         if(op==4)A.a[i]/=b.a[i];
         if(op>10)A.a[i]=(int)A.a[i]%(int)(b.a[i]);
      }
        else
   {
     // cout<<"A-b"<<A.n<<" "<<b.n<<endl;
         for(int i=1;i<=min(A.n,b.n);i++)
          uadd_inf(A.next[i],b.next[i],op);

   }

}





void softmax(infinit_array<T> put)
{

if(put.act_nr==put.number_of_dem)
   {

      double sm=0;
      for(int k=1;k<=n;k++)
         sm+=Math.expo(a[k]);

      for(int i=1;i<=n;i++)
      {
         a[i]=Math.expo(a[i])/sm;

      }
   }
   else
      for(int i=1;i<=n;i++)
       put.softmax(put.next[i]);
}












void help_gen(infinit_array<T>& res,infinit_array<T> other,T (*f)(T,T))
{
if(act_nr==number_of_dem)
   for(int i=1;i<=min(n,other.n);i++)
     res.a[i]=f(a[i],other.a[i]);
    else
   for(int i=1;i<=min(n,other.n);i++)
   next[i].help_gen(res.next[i],other.next[i],f);
}


template<typename R,typename R2>
infinit_array<T> compareable(infinit_array<T> other,T (*f)(R,R2) )
{
 infinit_array<T> res;
   int* a=new int [number_of_dem+1];
   int z=0;
   myshape(a,z);
   res.create(1,a,z);

   help_gen(res,other,f);

return res;
}













void help_min(infinit_array<T>& res,infinit_array<T> other)
{
if(act_nr==number_of_dem)
   for(int i=1;i<=min(n,other.n);i++)
     res.a[i]=min(a[i],other.a[i]);
    else
   for(int i=1;i<=min(n,other.n);i++)
   next[i].help_max(res.next[i],other.next[i]);
}



infinit_array<T> minimum(infinit_array<T> other)
{
 infinit_array<T> res;
   int* a=new int [number_of_dem+1];
   int z=0;
   myshape(a,z);
   res.create(1,a,z);

   help_max(res,other);

return res;
}











void help_max(infinit_array<T>& res,infinit_array<T> other)
{
if(act_nr==number_of_dem)
   for(int i=1;i<=min(n,other.n);i++)
     res.a[i]=max(a[i],other.a[i]);
    else
   for(int i=1;i<=min(n,other.n);i++)
   next[i].help_max(res.next[i],other.next[i]);
}








infinit_array<T> maximum(infinit_array<T> other)
{


 infinit_array<T> res;
   int* a=new int [number_of_dem+1];
   int z=0;
   myshape(a,z);
   res.create(1,a,z);

   help_max(res,other);

return res;

}












void one_value(T d=0)
{
if(act_nr==number_of_dem)
   for(int i=1;i<=n;i++)
    a[i]=d;
   else
    for(int i=1;i<=n;i++)
    next[i].one_value(d);
}


void op(T (*f)(T))
{
if(act_nr==number_of_dem)
   for(int i=1;i<=n;i++)
    a[i]=f(a[i]);
   else
    for(int i=1;i<=n;i++)
    next[i].op(f);
}


template<typename R>
void opb(T (*f)(T,R),R u)
{
if(act_nr==number_of_dem)
   for(int i=1;i<=n;i++)
    a[i]=f(a[i],u);
   else
    for(int i=1;i<=n;i++)
    next[i].opb(f,u);
}


T** multiply2d(T** u,int ni,int mi)
{

   //sca2d(u,ni,mi);

      if(infinit_array<T>::act_nr<infinit_array<T>::number_of_dem)
      {
         T** p=new T*[infinit_array<T>::n+2];
         for(int i=1;i<=infinit_array<T>::n;i++)
         {
  if(infinit_array<T>::act_nr==infinit_array<T>::number_of_dem-1)
          p[i]=new T[infinit_array<T>::next[i].n];
          else
          {
             int o=infinit_array<T>::get_end().n+2;
              p[i]=new T[o];
          }
         }



     for(int i=1;i<=infinit_array<T>::n;i++)
     {

     for(int j=1;j<=infinit_array<T>::get_end().n;j++)

     {

        infinit_array<T> op= this->operator[](i);

        p[i][j]=op(j) ;

     }
     }

        return dotppp(p,u,infinit_array<T>::n,infinit_array<T>::get_end().n,ni,mi);
      }
   }

void multiply2dm(T** u,int ni,int mi)
{
      if(infinit_array<T>::act_nr<infinit_array<T>::number_of_dim)
      {
         T** p=new T*[infinit_array<T>::n+2];
         for(int i=1;i<=infinit_array<T>::n;i++)
         {
            if(infinit_array<T>::act_nr==infinit_array<T>::number_of_dem-1)
          p[i]=new T*[infinit_array<T>::next[i].n];
          else
          {
             int o=infinit_array<T>::get_end().n+2;
              p[i]=new T[o];
          }
         }

     for(int i=1;i<=infinit_array<T>::n;i++)
     for(int j=1;j<=infinit_array<T>::get_end().n;j++)
        p[i][j]=this[0][i](j);

      T** use=dotppp(p,u,infinit_array<T>::n,infinit_array<T>::get_end().n,ni,mi);

      if(use)
      {
         for(int i=1;i<=use[1][0];i++)
          for(int j=1;j<=use[2][0];j++)
         if(use[1][0]<=infinit_array<T>::n && use[2][0]<=infinit_array<T>::get_end().n)
          this[0][i](j)=use[i][j];
      }

      }
   }


infinit_array<T>  mult_inf(infinit_array<T> put)
     {
      if(infinit_array<T>::act_nr<infinit_array<T>::number_of_dem)


         if(put.act_nr<put.number_of_dem)
      {
         T** p=new T*[n+2];
         T** r=new T*[put.n+2];

     for(int i=1;i<=n;i++)
     {

        p[i]=new T[get_end().n+2];

     for(int j=1;j<=get_end().n;j++)
     {
        infinit_array<T> op=this->operator[](i);
        p[i][j]=op(j) ;
     }

     }

     for(int i=1;i<=put.n;i++)
     {

        r[i]=new T[put.get_end().n+2];

     for(int j=1;j<=put.get_end().n;j++)
     {

         infinit_array<T> op2=put[i];
        r[i][j]=op2(j) ;

     }
     }

   T** res=dotppp(p,r,infinit_array<T>::n,infinit_array<T>::get_end().n,put.n,put.get_end().n);

            infinit_array<T> er;


            int sh[5]={0,res[1][0],res[2][0]};


            er.create(1,sh,2);

        for(int i=1;i<=res[1][0];i++)
        for(int j=1;j<=res[2][0];j++)
            er[i](j)=res[i][j];

        return er;

      }
      else
          if(put.act_nr==put.number_of_dem && act_nr<number_of_dem)
      {
         infinit_array<T> helper;
         helper.create(1,2,n,1);


         for(int i=1;i<=n;i++)
          helper[i](1)=put.a[i];

          return mult_inf(helper);
      }
      else
             if(put.act_nr==put.number_of_dem && act_nr==number_of_dem)
      {
        infinit_array<T> rest;
        rest.create(1,1,n);
        for(int i=1;i<=n;i++)
        rest[i]=put(i)*this->a[i];

      }

   }

   void help_multi(infinit_array<T>& r,infinit_array<T> ro,int* a2,int k)
   {

      if(act_nr<number_of_dem-1 &&  ro.act_nr<ro.number_of_dem-1)
      for(int i=1;i<=min(n,ro.n);i++)
      {            a2[k]=i;
            next[i].help_multi(r,ro.next[i],a2,k+1);
      }
         else
      if(act_nr==number_of_dem-1 &&  ro.act_nr==ro.number_of_dem-1)
      {
         // cout<<"aici"<<act_nr<<" "<<number_of_dem<<" "<<k<<endl;

         for(int i=1;i<=n;i++)
           for(int j=1;j<=ro[1].n;j++)
         {

         a2[k]=i;
         a2[k+1]=j;


        // cout<<"ki:";
        // sca(a2,k+1);

         int p[r.number_of_dem+1];
         int pk=0;

         pk=1;
         r.get(pk,a2)=0;



         //cout<<"pj:";
           r.myshape(p,pk);

            for(int w=1;w<=ro.n;w++)
            {
          pk=1;
         r.get(pk,a2)+=this->operator[](i)(w)*ro[w](j);
            }

         }

        // cout<<"una gata"<<endl;
      }


   }



infinit_array<T> multiew2(infinit_array<T> r)
{
   int a1[number_of_dem-act_nr+2];
   int a2[r.number_of_dem-r.act_nr+2];

   int k1=0,k2=0;

   myshape(a1,k1);
   r.myshape(a2,k2);


   if(k1==k2)
   if(k1 >1 && k2>1)
   {

   if(a1[k1]==a2[k2-1])
   {

      a1[k1]=a2[k2];
    infinit_array rest;
   rest.create(1,a1,k1);
   k2=1;
   help_multi(rest,r,a2,k2);
   return rest;
   }

   }

   cl(1,1,12);
   cout<<"eroare!!!"<<endl;

}


infinit_array<T> multiew23(infinit_array<T> r)
{


   int a1[number_of_dem-act_nr+2];
   int a2[r.number_of_dem-r.act_nr+2];


   int k1=0,k2=0;

   myshape(a1,k1);
   r.myshape(a2,k2);

   if(k1 >1 && k2>1)

   {
         if(k1>k2)
         {

        infinit_array restp;
       restp.create(1,a1,k1);


        for(int i=1;i<=n;i++)
            restp[i]=next[i].multiew23(r);

            return restp;
         }
         else
         if(k2>k1)
         {

         infinit_array restp;
         restp.create(1,a2,k2);

             for(int i=1;i<=r.n;i++)
               restp[i]=multiew23(r[i]);


                   return restp;

         }
         else
   if(a1[k1]==a2[k2-1])
   {

      a1[k1]=a2[k2];

    infinit_array rest;
   rest.create(1,a1,k1);

   k2=1;
   help_multi(rest,r,a2,k2);
   return rest;
   }

   }

   cl(1,1,12);
   cout<<"eroare!!!"<<endl;

}


 void addinf(T d,int op=1)
{
   if(act_nr==number_of_dem)
   for(int i=1;i<=n;i++)
   {
      if(op==1)
      a[i]+=d;
      if(op==2) a[i]*=d;
      if(op==3) a[i]/=d;
      if(op==10)a[i]=(int)a[i]%(int)d;
   }
   else
    for(int i=1;i<=n;i++)
    next[i].addinf(d,op);
}







void heilight(int* ind,int da,T ov=0, T of=1,int y=0)
{
   if(act_nr==number_of_dem)

            for(int j=1;j<=n;j++)
            {
               int c=0;
        for(int i=1;i<=da;i++)
          if(ind[i]==a[j]){ind[i]=0;a[j]=ov;c=1;}
         if(c==0)
             if(y==0)a[j]=of;
            }
     else
      for(int i=1;i<=n;i++)
    next[i].heilight(ind,da,ov,of);

}



void powinf(infinit_array<T> put)
{
   if(act_nr==number_of_dem && put.act_nr==put.number_of_dem)
   {
      for(int i=1;i<=n;i++)
       a[i]=sqrm(a[i],put.a[i]);
   }
   else
    for(int i=1;i<=min(n,put.n);i++)
      next[i].powinf(put.next[i]);
}


void powinfv(T d)
{
   if(act_nr==number_of_dem )
   {
      for(int i=1;i<=n;i++)
       a[i]=sqrm(a[i],d);
   }
   else
    for(int i=1;i<=n;i++)
      next[i].powinf(d);
}













infinit_array<T> SAME_AS_SHAPE(infinit_array<T>& u,T gv=NULL)
{
   infinit_array<T> ret;

   int se[u.number_of_dem+1];
   int k=0;
   u.myshape(se,k);


ret.create(1,se,k);
ret.one_value(gv);
return ret;

}


void help_copy(infinit_array<T>& u,infinit_array<T> us)
{

   if(us.act_nr==us.number_of_dem)
   {


      for(int i=1;i<=us.n;i++)
       u.a[i]=us.a[i];

   }
   else
       {

       for(int i=1;i<=us.n;i++)
       help_copy(u.next[i],us.next[i]);
       }


}



void assign_infinit(infinit_array<T>& u)
{


 help_copy(u,this[0]);

}

void print_ind()
{


   cout<<"dimension:"<<act_nr<<"/"<<number_of_dem<<endl;
   cout<<"number of neibors/number of data"<<n<<endl<<endl;

   if(next!=NULL)
for(int i=1;i<=n;i++)
   next[i].print_ind();




}








infinit_array<T> COPY(infinit_array<T> u)
{
   infinit_array<T> ret;

   int se[u.number_of_dem+1];
   int k=0;

   u.myshape(se,k);
   //sca(se,k);

   ret.create(1,se,k);
   k=0;
   ret.myshape(se,k);
   //sca(se,k);

 help_copy(ret,u);

return ret;
}








void help_avreage(infinit_array<T> r[],int ni,infinit_array<T>& res,int& k)
{


int a[100];
int k2=0;
res.myshape(a,k2);

if(r[1].act_nr==r[1].number_of_dem && res.act_nr==res.number_of_dem)

{

k++;


for(int i=1;i<=r[1].n;i++)
{

   T avj=0;
   for(int j=1;j<=ni;j++)
      avj+=r[j].a[i];

res(i)=avj/ni;

}
}
else
   for(int i=1;i<=r[1].n;i++)
{

   infinit_array<T> rest[ni+2];
   for(int j=1;j<=ni;j++)
   rest[j]=r[j].next[i];
   help_avreage(rest,ni,res.next[i],k);

}
}





void help_gen(infinit_array<T> r[],int ni,infinit_array<T>& res,int& k,T(*F)(T*,int))
{

int a[100];
int k2=0;
res.myshape(a,k2);

if(r[1].act_nr==r[1].number_of_dem && res.act_nr==res.number_of_dem)

{

k++;


for(int i=1;i<=r[1].n;i++)
{
T po[ni+2];

   for(int j=1;j<=ni;j++)
      po[j]=r[j].a[i];

res(i)=F(po,ni);

}
}
else
   for(int i=1;i<=r[1].n;i++)
{

   infinit_array<T> rest[ni+2];
   for(int j=1;j<=ni;j++)
   rest[j]=r[j].next[i];
   help_avreage(rest,ni,res.next[i],k);

}

}










infinit_array<T>  avreage(infinit_array<T> r[],int ni)
{
   int* a=new int[r[1].number_of_dem+5];
   int k=0;

   infinit_array<T> res;

   r[1].myshape(a,k);


   res.create(1,a,k);




   int o=0;
   help_avreage(r,ni,res,o);

return res;


}






infinit_array<T>  array_general(infinit_array<T> r[],int ni,T (*f)(T*,int))
{
   int* a=new int[r[1].number_of_dem+5];
   int k=0;

   infinit_array<T> res;

   r[1].myshape(a,k);


   res.create(1,a,k);

   int o=0;
   help_agen(r,ni,res,o,f);

return res;

}


void help_trans(infinit_array<T>& r,int* as,int* perm,int k,int ni)
{
   if(act_nr==number_of_dem)
   {
 int sa[number_of_dem+1];



      for(int j=1;j<=n;j++)

   {

      as[k]=j;
//cout<<"s:";sca(as,k);

      move_d(sa,as,k);

      for(int i=1;i<=k;i++)
      {
         int aux=sa[i];

         as[i]=sa[perm[i]];
         as[perm[i]]=aux;
      }

//sca(as,k);

//cout<<endl<<this->a[j]<<" ";
   r.get(1,as)=this->a[j];
   //cout<<r.get(1,as);
   move_d(as,sa,k);
   }


   }
   else
{

   for(int i=1;i<=n;i++)
   {
      as[k]=i;

       next[i].help_trans(r,as,perm,k+1,ni);
   }

}
}

infinit_array<T> transpusa(int perm[]=NULL,int ni=0)
{

   int ai[number_of_dem+1];

     int k=0;

     myshape(ai,k);
     int c1=0,c2=0;


   if(ni==0 || perm==NULL)
 {
    perm=new int[number_of_dem+1];


    for(int i=k;i>=1;i--)
      {
         ni++;
         perm[ni]=i;
      }

 for(int i=1;i<=k/2;i++)
      {


         int aux=ai[i];

         ai[i]=ai[k-i+1];

         ai[k-i+1]=aux;
      }


//sca(ai,k);
//sca(perm,k);


 }
  else
{
   c1=1;
   if(ni==k)
   {c2=1;
    //sca(ai,k);

    int sa[number_of_dem];

    move_d(sa,ai,k);
    for(int i=1;i<=k;i++)
      {

         int aux=sa[perm[i]];

         ai[perm[i]]=sa[i];
         ai[i]=aux;
      }
   }
//sca(ai,k);
//sca(perm,k);

}

   infinit_array<T> trn;

 if( (!c1) || (c1 && c2) )
{



//sca(ai,k);
 trn.create(1,ai,k);

 ni=1;

 //cout<<act_nr<<" "<<number_of_dem<<endl;
//system("pause");

   help_trans(trn,ai,perm,ni,k);

 }
//trn.print(-11);
   return trn;

}

infinit_array<T> oneslike(infinit_array<T> pat)
{
   int a1[pat.number_of_dem+1];
   int k=0;

   pat.myshape(a1,k);


   infinit_array<T> t;
   t.create(1,a1,k);

   t.one_value(1);

}


int update(int c=1)
{

   if(next!=NULL)
   {
      int maxi=0;
      act_nr=c;

   for(int i=1;i<=n;i++)
    {

     if(next[i].update(c+1)>maxi)
      maxi=next[i].update(c+1);
     number_of_dem=maxi;
    }

      return number_of_dem;

}
   else

   if(next==NULL)
   {

   act_nr=c;
   number_of_dem=c;
   return c;
   }
}





infinit_array<T> getn(int* a,int n,int i=0)
{
   if(i<n)
   {

      return this->next[a[i]].getn(a,n,i+1);
   }

   if( i==n)
   return this[0];
}


int nr_e(int k=0)
{
   if(act_nr<number_of_dem)
   {

     for(int i=1;i<=n;i++)
     k+=next[i].nr_e(0);

     return k;

   }

   if(act_nr==number_of_dem)
      return n;

}

void help_data(T* as,int& k)
{

   if(act_nr==number_of_dem)
   {
      for(int i=1;i<=n;i++)
      {k++;as[k]=a[i];}

   }
   else
      for(int i=1;i<=n;i++)
      next[i].help_data(as,k);
}




T* data(int& k)
{
   T* datas;

   datas=new T[nr_e()+1];
   k=0;

   help_data(datas,k);

   return datas;

}




T get_from_data(int p)
{

   int ui=0;
   T* pus=data(ui);
   return pus[p];

}


///give data for a infinit_array from a array
void givefa(T* ad,int& z,int ni)
{
  cout<<"z:"<<z<<endl;


   if(act_nr==number_of_dem)
   {

    for(int i=1;i<=n;i++)
   if(z<ni){z++;a[i]=ad[z];}

   }
      else
       for(int i=1;i<=n;i++)
      next[i].givefa(ad,z,ni);

}






 T& help_use_from_dats(int& k,int& pos,int u)
{

      if(act_nr==number_of_dem)
   {
   for(int i=1;i<=n;i++)
   {
        k++;
      if(k==u)
   {
   pos=1;
  return a[i];
   ;}


   }
   }
   else
      for(int i=1;i<=n;i++)
      {
         int ok=k;
         if(pos!=1)
         {

             next[i].help_use_from_dats(k,pos,u);
         }

         if(pos==1)
         {

           pos=-1;
            k=ok;
      return next[i].help_use_from_dats(k,pos,u);
         }

   }

}

T& use_from_data(int u)
{
   int k=0;
 int pos=0;
   return help_use_from_dats(k,pos,u);
}




void tense_contr(infinit_array<T>&r ,infinit_array<T>t ,infinit_array<T> s,int uj=1,int rank=2,int rankp=2)
{

  if(t.act_nr==t.number_of_dem)
  {

      r(uj)=0;
     for(int i=1;i<=t.n;i++)
     {

         r(uj)+=t(i)*s[i](uj);
     }

  }
  else
   if(rank%2==0)
   {
      rankp=rank;
  cout<<"here"<<rank<<" "<<t.n<<" "<<s[1].n<<endl;

   for(int i=1;i<=t.n;i++)
   {

   for(int j=1;j<=s[1].n;j++)
  {
     tense_contr(r[i],t[i],s,j,rank-1,rankp);
  }


   if(rank==2)
  {      cout<<"ila"<<endl;
        sca(r[i].a,r[i].n);
  }

  }



   }
   else
      if(rank%2==1)
   {

    cout<<"there"<<rank<<" "<<endl;


 infinit_array<T> po=r.COPY(r);
 infinit_array<T> ps=r.COPY(r);

   ps[1].print(24);

      for(int i=1;i<=t.n;i++)
      {

         if(rankp%2==0)
            tense_contr(po[i],t[i],s[i][uj],1,rank-1,rankp);
             else
         if(rankp%2==1)
      tense_contr(po[i],t[i],s[i],1,rank-1,rankp);
         uadd_inf(ps[1],po[i]);

      }

   r[uj]=ps[1];

   }


   }






  infinit_array<T> conv2d(infinit_array<T>x ,infinit_array<T> kernel,int pos=0,int(*fx)(int)=NULL,int(*fy)(int)=NULL)
   {

      infinit_array<T> g=x.COPY(x);
g.one_value(0);

      //if(x.act_nr==x.number_of_dem-1)
      for(int i=1;i<=x.n;i++)
       for(int j=1;j<=x[i].n;j++)
      {



         int hi=kernel.n;

         for(int l=1;l<=kernel.n;l++)
         {
             int  wi=kernel[l].n;

         for(int k=1;k<=kernel[l].n;k++)
         {

           if(pos==0)
   if(between(1,x.n,i+l-hi/2)&& between(1,x[i].n,j+k-wi/2))
   {


         g[i](j)+=x[i+l-hi/2-1](j+k-wi/2-1)*kernel[l](k);
   }

            if(pos)
if(between(1,x.n,i+l+fy(hi))&& between(1,x[i].n,j+k-fx(wi)))
         g[i](j)+=x[i+l+fy(hi)](j+k+fy(wi))*kernel[l](k);

         /*
         for(int ii=1;ii<=x.n;ii++)
         {

         for(int jj=1;jj<=x[ii].n;jj++)
         {
           if(ii==i && jj==j)cl(1,1,14);
           if(ii==i+l-hi/2 && jj==j+k-wi/2)cl(1,1,13);
            cout<<g[ii](jj)<<" ";
            cl(1,1,7);
         }

         cout<<endl
         ;}

         cout<<endl<<endl;

         Sleep(1000);
*/ }
      }
      }

      return g;
   }



infinit_array<T> conv2dless(infinit_array<T>x ,infinit_array<T> kernel,int s1=1,int s2=1,int pos=0,int(*fx)(int)=NULL,int(*fy)(int)=NULL)
   {

      infinit_array<T> g=x.COPY(x);
g.one_value(0);
      //if(x.act_nr==x.number_of_dem-1)
      for(int i=1;i<=x.n;i+=s1)
       for(int j=1;j<=x[i].n;j+=s2)
      {



         int hi=kernel.n;

         for(int l=1;l<=kernel.n;l++)
         {

            if(s1==0)s1=kernel.n;
            int  wi=kernel[l].n;

         for(int k=1;k<=kernel[l].n;k++)
         {
            if(s2==0)s2=kernel[l].n;

           if(pos==0)
   if(between(1,x.n,i+l-hi/2)&& between(1,x[i].n,j+k-wi/2))
   {


         g[i](j)+=x[i+l-hi/2-1](j+k-wi/2-1)*kernel[l](k);
   }

            if(pos)
if(between(1,x.n,i+l+fy(hi))&& between(1,x[i].n,j+k-fx(wi)))
         g[i](j)+=x[i+l+fy(hi)](j+k+fy(wi))*kernel[l](k);
 }
      }
      }

      return g;
   }


infinit_array<T> conv2dless2(infinit_array<T>x ,infinit_array<T> kernel,int s1=1,int s2=1,int rate_d=1,int pos=0,int(*fx)(int)=NULL,int(*fy)(int)=NULL)
   {

      infinit_array<T> g=x.COPY(x);
g.one_value(0);
      for(int i=1;i<=x.n;i+=s1)
       for(int j=1;j<=x[i].n;j+=s2)
      {

         int hi=kernel.n;

         for(int l=1;l<=kernel.n;l++)
         {

            if(s1==0)s1=kernel.n;
            int  wi=kernel[l].n;

         for(int k=1;k<=kernel[l].n;k++)
         {
            if(s2==0)s2=kernel[l].n;

           if(pos==0)
   if(between(1,x.n,i+l*rate_d-hi/2)&& between(1,x[i].n,j+k*rate_d-wi/2))
   {


         g[i](j)+=x[i+l*rate_d-hi/2-1](j+k*rate_d-wi/2-1)*kernel[l](k);
   }

            if(pos)
if(between(1,x.n,i+l*rate_d+fy(hi))&& between(1,x[i].n,j+k*rate_d-fx(wi)))
         g[i](j)+=x[i+l*rate_d+fy(hi)](j+k*rate_d+fy(wi))*kernel[l](k);
 }
      }
      }

      return g;
   }























  infinit_array<T> convnd(infinit_array<T>x ,infinit_array<T> kernel,int pos=0,int(*fx)(int)=NULL,int(*fy)(int)=NULL)
   {


      if(kernel.number_of_dem==x.number_of_dem)
      {


         if(x.number_of_dem-1==x.act_nr && kernel.number_of_dem-1==kernel.act_nr)
         return conv2d(x,kernel,pos,fx,fy);

      }
      else
      {
          for(int i=1;i<=n;i++)
           x[i]=convnd(x[i],kernel[i],pos,fx,fy);

           return x;

      }

      }








};

template<typename T>
struct infa_scalar
{

   T a;
   create(T b)
   {
      a=b;
   }
   T& operator()()
   {
      return a;
   }

};


template<typename T>
struct infa_1d:infinit_array<T>
{

  void  create(int* values,int nv,int* shape,int ns)
   {

      if(ns>=1)
      infinit_array<T>::redifine(values,nv,shape,1);

   }


   void  create(int* shape,int ns)
   {
   if(ns>=1)
      infinit_array<T>::create(1,shape,ns);

   }




 void screate(int nv,int* shape,int ns)
 {
    if(ns>1)
       infinit_array<T>::create(1,shape,1);
}

infa_1d<T> linespace(int st,int sp,int k)
{
   infa_1d<T> ls;
   int sh[100]={0,k+5};

   ls.create(sh,1);
   for(int i=1;i<=k;i++)
    if(st+i<=sp)ls(i)=st+i;

   return ls;
}
void vgc(T*v,int ni)
{
   infinit_array<T>::create(1,1,ni);

   for(int i=1;i<=ni;i++)
  infinit_array<T>::a[i]=v[i];









}







infa_1d<T> range(int st,int sp,int step=1)
{
   infa_1d<T> ls;
   int sh[100]={0,abs(sp-st)+5};

   ls.create(sh,1);
   for(int i=1;st+i<sp;i+=step)
    if(st+i<=sp)ls(i)=st+i;

   return ls;
}


T mult1d(infa_1d<T> t)
{
   T sum=NULL;

   for(int i=1;i<=min(infinit_array<T>::n,t.n);i++)
       sum+=infinit_array<T>::a[i]*t.a[i];
       return sum;
}





};

template<typename T>
infinit_array<T> one_hot_how(infa_1d<int> a,int depth=2,double on=1,double of=0)
{
   infinit_array<T> res;

   int lines=a.n;
cout<<lines;



   res.create(1,2,lines,depth);

   for(int i=1;i<=lines;i++)
   {

      for(int j=1;j<=depth;j++)
      res[i](j)=of;

      res[i](a(i))=on;
   }

return res;


}





template<typename T>
void help_flatten(infa_1d<T>& res,infinit_array<T> put, int& z)
{

    if(put.act_nr==put.number_of_dem)
      for(int i=1;i<=put.n;i++)

      {z++; res(z)=put.a[i];}
        else
         for(int i=1;i<=put.n;i++)
            help_flatten(res,put.next[i],z);

}

template<typename T>
infa_1d<T> flatten(infinit_array<T> put,int& z)
{

   z=0;
      infa_1d<T> res;
      int sh[3]={0,put.total_size};
      res.create(sh,1);


      help_flatten(res,put,z);




      return res;
}




template<typename T>
struct infa_2d:infinit_array<T>
{
  void  create(int* values,int nv,int* shape,int ns)
   {

      if(ns>=2)
      infinit_array<T>::redifine(values,nv,shape,2);

   }

   void  create(int nv,int* shape,int ns)
   {
   if(ns>=2)
      infinit_array<T>::create(1,shape,2);

   }
 void screate(int nv,int* shape,int ns)
 {
    if(ns>2)
       infinit_array<T>::create(1,shape,2);
   }



void vgc(T** a2 ,int ni,int m)
{


   infinit_array<T>::create(1,2,ni,m);

   cout<<"nu aci"<<endl;


   for(int i=1;i<=ni;i++)
    for(int j=1;j<=m;j++)


      this[0][i](j)=a2[i][j];




}






 infa_2d<T> transpose()
 {

    int ai [infinit_array<T>::number_of_dem+1];
    int k=0;

    infinit_array<T>::myshape(ai,k);



    for(int i=1;i<=k/2;i++)
     { T aux; aux=ai[i]; ai[i]=ai[k-i+1];ai[k-i+1]=aux;}




    infa_2d<T> trn;
    trn.create(1,ai,k);
    for(int i=1;i<= infinit_array<T>::n;i++)
     for(int j=1;j<= infinit_array<T>::get_end().n;j++)
       trn[j](i)=this->operator[](i)(j);

   return trn;

 }










};






template<typename T>
struct infa_3d:infinit_array<T>
{
  void  create(int* values,int nv,int* shape,int ns)
   {

      if(ns>=3)
      infinit_array<T>::redifine(values,nv,shape,3);

   }


   void  create(int nv,int* shape,int ns)
   {

   if(ns>=3)
      infinit_array<T>::create(1,shape,3);

   }
 void screate(int nv,int* shape,int ns)
 {
    if(ns>3)
       infinit_array<T>::create(1,shape,3);
   }





   infinit_array<T> mult3d(infa_3d<T> t)
   {

      int a1[infinit_array<T>::number_of_dem];
      int a2[t.number_of_dem];


      int k=0,k2=0;

      infinit_array<T>::myshape(a1,k);
      t.myshape(a2,k2);




      infinit_array<T> u;
      infinit_array<T> u3;


      u3=t;
      u.create(1,2,a1[k-1],a2[k2]);

    u3=infinit_array<T>::multiew2(u3);

     u=u3[1];


    for(int i=2;i<=min(infinit_array<T>::n,t.n);i++)
    infinit_array<T>::uadd_inf(u,u3[i]);
  return u;
   }





     void help_convert3d(infinit_array<T>& me,infinit_array<T> t)
   {


      if(t.act_nr<t.number_of_dem)
      {
       me.n=t.n;

       me.act_nr=t.act_nr;
       me.number_of_dem=t.number_of_dem;

      for(int i=1;i<=t.n;i++)
      {
          me.next[i]=t.next[i];
       help_convert3d(me.next[i],t.next[i]);
      }

      }
   else
   {

     me.n=t.n;
       me.act_nr=t.act_nr;
       me.number_of_dem=t.number_of_dem;

      for(int i=1;i<=t.n;i++)
      me.a[i]=t.a[i];
   }

   }














   void help_convert3d(infa_3d<T>& me,infinit_array<T> t)
   {
      if(t.act_nr<t.number_of_dem)
      {
       me.n=t.n;
           me.act_nr=t.act_nr;
            me.number_of_dem=t.number_of_dem;

      for(int i=1;i<=t.n;i++)
      {

          me.next[i]=t.next[i];
        help_convert3d(me.next[i],t.next[i]);
      }

      }

    }







 void operator=(infinit_array<T> t)
{

   //if(t.number_of_dem==3 && t.act_nr==1)
   {


help_convert3d(this[0],t);


   }


}













};








template<typename T>
struct infa_4d:infinit_array<T>
{

  void  create(int* values,int nv,int* shape,int ns)
   {
      if(ns>=4)
      infinit_array<T>::redifine(values,nv,shape,4);

   }


   void  create(int nv,int* shape,int ns)
   {

   if(ns>=3)
      infinit_array<T>::create(1,shape,4);

   }
 void screate(int nv,int* shape,int ns)
 {
    if(ns>4)
       infinit_array<T>::create(1,shape,4);
}

infinit_array<T> mult4d(infa_4d t)
{

    int a1[infinit_array<T>::number_of_dem];
      int a2[t.number_of_dem];




      int k=0,k2=0;
      infinit_array<T>::myshape(a1,k);
      t.myshape(a2,k2);





if(a1[3]==a2[4] && a1[2]==a2[1])
{

   infa_3d<T> u;
    infa_3d<T> u2;



 u2.infinit_array<T>::create(1,a2[1],a2[3],a2[4],3);

 infinit_array<T> fin;

 fin.create(1,this->n,t[1].n,a1[3],a2[4],4);

   for(int i=1;i<=min(infinit_array<T>::n,t[1].n);i++)
   {
      u=this->operator[](i);

      for(int j=1;j<=t.n;j++)
      u2[j]=t[j][i];

      fin[i]=u.mult3d(u2);

   }

  return fin;


}










}



};
template<typename T>

 struct layers_infinit:infinit_array<T>
 {

 int type;
 int nr_layer;


  struct dense
   {

    int units;
    int* shape;

    infinit_array<T> weight;

    int* imp_shape;

    int activ=0;

    double* bias;

    int use_Bias;




    template<typename T2>
   void denses(T2 s,int activs)
  {
     units=s.units;
     activ=s.activ;

  }

    template<typename T2>
  dense(T2 s)
  {
     units=s.units;

  }


  };

 struct compile
 {

struct optimizer
{
   int type;
   double* param;

}opt;

int loss;

 };

    infinit_array<T> sequential()
    {

    }


  infinit_array<T> sequential(int* outn,int noutn ,int* intn,int nintn,int* nhl,int nnhl)
    {
       infinit_array<T> input,output,hiden;

       input.create(1,intn,nintn);

    }








 };







































#endif // SPECIAL_ARRAYS_H
