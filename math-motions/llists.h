#ifndef LLISTS_H
#define LLISTS_H
#include<iostream>
#include<fstream>
#include<string.h>


template<typename T>
struct slista
{
char name[50];

T* eu;
int nr=0;
int lim=0;

T& operator [](int n)
{
   if(nr==0 && lim==0)
   {
      lim=n+10;
      eu=new T[lim+2];
   return eu[1];
   }
   else
   if(n<=nr)
   {
      return eu[n];

   }
   else
   {

  if(n>lim)
       {
          cout<<"prste limita";
          lim=n+10;

          T* aux;

          aux=new T[lim+2];
          move_d(aux,eu,nr);

          eu=aux;

            nr=n;
           return eu[n];

       }
       else
if(n>nr && n<lim)
     {
            nr=n;
           return eu[n];

      }
   }

}
void afisare(void (*f)(T)=NULL)
{

   cout<<nr<<endl;
   for(int i=1;i<=nr;i++)
   {
   if(f!=NULL)
      {
         f(eu[i]);
      }
}
}

void append(T a)
{
   nr++;
   eu[nr]=a;

}
T* begin()
{
   return eu+0;

}

T* end()
{
   return eu+nr;

}


};



template<typename T>
struct slista<T*>
{

char name[50];

T** eu;
int nr=0;
int lim=0;

T& operator [](int n)
{
   if(nr==0 && lim==0)
   {
      lim=n+10;
      eu=new T*[lim+2];
   return eu[1][0];
   }
   else
   if(n<=nr)
   {
      return eu[n][0];

   }
   else
   {

  if(n>lim)
       {
          cout<<"prste limita";
          lim=n+10;

          T** aux;

          aux=new T*[lim+2];
          move_d(aux,eu,nr);

          eu=aux;

            nr=n;
           return eu[n][0];

       }
       else
if(n>nr && n<lim)
     {
            nr=n;
           return eu[n][0];

      }
   }

}
T*& operator ()(int n)
{
   if(nr==0 && lim==0)
   {
      lim=n+10;
      eu=new T*[lim+2];
   return eu[1];
   }
   else
   if(n<=nr)
   {
      return eu[n];
   }
   else
   {

  if(n>lim)
       {
          cout<<"prste limita";
          lim=n+10;

          T** aux;

          aux=new T*[lim+2];
          move_d(aux,eu,nr);

          eu=aux;

            nr=n;
           return eu[n];

       }
       else
if(n>nr && n<lim)
     {
            nr=n;
           return eu[n];

      }
   }

}




void afisare(void (*f)(T)=NULL)
{

   cout<<nr<<endl;
   for(int i=1;i<=nr;i++)
   {
   if(f!=NULL)
      {
         f(eu[i][0]);
      }
}
}



void append(T a)
{
   nr++;
   eu[nr]=a;

}
T* begin()
{
   return eu+0;

}


T* end()
{
   return eu+nr;

}


};

template<typename T>
int assign_numbers(char*s ,T& a)
{
   int i=0;
   int k=0;
   int p=1;

   while(i<strlen(s))
   {
   k++;
   a[k]=0;
   p=1;
   while(s[i]!=','  && s[i]!=';' && i<strlen(s))
   {


      if(s[i]>='0' && s[i]<='9'  && s[i]!='.')
      a[k]=a[k]*10+s[i]-'0';




      if(p!=1)
      {
         p=p*10;
      }
      if(s[i]=='.')
      p=p*10;
      i++;
   }
  if(p!=1) p=p/10;
   a[k]=a[k]/p;
   i++;
   }
   return k;
}


template<typename T>
struct Llist
{


   int nr=0;
   T eu;
   T* for_begin=NULL;
   int kh;

   T* begin()
   {
      delete for_begin;
      for_begin=new T[nr+2];
      Llist<T>*p=this;

       kh=0;

         while(p!=NULL)
         {
            kh++;
           for_begin[kh]=p->eu;
           p=p->next;
         }

   return for_begin+1;

   }

      T* end()
   {
      return for_begin+kh+1;
   }





   int size()
   {
      return nr;
   }


   int kt,mkt;

    Llist<T>* next=NULL;


    struct Iter
    {

       Llist<T>* u;
       Llist<T>* now;

       int sf=0;
           int use=1;
          void operator =(Llist<T>& ui)
      {
        u=&ui;
        now=&ui;

      }
            void operator ++()
           {
              if(use<u->nr)
             {
                now=now->next;use++;
             }
             else
               sf=1;

           }
            void operator +=(int n)
           {
             for(int i=1;i<n ;i++)
              operator++();

           }
          void restore()
           {
              now=u;
              use=1;
              sf=0;
           }

           int cond()
           {

              return!sf;
           }

       T&    operator()()
      {

         return now->eu;

      }

    };








       T& operator[](int n)
    {


            if(n<=nr)
            {
               if(n==1)
                  return eu;


               Llist<T>* p=next;
                for(int i=3; i<=n; i++)
                        p=p->next;

            return p->eu;


            }

            else
            {

                   if(n==1)
                  {
                     nr++;
                     return eu;
                  }


                Llist<T>* p=this;

               for(int i=1;i<nr;i++)
               {
                  p=p->next;
               }

          for(int i=nr;i<n;i++)
               {
                  p->next=new Llist<T>;
                     p=p->next;
               }

               nr=n;
             return p->eu;

            }
    }

   void add(T a)
{
   Llist<T>* p;

   if(nr==0)
     {
        eu=a;nr++;
     }
      else
      {
         if(nr==1)
            {
               next=new Llist<T> ;
               next->eu=a;nr++;

            }
            else

            {

          p=next;
               for(int i=2;i<nr;i++)
            {
               p=p->next;

            }


            p->next=new Llist<T>;
            p->next->eu=a;
            nr++;
      }

}


}

struct Keys_Table
{

  Llist<T>* u;

   struct binds
   {
      char* keys="Empty";
      int indx;

   }* Key;

  int nr_k;
  int lim_k;

  int Mk=50;

void orderByKey(char* c="asc",int f(char*,char*,Llist<T>*)=NULL)
  {

        int inv=0;
        do{
         inv=0;
      for(int i=1;i<nr_k;i++)
         {

            if(f==NULL)
            {


               if((c[0]=='a' || c[0]=='A')&& strcmp(Key[i].keys,Key[i+1].keys)>0)

               {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }
               else
                  if((c[0]=='d' || c[0]=='D') && strcmp(Key[i].keys,Key[i+1].keys)<0)
               {

                  inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }


            }
            else
               if(f(Key[i].keys,Key[i+1].keys,u)==1)
            {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

            }






         }

        }while(inv!=0);


     }
void orderByInx(char* c="asc",int f(int,int,Llist<T>*)=NULL)
  {
        int inv=0;
        do{
         inv=0;
      for(int i=1;i<nr_k;i++)
         {

            if(f==NULL)
            {


               if((c[0]=='a' || c[0]=='A')&& Key[i].indx > Key[i+1].indx)

               {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }
               else
                  if((c[0]=='d' || c[0]=='D') && Key[i].indx < Key[i+1].indx)
               {

                  inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }


            }
            else
               if(f(Key[i].indx,Key[i+1].indx,u)==1)
            {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

            }






         }

        }while(inv!=0);
}


void make(int mk=100)
  {
     nr_k=0;
     if(mk!=0)
      Mk=mk;

     lim_k=Mk;
     cout<<"MK"<<Mk<<endl;
     Key=new binds[Mk];

  }

      void  remake(int bf,int mk=0)
  {
     binds *k=new binds[Mk];

     if(mk!=0)
      Mk=mk;

for(int i=1;i<=nr_k;i++)
    k[i].keys=Key[i].keys;
  }

  virtual T& operator[](char* c)
  {

     for(int i=1;i<=nr_k;i++)
     {

      if(strcmp(Key[i].keys,c)==0)
         return u->operator[](Key[i].indx);
     }


      if(nr_k+1>lim_k)
   remake(lim_k,nr_k+1);




      nr_k++;
      u->nr++;


      Key[nr_k].indx=u->nr;

//cout<<"Aici:"<<nr_k<<" "<<u->nr<<endl;

Key[nr_k].keys=new char[strlen(c)];
       strcpy(Key[nr_k].keys,c);

        return u->operator[](Key[nr_k].indx);

}



 int by_index(int j)
{
   for(int i=1;i<=nr_k;i++)
   if(Key[i].indx==j)
      return i;
   return 0;

}


void label(int i,char* c)
{

int ck=by_index(i);

if(ck==0)

   {nr_k++;
   ck=nr_k;}

   Key[ck].indx=i;
   Key[ck].keys=new char[strlen(c)];

   strcpy(Key[ck].keys,c);
}



}keys;


void KeyT(int m=100)
{
   kt=1;
   keys.Mk=m;
   keys.u=this;
   keys.make();
}


struct Multi_Key_Table:Keys_Table
{

int n_b=0;

T& operator[](char* c)
   {

     if(Keys_Table::nr_k+1>Keys_Table::lim_k)
   Keys_Table::remake(Keys_Table::lim_k,Keys_Table::nr_k+1);

      Keys_Table::nr_k++;

      Keys_Table::Key[Keys_Table::nr_k].indx=Keys_Table::u->nr+1;


Keys_Table::Key[Keys_Table::nr_k].keys=new char[strlen(c)];

cout<<"indx"<<Keys_Table::Key[Keys_Table::nr_k].indx<<endl;
       strcpy(Keys_Table::Key[Keys_Table::nr_k].keys,c);
        return Keys_Table::u->operator[](Keys_Table::Key[Keys_Table::nr_k].indx);
   }


slista<T*> operator()(char* c,int& was,int save=0)
{

   was=0;
    for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       was++;
     }
     if(save)
      n_b=was;
       if(was!=0)
       {

       slista<T*> res;
       res[was+10];

       was=0;
         for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       {
      was++;

       res.operator()(was)=&Keys_Table::u->operator[](Keys_Table::Key[i].indx);
       }
     }
       return res;

       }
slista<T*> res;
res[5];

    return res;
}





 slista<T*>  operator()(char* c)
{
   n_b=0;

    for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       n_b++;
     }

       if(n_b!=0)
       {

        slista<T*> res;
       res[n_b+10];
  cout<<"nu aci"<<endl;

       n_b=0;
         for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       {
      n_b++;

      strcpy(res.name,c);


      res.operator ()(n_b)=&Keys_Table::u->operator[](Keys_Table::Key[i].indx);
       }
     }
     cout<<"aici e ok"<<endl;
       return res;

       }


       else
       {
          slista<T*> res;
          res[2];

          return res;

       }





}



slista<T> Copy(char* c)
{
   n_b=0;

    for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       n_b++;
     }

       if(n_b!=0)
       {

        slista<T> res;
       res[n_b+10];
  cout<<"nu aci"<<endl;

       n_b=0;
         for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       {
      n_b++;

      strcpy(res.name,c);


      res.operator [](n_b)=Keys_Table::u->operator[](Keys_Table::Key[i].indx);


       }
     }
     cout<<"aici e ok"<<endl;
       return res;

       }


       else
       {
          slista<T> res;
          res[2];
          return res;
       }





}














}mkeys;


void MKeyT(int m=100)
{
   mkt=1;
   mkeys.Mk=m;
   mkeys.u=this;
   mkeys.make();

}

    T& operator[](char* c)
    {

       if(kt==1)
         return keys[c];
         cout<<"mkt==0"<<endl;

    }

        slista<T*> operator()(char* c)
    {

       if(mkt==1)
         return mkeys[c].operator()(c);

         cout<<"mkt==0"<<endl;

    }





    void afisare(void (*f)(T)=NULL)
{

   cout<<nr<<endl;
   for(int i=1;i<=nr;i++)
   {
   if(f!=NULL)
      {
         f(operator[](i));
      }
}
}




















};










































template<typename T>
struct lista
{

T* eu;
int nr=0;
int lim=0;
int kt=0,mkt=0;

T& operator [](int n)
{
   if(nr==0 && lim==0)
   {
      lim=n+10;
      eu=new T[lim+2];
   return eu[1];
   }
   else
   if(n<=nr)
   {


      return eu[n];
   }
   else
   {

  if(n>lim)
       {
          cout<<"prste limita";
          lim=n+10;

          T* aux;

          aux=new T[lim+2];

          move_d(aux,eu,nr);

          eu=aux;

            nr=n;
           return eu[n];

       }
       else
if(n>nr && n<lim)
     {
            nr=n;
           return eu[n];

      }
   }

}

T& operator [](char* n)
{
   if(kt==1)
   return keys[n];

   if(mkt==1)
   return mkeys[n];


}









void afisare(void (*f)(T)=NULL)
{

   cout<<nr<<endl;
   for(int i=1;i<=nr;i++)
   {
   if(f!=NULL)
      {
         f(eu[i]);
      }
}
}



void append(T a)
{
   nr++;
   eu[nr]=a;

}
T* begin()
{
   return eu+0;

}


T* end()
{
   return eu+nr;

}



























struct Keys_Table
{

   lista<T>* u;

   struct binds
   {
      char* keys="Empty";
      int indx;

   }* Key;

  int nr_k;
  int lim_k;

  int Mk=50;

void orderByKey(char* c="asc",int f(char*,char*,lista<T>*)=NULL)
  {

        int inv=0;
        do{
         inv=0;
      for(int i=1;i<nr_k;i++)
         {

            if(f==NULL)
            {


               if((c[0]=='a' || c[0]=='A')&& strcmp(Key[i].keys,Key[i+1].keys)>0)

               {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }
               else
                  if((c[0]=='d' || c[0]=='D') && strcmp(Key[i].keys,Key[i+1].keys)<0)
               {

                  inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }


            }
            else
               if(f(Key[i].keys,Key[i+1].keys,u)==1)
            {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

            }






         }

        }while(inv!=0);


     }
void orderByInx(char* c="asc",int f(int,int,lista<T>*)=NULL)
  {
        int inv=0;
        do{
         inv=0;
      for(int i=1;i<nr_k;i++)
         {

            if(f==NULL)
            {


               if((c[0]=='a' || c[0]=='A')&& Key[i].indx > Key[i+1].indx)

               {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }
               else
                  if((c[0]=='d' || c[0]=='D') && Key[i].indx < Key[i+1].indx)
               {

                  inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

               }


            }
            else
               if(f(Key[i].indx,Key[i+1].indx,u)==1)
            {
               inv++;
               binds a=Key[i];
               Key[i]=Key[i+1];
               Key[i+1]=a;

            }






         }

        }while(inv!=0);


     }


void make(int mk=100)
  {
     nr_k=0;
     if(mk!=0)
      Mk=mk;

     lim_k=Mk;
     Key=new binds[Mk];

  }


      void  remake(int bf,int mk=0)
  {
     binds *k=new binds[Mk];

     if(mk!=0)
      Mk=mk;

for(int i=1;i<=nr_k;i++)
    k[i].keys=Key[i].keys;
  }

  virtual T& operator[](char* c)
  {

     for(int i=1;i<=nr_k;i++)
     {


      if(strcmp(Key[i].keys,c)==0)
         return u->operator[](Key[i].indx);
     }


      if(nr_k+1>lim_k)
   remake(lim_k,nr_k+1);




      nr_k++;
      u->nr++;


      Key[nr_k].indx=u->nr;

//cout<<"Aici:"<<nr_k<<" "<<u->nr<<endl;

Key[nr_k].keys=new char[strlen(c)];
       strcpy(Key[nr_k].keys,c);

        return u->operator[](Key[nr_k].indx);

}



 int by_index(int j)
{
   for(int i=1;i<=nr_k;i++)
   if(Key[i].indx==j)
      return i;
   return 0;

}


void label(int i,char* c)
{

int ck=by_index(i);
if(ck==0)
   {nr_k++;
   ck=nr_k;}

   Key[ck].indx=i;
   Key[ck].keys=new char[strlen(c)];
   strcpy(Key[ck].keys,c);
}





}keys;


void KeyT(int m=0)
{
   kt=1;
   keys.Mk=lim;
   keys.u=this;
   keys.make();

}

struct Multi_Key_Table:Keys_Table
{

int n_b=0;

T& operator[](char* c)
   {

     if(Keys_Table::nr_k+1>Keys_Table::lim_k)
   Keys_Table::remake(Keys_Table::lim_k,Keys_Table::nr_k+1);

      Keys_Table::nr_k++;
      Keys_Table::u->nr++;

      Keys_Table::Key[Keys_Table::nr_k].indx=Keys_Table::u->nr;

Keys_Table::Key[Keys_Table::nr_k].keys=new char[strlen(c)];
       strcpy(Keys_Table::Key[Keys_Table::nr_k].keys,c);

        return Keys_Table::u->operator[](Keys_Table::Key[Keys_Table::nr_k].indx);
   }


slista<T*> operator()(char* c,int& was,int save=0)
{

   was=0;
    for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       was++;
     }
     if(save)
      n_b=was;
       if(was!=0)
       {

       slista<T*> res;
       res[was+10];

       was=0;
         for(int i=1;i<=Keys_Table::nr_k;i++)
     {
      if(strcmp(Keys_Table::Key[i].keys,c)==0)
       {
      was++;

       res.operator()(was)=&Keys_Table::u->operator[](Keys_Table::Key[i].indx);
       }
     }
       return res;

       }
slista<T*> res;
res[5];

    return res;
}













}mkeys;




void MKeyT()
{
   mkt=1;
   mkeys.Mk=lim;
   mkeys.u=this;
   mkeys.make();

}

private:
   template<typename Ti>
 void eliminate_key(Ti a,int h)
{
    int ck=a.by_index(h);


   if(ck!=0)
   {
    for(int i=ck;i<a.nr_k;i++)
    {

       a.Key[i]=a.Key[i+1];

    }

      a.nr_k--;




   }

}
 template<typename Ti>
void update_keys(Ti a,int h)
{
   for(int i=h+1;i<=nr;i++)
 {
    int ck=a.by_index(i);
    if(ck!=0)
    a.Key[ck].indx--;
 }


}










public:




T pull()
{
   if(nr!=0)
   {
       T res=eu[nr];

        if(kt==1)
        {

  eliminate_key(keys,nr);

   }
   if(mkt==1)
    eliminate_key(mkeys,nr);



      nr--;


      return res;

   }
     else
     {

        T res;

        return res;

     }

}

T pull(int a)
{
   if(a<nr)
   {

      T res=eu[a];

      for(int i=a;i<nr;i++)
      eu[i]=eu[i+1];


   if(kt==1)
{
   eliminate_key(keys,a);
update_keys(keys,a);
}

if(mkt==1)
{
   eliminate_key(mkeys,a);
   update_keys(mkeys,a);
}

      nr--;
      return res;
}
   else
   {
      T r;
      return r;

   }

}




};














#endif // LLISTS_H
