#ifndef ENCODING_H_H
#define ENCODING_H_H
#include<iostream>
#include<fstream>
#include"math-motions/math_sandus.h"
#include<string.h>
#include<time.h>

char* add_attop(char*& s,char c)
{
   char* s2=new char[strlen(s)+4];

   strcpy(s2,s);

   //cout<<s2<<endl;

   for(int i=strlen(s2);i>=0;i--)
   s2[i+1]=s2[i];
   s2[0]=c;

  // cout<<s2<<endl;

   return s2;

}



double f(double x,double y,double a=3,double b=2)
{

return x*y+ a*x-b*y;

}


int low_of_composition(char x,char y,double(*f)(double,double,double,double)=NULL,double a=3,double b=2)
{
double xi=x,yi=y,res;

xi=map15(xi,(double)'1',(double)'z',(double)'A',(double)'Z');
yi=map15(yi,(double)'1',(double)'z',(double)'A',(double)'Z');

if(f)
res=f(xi-'A',yi-'A',a,b);
else
res=xi+yi;

return (int) res;
}

int compose(char* s,int a=3,int b=2)
{
   int res=s[0];

for(int i=1;i<strlen(s);i++)
res=abs(low_of_composition(res,s[i],f,a,b));

return res;
}

char* in_base(int a,int b)
{

   char* s="";
   b=(b+1)%9;

   if(b==0)
      b=9;

   while(a!=0)
   {
      s=add_attop(s,a%b+'0');
   a=a/b;
   }
   return s;
}

char* last_coding(char*& s,int b)
{
   b=(b+1)%9;

      int n=strlen(s);
      cout<<"s: "<<s<<endl;


   for(int i=0;i<strlen(s);i++)
   {
      cout<<s[i]<<" "<<(char)('a'+(s[i]-'0'+n)%28)<<endl;

         s[i]=(char)('a'+(s[i]-'0'+n)%28);
   }

cout<<"pre n"<<n<<endl;
   char add=(char)(b+n%9+'a');

s=add_attop(s,add);

}


char* encode(char* s,int a=3,int b2=2)
{
int b=1+rand()%7;

int r=compose(s,a,b2);

cout<<"r:"<<r<<endl;

s=in_base(r,b);

last_coding(s,b);

   return s;
}


int nr_b10(char* s,int b)
{
   int n=0,p,k=strlen(s)-1;

   b=(b+1)%9;
   for(int i=0;i<strlen(s);i++)
   {
      p=pow(b,k-i);
      n=n+p*(s[i]-'0');
   }
   return n;

}

int decode(char* s)
{


  int n=strlen(s)-1;


  char* s2=new char[strlen(s)+1];
  strcpy(s2,s);

    char p1=s2[0]-'a';

  for(int i=0;i<=n;i++)
  s2[i]=s2[i]-'a'+'0'-n;
  int b=abs((char)(p1-n%9)-1);

n=nr_b10(s2+1,b);

return n;

}

int issame(char* cpass,char* rpass,int a=3,int b=2)
{

  int dc=compose(cpass,a,b);
  int d=decode(rpass);

  return (dc==d);

}






#endif // ENCODING_H_H
