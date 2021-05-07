#ifndef MAP_STYLE_H
#define MAP_STYLE_H
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include"math_sandus.h"
using namespace std;
math_Sandu st;
template<typename T>
struct multi_array
{

   int n;
   int* dem;
   char* desc;
   T a;

   void make(int n1,int* dem1)
   {
      n=n1;
      dem=new int[n1+1];

      for(int i=1;i<=n1;i++)
      dem[i]=dem1[i];


   }


   void make_1(int n1)
   {

       n=1;
      dem=new int[2];
    dem[1]=n1;
   }






};














template<class T, size_t M>
struct Matrix
{
T a[M][M];
int nr_col[M];
int nr_line=0;
char tip[15];





void remove_line(int i=0)
{
if(i<0 && i>nr_line)
{
   cout<<"the index given incorrect"<<endl;
return;

}
else
{

if(i==0)
i=nr_line;

{

for(int j=1;j<=nr_col[i];j++)
   a[i][j]=0;

}

}


}






void add_line( T b[],int n=0,T des=NULL)
{ int i;
nr_line++;
if(n!=0)
{

nr_col[nr_line]=n;
   for(i=1;i<=n;i++)
    a[nr_line][i]=b[i];
}
else
{
    int j=0;
    do
    {
        j++;
        a[nr_line][j]=b[j];


    }while(b[j]!=des);

nr_col[nr_line]=j;

}
}

void change_mat(T c[][M],int m,int n=0,T des=NULL)
{
    int i=0,j=0;

    nr_line=m;

    for(i=1;i<=m;i++)
    {

     for(j=1;(j<=n && n!=0)||(n==0 && c[i][j]!=des);j++)
     {

     //cout<<"se poate"<<endl;
     a[i][j]=c[i][j];


     }
      nr_col[i]=j;
    }
  //  cl(3,3,192);
//cout<<"nr-col"<<nr_col[i]<<endl;
   //cl(4,4,7);

}


void change_mat(T** c,int m,int n=0,T des=NULL)
{
    int i,j;
    nr_line=m;
    for(i=1;i<=m;i++)
    {
     for(j=1;(j<=n &&n!=0)||(n==0 && c[i][j]!=des);j++)
      a[i][j]=c[i][j];

      nr_col[i]=j;
    }



}












 T*  operator [](int b)
{
if(b>0 && b<=nr_line)
   return a[b];

}










};











template<typename Pasword,typename kod,int I>
struct map_style
{

Pasword* me;
kod* data;
int nr_s=1;
int nr_a=1;
int nr_b=1;
map_style** subs;

map_style<Pasword[],kod[],57>** suba;
map_style<Pasword[],kod,50>** subb;


map_style<Pasword[],kod[],57>* operator >(int n)
{
if(n==0)
return  suba[nr_b];

}


int sizen;
int* lenghts;
bool compare(Pasword,Pasword);
bool compall(Pasword);
void add_element(Pasword,kod);
void see_map()
{

    for(int i=1;i<=sizen;i++)
    cout<<me[i]<<" "<<data[i];


}

void create(int n=100,int m=100,int o=100,int p=100)
{


if(me!=NULL) delete[] me;
if(data!=NULL) delete[] data;
if(subs!=NULL) delete[] subs;
if(suba!=NULL) delete[] suba;
if(subb!=NULL) delete[] subb;

if(lenghts !=NULL) delete[] lenghts;

me=new Pasword[n+1];
data=new kod[n+1];

lenghts=new int[n+1];

suba=new map_style<Pasword[],kod[],57>*[m+1];
subb=new map_style<Pasword[],kod,50>*[o+1];
subs=new map_style*[p+1];

}


map_style()
{


sizen=0;

}

};





template<typename Pasword,typename kod,int I>
bool map_style<Pasword,kod,I>::compare(Pasword a,Pasword b)
{
if(a!=b)return true;

}

template<typename Pasword,typename kod,int I>
 bool map_style<Pasword,kod,I>::compall(Pasword a)
{
for(int i=1;i<=sizen;i++)
if(a==me[i])return false;
return true;

}




template<typename Pasword, typename kod,int I>
 void map_style<Pasword,kod,I>::add_element(Pasword a,kod b)
{
    if(compall(a))
    {
        sizen++;
    me[sizen]=a;
    data[sizen]=b;

      cout<<me[sizen]<<" "<<data[sizen]<<endl<<"new entery"<<sizen;

    }
    else
    {
        cout<<a<<" ";
    cout<<" already in list"<<endl;

    }

}
template<typename Pas,typename kode>
 struct map_style<Pas [],kode,50>
{


Pas**  me;


kode* data;


map_style** subs;


map_style<Pas[],kode[],57>** suba;


map_style<Pas,kode,5>** subp;


int sizen;
int* lenghts;

void create(int m1=100,int m2=100,int s1=100,int s2=100,int s3=100)
{

if(me!=NULL) delete[] me;
if(data!=NULL) delete[] data;
if(subs!=NULL) delete[] subs;
if(suba!=NULL) delete[] suba;
if(subp!=NULL) delete[] subp;

if(lenghts !=NULL) delete[] lenghts;


me=new Pas*[m1+1];

for(int i=0;i<=m1;i++)
me[i]=new Pas[m2];

data=new kode[m1+1];

lenghts=new int[m1];

subs=new map_style*[s1+1];

suba=new map_style<Pas[],kode[],57>[s2+1];

subp=new map_style<Pas,kode,5>[s3+1];



}






bool compare(Pas a[],Pas b[],int n=0, Pas des=NULL)
{ int j=0;
    if(n!=0)
    for(int i=1;i<=n;i++)

    {  cout<<a[i]<<" "<<b[i]<<endl;
if(a[i]!=b[i])
    return true;

}
    else
        do{

            j++;
            //cout<<"me-him:"<<a[j]<<" "<<b[j]<<endl;
            if(a[j]!=b[j])
            {//cout<<"aici"<<endl;
            return true;
            }

        }while(a[j]!=des && b[j]!=des);



return false;

}
void sortm(bool c(kode a,kode d)=b_comp)
{
   int inv=0;
   do{
      inv=0;kode aux;Pas auxi;
for(int i=1;i<sizen;i++)
   {
      if(c(data[i],data[i+1]))
      {
         aux=data[i];
         data[i]=data[i+1];
         data[i+1]=aux;
         for(int j=1;j<=100;j++)
             {
                auxi=me[i][j];
                me[i][j]=me[i+1][j];
                me[i+1][j]=auxi;

             }

 inv=1;

      }

        }
   }while(inv!=0);

}






;
int compall(Pas a[],int n=0,Pas des=NULL)
{
for(int i=1;i<=sizen;i++)
   // for(int j=1;(n!=0 && j<=n)||(me[i][j]!=des || a[j]!=des);j++)
    if(compare(a,me[i])==false)
        return i;


return 0;
}

void add_Array1(Pas a[],kode* b,int n=0,Pas des=NULL)
    {  //sca(a,st.len(a,'.'));
        int i;
        if(compall(a,n,des)==0)
        {
            sizen++;
     //cout<<des;
    // Sleep(1000);
        for( i=1;(n!=0 && i<=n)||(a[i]!=des);i++)
        {
        me[sizen][i]=a[i];
        //cout<<a[i]<<" "<<me[sizen][i]<<endl;
        }
        me[sizen][i]=a[i];
        lenghts[sizen]=i;
        data[sizen]=*b;

       cout<<"name:";
        sca(me[sizen],lenghts[sizen]);
        cout<<"it was entry "<<sizen<<endl;

    }
    else
    {
    cout<<"already in list elm. nr. "<<compall(a,n,des)<<endl;

    }

};
void see_keys(Pas des,int i=0)
{
if(i>0 && i<=sizen)
  sca(me[i],lenghts[i]);
   else
  st.scas2d(me,sizen,des);

}








void add_Array1(Pas a[],kode b,int n=0,Pas des=NULL)
    {  //sca(a,st.len(a,'.'));
        int i;
        if(compall(a,n,des)==false)
        {
            sizen++;
     //cout<<des;
     Sleep(1000);
        for( i=1;(n!=0 && i<=n)||(a[i]!=des);i++)
        {
        me[sizen][i]=a[i];
        //cout<<a[i]<<" "<<me[sizen][i]<<endl;
        }
        me[sizen][i]=a[i];
        lenghts[sizen]=i;
        data[sizen]=b;

       cout<<"name:";
        sca(me[sizen],lenghts[sizen]);
        cout<<"it was entry "<<sizen<<endl;

    }
    else
    {
    cout<<"already in list elm. nr. "<<compall(a,n,des)<<endl;

    }

};

void see_map()
{

    for(int i=1;i<=sizen;i++)
    {

        for(int j=1;j<=lenghts[i];j++)
    cout<<me[i][j];
    cout<<endl;

    }

}






map_style()
{

sizen=0;

}
kode* operator[](const Pas a[])
{
int choose, n;Pas des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{
 cin>>n;
}

else
{
cin>>des;
}

if(compall(a,n,des))
{
  kode* bus=data[compall(a,n,des)];
return bus ;
}
else
{
cout<<"you should have to create one with Array1()"<<endl;



return NULL;


;}
}


kode* operator[](Pas a[])
{
int choose, n;Pas des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{cout<<"n=";
cin>>n;
}
else
{
cout<<"add des: ";
cin>>des;
cout<<"des-choosed:"<<des<<endl;
Sleep(2000);
}
if(compall(a,n,des))
{
int po=compall(a,n,des);
kode*bus=&data[po];

return bus;

}
else
{cout<<"you should have to create one with Array1()"<<endl;


return NULL;

;}
}










};

template<typename Pasw,typename kodi>

struct map_style<Pasw [],kodi[],57>
{

 Pasw** me;
 kodi** data;

map_style** subs;

map_style<Pasw[],kodi,50>** suba;
map_style<Pasw,kodi,5>** subp;

int sizen;

int* lenghtm;
int* lenghtd;





void create(int m1=100,int m2=100,int d1=100,int s1=100,int s2=100,int s3=100)
{

if(me!=NULL) delete[] me;
if(data!=NULL) delete[] data;
if(subs!=NULL) delete[] subs;
if(suba!=NULL) delete[] suba;
if(subp!=NULL) delete[] subp;

if(lenghtm !=NULL) delete[] lenghtm;
if(lenghtd !=NULL) delete[] lenghtd;

me=new Pasw*[m1+2];
for(int i=0;i<=m1+1;i++)
me[i]=new Pasw[m2+2];

data=new kodi*[m1+2];
for(int i=0;i<=m1+1;i++)
data[i]=new kodi[d1+2];

lenghtm=new int[m1+2];
lenghtd=new int[d1+2];

subs=new map_style*[s1+1];
suba=new map_style<Pasw[],kodi,50>*[s2+2];
subp=new map_style<Pasw,kodi,5>*[s3+1];




}



bool compare(Pasw a[],Pasw b[],int n=0, Pasw des=NULL)
{ int j=0;
    if(n!=0)
    for(int i=1;i<=n;i++)
    { cout<<"me-him:"<<a[i]<<" "<<b[i]<<endl;
    if(a[i]!=b[i])return true;
}
    else
        do{

            j++;
            cout<<"me-him:"<<a[j]<<" "<<b[j]<<endl;
            if(a[j]!=b[j])return true;


        }while(a[j]!=des && b[j]!=des);



return false;

}
;
int compall(Pasw a[],int n=0,Pasw des=NULL)
{
for(int i=1;i<=sizen;i++)
   // for(int j=1;(n!=0 && j<=n)||(me[i][j]!=des && a[j]!=des);j++)
    if(compare(a,me[i])==false)
    {
        return i;
    }



return 0;
}

void add_Array2(Pasw a[],kodi b[],int n=0,int m=0,Pasw des1=NULL,Pasw des2=NULL)
    {
        int i;
        if(compall(a,n,des1)==false)
        {
            sizen++;

        for( i=1;(n!=0 && i<=n)||(a[i]!=des1);i++)
        {
        me[sizen][i]=a[i];
        }
        me[sizen][i]=a[i];
        lenghtm[sizen]=i;

         for( int j=1;(m!=0 && j<=m)||(b[j]!=des2);j++)
       data[sizen][j]=b[j];
   lenghtd[sizen]=i;

        cout<<"name:";
        sca(me[sizen],lenghtm[sizen]);
        cout<<" ";
        sca(data[sizen],lenghtd[sizen]);
        cout<<endl;
        cout<<"entery nr."<<sizen<<endl;

    }
    else cout<<"already in list"<<endl;
};
/*
kodi* operator[](const Pasw a[])
{
int choose, n;Pasw des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{
 cin>>n;
}

else
{
cin>>des;
}

if(compall(a,n,des))
{
  kodi* bus=data[compall(a,n,des)];
return bus ;
}
else
{cout<<"you should first create the element with add_Array1()"<<endl;
return NULL
;}
}
*/

kodi* operator[](Pasw a[])
{
int choose, n;Pasw des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{cout<<"n=";
cin>>n;
}
else
{
cout<<"add des: ";
cin>>des;
cout<<"des-choosed:"<<des<<endl;
Sleep(2000);
}
if(compall(a,n,des))
{
int po=compall(a,n,des);
kodi*bus=data[po];

return bus;

}
else
{cout<<"you should first create the element with add_Array1()"<<endl;
return NULL
;}
}

void ass(kodi* a,kodi b[],int n=0,kodi des=NULL)
{

for(int i=1;(i<=n&&n!=0)||(b[i]!=des);i++)
a[i]=b[i];

}


map_style()
{


sizen=0;

}
};


template<typename Pasw,typename kodi>
struct map_style<Pasw [],kodi**,57>
{

 Pasw** me;
 kodi*** data;
int nm=0;
map_style** subs;

map_style<Pasw[],kodi,50>** suba;
map_style<Pasw,kodi,5>** subp;

int sizen;

int* lenghtm;
int* lenghtd;
int* length3;




void create(int m1=100,int m2=50,int d2=10,int d1=15,int s1=100,int s2=100,int s3=100)
{
/*
if(me!=NULL) delete[] me;
if(data!=NULL) delete[] data;
if(subs!=NULL) delete[] subs;
if(suba!=NULL) delete[] suba;
if(subp!=NULL) delete[] subp;
if(lenghtm !=NULL) delete[] lenghtm;
if(lenghtd !=NULL) delete[] lenghtd;
*/

me=new Pasw*[m1+2];
nm=m1;

for(int i=0;i<=m1+1;i++)
me[i]=new Pasw[m2+2];

data=new kodi**[m1+2];


;

for(int i=0;i<=m1+1;i++)
data[i]=new kodi*[d2+2];

cout<<"nu aici"<<endl;

for(int i=0;i<=m1+1;i++)
 for(int j=0;j<=d2+1;j++)

data[i][j]=new kodi[d1+2];

cout<<"nu aici 2"<<endl;


lenghtm=new int[m1+2];
lenghtd=new int[d2+2];
length3=new int[d1+2];

subs=new map_style*[s1+1];
suba=new map_style<Pasw[],kodi,50>*[s2+2];
subp=new map_style<Pasw,kodi,5>*[s3+1];

cout<<"nu aici 3"<<endl;

cout<<"aici"<<endl;


}



bool compare(Pasw a[],Pasw b[],int n=0, Pasw des=NULL)
{
    int j=0;
    if(n!=0)
    for(int i=0;i<=n;i++)
    { //cout<<"me-him:"<<a[i]<<" "<<b[i]<<endl;
    if(a[i]!=b[i])return true;
}
    else
        do{
            j++;
           // cout<<"me-him:"<<a[j]<<" "<<b[j]<<endl;
            if(a[j]!=b[j])return true;
        }while(a[j]!=des && b[j]!=des);

return false;

}

int compall(Pasw a[],int n=0,Pasw des=NULL)
{
for(int i=1;i<=sizen;i++)
{
cout<<a<<" "<<me[i]<<endl;
    if(compare(a,me[i],n,des)==false)
    {
        return i;
    }
return 0;
}
}


int extend()
{

   if(sizen>=nm)
   {
      Pasw** a=new Pasw*[sizen+200];
      kodi*** b=new kodi**[sizen+200];

      for(int i=1;i<=sizen;i++)
      {      a[i]=new Pasw[lenghtm[i]+3];
        for(int j=0;j<=lenghtm[i];j++)
      a[i][j]=me[i][j];
      me=a;

      b[i]=new kodi*[lenghtd[i]+3];
      for(int j=1;j<=lenghtd[i];j++)
      {
         b[i][j]=new kodi[length3[i]+3];
        for(int k=0;k<=length3[i];k++)
         b[i][j][k]=data[i][j][k];
      }
   data=b;
      }

      nm+=200;

   return 1;
   }
return 0;
}

int index()
{
int index=0;
   for(int i=1;i<sizen;i++)
      index+=lenghtd[i];

}




void add_Array3(Pasw a[],kodi** b,int n=0,int t=0,int m=0,Pasw des1=NULL,Pasw des2=NULL)
    {
        int i;
        if(compall(a,n,des1)==false)
        {

         sizen++;
         extend();

        for( i=0;(n!=0 && i<=n)||(a[i]!=des1 && n==0);i++)
        {
        me[sizen][i]=a[i];
        }

        me[sizen][i]=des1;
        me[sizen][i+1]=0;

        cout<<me[sizen];
        Sleep(3000);
        lenghtm[sizen]=i;

        for(int k=1;k<=t;k++)
        {

         int j;
       for( j=0;(m!=0 && j<=m)||( m==0 && b[k][j]!=des2);j++)
      data[sizen][k][j]=b[k][j];

      if(m==0)
      {
      data[sizen][k][j]=des2;
      data[sizen][k][j+1]=0;
      }

      length3[index()+k]=j;
        }
       lenghtd[sizen]=t;

        cout<<"name:";
        scap(me[sizen],lenghtm[sizen],0);
       // cout<<" ";
       // sca2d(data[sizen],lenghtd[sizen],length3[sizen]);
        cout<<endl;
        cout<<"entery nr."<<sizen<<endl;
    }

    else cout<<"already in list"<<endl;

}
/*
kodi** operator[]( Pasw a[])
{
int choose, n;Pasw des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{
 cin>>n;
}

else
{
cin>>des;
}

if(compall(a,n,des))
{
  kodi** bus=data[compall(a,n,des)];
return bus ;
}
else
{cout<<"you should first create the element with add_Array3()"<<endl;
return NULL
;}
}
*/

kodi** operator[](Pasw a[])
{
int choose,n;Pasw des;
cout<<"lenght 1 or des. 2";cin>>choose;
if(choose==1)
{cout<<"n=";
cin>>n;
}
else
{
cout<<"add des: ";
cin>>des;
cout<<"des-choosed:"<<des<<endl;
//Sleep(2000);
}

if(compall(a,n,des))
{
int po=compall(a,n,des);

kodi**bus=data[po];

a[0]=lenghtd[po];

for(int i=1;i<=a[0];i++)
a[i]=length3[index()+i];

return bus;

}
else
{cout<<"you should first create the element with add_Array3()"<<endl;
return NULL
;}

}

void ass(kodi** a,kodi** b,int n=0,kodi des=NULL)
{

for(int i=1;(i<=n&&n!=0)||(b[i]!=des);i++)
a[i]=b[i];

}

map_style()
{

sizen=0;

}


};


template<typename T>
struct map_sstyle
{

   int n=1;
   int used;
   int cr=100;
   char* key=NULL;
   T data;
   int index=0;
   map_sstyle* next=NULL;


   map_sstyle* operator [](char* use)
   {

       update_n();


      if(key!=NULL)
      {


        if(strcmp(key,use)==0)return this;
      else
      {
         if(next!=NULL)
           { return next->operator[](use);}
         else
         {
            cout<<"not yet in list"<<endl;

            next=new map_sstyle<T>;
            next->key=new char[cr];
            strcpy(next->key,use);
            next->index=index+1;
          return next;

         }

      }

      }
      else
      { cout<<"first"<<endl;
           key=new char[cr];
            index=1;
            strcpy(key,use);

         return this;
      }



   }
 void  update_n()
   {
      n=1;
     map_sstyle* q=this;

      do{
         n++;
         q=q->next;


      }while(q!=NULL);
   }








     map_sstyle* operator [](int in)
   {
            update_n();
      if(index!=0)
      {


        if(index==in)return this;
      else
      {
         if(next!=NULL)
           { return next->operator[](in);}
         else
         {
            cout<<"not yet in list"<<endl;
            next=new map_sstyle<T>;
            next->key=new char[cr];
            n++;
            next->index=n;
          return next;

         }

      }

      }
      else
      { cout<<"first"<<endl;
           key=new char[cr];
            index=1;
         return this;
      }



   }










  void use_for_keys(char** t,int& k)
   {

      t[k]=new char[cr+1];
      strcpy(t[k],key);
      if(next!=NULL)
      {
        k=k+1;next->use_for_keys(t,k);

   }
   }

  char** keys()
   {
      char** ks=new char*[n+1];
      n=0;
      use_for_keys(ks,n);
      return ks;
   }



char**keys (int (*f)(map_sstyle<T>* a, map_sstyle<T>* b),int uj=0)
   {
      char** ks=new char*[n+1];
      n=0;
      use_for_keys(ks,n);

      int inv=0;

      do{//
            inv=0;


          for(int i=0;i<n;i++)
           if(f(operator[](ks[i]),operator[](ks[i+1])))
        {



           char* g;
            g=new char[cr+1];





           strcpy(g,ks[i]);
           strcpy(ks[i],ks[i+1]);
           strcpy(ks[i+1],g);
           inv=1;
        }

        }while(inv!=0);




if(uj==1)
        {

           int i=0;

           char* s=new char[cr];

           T d=data;


           map_sstyle<T>* q=operator[](ks[i]);

           data=q->data;
           q->data=d;

           strcpy(s,key);

           strcpy(key,q->key);

           strcpy(q->key,s);




               q=next;


           while(q!=NULL)
          {
             i++;

            map_sstyle<T>* p=operator[](ks[i]);

            d=q->data;

            q->data=p->data;
            p->data=d;


           strcpy(s,q->key);
           strcpy(q->key,p->key);
           strcpy(p->key,s);

             q=q->next;


          }


        }







         return ks;

   }

  int  is_num(char* p)
   {
      int c=1;
      for(int i=0;i<strlen(p);i++)
      if(strchr("1234567890,",p[i])==NULL)c=0;
      return c;

   }


double take_num(char* p)
   {
      int  pu=1;
      int dec=1;

      double r=0;

      for(int i=0;i<strlen(p);i++)
      {

      if(dec==0)pu=pu*10;

      if(strchr("1234567890",p[i])!=NULL)
      {
         cout<<(int)p[i]<<" "<<(int)p[i]-48<<endl;
      if(dec==1)
         r=r*10+((double)p[i]-48)/pu;
        else r=r+((double)p[i]-48)/pu;

      }
   else
      if(p[i]=='.'|| p[i]==',')dec=0;

      }
      return  r;

   }











};



































#endif // MAP_STYLE_H
