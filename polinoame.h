#ifndef derivate_2_H
#define derivate_2_H
#include<iostream>
#include"math-motions/math_sandus.h"
#include"math-motions/vectorization.h"
using namespace std;

struct derivate_2
{

template<typename T>
T* sum(T a[],T b[],int& n,int m);

template<typename T>
T* dif(T[],T[],int&,int);

template<typename T>
T* prod(T[],T[],int,int&);


template<typename T>
T* div(T[],T[],int,int&);

template<typename T>
T* der(T[],int&);


template<typename T>
T* mults(T[],int ,T );


template<typename T>
T* power(T[],int&,int,int);

template<typename T>
T* comp(T[],T[],int& ,int);

template<typename T>
T* derCr(T[],T[],int& ,int );
template<typename T>
T* derPow(T[],T[],int& ,int );
template<typename T>
T* derQot(T[],T[],int& ,int );

;};


template<typename T>
T* derivate_2::sum(T a[],T b[],int& n,int m)
{

int ri;

ri=min(n,m);

int ru;

ru=max(n,m);

   T* ne=new T[ru*5];

sca(a,n);

sca(b,m);

cout<<n<<" "<<m<<ru<<" "<<ri<<endl;


 for(int i=1;i<=ru+5;i++)
   {
     ne[i]=0;

   }


   for(int i=1;i<=ri;i++)
   {
      ne[i]=a[i]+b[i];

   }


   for( int i=ri+1;i<=ru;i++)
   {

      if(n>=m)
      {

        ne[i]=a[i];

       // cout<<"naia "<<na[i]<<endl;

      }
        else
         {


            ne[i]=b[i];
           // cout<<"naib "<<na[i]<<endl;

         }



   }


   n=ru;

cout<<"pizza"<<endl;

cout<<ri<<" "<<ru<<endl;


return ne;

}


template<typename T>
T* derivate_2::dif(T a[],T b[],int& n,int m)
{

int ri;

ri=min(n,m);

int ru;

ru=max(n,m);

   T* ne=new T[ru*5];

sca(a,n);

sca(b,m);

cout<<n<<" "<<m<<ru<<" "<<ri<<endl;


 for(int i=1;i<=ru+5;i++)
   {
     ne[i]=0;

   }


   for(int i=1;i<=ri;i++)
   {
      ne[i]=a[i]-b[i];

   }


   for( int i=ri+1;i<=ru;i++)
   {

      if(n>=m)
      {

        ne[i]=a[i];

       // cout<<"naia "<<na[i]<<endl;

      }
        else
         {


            ne[i]=b[i];
           // cout<<"naib "<<na[i]<<endl;

         }



   }


   n=ru;

cout<<"pizza"<<endl;

cout<<ri<<" "<<ru<<endl;


return ne;

}









template<typename T>
T* derivate_2::prod(T a[],T b[],int n,int& m)
{


   T* na=0;


cout<<"nm"<<n<<" "<<m<<endl;


   na=new T[100];



cout<<"before"<<endl;

for(int i=1;i<=n+m+5;i++)

   na[i]=0;


int cp=0;

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
{


cout<<"ijab"<<i+j-1<<" "<<a[i]<<" "<<b[j]<<endl;


na[i+j-1]+=a[i]*b[j];

cp=i+j-1;

}


m=cp;

cout<<"array after prod:"<<endl;

cout<<m<<endl;

sca(na,m);

cout<<endl;

return na;



}


template<typename T>
T* derivate_2::div(T a[],T b[],int n,int& m)
{


   T* na=0;


cout<<"nm"<<n<<" "<<m<<endl;


   na=new T[100];


int hold[100];

cout<<"before"<<endl;


for(int i=1;i<=n+m+5;i++)

   na[i]=0;


int cp=0;
int nindex=0;

for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
{

cout<<"ijab"<<i-j+1<<" "<<a[i]<<" "<<b[j]<<endl;
nindex++;
hold[nindex]=i-j+1;


if(i-j+1>=1)
{

na[i-j+1]+=a[i]/b[j];
cp=i-j+1;

}


}


m=cp;

cout<<"array after prod:"<<endl;

cout<<m<<endl;

sca(na,m);

cout<<endl;

return na;



}










template<typename T>
T* derivate_2::power(T a[],int& n,int m,int k)
{
   cout<<"k:"<<k<<endl;

   T* na;

   if(k==1)
{

    na=a;

cout<<"array1 after power:"<<endl;

sca(na,m);

       return na;

   }

  else
  {


  return prod(a,power(a,n,m,k-1),m,n);

 }


}










template<typename T>
T* derivate_2::mults(T a[],int n,T k)
{

cout<<"mults"<<k<<endl;

   T* na;

size_t pu=n+10;
na=new T[100];

for(int i=1;i<=n+8;i++)
   na[i]=0;

   for(int i=1;i<=n;i++)
   na[i]=a[i]*k;
   cout<<"m-read"<<endl;

return na;

}



template<typename T>
T* derivate_2::comp( T f [],T g[],int& n,int m)
{


int n2=sum_gauss(n);


cout<<"sum gauss"<<n2<<endl;

cout<<n2*m<<endl;


T* suma=new T[n2*m+5];


for(int i=1;i<=n2*m;i++)
  suma[i]=0;


sca(suma,n2*m);

   int t=n-1;int p=m;

int nr_suma=0;


   for(int i=1;i<=t;i++)
   {

p=m;

T piu;

piu=f[i+1];

cout<<"piu"<<piu<<endl;


T* sub1=power(g,p,m,i);

cout<<"power";


sca(sub1,p);

T* sub=mults(sub1,p,piu);


suma=sum(suma,sub,nr_suma,p);


cout<<"suma"<<endl;

sca(suma,nr_suma);

   }



   suma[1]+=f[1];


   sca(suma,nr_suma);
n=nr_suma;
   return suma;


}

template<typename T>
T* derivate_2::der(T a[],int& n)
{

int py=n+5;


T* as=new T[100];

int t=n+4;
for(int i=1;i<=t;i++)

{

as[i]=0;

}




for(int i=1;i<=n;i++)
{
if(i!=1)
as[i-1]=(i-1)*a[i];


}


   n-=1;

return as;

}


template<typename T>
T* derivate_2::derCr(T a[],T b[],int& n,int m)
{

T* as=new T[100];
as=prod(comp(a,b,n,m),b,n,m);
return as;


}



template<typename T>
T* d2er(T* a,int& n)
{

int i;
int py=n+5;


T* as=new T[100];

int t=n+4;
for(i=1;i<=t;i++)

{

as[i]=0;

}


for(i=1;i<=n;i++)
{
if(i!=1)
as[i-1]=(i-1)*a[i];

}


   n--;


return as;

}





template<typename T>
T* derivate_2::derPow(T a[],T b [],int& n,int m)
{
int n1=n;
int m1=m;


T* der1=d2er(a,n1);

T* der2=d2er(b,m1);

n=m1;

return sum(prod(a,der1,n,n1),prod(b,der2,m,n),n1,n);

}



template<typename T>
T* derivate_2::derQot(T a[],T b [],int& n,int m)
{
int n1=n;
int m1=m;


T* der1=der(a,n1);

T* der2=der(b,m1);

n=m1;


}

struct Basic_derivate_2
{
    double dpow(double x,int n)
    {
      return n*sqrm(x,n-1);
    }

    double dexp(double x)
    {

      return Math.expo(x);

    }

    double datox(double a,double x)
    {
      return sqrm(a,x)*Math.lon(a);
    }

    double dconst(double x)
    {
        return 0;
    }

   double dln(double x)
   {
      return 1.0/x;
   }

 double  dsina(double x)
   {
      return Math.cosa(x);
   }

    double  dcosa(double x)
   {
      return -Math.sina(x);
   }

    double  dtana(double x)
   {
      return 1.0/(Math.cosa(x)*Math.cosa(x));
   }

     double  dctg(double x)
   {
      return 1.0/(Math.sina(x)*Math.sina(x));
   }

  double darcsin(double x)
  {

     return 1.0/(sqrm(1.0-x*x,0.5));

  }

    double darccos(double x)
  {
     return -1.0/(sqrm(1.0-x*x,0.5));

  }
  double darctan(double x)
  {
     return 1.0/(1+x*x);

  }

   double darcctg(double x)
  {
     return -1.0/(1+x*x);

  }
double dabs(double x)
{
if(x>0)return  x;
else
return -x;
}
double dcx(double x,double y)
{
return y;
}



double func(int n,int x,int p=1)
{

if(n==0)return x*p;
if(n==1)return sqrm(x,p);
if(n==2)return Math.expo(x);
if(n==3) return sqrm(p,x);
if(n==4) return Math.lon(x);
if(n==5) return Math.sina(x);
if(n==6) return Math.cosa(x);
if(n==7) return Math.tana(x);
if(n==8) return ctg(x);

if(n==9) return arcsina(x);
if(n==10) return arccosa(x);
if(n==11) return Math.arctan(x);
if(n==12) return arcctg(x);
if(n==13) return Math.abso(x);

}






double  panal(int n,double x,double p=1)
{

if(n==0)return dcx(x,p);
if(n==1)return dpow(x,p);
if(n==2)return dexp(x);
if(n==3) return datox(p,x);
if(n==4) return dln(x);
if(n==5) return dsina(x);
if(n==6) return dcosa(x);
if(n==7) return dtana(x);
if(n==8) return dctg(x);
if(n==9) return darcsin(x);
if(n==10) return darccos(x);
if(n==11) return darctan(x);
if(n==12) return darcctg(x);
if(n==13) return dabs(x);

}






double solve1(double** fe,int n,int x)
{

   double sol=0;
   for(int i=1;i<=n;i++)
   sol+=fe[2][i]*panal(fe[1][i],x,fe[3][i]);

return sol;

}

double solvef(double** fe,int n,int x)
{

    double sol=0;
   for(int i=1;i<=n;i++)
   sol+=fe[2][i]*func(fe[1][i],x,fe[3][i]);


return sol;
}







double produs(double** f,double** g,int n,int m,int x)
{

   return solve1(f,n,x)*solvef(g,m,x)+solve1(g,m,x)*solvef(f,n,x);

}
double ratiod(double** f,double** g,int n,int m,int x)
{

   return (solve1(f,n,x)*solvef(g,m,x)-solve1(g,m,x)*solvef(f,n,x))/(solvef(g,m,x)*solvef(g,m,x));

}


};







struct resturi
{

int x;
int n=1;
  void repair()
   {

      if(x<0)
       x=n+x;

      if(x>=n)
       x=x%n;

   }






       int repair(int i)
   {
      if(i<0)
       i=n+i;
      if(i>=n)
       i=i%n;
       return i;
   }



   int inversul()
   {
      repair();
      for(int i=0;i<n;i++)
      if(repair(x*i)==1)
      return i;

      return 0;
   }

      int inversul(int k)
   {
      repair();
      for(int i=0;i<n;i++)
      if(repair(k*i)==1)
      return i;

      return 0;
   }


   int opusul()
   {
         repair(x);
          for(int i=1;i<n;i++)
      if(repair(x+i)==0)

      return 0;
   }

   int opusul(int k)
   {
         repair(x);
          for(int i=1;i<n;i++)
      if(repair(k+i)==0)

      return 0;
   }

template<typename T>
int operator !=(T a)
   {
      return (x!=a%n);

   }

template<typename T>
int operator ==(T a)
   {

      return (x==a);
   }


 resturi operator /(resturi xi)
{
   xi.repair();
   repair();
   int r=repair(x*xi.inversul());


   resturi res;
   res.x=r;
   res.n=n;
       return res;

}

void operator /=(resturi xi)
{
   xi.repair();
   repair();
   int r=repair(x*xi.inversul());
    x=r;

}

resturi operator *(resturi xi)
{

   n=xi.n;
   xi.repair();

   repair();

   int r=repair(x*xi.x);
   resturi res;

   res.x=r;
   res.n=n;

     return res;

}

void operator *=(resturi xi)
{

   xi.repair();
   repair();
   int r=repair(x*xi.x);
    x=r;
}

resturi operator +(resturi xi)
{

   n=xi.n;

   xi.repair();
   repair();
   int r=repair(x+xi.x);
   resturi res;


   res.x=r;




   res.n=n;
   res.repair();
   return res;


}
void operator +=(resturi xi)
{
   n=xi.n;
     xi.repair();
   xi.repair(x);

   int r=xi.repair(x+xi.x);
      x=r;

}

resturi operator -(resturi xi)
{
    xi.repair();
   repair();
   int r=repair(x-xi.x);
  resturi res;
   res.x=r;
   res.n=n;
   return res;
}

void operator -=(resturi xi)
{
    xi.repair();
   repair();
   int r=repair(x-xi.x);
    x=r;

}
int operator /(int xi)
{

 repair(xi);
   int r=repair(x*inversul(xi));
       return r;



}
void operator /=(int xi)
{
   repair(xi);
   repair();
   int r=repair(x*inversul(xi));
   x=r;
}
int operator *(int xi)
{
   repair(xi);
   repair();
   int r=repair(x*xi);
       return r;

}
void operator *=(int xi)
{
   repair(xi);
   repair();
   int r=repair(xi*x);
   x=r;
}

int operator +(int xi)
{

   repair(xi);

   repair();

   int r=repair(x+xi);
       return r;

}
void operator +=(int xi)
{
   repair(xi);
   repair();

   int r=repair(x+xi);
   x=r;
}

int operator -(int xi)
{
   repair(xi);
   repair();

   int r=repair(x-xi);
  return r;

}

void operator -=(int xi)
{
   repair(xi);
   repair();

   int r=repair(x-xi);
   x=r;
}


void operator =(double i)
{
   x=i;
   if(n!=0)
   x=x%n;



}

void operator =(int i)
{
   x=i;
   if(n!=0)
   x=x%n;

}



};























void afis(double x)
{

   cout<<x<<' ';

}


template<typename T>
  struct Pol_res
  {
     Llist<T> r,q;

  };





template<typename T>
struct Polinoame
{

  Llist<T> pol;
   int grad;

   operator =(double a)
   {
      pol[1]=a;
      grad=0;

   }

void operator*(double a)
   {
      for(int i=1;i<=pol.nr;i++)
       pol[i]=pol[i]*a;

   }

 void  make(int n)
   {
      pol[abs(n)];
      grad=abs(n);
   }


   int iszero()
{
   int c=1;
   for(int i=1;i<=grad;i++)
   if(pol[i]!=0)
      c=0;
return c;
}

   int iszero(Polinoame p)
{
   int c=1;
   for(int i=1;i<=p.pol.nr;i++)
   if(p.pol[i]!=0)
      c=0;

return c;
}


  template<typename T2>
  Pol_res<T2> divide(Llist<T2>& dividend ,Llist<T2>& divizor,void (*afise)(T2)=NULL)
   {

      // preparation of the data
      Pol_res<T2> res;

      move_dr(res.r,dividend,dividend.nr);


          if(afise!=NULL)
          {

         divizor.afisare(afise);
         cout<<endl;

          }



      while(res.r.nr>=divizor.nr)
      {
         T2 coef;

         //cout<<"div:"<<res.r[res.r.nr]<<" "<<divizor[divizor.nr]<<endl;

         coef=res.r[res.r.nr]/divizor[divizor.nr];

         int poo=res.r.nr-divizor.nr+1;


         res.q[poo]=coef;

         int n=divizor.nr;

         for(int i=n;i>=1;i--)
         {
            res.r[i+poo-1]-=coef*divizor[i];
         }
         res.r.nr--;
      }


   return res;

      }




template<typename  T2>
Llist<T2> product(Llist<T2> a,Llist<T2> b)
      {
         Llist<T2> res;

         for(int i=1;i<=a.nr+b.nr+1;i++)
         res[i]=0;

         for(int i=a.nr;i>=1;i--)
         {
            for(int j=b.nr;j>=1;j--)
            {

               T2 aux1=a[i]*b[j];

               T2 aux2=res[i+j-1]+aux1;

               res[i+j-1]=aux2;
            }
            }

            res.nr=a.nr+b.nr-1;
 //cout<<"res:"<<res.nr<<endl;


          if(res.nr>2)
         while(res[res.nr]==0 && res.nr>1)
         res.nr--;

      return res;
      }



    Polinoame<T>  operator *(Polinoame<T> b)
      {

      Polinoame<T> R;

       R.pol=product(pol,b.pol);

       R.grad=R.pol.nr-1;


       return R;
      }


        Polinoame<T>  operator /(Polinoame<T> b)
      {

      Polinoame<T> R;



       Pol_res<T> rs=divide(pol,b.pol);

         R.pol=rs.q;

       R.grad=R.pol.nr-1;

       return R;
      }






template<typename  T2>
Llist<T2> add(Llist<T2> a,Llist<T2> b)
{
         Llist<T2> res;


    if(a.nr>=b.nr)
{
   move_dr(res,a,a.nr);


   for(int i=1;i<=b.nr;i++)
   res[i]+=b[i];

}
   else
   {


   move_dr(res,b,b.nr);

   for(int i=1;i<=a.nr;i++)
   res[i]+=a[i];

   }

return res;
}

template<typename  T2>
Llist<T2> subtract(Llist<T2> a,Llist<T2> b)
{
   Llist<T2> res;


   move_dr(res,a,a.nr);

   for(int i=1;i<=b.nr;i++)
   res[i]=res[i]-b[i];


return res;

}
Polinoame<T>  operator-(Polinoame<T> r)
   {
      Polinoame<T> ret;

      ret.pol=subtract(pol,r.pol);

      ret.grad=pol.nr-1;

    return ret;
   }



 Polinoame<T>  operator+(Polinoame<T> r)
   {
        Polinoame<T> ret;

      ret.pol=add(pol,r.pol);
      ret.grad=pol.nr-1;

    return ret;

   }

void  operator+=(Polinoame<T> r)
   {
      pol=add(pol,r.pol);
      grad=pol.nr-1;

   }









template<typename  T2>
Llist<T2> operator %(Llist< T2> a)
{
   Pol_res<T2> res;
   res=divide(pol,a);
return res.r;
}

template<typename  T2>
Llist<T2> operator /(Llist< T2> a)
{
   Pol_res<T2> res;
   res=divide(pol,a);

return res.q;

}
















void Copy(Polinoame& t)
{
   t.grad=grad;
   for(int i=1;i<=grad;i++)
   t.pol[i]=pol[i];

}
void repair()
{

   while(pol[grad+1]==0)

      {
         grad--;
         pol.nr--;

      ;}
}





Polinoame cmmdc(Polinoame p1,Polinoame p2)
{
   Polinoame cat,rest;
   if(p1.grad>=p2.grad)
   {
      rest.pol=p1%p2.pol;

      rest.grad=rest.pol.size()-1;
   }
   else
   {

      rest.pol=p2%p1.pol;
      rest.grad=rest.pol.size()-1;
   }



 cout<<"f=";
for(int i=0;i<=p1.grad;i++)
  cout<<p1.pol[i+1]<<" ";
   cout<<endl;

cout<<"g=";
   for(int i=0;i<=p2.grad;i++)
   cout<<p2.pol[i+1]<<" ";
   cout<<endl;


   while(!rest.iszero())
   {
      p1=p2;
      p2=rest;

      p1.repair();

      p2.repair();

      rest.pol=p1%p2.pol;

      rest.grad=rest.pol.size()-1;

   }


return p2;

}


Polinoame cmmmc(Polinoame p1,Polinoame p2)
{


Polinoame k=cmmdc(p1,p2);



for(int i=1;i<=k.pol.nr;i++)
cout<<k.pol[i]<<" ";
cout<<endl;


Polinoame p3=p1*p2;



Polinoame res;




res.pol=p3/k.pol;





res.grad=res.pol.nr-1;

return res
;}



void setGrad()
{
      grad=pol.nr-1;

      cout<<"nu asta"<<grad<<endl;

   while(pol[grad+1]==0 && grad>0)
         grad--;
}


   };

   template<typename T,typename D>
   T F_polynom1(Polinoame<T> P, D a)
   {
      T res;
      res=0;
      for(int i=1;i<=P.grad+1;i++)
        res+=P.pol[i]*pow(a,i-1);

      return res;

   }


   template<typename T,typename D>
   T F_polynom2(Polinoame<T> P, D a)
   {
      T res;
      res=0;
      for(int i=1;i<=P.grad+1;i++)
        res+=P.pol[i]*pow(a,P.grad-i+1);

      return res;

   }











   template<typename T,typename...arg>
void make_rest_el(int i,int j,int n,int m,int grd,resturi** mat,T a,arg...r)
{
      if(i<n && j<=m)
      {
          mat[i][j].x=a;
          mat[i][j].n=grd;
      }

      if(i==n && j<m)
      {
          mat[i][j].x=a;
          mat[i][j].n=grd;
      }

     if(i<n)
     {
        if(j<m)
        make_rest_el(i,j+1,n,m,grd,mat,r...);

         if(j==m)
        make_rest_el(i+1,1,n,m,grd,mat,r...);
     }

       if(i==n)
     {
        if(j<m)
        make_rest_el(i,j+1,n,m,grd,mat,r...);
     }


}

template<typename T>
void make_rest_el(int i,int j,int n,int m,int grd,resturi** mat,T a)
{
   mat[i][j]=a;

}






ostream& operator <<(ostream& o, resturi& x)
{

    //x.repair();
   o<<x.x<<" ";

   return o;
}




template<typename T,typename...arg>
resturi** make_rest_matrix(int n,int m,int grad,T a,arg...r)
{
   resturi** res;
   res=new resturi*[n+5];

   for(int i=0;i<=n;i++)
   res[i]=new resturi[m+5];
   make_rest_el(1,1,n,m,grad,res,a,r...);

   return res;

}



void afisare_matrix(resturi**d,int n,int m)
{
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      cout<<d[i][j];

      cout<<endl;
   }
}


int is_det_zero(resturi r)
{
   if(r.x==0 ||  primie(r.x,r.n)==0)
     return 1;

   return 0;
}














void rrm(resturi** a,int n,int m)
{
   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
   {
       a[i][j].x=a[i][j].x%a[i][j].n;
   }


}



void gauss_jordan(resturi** a,int n,int m)
{


int im[10]={1};

resturi mina;

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

mina.n=a[1][1].n;

if(a[t][k].x!=0 && con && (a[t][k].x<mina.x|| mina.x==0))
{
mina=a[t][k];
im[k]=t
;}



}
if(mina.x==0)
   mina=1;

for(int i=1;i<=m;i++)
a[im[k]][i]=a[im[k]][i]/mina;


for(int i=1;i<=n;i++)
{
if(i!=im[k])
{
resturi f;
f.n=a[1][1].n;
f=0;

if(a[im[k]][k].x!=0 && a[i][k].x!=0)
   f=f-a[i][k]/a[im[k]][k];

for(int j=1;j<=m;j++)
{
a[i][j]+=a[im[k]][j]*f;
if(Math.ap(a[i][j].x)==-0)
   a[i][j].x=0;
}
}
}

;
}

int con=0;

for(int u=1;u<=n;u++)
{
   int con2=0;
for(int p=1;p<=m-1;p++)
if(a[u][p].x!=0)con2++;

if(con2==0 && a[u][m].x!=0)con=1;


}
if(con)
{cout<<"sistem incompatibil"<<endl;
sca2d(a,n,m);
}
rrm(a, n, m);


}
void afisare(double a)
{
   cout<<a<<" ";
}

struct Super_imag
{
   roots r,i;


};


ostream& operator<<(ostream& o,Super_imag a)
{

   cout<<a.r.n;

   if(a.r.b!=0)
   {
      if(a.r.a>0 && a.r.n!=0)
       cout<<"+";

       if(a.r.a!=1 && a.r.a!=-1)
      cout<<a.r.a;
       else
       {
          if(a.r.a<0)
            cout<<"-";
       }

      cout<<"root2("<<a.r.b<<")";
   }

  if(a.i.n!=0 || a.i.b!=0)
  {

     cout<<"+(";

    if(a.i.n!=0)
     cout<<a.i.n;

  if(a.i.b!=0)
   {
      if(a.i.a>0 && a.i.n!=0)
       cout<<"+";

       if(a.i.a!=1 && a.i.a!=-1)
      cout<<a.i.a;
       else
       {
          if(a.r.a<0)
            cout<<"-";
       }
      cout<<"root2("<<a.i.b<<")";
   }
  cout<<")i";
  }

}







///x si y reprezinta numarul x+sign(y)*sqrt(abs(y)) o radacina a lui 'a'
template<typename T>
Super_imag* rorrc(T* a,int n,int& nr,double x,double  y)
{
   Super_imag* d4;

   d4=new Super_imag[n+2];
   nr=2;

   d4[1].r.n=x;
   d4[1].r.b=abs(y);
   if(y<0)
   d4[1].r.a=-1;
   else
   d4[1].r.a=1;


   d4[2].r.n=x;
   d4[2].r.b=abs(y);
   if(y>0)
   d4[2].r.a=-1;
   else
   d4[2].r.a=1;


   double x2=x;
   double y2=-y;

   double s=x2+x;
   double p=x*x2-abs(y);
   T* b=new T[5];


   b[1]=p;
   b[2]=-s;
   b[3]=1;


Llist<T> d2;
d2.add_array(a,n);



   Polinoame<T> d;
   d.pol.add_array(b,3);
   d.grad=2;

   Pol_res<T> rs=d.divide(d2,d.pol,afisare);

  if(rs.q.nr==3)
  {
     imag* tem;

     tem=equa2(rs.q[3],rs.q[2],rs.q[1]);

     nr++;
     d4[nr].r.n=tem[1].r;
     d4[nr].i.n=tem[1].i;

     nr++;
     d4[nr].r.n=tem[2].r;
     d4[nr].i.n=tem[2].i;


  }
 else
   if(rs.q.nr==2)
 {
      nr++;
      d4[nr].r.n=-rs.q[1]/rs.q[2];
 }
 else
 {
    T* roo;
    T* aux=rs.q.arrayfy();
    T* comm;

    int k=0;

   roo=horner3(aux,rs.q.nr,k);






   int k2=rs.q.nr;
   for(int i=1;i<=k;i++)
   {
        int inv=0;

      do{
        comm=horner2(aux,k2,roo[i]);
       inv=0;
         if( (comm[1]>=0 && comm[1]<0.001) ||(comm[1]<=0 && comm[1]>-0.001))
      {
         inv=1;
       comm[1]=0;

        delete aux;
        aux=comm;

         for(int j=1;j<k2;j++)
          aux[j]=aux[j+1];

         k2--;

         nr++;
         d4[nr].r.n=roo[i];

      }
      }while(inv);

}

 if(k2==3)
  {
     imag* tem;

     tem=equa2(aux[3],aux[2],aux[1]);

     nr++;
     d4[nr].r.n=tem[1].r;
     d4[nr].i.n=tem[1].i;

     nr++;
     d4[nr].r.n=tem[2].r;
     d4[nr].i.n=tem[2].i;


  }
  else
      if(k2==2)
  {
     nr++;

      d4[nr].r.n=-aux[1]/aux[2];

  }

 }
return d4;



}

template<typename T>
Super_imag* rorcc(T* a,int n,int& nr,double x,double  y)
{
   Super_imag* d4;

   d4=new Super_imag[n+2];
   nr=2;

   d4[1].r.n=x;

   d4[1].i.b=abs(y);
   if(y<0)
   d4[1].i.a=-1;
   else
   d4[1].i.a=1;


   d4[2].r.n=x;

   d4[2].i.b=abs(y);
   if(y>0)
   d4[2].i.a=-1;
   else
   d4[2].i.a=1;


   double x2=x;
   double y2=-y;

   double s=x2+x;
   double p=x*x2+y*y;
   T* comm;
   T* b=new T[5];

   b[1]=p;
   b[2]=-s;
   b[3]=1;

Llist<T> d2;
d2.add_array(a,n);



   Polinoame<T> d;
   d.pol.add_array(b,3);
   d.grad=2;


   Pol_res<T> rs=d.divide(d2,d.pol,afisare);

  if(rs.q.nr==3)
  {
     imag* tem;

     tem=equa2(rs.q[3],rs.q[2],rs.q[1]);

          nr++;
     d4[nr].r.n=tem[1].r;
     d4[nr].i.n=tem[1].i;

     nr++;
     d4[nr].r.n=tem[2].r;
     d4[nr].i.n=tem[2].i;

  }
  else
    if(rs.q.nr==2)
  {
        nr++;
      d4[nr].r.n=-rs.q[1]/rs.q[2];

  }
 else
 {
    T* roo;
    T* aux=rs.q.arrayfy();

    int k=0;
   int k2=rs.q.nr;


   roo=horner3(aux,rs.q.nr,k);


   for(int i=1;i<=k;i++)
   {
      int inv=0;

      do{
        comm=horner2(aux,k2,roo[i]);
       inv=0;


          if( (comm[1]>=0 && comm[1]<0.001) ||(comm[1]<=0 && comm[1]>-0.001))
      { inv=1;

        delete aux;

         aux=comm;

         for(int j=1;j<k2;j++)
          aux[j]=aux[j+1];

         k2--;
         nr++;
         d4[nr].r.n=roo[i];

      }

      }while(inv);
   }

 if(k2==3)
  {
     imag* tem;
     tem=equa2(aux[3],aux[2],aux[1]);

     nr++;
     d4[nr].r.n=tem[1].r;
     d4[nr].i.n=tem[1].i;

     nr++;
     d4[nr].r.n=tem[2].r;
     d4[nr].i.n=tem[2].i;


  }
  else
   if(k2==2)
  {
     nr++;

      d4[nr].r.n=-aux[1]/aux[2];

  }

 }



return d4;

}
template<typename T>
T Viete(T* a,int n,int k,int s=0)
{
   if(s==0)
   return pow(-1,k)*a[n-k]/a[n];
  else
   if(s==2)
    return Viete(a,n,2)*Viete(a,n,2)-Viete(a,n,1);
}
template<typename T>
void Special_sort(T& a,int& nr)
{

   int inv=0;
   do{

      inv=0;
      for(int i=1;i<nr;i++)
      {

          if(is_essential_zero(abs(a[i+1]-a[i])))
         {

            if(a[i+1]<a[i])
            for(int j=i;j<nr;j++)
            a[j]=a[j+1];

            else

            for(int j=i+1;j<nr;j++)
            a[j]=a[j+1];

            nr--;
            inv=1;
         }
         else
            if(a[i+1]>a[i])
          {
             double aux;
             aux=a[i];
             a[i]=a[i+1];
             a[i+1]=aux;
             inv=1;

          }
      }

   }while(inv==1);
}









void Send_to_fxp_pol(Polinoame<double> a)
{
   fxp=new double[a.pol.nr+2];
    fxp[0]=a.pol.nr;
    for(int i=1;i<=a.pol.nr;i++)
    fxp[i]=a.pol[i];


}


void Send_to_fxp_Llist(Llist<double> a)
{
   fxp=new double[a.nr+2];
    fxp[0]=a.nr;
    for(int i=1;i<=a.nr;i++)
    fxp[i]=a[i];
}


Llist<double> Newtonize(Llist<double> r)
{

Send_to_fxp_Llist(r);
int u;
Llist<double> res;


//cout<<"Newtonize"<<endl;

do{
//cout<<"N:"<<endl;

//for(int i=1;i<=fxp[0];i++)
//cout<<fxp[i]<<" ";
//cout<<endl;

int gasit=0;
double p=Newton_Raphson(function_poli,gasit,0);

if(gasit)
{

//cout<<p<<endl;
res.add(p);

double* o=r.arrayfy();

o=horner2(o,r.nr,p);

essentialize(o,r.nr);


for(int i=1;i<r.nr;i++)
o[i]=o[i+1];

u=r.nr-1;

r.nr=0;

r.add_array(o,u);
Send_to_fxp_Llist(r);
}
else
u=0;

}while(u>1);






return res;

}


Llist<double> find_real_solutions(Llist<double> a)
{

   Llist<double> b;
   Llist<double> b2;

   b.add_Llist(a);
   b2.add_Llist(a);

    int k=0;


   double* p=horner3(b.arrayfy(),b.nr,k);
    // cout<<"dupa horner"<<endl;



b.nr=0;


   b.add_array(p,k);


   b2=Newtonize(b2);


 for(int i=1;i<=b2.nr;i++)
   b.add(b2[i]);


   Special_sort(b,b.nr);
return b;

}








template<typename T>
struct Eigen
{

Llist<T>* man;

int nr_nec()
{
   return man[1].nr-1;

}


int max_ln(T** a,int n,int m,int& ln,int& n_e)
{
   ln=1;
   n_e=-1;
   for(int i=1;i<=n;i++)
   {
      int j=1;
      int gasit=0;

      while(gasit==0 && j<=m)
      {
         if(is_essential_zero(a[i][j]))
            j++;
            else
            gasit=1;
      }


      if(j>n_e && j<=m)
      {ln=i;
        n_e=j;
      }

   }
   if(n_e==-1)
    return 0;

    return 1;
}

template<typename T2>
void add_Llist(Llist<T> a,Llist<T> b,T2 k)
{
   for(int i=1;i<=min(a.nr,b.nr);i++)
         a[i]=a[i]+k*b[i];
}

template<typename T2>
void devide_Llist(Llist<T> a,T2 k)
{
   for(int i=1;i<=a.nr;i++)
         a[i]=a[i]/k;
}

template<typename T2>
void add_lines(T* a,T* b,int n,int m,T2 k)
{
   for(int i=1;i<=min(n,m);i++)
         a[i]=a[i]+k*b[i];
}


void move_to_sol(Llist<T>& a,T* b, int n,int n_e)
{
   a.nr=0;
   a.add(b[n]);
   for(int i=n_e+1;i<n;i++)
   {
        a.add(b[i]);
         b[i]=0;
   }
}

void move_to_sol2(Llist<T>& a,T* b, int n,int n_e)
{
   a.nr=0;
   a.add(0);

   for(int i=n_e+1;i<=n;i++)
   {
        a.add(-b[i]);
         b[i]=0;
   }
}





Llist<T>* solve_gauss_jodan(T** A,int n,int m2)
{
   cout<<"intrat"<<endl;
   Llist<T>* m;
   m=new Llist<T>[n+2];

   int l1,np;
   //this part deals with the indeterminate elements
   if(max_ln(A,n,m2-1,l1,np))
   {

     for(int i=1;i<n;i++)
        move_to_sol(m[i],A[i],m2,np);
   }
//now we have to do reduction: inverse gauss

 while(max_ln(A,n-1,m2-1,l1,np))
{

   for(int i=1;i<n;i++)
   if(i!=l1)
   {
      if(A[i][np]!=0)
       {
          T r=-A[i][np]/A[l1][np];

          add_lines(A[i],A[l1],m2,m2,r);
          add_Llist(m[i],m[l1],r);
       }
   }
devide_Llist(m[l1],A[l1][np]);
A[l1][np]=0;
}

   return m;

}

Llist<T>* solve_gauss_jodan2(T** A,int n,int m2)
{
   cout<<"intrat"<<endl;
   Llist<T>* m;
   m=new Llist<T>[n+2];

   int l1,np;
   //this part deals with the indeterminate elements
   if(max_ln(A,n,m2,l1,np))
   {

     for(int i=1;i<=n;i++)
        move_to_sol2(m[i],A[i],m2,np);
   }
//now we have to do reduction: inverse gauss
// find the maxim line
 while(max_ln(A,n,m2,l1,np))
{

   for(int i=1;i<=n;i++)
   if(i!=l1)
   {
      if(A[i][np]!=0)
       {
          T r=-A[i][np]/A[l1][np];

          add_lines(A[i],A[l1],m2,m2,r);
          add_Llist(m[i],m[l1],r);
       }
   }
devide_Llist(m[l1],A[l1][np]);
A[l1][np]=0;
}

   return m;

}








T* eigen_values(Polinoame<T>** A,int n,int om=0)
{
   if(om==0)
   for(int i=1;i<=n;i++)
   {
   A[i][i].pol.add(-1);
   A[i][i].grad++;
   }

  Polinoame<T> A2=detm(A,n);

   int p=0;
   T* r=horner3(A2.pol.arrayfy(),A2.pol.nr,p);





   return r;
}


T* eigen_values2(T** A,int n,int& p,int om=0)
{
   Polinoame<T>** A1;
   A1=new Polinoame<T>*[n+2];

   for(int i=0;i<=n;i++)
    A1[i]=new Polinoame<T>[n+2];



   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        A1[i][j].pol.add(A[i][j]);
       A1[i][j].grad=0;
    }



   for(int i=1;i<=n;i++)
   {
   A1[i][i].pol.add(-1);
   A1[i][i].grad++;
   }


  Polinoame<T> A2=detm(A1,n-1);


     T* r;
     p=0;

    if(A2.pol.nr>3)
    r=horner3(A2.pol.arrayfy(),A2.pol.nr,p);
   else
      if(A2.pol.nr==3)
   {
      imag* rt=equa2(A2.pol[3],A2.pol[2],A2.pol[1]);
   r=new T[4];
   r[1]=rt[1].r;
   r[2]=rt[2].r;
      p=2;

   }
   else
      if(A2.pol.nr==2)
   {
      r=new T[2];
      r[1]=-A2.pol[1]/A2.pol[2];
   }

   return r;

}
double* eigen_values3(double** A,int n,int& p,int om=0)
{
    Polinoame<double>** A1;
   A1=new Polinoame<T>*[n+2];

   for(int i=0;i<=n;i++)
    A1[i]=new Polinoame<double>[n+2];



   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        A1[i][j].pol.add(A[i][j]);
       A1[i][j].grad=0;
    }

   for(int i=1;i<=n;i++)
   {
   A1[i][i].pol.add(-1);
   A1[i][i].grad++;
   }

  Polinoame<double> A2=detm(A1,n-1);


    p=0;
     double* r;
     Llist<double> pp=find_real_solutions(A2.pol);
    r=pp.arrayfy();
   p=pp.nr;

   return r;
}

double* eigen_values4(double** A,int n,int& p,int om=0)
{
  // cout<<"covar"<<endl;
  // sca2d(A,n,n);
    Polinoame<double>** A1;
   A1=new Polinoame<T>*[n+2];

   for(int i=0;i<=n;i++)
    A1[i]=new Polinoame<double>[n+2];



   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        A1[i][j].pol.add(A[i][j]);
       A1[i][j].grad=0;
    }

   for(int i=1;i<=n;i++)
   {
   A1[i][i].pol.add(-1);
   A1[i][i].grad++;
   }


  Polinoame<double> A2=detm(A1,n);


    p=0;
     double* r;

     //cout<<"nu detm"<<endl;
  //for(int i=1;i<=A2.pol.nr;i++)
     //cout<<A2.pol[i]<<" ";
        //  cout<<"gata"<<endl;

     Llist<double> pp=find_real_solutions(A2.pol);
 //cout<<"found"<<endl;

    r=pp.arrayfy();
    // sca(r,n);
   p=pp.nr;
   return r;
}

T* eigen_vectors(T** A,int n,int m,T e_v,T* undet=NULL)
{
   T* rt;
   rt=new T[n+2];
   int k=0;

   for(int i=1;i<=min(n-1,m-1);i++)
 A[i][i]=A[i][i]-e_v;

  for(int i=1;i<=n;i++)
   A[i][m]=0;


    for(int i=1;i<=m;i++)
    A[n][i]=0;

 sca2d(A,n,m);


    T** A2;
    A2=new T*[n+2];
    for(int i=0;i<=n;i++)
    A2[i]=new T[m+2];


  move_pp(A2,A,n,m);

 gauss_jordan3(A2,n,m);
 cout<<"gauss_jordened1"<<endl;
 sca2d(A2,n,m);


Llist<T>* svgj=solve_gauss_jodan(A2,n,m);

for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(is_essential_zero(A2[i][j]))
A2[i][j]=0;

man=svgj;


Llist<T> rtt=solve_undet(svgj,undet,m-1);



rt=rtt.arrayfy();

delete A2;
 return rt;
}

void undeterminate(T** A,int n,int m)
{

int ln=0,ml=0;
 max_ln(A,n,m,ln,ml);
if(ml==m)
{

   //for(int i=1;i<=n;undeterminatei++)
 //  if(i!=ln)
  // {
   //A[i][ml]= A[i][ml]+A[ln][ml];
   //}sca(values,nr_e);

   A[ln][ml]=0;

}



}
template<typename T2>
void reduce_same_line(T2& a,int n,int m)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int c=1;
           for(int k=1;k<=m;k++)
            if(a[i][k]!=a[j][k])
            c=0;
            if(c==1)
            for(int k=1;k<=m;k++)
             a[j][k]=0;

        }

}

}


template<typename T2>
void arrange(T2** a,int n,int m)
{

     for(int i=1;i<=n;i++)
    {
        if(is_essential_zero(a[i][i]))
        {
            int j=i+1;
            while(is_essential_zero(a[j][i]) && j<=n)
                j++;
            if(j<=n)
             for(int k=1;k<=m;k++)
            swap(a[i][k],a[j][k]);


        }



    }


}





T* eigen_vectors3(T** A,int n,int m,T e_v,T* undet=NULL)
{

   if(is_essential_zero(e_v))
         e_v=0;
         //cout<<"eigenvalue "<<e_v<<endl;



   T* rt;
   rt=new T[n+2];
   int k=0;


//sca2d(A,n,m);
//cout<<endl;


    T** A2;
    A2=new T*[n+2];
    for(int i=0;i<=n;i++)
    A2[i]=new T[m+2];


    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         A2[i][j]=A[i][j];

   for(int i=1;i<=min(n,m);i++)
 A2[i][i]=A2[i][i]-e_v;



reduce_same_line(A2,n,m);

//arrange(A2,n,m);

 gauss_jordan3(A2,n,m);


for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(is_essential_zero(A2[i][j]))
A2[i][j]=0;



//undeterminate(A2,n,m);



Llist<T>* svgj=solve_gauss_jodan2(A2,n,m);
sca2d(A2,n,m);
cout<<endl<<"asta e"<<endl;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(is_essential_zero(A2[i][j]))
A2[i][j]=0;

 //sca2d(A2,n,m);

 //for(int i=1;i<=svgj->nr;i++)
 //cout<<svgj->operator[](i)<<" ";
 //cout<<endl;
man=svgj;

Llist<T> rtt=solve_undet(svgj,undet,m);

rt=rtt.arrayfy();

delete A2;
 return rt;
}



































Llist<T> solve_undet(Llist<T>* m,T* p,int n)
{

 Llist<T> sol;

int und=m[1].nr-1;

   for(int i=1;i<=n-und;i++)
     {
        sol[i]=0;
        for(int j=1;j<=m[i].nr;j++)
           {
              if(j==1)
              sol[i]=sol[i]+m[i][j];
               else
               if(p!=NULL)
               sol[i]=sol[i]+m[i][j]*p[j-1];
               else
               sol[i]=sol[i]+m[i][j];
           }
   }
    for(int i=n-und+1;i<=n;i++)
   {
        if(p!=NULL)
        sol[i]=p[i-1];
        else
        sol[i]=1;
   }
   return sol;
}




Llist<T> solve_undetu(int n,T* p=NULL)
{
   Llist<T> sol;
int und=man[1].nr-1;

   for(int i=1;i<=n-und;i++)
     {
        sol[i]=0;
        for(int j=1;j<=man[i].nr;j++)
           {

              if(j==1)
              sol[i]=sol[i]+man[i][j];
               else
               if(p!=NULL)
               sol[i]=sol[i]+man[i][j]*p[j-1];
               else
               sol[i]=sol[i]+man[i][j];
           }
   }
    for(int i=n-und+1;i<=n;i++)
   {
        if(p!=NULL)
        sol[i]=p[i-1];
        else
        sol[i]=1;
   }
   return sol;
}

};


template<typename T>
double** matrix_points(T P,int n)
{
   double** res=new double*[n+3];
   for(int i=0;i<=n+1;i++)
        res[i]=new double[n+3];


        for(int i=1;i<=n;i++)
        {

           for(int j=n;j>=1;j--)
           res[i][n-j+1]=pow(P[i].x,j-1);

            res[i][n+1]=P[i].y;


        }

      return res;

}


template<typename T>
Polinoame<double> poly_from_points(T P,int n)
{

 double** u=matrix_points(P,n);
  Eigen<double> pt;

 double sol[n+2];
for(int i=1;i<=n;i++)
sol[i]=u[i][n+1];


double* p=Ecuatie_Cramer(u,sol,n);


Polinoame<double> t;

if(p==NULL)
{

gauss_jordan3(u,n,n+1);


Llist<double>* svgj=pt.solve_gauss_jodan2(u,n,n+1);


for(int i=1;i<=n;i++)
svgj[i][2]*=-1;

p=new double[n+2];

for(int i=1;i<=n;i++)
   {
      p[i]=svgj[i][2];

   }

}

for(int i=1;i<=n;i++)
   {
     t.pol[i]=p[i];

   }

t.grad=n-1;


return t;

}







#endif // derivate_2_H
