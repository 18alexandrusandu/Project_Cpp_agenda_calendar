#ifndef COMPLEX_H
#define COMPLEX_H
#include"math_sandus.h"
math_Sandu sc;

struct imag
{
long double r,i;
long double Re()
{
return r;
}
long double Im()
{
return i;
}
imag conj()
{
imag b;
b.r=r;
b.i=-i;
return b;
}

float mag()
{
   return sqrm(r*r+i*i);
}


template<typename T,typename T2,typename...arg>
void add_all(Llist<imag>& A,T rl,T2 ig,arg... r)
{

imag res;
res(rl,ig);
A.add(res);
add_all(A,r...);
}

template<typename T,typename T2>
void add_all(Llist<imag>& A,T rl,T2 ig)
{
imag res;
res(rl,ig);
A.add(res);
}


void add_all(Llist<imag>& A)
{}







template<typename T>
int operator==(T a)
{

if(a==r && i==0)return 1;
return 0;
}


int operator==(imag a)
{

if(a.r==r && a.i==i)return 1;
return 0;
}


template<typename T>
int operator!=(T a)
{

if(a==r && i==0)return 0;
return 1;
}


int operator!=(imag a)
{

if(a.r==r && a.i==i)return 0;
return 1;
}


void operator()(double x,double y)
{
   r=x;
   i=y;

}


imag operator+(imag a)
   {
      imag b;
      b.r=r+a.r;
      b.i=i+a.i;
      return b;
   }

void operator+=(imag a)
   {

      r=r+a.r;
      i=i+a.i;
   }

   imag operator-(imag a)
   {
      imag b;
      b.r=r-a.r;
      b.i=i-a.i;
      return b;
   }




void operator=(double a)
{
r=a;
}




void operator-=(imag a)
   {
      r=r-a.r;
      i=i-a.i;
   }
imag operator*(imag a)
   {
      imag b;
      b.r=a.r*r-a.i*i;
      b.i=a.i*r+a.r*i;
      return b;

   }

void operator*=(imag a)
   {
      r=a.r*r-a.i*i;
      i=a.i*r+a.r*i;

   }

imag operator/(imag a)
{
   imag b;
   b.r=(float)(a.r*r + a.i*i)/(a.i*a.i+a.r*a.r);

   b.i=(long double)( i*a.r-r*a.i)/(a.i*a.i+a.r*a.r);
   return b;

}

void operator/=(imag a)
{

   r=(a.r*r + a.i*i)/(a.i*a.i+a.r*a.r);
   i=( a.r*i-a.i*r)/(a.i*a.i+a.r*a.r);

}

imag add(float re,float im=0)
   {
      imag b;
      b.r=r+re;
      b.i=i+im;
      return b;
   }

 void  give_me(double re,double im=0)
   {
      r=re;i=im;
   }



void add_me(float re,float im=0)
   {

      r=r+re;
      i=i+im;
   }

   imag subs(float re,float im=0)
   {
      imag b;
      b.r=r-re;
      b.i=i-im;
      return b;
   }

void subs_me(float re,float im=0)
   {

      r=r-re;
      i=i-im;
   }


template<typename T>
imag operator*(T re)
   {
      imag b;
      b.r=re*r;
      b.i=re*i;
      return b;

   }
template<typename T>
void operator*=(T re)
   {

      r=re*r;
      i=re*i;

   }

imag operator/(float re)
{
   imag b;
   b.r=r/re;
   b.i=i/re;
   return b;

}

void operator/=(float re)
{
 r=(double)r/re;
 i=(double)i/re;

}


imag operator^(int n)
{

imag b;

float r1=sqrm(i*i+r*r);

float arg=i/r;
float pluse=0;

if(r<0 && i>0)pluse=pi;

if(r<0 && i<0)pluse=-pi;

if(i<0 && r>0)pluse=2*pi;

arg=(sc.arctan(arg)+pluse)*n;
arg=deg_angle(arg);

r1=sc.powe(r1,n);

b.r=r1*sc.cosa(arg);
b.i=r1*sc.sina(arg);

return b;

}




double Arg(imag z,int deg=0)
{
  double arg=z.i/z.r;
float pluse=0;

if(z.r<0 && z.i>0)pluse=pi;

if(z.r<0 && z.i<0)pluse=-pi;

//if(z.i<0 && z.r>0)pluse=2*pi;

arg=(sc.arctan(arg)+pluse);


if(deg==1)arg=deg_angle(arg);

return arg;
}

double Argu(int deg=0)
{
  double arg=i/r;
float pluse=0;
cout<<arg<<endl;

if(r<0 && i>0)pluse=pi;

if(r<0 && i<0)pluse=-pi;

//if(z.i<0 && z.r>0)pluse=2*pi;

arg=(sc.arctan(arg)+pluse);


if(deg==1)arg=deg_angle(arg);

return arg;
}

imag operator^(imag z)
{

   imag fin;
   double r2=Argu();

   double m=mag();

   double R=pow(m,z.r)*exp(-z.i*r2);

   double x=Math.cosa( deg_angle(z.r*r2+z.i*Math.lon(m)));
   double y=Math.sina( deg_angle(z.r*r2+z.i*Math.lon(m)));


   fin.r=R*x;
   fin.i=R*y;
   return fin;
}







void operator^=(int n)
{
float r1=sqrm(i*i+r*r);

float arg=i/r;
float pluse=0;

if(r<0 && i>0)pluse=pi;

if(r<0 && i<0)pluse=-pi;

if(i<0 && r>0)pluse=2*pi;

arg=(sc.arctan(arg)+pluse)*n;

arg=deg_angle(arg);

r1=sc.powe(r1,n);


r=r1*sc.cosa(arg);
i=r1*sc.sina(arg);

}


imag* sqrc(int n)
{
imag* a=new imag[n+1];


float y=(float)1.0/(n);


float r1=sqrm(r*r+i*i);
cout<<y<<endl;
;r1=sqrm(r1,y);


float arg=i/r;
float pluse=0;

if(r<0 && i>0)pluse=pi;

if(r<0 && i<0)pluse=-pi;

if(i<0 && r>0)pluse=2*pi;


arg=(sc.arctan(arg)+pluse);
//

for(int i=0;i<=n-1;i++)
{
float g=deg_angle((arg+2*pi*i)/n);
//cout<<g<<endl;
//cout<<"r:"<<r1<<endl;
//;
//
//;

   a[i+1].r=r1*sc.cosa(g);
   a[i+1].i=r1*sc.sina(g);

}

return a;

}

imag epowi(imag a)
{
math_Sandu d;
   imag b;
   b.r=sqrm(e,a.r)*d.cosa(deg_angle(a.i));
   b.i=sqrm(e,a.r)*d.sina(deg_angle(a.i));

return b;
}

imag xpowi(double x,imag a)
{

math_Sandu d;
   imag b;
   b.r=sqrm(x,a.r)*d.cosa(deg_angle(d.lon(x)*a.i));
   b.i=sqrm(x,a.r)*d.sina(deg_angle(d.lon(x)*a.i));

return b;
}














imag sina(imag a,int deg=0)
{
      math_Sandu d;
   imag b;

   if(deg==0)
   {
   b.r=d.sina(deg_angle(a.r))*cosha(a.i);
   b.i=d.cosa(deg_angle(a.r))*sinha((a.i));
   }
  else
   {
   b.r=d.sina((a.r))*cosha(a.i);
   b.i=d.cosa(a.r)*sinha((a.i));

   }

return b;

}

imag sina2(imag a,int deg=0)
{
      math_Sandu d;
   imag b;

   float expoa=exp(a.i)-1.0/exp(a.i);
   float expob=exp(a.i)+1.0/exp(a.i);



   if(deg==0)
   {

   b.r=d.sina(deg_angle(a.r))*expob/2;
   b.i=d.cosa(deg_angle(a.r))*expoa/2;


   }
  else
   {
   b.r=d.sina((a.r))*expob/2;
   b.i=d.cosa(a.r)*expoa/2;

   }

return b;

}


















imag sinhz(imag a,int deg=0)
{
   math_Sandu d;
   imag b;

   if(deg==0)
   {
   b.r=sinha(a.r)*d.cosa(deg_angle(a.i));
   b.i=cosha(a.r)*d.sina(deg_angle(a.i));
   }
  else
   {

   b.r=sinha(a.r)*d.cosa(a.i);
   b.i=cosha(a.r)*d.sina(a.i);
   }

return b;

}

imag cosa(imag a,int deg=0)
{
   math_Sandu d;
   imag b;

  if(deg==0)
{
   b.r=d.cosa(deg_angle(a.r))*cosha(a.i);
   b.i=-d.sina(deg_angle(a.r))*sinha(a.i);

}
else
{
   b.r=d.cosa(a.r)*cosha(a.i);
   b.i=-d.sina(a.r)*sinha(a.i);
}

return b;

}
imag tana(imag a)
{
   sina(a)<<sina(a);
   sina(a)<<cosa(a);

   imag u=sina(a)/cosa(a);
return u;

}






imag coshz(imag a,int deg=0)
{
   math_Sandu d;
   imag b;

  if(deg==0)
{
   b.r=cosha(a.r)*d.cosa(deg_angle(a.i));
   b.i=sinha(a.r)*d.sina(deg_angle(a.i));

}
else
{
   b.r=cosha(a.r)*d.cosa(a.i);
   b.i=sinha(a.r)*d.sina(a.i);
}

return b;

}


imag tanhz(imag a,int deg=0)
{

imag b=sinhz(a,deg);
imag c=coshz(a,deg);
imag r=b/c;
return r;
}

imag lnz(imag z)
{
   math_Sandu d;
double rr=sqrm(z.r*z.r+z.i*z.i);

imag b;

b.r=d.lon(rr);
b.i=Arg(z);

return b;
}

imag asinhz(imag z)
{
   imag a=z^2;
   a=a.add(1);
   imag* t= a.sqrc(2);
   a=t[1];
   a=a+z;
   a=lnz(a);
   return a;

}
imag acoshz(imag z)
{
   imag a=z;
   a=a.add(1);
   imag* t= a.sqrc(2);
   a=t[1];

  imag b=z;
  b=b.add(-1);
  t=b.sqrc(2);
  b=t[1];
  a=a*b;
  a=a+z;
  a=lnz(a);
 return a;

}
imag atanhz(imag z)
{
   imag a=z;
   a=a.add(1);

   a=lnz(a);

   imag b=z;
  b=b*(-1);
  b=b.add(1);

 b=lnz(b);
   a=a-b;

   a/=2;


 return a;

}


void operator <<(imag a)
{

cout<<a.r<<" "<<a.i<<"i"<<endl;
}


};









imag arcsin_rc(float x)
{math_Sandu d;
  float delta;
   delta=-4*x*x+4;
   imag etox;
      etox.i=x;

   if(delta>=0)
   etox.r=sqrt(delta)/2;
    else
   etox.i+=sqrt(-delta)/2;


   if(delta<0)
   {
      imag z;
      z.r=pi/2;
      z.i=-d.lon(etox.i);
      return z;
   }
   else
   {

      float arg=etox.Arg(etox);
      imag z;

      z.r=arg;
      z.i=0;
      return z;
   }
}





imag* sqrc(imag x)
{
   int nr=0;

   imag* res=new imag[5];
   float b=-x.r,c=-x.i*x.i/4;

float ato21=-b/2+ sqrt(b*b-4*1*c)/2;
float ato22=-b/2- sqrt(b*b-4*1*c)/2;
  if(ato21>0)
  {
     nr++;
     res[nr].r=sqrt(ato21);

     res[nr].i=(x.i/2)/res[nr].r;

     nr++;
     res[nr].r=-sqrt(ato21);
     res[nr].i=(x.i/2)/res[nr].r;
     nr+=2;
  }

 if(ato22>0)
  {
     nr++;

     res[nr].r=sqrt(ato22);

     res[nr].i=(x.i/2)/res[nr].r;

     nr++;
     res[nr].r=-sqrt(ato22);
     res[nr].i=(x.i/2)/res[nr].r;
  }

  res[0].r=nr; res[0].i=nr;
return res;
}












imag* arcsin_cc(imag x)
{math_Sandu d;
  imag s;
  s.r=-2*x.i;
  s.i=2*x.r;

  imag delta;

  delta.r=4+s.r*s.r-s.i*s.i;
  delta.i=2*s.r*s.i;

  imag* z;
  z=new imag[5];

  int i=1;

  while(i<=4)
  {
   if((i<=sqrc(delta)[0].r))
   {
      z[0].r=sqrc(delta)[0].r;

  imag etox=sqrc(delta)[i];

  etox.r/=2;
  etox.i/=2;

  etox.r+=s.r/2;
  etox.i+=s.i/2;

 z[i].r=etox.Arg(etox);
 z[i].i=-d.lon(etox.mag());


   }
i++;}

  return z;

}


imag det(int n,imag** a)
{
   imag detr;
   detr.r=0;
   detr.i=0;

    if(n==2)
    detr=a[1][1]*a[2][2]-a[1][2]*a[2][1];

    if(n==3)
    {


        imag det1,det2,det3;

    det1=a[1][1]*(a[2][2]*a[3][3]-a[3][2]*a[2][3]);
    det2=a[1][2]*(a[2][1]*a[3][3]-a[3][1]*a[2][3]);
    det3=a[1][3]*(a[2][1]*a[3][2]-a[3][1]*a[2][2]);

    detr=det1-det2+det3;


}

return detr
;}

imag detm(imag** a,int n)
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
     imag dete;dete.r=0;dete.i=0;
     for(int i=1;i<=n;i++)
   {

      imag fi[50][50];
      imag** f;
         f=give_ref2d(f,fi,n);

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
 dete+=(a[1][i]*detm(f,n-1))*sd.powe(-1,i+1);



   }
return dete;

  }
  imag b;b.r=0;
  b.i=0;
return b;
}

ostream& operator<<(ostream& os, imag& dt)
{
   os<<dt.r<<" "<<dt.i<<" i"<<endl;

}

istream& operator>>(istream& is,imag& dr)
{
is>>dr.r;
is>>dr.i;

}

template<typename T>
ostream& operator<<(ostream& is,T** a)
{
   cout<<endl;
   for(int i=1;i<=a[1][0];i++)
   {
    for(int j=1;j<=a[2][0];j++)
     is<<a[i][j]<<" ";

     is<<endl;
}

}
imag f1part(double t,double f)
{
   imag use;
   use(0,-2*pi*t*f);
   return use.epowi(use);

}

template<typename T,typename R>
imag  Ffi(double t1,double t2,int f2=0.5,double f=0.2,T (*fu)(T,R)=Math.sina)
{
imag s(0,0);

for(int i=t1;i<=t2;i+=f2)
{
s+=fu(i)*s.epowi(f1part(i,f));

}
s/=(t2-t1)/f2;

return s;
}

void f(double x)
{

   cout<<x<<" ";
}


struct fourier_results
{
   imag four;
   double freq,amp,phase;

};













template<typename T>
Llist<fourier_results> dft(T x,int N)
{

   Llist<fourier_results> four;



   for(int k=0;k<N;k++)
   {

   four[k+1].four(0,0);


   double re=0;
   double img=0;

   for(int n=0;n<=N-1;n++)
   {

   double phi=(2*pi*k*n)/N;

   double dphi=deg_angle(phi);

   re=0;img=0;

    re=x[n+1]*Math.cosa(dphi);
    img=(-x[n+1]*Math.sina(dphi));



    four[k+1].four.add_me(re,img);


   }

   four[k+1].four/=N;



   re=four[k+1].four.Re();

   img=four[k+1].four.Im();

   four[k+1].freq=k;

   four[k+1].amp=sqrt(re*re+img*img);

   four[k+1].phase=arctan3(re,img);


   }
   return four;
}




template<typename T>
void dft(T x,T y,T ox,T oy,int N,int M)
{
   for(int k=0;k<N;k++)
   {

   double re=0;
   double img=0;


   for(int n=0;n<=N-1;n++)
   {


   double phi=(2*pi*k*n)/N;

   double dphi=deg_angle(phi);

    re+=x[n+1]*Math.cosa(dphi)+y[n+1]*Math.sina(dphi);;
    img+=(-x[n+1]*Math.sina(dphi))+y[n+1]*Math.cosa(dphi);

   }
  ox[k+1]=re;
  oy[k+1]=img;

   }

}















#endif // COMPLEX_H
