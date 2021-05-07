#ifndef VECTORIZATION_H
#define VECTORIZATION_H
#include"math_sandus.h"
math_Sandu sm;

struct vecto{
float x=0,y=0,z=0;


vecto(double x2,double y2,double z2=0)
{
   x=x2;y=y2;z=z2;


}


float mag(float );

void setMag(float);


void va(vecto);
double angle()
{

   double arg=0;
  return arctan3(x,y);

}


vecto fromAngle(double ang,int deg=1)
{
   vecto c;
   if(deg==1)
   {
   c.y=Math.sina(ang);
   c.x=Math.cosa(ang);
   }
   else
   {
   c.y=Math.sina(deg_angle(ang));
   c.x=Math.cosa(deg_angle(ang));
   }

 return c;
}






void ve(vecto);
void vsub(vecto);
void mults(float);
void div(float);
vecto multo(float);

float dot(vecto);
void limit(float);

void sa(int ,int,int );
void se(float,float,float);
float distc(int ,int ,int);
int dist(vecto);
float dist(int,int,int);
vecto disto(vecto);
vecto disto(int ,int,int);
vecto cross(vecto);

void normalize();

double distd(vecto a)
{
      return sm.aps(sqrt( (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y) ));


}
float dot2(vecto a)
{
  return a.x*x+a.y*y;

}









void repair_over(int i,int j,int k=10)
{
   if(x>=i)x=k;
   else
   if(x<=5)x=i-k;

   if(y>=j)y=k;
  else
   if(y<=5)y=j-k;

}


vecto Copy()
{
   vecto c;
   c.x=x;
   c.y=y;
   c.z=z;
   return c;

}
vecto nvsub(vecto a,vecto b)
{

   vecto c;
   c.x=a.x-b.x;
   c.y=a.y-b.y;
   c.z=a.z-b.z;
   return c;
}






void randvec(int xi,int yj ,int zi=0)
{

x=randf(zi,xi);
y=randf(zi,yj);

if(zi)z=0;

}

int operator ==(vecto b)
{
if(x==b.x && y==b.y && z==b.z)return 1;
return 0;
}
int operator !=(vecto b)
{
if(x==b.x && y==b.y && z==b.z)return 0;
return 1;
}




void operator ()(double x2,double y2,double z2=0)
{
x=x2;y=y2;z=z2;

}
vecto()
{
   ;
}


int cadran2_d()
{

   if(x>0 && y>0)return 1;
   if(x<0 && y>0)return 2;
   if(x<0 && y<0)return 3;
   if(x>0 && y<0)return 4;


}

int cadran3_d()
{

   if(x>0 && y>0)return 1;
   if(x<0 && y>0)return 2;
   if(x<0 && y<0)return 3;
   if(x>0 && y<0)return 4;


}

vecto Vector_ADD(vecto A ,vecto B)
{

   vecto C;
   C.x=A.x+B.x;
   C.y=A.y+B.y;
   C.z=A.z+B.z;
   return C;
}

vecto Vector_SUB(vecto A ,vecto B)
{

   vecto C;
   C.x=A.x-B.x;
   C.y=A.y-B.y;
   C.z=A.z-B.z;
   return C;
}


vecto apv(vecto a)
{
   a.x=Math.ap(a.x);
   a.y=Math.ap(a.y);
   a.z=Math.ap(a.z);
}





}Vecto_SS;



float vecto::mag(float i=2)
{
float p=x*x+y*y+z*z;

if(p<0)p=-p;
    return sqrt(p);


}


void vecto::setMag(float len)
{

vecto c=Copy();

if(mag()!=0)
c.mults(1.0/mag());
c.mults(len);

x=c.x;
y=c.y;
z=c.z;

}




void vecto::normalize()
{
vecto c=Copy();

c.mults(1.0/c.mag());

x=c.x;
y=c.y;
z=c.z;


}



void vecto::mults(float a)
{
    x=x*a;
    y=y*a;
    z=z*a;

}

void vecto::div(float a)
{ if(a!=0)
{   x=x/a;
    y=y/a;
    z=z/a;

}

}


vecto vecto::multo(float a)
{//sm.ap(
         vecto rez;
    rez.x=sm.ap(x*a);
    rez.y=sm.ap(y*a);
    rez.z==sm.ap(z*a);

return rez;
}

/// how similar are 2 vectors that are normalized
float vecto::dot(vecto a)
{
  return a.x*x+a.y*y+a.z*z;

}





/// help figure out what to be rendered on a screen
vecto vecto::cross(vecto a)
{
    vecto newv;
    newv.x=y*a.z-z*a.y;
    newv.y=z*a.x-x*a.z;
    newv.z=x*a.y-y*a.x;

  return newv;

}
// What you can learn from https://www.youtube.com/watch?v=XgMWc6LumG4&list=WL&index=58

//PART I
//for a 3d engine to each faces use first
//cross product to find the normals then
//use dot product with difference
//between camera and one one of the faces vertexes
// if is less then 0 is visible if not then not.
// Do dot product with the directional light.
// Use color based on the last dot product
//(  an be used an algorithm that takes between 0 and 1 and returns a grey color)


//PART 2
//you can use Blender but only work in video studios
// to read premade models










//useful for convex hulls gift wrapping
float cross_2d(vecto x,vecto y)
{
   return x.x*y.y - x.y*y.x;


}
float cross_2d(float x1,float y1,float x2,float y2)
{
   return x1*y2-x2*y1;


}



float vecto::dist(int a,int b,int c=0)
{
    return sqrm( (a-x)*(a-x)+(b-y)*(b-y));
}


 float vecto::distc(int a,int b,int c=0)
{
    return a-x+b-y+c-z;
}





int vecto::dist(vecto a)
{
      return sm.ap(sqrt( (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y) ));


}
vecto vecto::disto(vecto b)
{
    vecto dis;
    dis.x=b.x-x;
    dis.y=b.y-y;
    dis.z=b.z-z;
    return dis;

}

vecto vecto::disto(int a,int b,int c=0)
{
    vecto dis;
    dis.x=a-x;
    dis.y=b-y;
    dis.z=c-y;

    return dis;

}


void vecto::limit(float a)
{
   if(x*x+y*y>0)
   {
      cout<<sqrt(x*x+y*y)<<endl;

    if(sqrt(x*x+y*y)>a)

{

        setMag(a);
}

   }


}

void vecto::va(vecto a)
{
    x=x+a.x;
    y=y+a.y;
    z=z+a.z;

}

void  vecto::vsub(vecto a)
{ x=x-a.x;
y=y-a.y;
z=z-a.z;
}




void vecto::ve(vecto a)
{
    x=a.x;
    y=a.y;
    z=a.z;

}
vecto vzero()
{
   vecto c;
   c.x=0;
   c.y=0;
   c.z=0;
return c;
}



void vecto::se(float a,float b,float c=0)
{
    x=a;
    y=b;
    z=c;
}
void vecto::sa(int i,int j,int k=0)
{
    x=x+i;
    y=y+j;
    z=z+k;


}


vecto rotate_point_2d(double x,double y,double angle )
{
   vecto v;
   v.x=x*Math.cosa(angle)-y*Math.sina(angle);
   v.y=y*Math.cosa(angle)-x*Math.sina(angle);
return v;

}








double Aria_triunghi(vecto A,vecto B,vecto C)
{

   double a[4][4]={  {0,0,0},
                     {0,A.x,A.y,1},
                     {0,B.x,B.y,1},
                     {0,C.x,C.y,1},};

sca2d(a,3,3);


         return det(3,a);

}
vecto cross_prodct(vecto X,vecto Y)
{
   double d1[4][4]={ {0,0,0,0},
                     { 0,1,-1,1},
                     { 0,X.x,X.y,X.z },
                     {0,Y.x,Y.y,Y.z},};

         double d2[3][3];
               vecto aux;
               double h[4];

                for(int k=1;k<=3;k++)
                {

               for(int i=2;i<=3;i++)
               {
                  int ind=0;
                   for(int j=1;j<=3;j++)
                   {
                      if(j!=k)
                     {  ind++;
                         d2[i-1][ind]=d1[i][j];
                     }
                   }

               }
               h[k]=det(2,d2);
                }
                aux(h[1],-h[2],h[3]);
                return aux;

}


double Volume_pal(vecto X,vecto Y,vecto Z)
{
   vecto aux=cross_prodct(Y,Z);
 double res=aux.x*X.x+aux.y*X.y+aux.z*X.z;
   return abs(res);

}




double Volume_sqpyramid(vecto X,vecto Y,vecto Z)
{

   double d1[4][4]={ {0,0,0,0},
                     { 0,Z.x,Z.y,Z.z},
                     { 0,X.x,X.y,X.z },
                     {0,Y.x,Y.y,Y.z},};

      return abs(det(3,d1)/3);

}

double Volume_trpyramid(vecto X,vecto Y,vecto Z)
{

   double d1[4][4]={ {0,0,0,0},
                     { 0,Z.x,Z.y,Z.z},
                     { 0,X.x,X.y,X.z },
                     {0,Y.x,Y.y,Y.z},};

      return abs(det(3,d1)/6);

}

double AllVolume_trpyramid(vecto A,vecto B,vecto C,vecto D)
{

   double d1[4][4]={ {0,0,0,0},
                     { 0,A.x-D.x,A.y-D.y,A.z-D.z},
                     { 0,B.x-D.x,B.y-D.y,B.z-D.z },
                     {0,C.x-D.x,C.y-D.y,C.z-D.z},};

      return abs(det(3,d1)/6);

}


double cos_v(vecto v,vecto u)
{


   double dp=v.dot(u);
   double magi=v.mag()*u.mag();

   if(magi!=0)
   return dp/magi;
 return 2;


}

double sin_v(vecto v,vecto u)
{

return sqrt(1-cos_v(v,u)*cos_v(v,u));


}

struct roots
{

   double a=1, b=0;
   double n=0;

   int n2=2;

 int p=2;


   double operator()()
   {
      return Math.rf(a*sqrm(b,1.0/n2),p);

   }

};


roots square_root(int N)
{
   int d=2,p=0;
   roots r;
   r.b=1;
   r.a=1;

   while(N!=1)
{
      if(N%d==0)
      {

         p=0;
         while(N%d==0)
           {p++;N=N/d;}
         for(int i=1;i<=p/2;i++)
         r.a=r.a*d;

         for(int i=1;i<=p%2;i++)
         r.b=r.b*d;
      }
    d++;
}

return r;
}


roots Metal_ratios(int N)
{

   roots r;
   r=square_root(N*N+4);
   r.n= N/2.0;


    return r;
}





struct stroke
{
   double dx,dy;
   int pen=1;

  void pen_up()
   {
      pen=0;

   }
     void pen_down()
   {
      pen=1;
   }

     void pen_end()
   {
      pen=-1;
   }

};

///first the target ,second the starting point
vecto* P_intersect(double x1,double x2,double y1,double y2,double x3,double x4,double y3,double y4)
{

   vecto* P;
   float t=t_intesect(x1, x2, y1, y2,x3,x4, y3, y4);



   float u=u_intesect(x1, x2, y1, y2,x3,x4, y3, y4);


   if(t>=0 && t<=1 && u>0)
   {
      P=new vecto;

   P->x=x1+t*(x2-x1);
   P->y=y1+t*(y2-y1);
  return P;
   }



      return NULL ;



}


///first the target ,second the starting point
vecto* P_intersecti(double x1,double x2,double y1,double y2,double x3,double x4,double y3,double y4)
{

   vecto* P;
   float t=t_intesect(x1, x2, y1, y2,x3,x4, y3, y4);



   float u=u_intesect(x1, x2, y1, y2,x3,x4, y3, y4);


   if(t>= 0 && t <= 1 && u >0 && u <= 1 )
   {
      P=new vecto;

   P->x=x1+t*(x2-x1);
   P->y=y1+t*(y2-y1);
  return P;
   }



      return NULL ;



}

ostream& operator<<(ostream& o,vecto a)
{

o<<a.x<<" "<<a.y;

if(a.z!=0)
cout<<" "<<a.z;
cout<<endl;


}












/// return the point of a bezier curve of n-1 degree
template<typename T>
vecto Bezier_point(float t,T P,int n)
{


   while(t>1)
      t=t/10;

   while(t<-1)
      t=t/10;

   vecto Bt;
   Bt.x=0;
   Bt.y=0;

   for(int i=1;i<=n;i++)
   {
      vecto bt;
      bt=P[i];


       int j=i-1;


      float c=Math.comb(n-1,j)*pow(1.0-t,n-j-1)*pow(t,j);

      bt.mults(c);





      Bt.va(bt);


   }
   return Bt;

}


template<typename T>
Llist<vecto> Bezier_curve(T P,int n,int nt)
{
   Llist<vecto> b_crv;
   for(float i=0;i<=1;i+=1.0/nt)
   {

        b_crv.add(Bezier_point(i,P,n));
   }







return  b_crv;

}



float* d_intersect(vecto plane_p,vecto plane_n,vecto pa,vecto pb)
{
   plane_n.normalize();

   vecto dif_p=Vecto_SS.Vector_SUB(plane_p,pa);
   float up_part=dif_p.dot(plane_n);
   vecto line_v=Vecto_SS.Vector_SUB(pb,pa);

   line_v.normalize();

   float dn_part=line_v.dot(plane_n);

   if(!dn_part)
   return NULL;


   float* res=new float;
   *res=up_part/dn_part;
   return res;

}






vecto* lp_intersect(vecto plane_p,vecto plane_n,vecto pa,vecto pb)
{

   vecto* rp=NULL;
   float* d=d_intersect(plane_p, plane_n,pa,pb);
   if(d)
     {

        rp=new vecto;

      vecto line_v=Vecto_SS.Vector_SUB(pb,pa);
      line_v.normalize();


        *rp=line_v;
        rp->mults(*d);
        rp->va(pa);

     }

   return rp;


}



vecto* lp_intersect(float a,float b,float c, float d,vecto sp,vecto ep)
{

   vecto* rp=NULL;

   vecto l=Vecto_SS.Vector_SUB(ep,sp);




   vecto nl;

   nl.x=l.x*a;
   nl.y=l.y*b;
   nl.z=l.z*c;

   vecto nlo;

   nlo.x=sp.x*a;
   nlo.y=sp.y*b;
   nlo.z=sp.z*c;

   if(nl.x+ nl.z+nl.y)
   {
      rp=new vecto;

      float de=(-d-nlo.x-nlo.y-nlo.z)/(nl.x+ nl.z+nl.y);
      *rp=sp;


      l.mults(de);
      rp->va(l);

   }




   return rp;


}

float sdist_point_plane(float a,float b,float c, float d,vecto sp)
{
   vecto nlo;
   nlo.x=sp.x*a;
   nlo.y=sp.y*b;
   nlo.z=sp.z*c;

 float  distp=sqrt(a*a+b*b+c*c);

   if(distp)

   return (-d-nlo.x-nlo.y-nlo.z)/distp;

  return NULL;

}

float dist_point_plane(float a,float b,float c, float d,vecto sp)
{

   vecto nlo;
   nlo.x=sp.x*a;
   nlo.y=sp.y*b;
   nlo.z=sp.z*c;

 float  distp=sqrt(a*a+b*b+c*c);

   if(distp)
   return Math.absinth(-d-nlo.x-nlo.y-nlo.z)/distp;

   return -1;


}

















#endif // VECTORIZATION_H
