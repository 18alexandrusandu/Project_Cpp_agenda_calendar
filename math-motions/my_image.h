#ifndef MY_IMAGE_H
#define MY_IMAGE_H

#include"images/ss.h"

#include"math_sandus.h"

#include"special_arrays.h"






 struct vect4
 {
   int r,g,b,a;

 }Crefs[256]={{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},
 {1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},
 {0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,0,128,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,0,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},
 {0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{0,128,128,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,0,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},
 {128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,0,128,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{128,128,0,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{190,190,190,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},
 {128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},
 {128,128,128,0},{128,128,128,0},{128,128,128,0},{128,128,128,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,0,255,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,0,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{0,255,255,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,0,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,50,0,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},{255,0,255,0},
 {255,255,0,0}, {255,255,0,0}, {255,255,0,0},{255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0},{255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0}, {255,255,0,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0},{255,255,255,0}
 };


struct Color
{

 unsigned char r,g,b,a2=1;
 unsigned char color;
 void operator=(vect4 a)
{
    r=a.r;
    b=a.b;
    g=a.g;
    a2=a.a;
}
double* aRGBA()
{
double* u=new double[12];
u[1]=r;u[2]=g;u[3]=b;u[4]=a2;u[5]=color;//double u[7]=x,u[8]=y,u[9]=u,u[10]=v
return u;
}

int RGBc(float a,float bi,float c,float a3=0)
{

float u=0,m=255,n=3;

a2=Math.ap(map12(a3,u,m,u,n));

r=Math.ap(map12(a,u,m,u,n));

g=Math.ap(map12(bi,u,m,u,n));

b=Math.ap(map12(c,u,m,u,n));


//cout<<r<<" "<<g<<" "<<b<<endl;

if(a2==0)a2=0;
if(a2==1)a2=112;
if(a2==2)a2=128;
if(a2==3)a2=245;

if(r==0)r=2;
else
if(r==1)r=192;
else
if(r==2)r=64;
else
if(r==3)r=245;


if(b==0)b=2;
else
if(b==1)b=176;
else
if(b==2)b=16;
else
if(b==3)b=245;

if(g==0)g=3;
else
if(g==1)g=160;
else
if(g==2)g=32;
else
if(g==3)g=245;

//cout<<r<<" "<<g<<" "<<b<<endl;
color=r+g+b+a2;
return color;

}


int RGBc4(float a,float bi,float c,float a3=1)
{




float u=0,m=255,n=4;


if(a3!=0)
{
   a=a/a3;
   bi=bi/a3;
   c=c/a3;


}



if(a==bi && bi==c && a==128)
{
   color=128;
   return color;

}

if(a==bi && bi==c && a==190)
{
   color=112;
   return color;

}




if(!(a==bi && bi==c))
{

   if(a==255)
   {

if(a==c && a!=0)
    a=abs(a-128);

if(a==bi && a!=0 )
   a=abs(a-128);

if(bi==c && bi!=0)
   c=abs(c-128);
   }
}


//cout<<endl<<a<<" "<<bi<<" "<<c<<endl;

a2=Math.ap(map12(a3,u,m,u,n));

r=Math.ap(map12(a,u,m,u,n));

g=Math.ap(map12(bi,u,m,u,n));

b=Math.ap(map12(c,u,m,u,n));






//cout<<endl<<r<<" "<<g<<" "<<b<<endl;

//cout<<r<<" "<<g<<" "<<b<<endl;

if(a2==0)a2=0;
if(a2==1)a2=112;
if(a2==2)a2=128;
if(a2==3)a2=245;


if(r==0)r=2;
else
if(r==1 || r==2 )r=64;
else
if(r==3 || r>=4)r=192;



if(b==0 )b=2;
else
if(b==1 || b==2)
b=16;
else
if(b==3 || b==4)b=144;


if(g==0)g=3;
else
if(g==2|| g==1)g=32;
else
if(g==3 || g>=4) g=160;


//cout<<r<<" "<<g<<" "<<b<<endl;
color=(r+g+b);


return color;

}



int RGBc5(float a,float bi,float c,float a3=1)
{

r=a;
g=bi;
b=c;


float u=0,m=255,n=4;


if(a3!=0)
{
   a=a/a3;
   bi=bi/a3;
   c=c/a3;


}



if(a==bi && bi==c && a==128)
{
   color=128;
   return color;

}

if(a==bi && bi==c && a==190)
{
   color=112;
   return color;

}




if(!(a==bi && bi==c))
{

   if(a==255)
   {

if(a==c && a!=0)
    a=abs(a-128);

if(a==bi && a!=0 )
   a=abs(a-128);

if(bi==c && bi!=0)
   c=abs(c-128);
   }
}


//cout<<endl<<a<<" "<<bi<<" "<<c<<endl;

int a21=Math.ap(map12(a3,u,m,u,n));

int r1=Math.ap(map12(a,u,m,u,n));

int g1=Math.ap(map12(bi,u,m,u,n));

int b1=Math.ap(map12(c,u,m,u,n));






//cout<<endl<<r<<" "<<g<<" "<<b<<endl;

//cout<<r<<" "<<g<<" "<<b<<endl;

if(a2==0)a21=0;
if(a2==1)a21=112;
if(a2==2)a21=128;
if(a2==3)a21=245;


if(r1==0)r1=2;
else
if(r1==1 || r1==2 )r1=64;
else
if(r1==3 || r1>=4)r1=192;



if(b1==0 )b1=2;
else
if(b1==1 || b1==2)
b1=16;
else
if(b1==3 || b1==4)b1=144;


if(g1==0)g1=3;
else
if(g1==2|| g1==1)g1=32;
else
if(g1==3 || g1>=4) g1=160;


//cout<<r<<" "<<g<<" "<<b<<endl;
color=(r1+g1+b1)%256;


return color;

}


int RGBc5()
{
float a=r,
bi=g,
c=b,
a3=a2;


float u=0,m=255,n=4;


if(a3!=0)
{
   a=a/a3;
   bi=bi/a3;
   c=c/a3;


}



if(a==bi && bi==c && a==128)
{
   color=128;
   return color;

}

if(a==bi && bi==c && a==190)
{
   color=112;
   return color;

}




if(!(a==bi && bi==c))
{

   if(a==255)
   {

if(a==c && a!=0)
    a=abs(a-128);

if(a==bi && a!=0 )
   a=abs(a-128);

if(bi==c && bi!=0)
   c=abs(c-128);
   }
}


//cout<<endl<<a<<" "<<bi<<" "<<c<<endl;

int a21=Math.ap(map12(a3,u,m,u,n));

int r1=Math.ap(map12(a,u,m,u,n));

int g1=Math.ap(map12(bi,u,m,u,n));

int b1=Math.ap(map12(c,u,m,u,n));






//cout<<endl<<r<<" "<<g<<" "<<b<<endl;

//cout<<r<<" "<<g<<" "<<b<<endl;

if(a2==0)a21=0;
if(a2==1)a21=112;
if(a2==2)a21=128;
if(a2==3)a21=245;


if(r1==0)r1=2;
else
if(r1==1 || r1==2 )r1=64;
else
if(r1==3 || r1>=4)r1=192;



if(b1==0 )b1=2;
else
if(b1==1 || b1==2)
b1=16;
else
if(b1==3 || b1==4)b1=144;


if(g1==0)g1=3;
else
if(g1==2|| g1==1)g1=32;
else
if(g1==3 || g1>=4) g1=160;


//cout<<r<<" "<<g<<" "<<b<<endl;
color=(r1+g1+b1)%256;


return color;

}



void blend()
{
   color=r+g+b+a2;

}





int red()
{
   return r;
}
int green()
{
   return g;
}

int blue()
{
   return b;
}


void operator() (float a,float b,float c,float a3=0)
{
  RGBc5(a,b,c,a3);

}


void  s (float a,float bi,float c,float a3=0)
{
 r=a;g=bi;b=c;a2=a3;

}



  float Clin(float srgb)
   { double t=0;
   if(srgb>1)srgb=srgb/255;
      if(srgb<=1)
      {
         if(srgb<=0.04045)t=srgb/12.92;
          else
           t=sqrm((srgb+0.055)/1.055,2.4);

      }

   }
  int Ylin()
   {
     float y;
     y=0.2146*Clin(r)+0.7125*Clin(g)+0.0722*Clin(b);
     y=y*255;
   }


   Color trc(int i)
{

   Color c1;
   int n=i%256;
   c1.color=i;

   c1.r=Crefs[n].r;
     c1.g=Crefs[n].g;
   c1.b=Crefs[n].b;
    c1.a2=Crefs[n].a;





return c1;
}


int RGBc2(float a,float bi,float c,float a3=0)
{

r=a;b=c;g=bi;a2=a3;
float u=0,m=255,n=3;
float r,g,b,a2;

a2=Math.ap(map12(a3,u,m,u,n));

r=Math.ap(map12(a,u,m,u,n));

g=Math.ap(map12(bi,u,m,u,n));

b=Math.ap(map12(c,u,m,u,n));

//cout<<r<<" "<<g<<" "<<b<<endl;

if(a2==0)a2=0;
if(a2==1)a2=112;
if(a2==2)a2=128;
if(a2==3)a2=245;

if(r==0)r=2;
else
if(r==1)r=192;
else
if(r==2)r=64;
else
if(r==3)r=245;


if(b==0)b=2;
else
if(b==1)b=176;
else
if(b==2)b=16;
else
if(b==3)b=245;

if(g==0)g=3;
else
if(g==1)g=160;
else
if(g==2)g=32;
else
if(g==3)g=245;

//cout<<r<<" "<<g<<" "<<b<<endl;
color=r+g+b+a2;


return color;

}


void operator *=(double x)
{
   float rf=r;
   float gf=g;
   float bf=b;

   rf=rf*x;
   gf=gf*x;
   bf=bf*x;

   r=rf;
   g=gf;
   b=bf;

}
Color operator *(double x)
{
   float rf=r;
   float gf=g;
   float bf=b;

   rf=rf*x;
   gf=gf*x;
   bf=bf*x;
   Color t;

   t.r=rf;
   t.g=gf;
   t.b=bf;
   return t;
}

Color operator +(Color x)
{
  Color c;
  c.r=x.r+r;
  c.g=x.g+g;
  c.b=x.b+b;
  return c;

}
void  operator +=(Color x)
{
  r=x.r+r;
  g=x.g+g;
  b=x.b+b;

}



float Colorimetric(int i)
{
   float rf,gf,bf;

  rf=(float)r/256;
  gf=(float)g/256;
  bf=(float)b/256;




//cout<<"fff:"<<rf<<" "<<gf<<" "<<bf<<endl;


   if(i==1)
   {
      if(rf<=0.04)
         return rf/12.92;
      else
        return pow( (rf+0.055)/1.055,2.4);

   }



   if(i==2)
    if(gf<=0.04)
         return gf/12.92;
      else
        return pow( (gf+0.055)/1.055,2.4);



   if(i==3)
       if(bf<=0.04)
         return bf/12.92;
      else
        return pow( (bf+0.055)/1.055,2.4);


return 0;


}


float liniar_lumY()
{



   return 0.2126*Colorimetric(1)+0.71*Colorimetric(2)+0.07*Colorimetric(3);

}

float brightness()
{
float C1=(float)r/255;
float C2=(float)g/255;
float C3=(float)b/255;

   return 0.2126*C1+0.71*C2+0.07*C3;

}
///level between -255 and 255
float F_corection(float level)
{
  float C=(float)(259*(level+255))/(255*(259-level));

    r=max(min(C*(float)(r-128)+128,(float)255),(float)0);
    g=max(min(C*(float)(g-128)+128,(float)255),(float)0);
    b=max(min(C*(float)(b-128)+128,(float)255),(float)0);
     RGBc5();
  return C;

}


float G_corection(float alpha=1,float ab=0)
{

    r=max(min(alpha*(float)(r-128)+128+ab,(float)255),(float)0);
    g=max(min(alpha*(float)(g-128)+128+ab,(float)255),(float)0);
    b=max(min(alpha*(float)(b-128)+128+ab,(float)255),(float)0);
     RGBc5();
  return alpha;

}





float liniar_lumY2()
{
   if(liniar_lumY()<0.003)
   return 12.92*liniar_lumY();
   else
   return 1.055*pow(liniar_lumY(),1.0/2.4)-0.055;


}










}color;

float greys(double x)
{
   int pos[5]={0,128,112,240};

   if(x<0)
   x=-x;

   while(x>1.0)
     x=x/10;

   if(x<0.33)
      return pos[0];

   if(x>=0.33 && x<0.70)
      return pos[1];

    if(x>=0.70 && x<0.95)
      return pos[2];

     if(x>=0.95 && x<=1)
      return pos[3];



}












struct image
{

  Color* pixels=NULL;
  int width;
  int height;
  int nx=0,ny=0;
  Color backg;
  int system_type=1;


void operator()(int i,int j)
{
if(pixels)
    free(pixels);
pixels=NULL;
pixels=new Color[i*j+1];
if(!pixels)
    printf("no pixels\n");
for(int k=1;k<=i*j;k++)
pixels[k].color=0;



height=i;
width=j;

}

void operator+=(image a)
{

   for(int i=1;i<=height;i++)
   for(int j=1;j<=width;j++)
   pixels[(i-1)*width+j].color+=a.pixels[(i-1)*width+j].color;





}













void space(int i,int j)
{

pixels=new Color[(i+1)*j];
//cout<<"space"<<"h"<<i<<" "<<"width"<<j<<endl<<endl;
height=i;
width=j;
//cout<<"gata"<<endl;
system("cls");

}


void fill_null( Color* ni,int x,int y,int pc=0)
{

   for(int i=1;i<=x*y;i++)
   {
      ni[i].color=pc;
      ni[i].r=pc;
      ni[i].g=pc;
      ni[i].b=pc;

   }



}
///input between -255 and 255
void F_corection(int level)
{
for(int i=1;i<=height*width;i++)
 pixels[i].F_corection(level);

}

void G_corection(float alpha=1,float ab=0)
{
for(int i=1;i<=height*width;i++)
 pixels[i].G_corection(alpha,ab);

}




void reshapeI(int x,int y)
{
Color* ni=NULL;
ni=new Color[x*y+1];
fill_null(ni,x,y);


double sw=(double)y/width;
double sh=(double)x/height;

if(pixels)
if(sh<=1 && sw<=1)
{

   for(int i=1;i<=height;i++)
   for(int j=1;j<=width;j++)
{

   int p1=Math.ap((double)i*sh);int p2=Math.ap((double)j*sw);
   //cout<<i<<" "<<j<<" "<<p1<<" "<<p2<<" "<<(p1-1)*y+p2<<endl;
   if(p1>0 && p2>0)
   ni[abs((int)(p1-1)*y+p2)]=pixels[(i-1)*width+j];

}

}
else
{
if(sh>1)
    sh=Math.ap(sh);

    if(sw>1)
    sw=Math.ap(sw);

     for(int i=1;i<=x;i++)
      for(int j=1;j<=y;j++)
      {
          int p1,p2;
          if(sh>=1)
        int p1=Math.ap((double)i/sh);
             else
        int p1=Math.ap((double)i*sh);

        if(sw>=1)
        int p2=Math.ap((double)j/sw);
        else
        int p2=Math.ap((double)j*sw);

     if(p1>0 && p2>0)
   ni[(i-1)*y+j]=pixels[(p1-1)*width+p2];

      }

}




   height=x;
   width=y;
   if(pixels)
  free(pixels);
   pixels=ni;
}
void reshapeI3(int x,int y)
{
Color* ni=NULL;
ni=new Color[(x+2)*(y+2)];
fill_null(ni,x+1,y+1,255);


double sw=(double)y/width;
double sh=(double)x/height;

int p1,p2,p3,p4;
//printf("sizes:%d %d -> %d %d\n",width,height,y,x);
//system("pause");

for(float i=1;i<=max(height,x);i+=1)
for(float j=1;j<=max(width,y);j+=1)
{
    if(sh<=1)
        {
            p3=i;
            p1=ceil(i*sh);

        }
      if(sw<=1)
        {
           p4=j;
           p2=ceil(j*sw);
        }

        if(sh>1)
        {   p3=ceil(i/sh);
            p1=i;

        }
       if(sw>1)
        {
            p2=j;
            p4=ceil(j/sw);
        }
       // printf("%d %d %d %d\n",p1,p2,p3,p4);
        //Sleep(1000);
        if(pi<=x && p3<=height && p2<=y && p4<=width && pi>=1 && p3>=1 && p2>=1 && p4>=1)
              ni[(p1-1)*y+(p2)]=pixels[(p3-1)*width+p4];






}

   height=x;
   width=y;
   if(pixels)
  free(pixels);
   pixels=ni;
}



image* image_copy()
{

   image* j=new image;

j->height=height;
j->width=width;

   j->pixels=new Color[nr_pix()+10];

   for(int i=1;i<=nr_pix();i++)
    j->pixels[i]=pixels[i];


return j;
}
void increase_size(int x,int y)
{
Color* ni=NULL;
ni=new Color[(x+2)*(y+2)];
fill_null(ni,x+1,y+1);



    int sh=floor((double)x/height);
    int sw=floor((double)y/width);

          // printf("sw sh %d %d\n",sh,sw);
         // system("pause");

    for(int i=1;i<=height;i++){
    for(int j=1;j<=width;j++)
    {   int p1=(i-1)*sh;
        int p2=(j-1)*sw;

        for(int ifill=0;ifill<=sh;ifill++)
        for(int jfill=0;jfill<=sw;jfill++)
        {     if(p1+ifill<=x && p2+jfill<=y)
        {
            //if(sh-ifill<ifill && sw-jfill<jfill)
            ni[(p1+ifill)*y+p2+jfill]=pixels[(i-1)*width+j];
           /* else
             if(sh-ifill>=ifill && sw-jfill<jfill)
             {
                if(i!=height)
            ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i)*width+j];
                 else
            ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i-1)*width+j];

             }
             else
              if(sh-ifill<ifill && sw-jfill>=jfill){
                 if(j!=width)
                 ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i-1)*width+j+1];
                 else
                 ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i-1)*width+j];
             }
             else
                if(i!=height && j!=width)
            ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i)*width+j+1];
                else
            ni[(p1+ifill-1)*y+p2+jfill]=pixels[(i-1)*width+j];
            */
        }
        }
        ;
    }
    }

   height=x;
   width=y;
   if(pixels)
  free(pixels);
   pixels=ni;

}




void reshapeI2(int x,int y)
{




Color* ni;

ni=new Color[x*y+1];
cout<<"color"<<endl;
return ;

fill_null(ni,x,y);


double sh=(double)y/height;
double sw=(double)x/width;



   for(int i=1;i<=height;i++)
   for(int j=1;j<=width;j++)
{

   int p1=Math.ap((double)i*sh);int p2=Math.ap((double)j*sw);
   //cout<<i<<" "<<j<<" "<<p1<<" "<<p2<<" "<<(p1-1)*y+p2<<endl;


   if(p1>0 && p2>0)
   {

   for(int iF=Math.ap(sh*(i-1));iF<=Math.ap(sh*i);iF++)
   for(int jF=Math.ap(sw*(j-1));jF<=Math.ap(sw*j);jF++)


   //if(abs(Math.ap(sh*(i-1))-iF)<abs(Math.ap(sh*i-iF)))
    ni[abs((int)(iF-1)*x+jF)]=pixels[(i-1)*width+j];






    ni[abs((int)(p1-1)*x+p2)]=pixels[(i-1)*width+j];


   }


}
   height=y;
   width=x;
   delete pixels;
   pixels=ni;
}

template<typename T>
void liniar_transf(T a)
{
   for(int i=1;i<=height;i++)
    for(int j=1;j<=width;j++)
    {
       float rn=choose(i,j).r*a[1][1]+choose(i,j).g*a[1][2]+choose(i,j).b*a[1][3];
       float gn=choose(i,j).r*a[2][1]+choose(i,j).g*a[2][2]+choose(i,j).b*a[2][3];
       float bn=choose(i,j).r*a[3][1]+choose(i,j).g*a[3][2]+choose(i,j).b*a[3][3];

       choose(i,j).r=min(rn,(float)255);
       choose(i,j).g=min(gn,(float)255);
       choose(i,j).b=min(bn,(float)255);
       choose(i,j).RGBc5();
    }

}










template<typename T>
void convolute(T ker,int n,float k=0)
{

   image t=*image_copy();


    for(int i=1;i<=height;i++)
     for(int j=1;j<=width;j++)
  {

   choose(i,j).color=0;
   choose(i,j).r=0;
   choose(i,j).g=0;
   choose(i,j).b=0;
   int nrp=0;

     for(int l=1;l<=n;l++)
     for(int k=1;k<=n;k++)
     {
        if(i+l-n/2>0 && j+k-n/2>0  && i+l-n/2<=height && j+k-n/2<=width)
        {

   choose(i,j).color+=t.pixels[index(i+l-n/2,j+k-n/2)].color*ker[l][k];
   choose(i,j).r+=t.pixels[index(i+l-n/2,j+k-n/2)].r*ker[l][k];
   choose(i,j).g+=t.pixels[index(i+l-n/2,j+k-n/2)].g*ker[l][k];
   choose(i,j).b+=t.pixels[index(i+l-n/2,j+k-n/2)].b*ker[l][k];
     nrp++;

        }

     }


     if(nrp!=0)
     {
        if(k==0)
         k=n*n;

   choose(i,j).color/=k;
   choose(i,j).r/=k;
   choose(i,j).g/=k;
   choose(i,j).b/=k;
     }


  }
  delete t.pixels;
}
template<typename T>
void convolute2(T ker,int n,float k=0)
{

   image t=*image_copy();


    for(int i=1;i<=height;i++)
     for(int j=1;j<=width;j++)
  {

   choose(i,j).color=0;
   choose(i,j).r=0;
   choose(i,j).g=0;
   choose(i,j).b=0;
   int nrp=0;

     for(int l=0;l<n;l++)
     for(int k=0;k<n;k++)
     {
        if(i+l-n/2>0 && j+k-n/2>0  && i+l-n/2<=height && j+k-n/2<=width)
        {

   choose(i,j).color+=t.pixels[index(i+l-n/2,j+k-n/2)].color*ker[l][k];
   choose(i,j).r+=t.pixels[index(i+l-n/2,j+k-n/2)].r*ker[l][k];
   choose(i,j).g+=t.pixels[index(i+l-n/2,j+k-n/2)].g*ker[l][k];
   choose(i,j).b+=t.pixels[index(i+l-n/2,j+k-n/2)].b*ker[l][k];
     nrp++;

        }

     }


     if(nrp!=0)
     {
        if(k==0)
         k=n*n;

   choose(i,j).color/=k;
   choose(i,j).r/=k;
   choose(i,j).g/=k;
   choose(i,j).b/=k;
     }
  }

delete t.pixels;
}


 //choose(i,j)=color.trc(choose(i,j).color);


double** sepia(int nr=3)
{

   return make_mat<double>(3,3,.393,.769,.189,
                         .349,.686,.168,
                         .272,.534,.131);

}









template<typename T,typename P>
void sobel_type(T ker,P ker2,int n,float k=0)
{
   image t=*image_copy();


    for(int i=1;i<=height;i++)
     for(int j=1;j<=width;j++)
  {

   float Gx=0, Gy=0;
   float Gxr=0, Gyr=0;
   float Gxg=0 ,Gyg=0;
   float Gxb=0, Gyb=0;



   int nrp=0;

     for(int l=1;l<=n;l++)
     for(int k=1;k<=n;k++)
     {
        if(i+l-n/2>0 && j+k-n/2>0  && i+l-n/2<=height && j+k-n/2<=width)
        {



   Gx+=t.pixels[index(i+l-n/2,j+k-n/2)].color*ker[l][k];
   Gy+=t.pixels[index(i+l-n/2,j+k-n/2)].color*ker2[l][k];

   Gxr+=t.pixels[index(i+l-n/2,j+k-n/2)].r*ker[l][k];
   Gyr+=t.pixels[index(i+l-n/2,j+k-n/2)].r*ker2[l][k];

   Gxg+=t.pixels[index(i+l-n/2,j+k-n/2)].g*ker[l][k];
   Gyg+=t.pixels[index(i+l-n/2,j+k-n/2)].g*ker2[l][k];

   Gxb+=t.pixels[index(i+l-n/2,j+k-n/2)].b*ker[l][k];
   Gyb+=t.pixels[index(i+l-n/2,j+k-n/2)].b*ker2[l][k];



   }

     }


   choose(i,j).color=sqrt(Gx*Gx+Gy*Gy);
   choose(i,j).r=sqrt(Gxr*Gxr+Gyr*Gyr);
   choose(i,j).g=sqrt(Gxg*Gxg+Gyg*Gyg);
   choose(i,j).b=sqrt(Gxg*Gxg+Gyg*Gyg);

  }



 //choose(i,j)=color.trc(choose(i,j).color);
delete t.pixels;
}




template<typename T>
void sobel_multy(T kers,int nk,int n,float k=0)
{
   image t=*image_copy();

    for(int i=1;i<=height;i++)
     for(int j=1;j<=width;j++)
  {


   float G[(nk+1)]={0};
   float Gr[(nk+1)]={0};
   float Gg[(nk+1)]={0};
   float Gb[(nk+1)]={0};


   int nrp=0;

     for(int l=1;l<=n;l++)
     for(int k=1;k<=n;k++)
     {
        if(i+l-n/2>0 && j+k-n/2>0  && i+l-n/2<=height && j+k-n/2<=width)
        {


    for(int z=1;z<=nk;z++)
   {
       G[z]+=t.pixels[index(i+l-n/2,j+k-n/2)].color*kers[z][l][k];
       Gr[z]+=t.pixels[index(i+l-n/2,j+k-n/2)].r*kers[z][l][k];
       Gg[z]+=t.pixels[index(i+l-n/2,j+k-n/2)].g*kers[z][l][k];
       Gb[z]+=t.pixels[index(i+l-n/2,j+k-n/2)].b*kers[z][l][k];
   }

        }}

   float cs,rs,gs,bs;
     for(int z=1;z<=nk;z++)
   {
       cs+=G[z]*G[z];
       rs+=Gr[z]*Gr[z];
       gs+=Gg[z]*Gg[z];
       bs+=Gb[z]*Gb[z];
   }





   choose(i,j).color=sqrt(cs);
   choose(i,j).r=sqrt(rs);
   choose(i,j).g=sqrt(gs);
   choose(i,j).b=sqrt(bs);

}

delete t.pixels;

  }


template<typename T>
void kirsch_multy(T kers,int nk,int n,float k=0)
{
   image t=*image_copy();

    for(int i=1;i<=height;i++)
     for(int j=1;j<=width;j++)
  {

   float gcs=0,grs=0,ggs=0,gbs=0;

   int nrp=0;
 for(int z=0;z<nk;z++)
 {  float cs=0,rs=0,gs=0,bs=0;
     for(int l=1;l<=n;l++)
     for(int k=1;k<=n;k++)
     {
        if(i+l-n/2>0 && j+k-n/2>0  && i+l-n/2<=height && j+k-n/2<=width)
        {



       cs+=t.pixels[index(i+l-n/2,j+k-n/2)].color*kers[z][l][k];
       rs+=t.pixels[index(i+l-n/2,j+k-n/2)].r*kers[z][l][k];
       gs+=t.pixels[index(i+l-n/2,j+k-n/2)].g*kers[z][l][k];
       bs+=t.pixels[index(i+l-n/2,j+k-n/2)].b*kers[z][l][k];
       }

        }

        gcs=max(cs,gcs);
        grs=max(rs,grs);
        ggs=max(gs,ggs);
        gbs=max(bs,gbs);
}
   choose(i,j).color=gcs;
   choose(i,j).r=grs;
   choose(i,j).g=ggs;
   choose(i,j).b=gbs;

  }

delete t.pixels;
}























void crop_smart(int fx,int fy,int tx,int ty)
{

/*
   image t;
   t(abs(ty-fy+1),tx-fx+1);
   for(int i=fy;i<=ty;i++)
     for(int j=fx;j<=tx;j++)
   t.choose(i-fy+1,j-fx+1)=choose(i,j);
   */
/*
   if(fy>1)
for(int i=fy;i<=ty;i++)
     for(int j=fx;j<=tx;j++)
   choose(i,j)=choose(fy-1,j);
   else
      if(fx>1)
   for(int i=fy;i<=ty;i++)
     for(int j=fx;j<=tx;j++)
   choose(i,j)=choose(i,fx-1);
   else
*/
   for(int i=fy;i<=ty;i++)
     for(int j=fx;j<=tx;j++)
   {choose(i,j).color=0;
    choose(i,j).r=0;
    choose(i,j).g=0;
    choose(i,j).b=0;
   }


//return t;


}






image* image_copy2(int fx=1,int fy=1,int tx=-1,int ty=-1)
{

   image* j=new image;

   j->space(ty-fy+1,tx-fx+1);



 for(int i=1;i<=ty-fy;i++)
    for(int k=1;k<=tx-fx;k++)
    j->choose(i,k)=choose(fy+i,fx+k);

return j;
}

image* empti(int h,int w, int clr=0)
{
   image* im=(image*)malloc(sizeof(image));

   im->operator()(h,w);
   for(int i=1;i<=h*w;i++)
     im->pixels[i]=Crefs[clr];
return im;
}











void unique_change(int ctc,int ctr,int dir=1)
{


   for(int i=1;i<=height*width;i++)
   {
     // pixels[i].RGBc5();
      //cout<<pixels[i].color<<" ";

      if((pixels[i].color<ctc && dir>0 ) || (pixels[i].color>ctc && dir<0 ))
{
    pixels[i]=pixels[i].trc(ctr);
   pixels[i].color=ctr;

}



   }
}





void set_bkc(Color a)
{
   cout<<"h"<<height<<" "<<"w"<<width<<endl;



   for(int i=1;i<=height;i++)
      for(int j=1;j<=width;j++)
      pixels[(i-1)*width+j]=a;

      backg=a;
}









void set_bkcs(Color a)
{
   for(int i=1;i<=height;i++)
      for(int j=1;j<=width;j++)
      {
         int d=0;
      if(pixels[(i-1)*width+j].color==backg.color)
      if(pixels[(i-1)*width+j-1].color==backg.color)
      d=1;
       else
       if(pixels[(i-1)*width+j+1].color==backg.color)
      d=1;
       else
       if(pixels[(i)*width+j].color==backg.color)
      d=1;
       else
      if(pixels[(i-2)*width+j].color==backg.color)
      d=1;
       if(d)pixels[(i-1)*width+j]=a;
      }

      backg=a;


}







Color& choose(int i,int j)
{

return pixels[(i-1)*width+j];

}

   void make_grayall()
{
for(int i=1;i<=nr_pix();i++)
{

pixels[i].r=pixels[i].a2;
pixels[i].b=pixels[i].a2;
pixels[i].g=pixels[i].a2;
}
}

   void load_image(char a[])
   {

      ifstream f;
      f.open(a);
      f>>width;
      f>>height;
       pixels=new Color[(width+1)*(height+1)];

      for(int i=1;i<=width*height && !f.eof();i++)
      {

          f>>pixels[i].r;f>>pixels[i].g;f>>pixels[i].b;
         pixels[i].blend();


      }
   }




void addct(int n,int ru=1,int gu=1,int bu=1,int au=1 )
   {
      for(int i=1;i<=nr_pix();i++)
      {
      if(ru==1)pixels[i].r+=n;
      if(gu==1)pixels[i].g+=n;
      if(bu==1)pixels[i].b+=n;
      if(au==1)pixels[i].a2+=n;
      }

   }


   void load_image5(char s[],int x=0,int y=0)
{

Image_use* rbi;

int w=0,h=0,bp=0;

rbi=stbi_load(s,&h,&w,&bp,3);


h+=x;w+=y;


operator()(h,w);

cout<<"bpp"<<bp<<endl;

width=h;height=w;


for(int i=1;i<=h;i++)
   for(int j=1;j<=w;j++)
     // for(int b=0;b<bp;b++)

{
if(bp==3)
{
choose(i,j).r=rbi[((i-1)*h+j-1)*bp+0];
choose(i,j).g=rbi[((i-1)*h+j-1)*bp+1];
choose(i,j).b=rbi[((i-1)*h+j-1)*bp+2];
}
else
if(bp==1)
{
choose(i,j).r=rbi[((i-1)*h+j-1)*bp];
choose(i,j).g=rbi[((i-1)*h+j-1)*bp];
choose(i,j).b=rbi[((i-1)*h+j-1)*bp];
}


}

blend_all2();
cout<<"gata";

stbi_image_free(rbi);
}



   void load_image7(char s[],int x=0,int y=0)
{

Image_use* rbi=NULL;

int w=0,h=0,bp=0;
int bps=-1;


while(rbi==NULL || bp!=bps)
{
if(rbi)
free(rbi);
rbi=NULL;
bps++;
rbi=stbi_load(s,&w,&h,&bp,bps);
//printf("%d",bp);

//printf("%p\n",rbi);
}


//printf("ok\n");


h+=x;w+=y;


operator()(h+1,w+1);
//printf("asta %d %d %d\n",bp,w,h);

//cout<<"bpp"<<bp<<" "<<bps<<" "<<h<<" "<<w<<endl;

width=w;height=h;
//free(rbi);
//return;
//free(rbi);
//return;

for(int i=1;i<=h;i++)
   for(int j=1;j<=w;j++)
     // for(int b=0;b<bp;b++)





{



   if(bp==4)
{
choose(i,j).r=rbi[((i-1)*w+j-1)*bp+0];
choose(i,j).g=rbi[((i-1)*w+j-1)*bp+1];
choose(i,j).b=rbi[((i-1)*w+j-1)*bp+2];
}
else
if(bp==3)
{
choose(i,j).r=rbi[((i-1)*w+j-1)*bp+0];
choose(i,j).g=rbi[((i-1)*w+j-1)*bp+1];
choose(i,j).b=rbi[((i-1)*w+j-1)*bp+2];
}
else
if(bp==1)
{
choose(i,j).r=rbi[((i-1)*w+j-1)*bp];
choose(i,j).g=rbi[((i-1)*w+j-1)*bp];
choose(i,j).b=rbi[((i-1)*w+j-1)*bp];
}


}



//blend_all3();

//printf("asta e buna\n");
//if(rbi)

free(rbi);
//printf("asta e buna2\n");
//cout<<"ready\n";
//delete rbi;
}





void replace_color(int c1,int d,int c2=-7)
{
    if(c2<0)
      c2=c1+c2;

    blend_all3();
   vect4 Vc=Crefs[d];
   color(Vc.r,Vc.g,Vc.b);
    Color col_rep=color;

    for(int i=1;i<=height;i++)
        for(int j=1;j<=width;j++)
            if(pixels[(i-1)*width+j].color>c2 && pixels[(i-1)*width+j].color<c1)
              pixels[(i-1)*width+j]=col_rep;
}










Image_use* send_back_vector(int nr_ch=3)
{
   Image_use* rbi=new  Image_use[height*width*12];

for(int i=1;i<=height;i++)
   for(int j=1;j<=width;j++)
   {
      rbi[((i-1)*width+j-1)*nr_ch+0]=choose(i,j).r;
      rbi[((i-1)*width+j-1)*nr_ch+1]=choose(i,j).g;
      rbi[((i-1)*width+j-1)*nr_ch+2]=choose(i,j).b;
   }


return rbi;


}


void make_new_picture(char* name,int ch=3,int p=1,int jpq=100)
{

   if(p==1)
   stbi_write_png(name,width,height,ch,send_back_vector(),width*ch);
   else
   if(p==2)
    stbi_write_jpg(name,width,height,ch,send_back_vector(),jpq);


}









   void load_image2(char a[],int ru=1,int gu=1,int bu=1,int alp=0)
   {
      ifstream f;
      f.open(a);
      f>>width;
      f>>height;
       pixels=new Color[(width+1)*(height+1)];

      for(int i=1;i<=width*height && !f.eof();i++)
      {  if(ru==1)
          f>>pixels[i].r;
         if(gu==1)
          f>>pixels[i].g ;
          if(bu==1)
        f>>pixels[i].b;
          if(alp==1)
       f>>pixels[i].a2;
         pixels[i].RGBc(pixels[i].r,pixels[i].g,pixels[i].b,pixels[i].a2);
      }
   }

void load_image3(char a[],int h,int w,int ru=1,int gu=1,int bu=1,int alp=0)
   {
      ifstream f;
      f.open(a);
       width=w;
       height=h;
       pixels=new Color[(width+1)*(height+1)];

      for(int i=1;i<=width*height && !f.eof();i++)
      {  if(ru==1)
          f>>pixels[i].r;
         if(gu==1)
          f>>pixels[i].g ;
          if(bu==1)
        f>>pixels[i].b;
          if(alp==1)
       f>>pixels[i].a2;
         pixels[i].RGBc(pixels[i].r,pixels[i].g,pixels[i].b,pixels[i].a2);
      }
   f.close();

   }



image* load_images(char a[],int& ni,int h=0,int w=0,int ru=1,int gu=1,int bu=1,int alp=0)
{
   int nuse=100;
   int aci=0;
   image* res=new image[nuse+3];
    ifstream f;
      f.open(a);
      if(h!=0 && w!=0)
      {
       width=w;
       height=h;
      }
      else
      {
         f>>height;
         f>>width;
      }


      while(!f.eof())
   { aci++;
        // cout<<aci<<" "<<!f.eof()<<endl;
         if(aci>nuse)
         {
            image* es=new image[nuse+nuse+2];
            for(int i=1;i<aci;i++)
            es[i]=res[i];
            delete[] res;
             res=es;
            nuse+=nuse;
         }

         res[aci].height=height;
         res[aci].width=width;
      res[aci].pixels=new Color[(width+1)*(height+1)];
      for(int i=1;i<=width*height && !f.eof();i++)
      {  if(ru==1)
          f>>res[aci].pixels[i].r;
         if(gu==1)
          f>>res[aci].pixels[i].g ;
          if(bu==1)
        f>>res[aci].pixels[i].b;
          if(alp==1)
       f>>res[aci].pixels[i].a2;
         res[aci].pixels[i].RGBc(res[aci].pixels[i].r,res[aci].pixels[i].g,res[aci].pixels[i].b,res[aci].pixels[i].a2);
         //cout<<i<<" ";
      }
      //cout<<endl<<endl;
}



f.close();

ni=aci;
return res;
}



image* load_imagess(char a[],int& ni,int h=0,int w=0,int ru=1,int gu=1,int bu=1,int alp=0)
{
   int nuse=100;
   int aci=0;
   image* res=new image[nuse+3];
    ifstream f;
      f.open(a);
      if(h!=0 && w!=0)
      {
       width=w;
       height=h;
      }
      else
      {
         f>>height;
         f>>width;
      }


      while(!f.eof())
   { aci++;
        // cout<<aci<<" "<<!f.eof()<<endl;
         if(aci>nuse)
         {
            image* es=new image[nuse+nuse+2];
            for(int i=1;i<aci;i++)
            es[i]=res[i];
            delete[] res;
             res=es;
            nuse+=nuse;
         }

         res[aci].height=height;
         res[aci].width=width;
      res[aci].pixels=new Color[(width+1)*(height+1)];
      for(int i=1;i<=width*height && !f.eof();i++)
      {  if(ru==1)
          f>>res[aci].pixels[i].r;
         if(gu==1)
          f>>res[aci].pixels[i].g ;
          if(bu==1)
        f>>res[aci].pixels[i].b;
          if(alp==1)
       f>>res[aci].pixels[i].a2;
         //res[aci].pixels[i].RGBc(res[aci].pixels[i].r,res[aci].pixels[i].g,res[aci].pixels[i].b,res[aci].pixels[i].a2);
      }
      if(ru==0 && gu==0 && bu==0 && alp==1)res[aci].make_grayall();

      if(aci%500==0)
      {
cout<<"done"<<aci<<"/"<<ni<<" "<<(double)aci/ni*100<<"%"<<endl<<endl<<endl;
system("cls");
cout<<"done"<<aci<<"/"<<ni<<" "<<(double)aci/ni*100<<"%"<<endl<<endl<<endl;
      }

   }
;
/*
if(aci%100==0)




}
*/

f.close();

ni=aci;
return res;
}


int nr_pix()
{
return width*height;
}


void blend_all()
{
for(int i=1;i<=width*height;i++)
   pixels[i].RGBc( pixels[i].r, pixels[i].g, pixels[i].b, pixels[i].a2);
}

void blend_all2(int a3=0 ,int ri=1,int gi=1,int b1=0)
{



for(int i=1;i<=width*height;i++)
   pixels[i].RGBc4( pixels[i].r, pixels[i].g, pixels[i].b, pixels[i].a2);


}


void blend_all3(int a3=0 ,int ri=1,int gi=1,int b1=0)
{
for(int i=1;i<=width*height;i++)
  pixels[i].RGBc5( pixels[i].r, pixels[i].g, pixels[i].b, pixels[i].a2);


}







int index(int x,int y)
{
   return  (x-1)*width+y;

}



# define GRAY 128

  void renderer1()
   {

      for(int i=1;i<=height;i++)
      {

       for(int j=1;j<=width;j++)
       {
         cl(1,1,pixels[(i-1)*width+j].color);
         cout<<" ";

       }
       cl(1,1,7);
       cout<<endl;
      }
   }





  void renderer2(int x=0,int y=0)
   {

    HWND myconsole =GetConsoleWindow();

    //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;


      for(int i=1;i<=height;i++)
       for(int j=1;j<=width;j++)
       {
          ;

          int r=pixels[index(i,j)].red();
          int b=pixels[index(i,j)].blue();
          int g=pixels[index(i,j)].green();
          int alp=pixels[index(i,j)].a2;
          COLOR=RGB(r,g,b);

          SetPixel(mydc,x+i,y+j,COLOR);
       }



     ReleaseDC(myconsole, mydc);
    cin.ignore();
   }

void renderer4(int ca=0,int x=0,int y=0)
   {
  if(x!=0)
    nx=x;

    if(y!=0)
    ny=y;



 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {
//if(pixels[(i-1)*width+j].color<ca-15 || pixels[(i-1)*width+j].color>ca+15)
       {
         Color u=color.trc(pixels[(i-1)*width+j].color);
         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,nx+j,ny+i,COLOR);
       }

      }
   }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }


   void renderer5(int ca=0,int x=0,int y=0)
   {
  if(x!=0)
    nx=x;

    if(y!=0)
    ny=y;



 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {



         Color u=pixels[(i-1)*width+j];

         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,nx+j,ny+i,COLOR);

      }
   }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }



void renderer7(int ca=0,int x=0,int y=0)
{
if(system_type==1)
renderer4(ca,x,y);
else
renderer5(ca,x,y);

}




   void renderer9(int ca=0,int x=0,int y=0)
   {

     nx=x;
     ny=y;

 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;

      for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {

   //if( ((i<y && y>0)|| y==0) && ((j<x && x>0)|| x==0))
       {

       //if(pixels[(i-1)*width+j].color<ca-15 || pixels[(i-1)*width+j].color>ca+15)
{


         Color u=color.trc(pixels[(i-1)*width+j].color);
         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,nx+j,ny+i,COLOR);
}}

      }
   }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }


   void renderer10(int ca=0,int x=0,int y=0)
   {


     nx=x;
     ny=y;

 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {

        // if( ((ny+i<=y && y>0)|| y==0) && ((nx+j<=x && x>0)|| x==0))
       {


         Color u=pixels[(i-1)*width+j];
         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,nx+j,ny+i,COLOR);


       }
       }
      }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }












void renderer11(int ca=0,int x=0,int y=0)
{
if(system_type==1)
renderer9(ca,x,y);
else
renderer10(ca,x,y);

}



void rendererStar(int fx=1,int fy=1,int tx=-1,int ty=-1,int x=0,int y=0,int ca=0)
   {
  if(tx<0)
     tx=width;
   if(ty<0)
     ty=height;


 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=fy;i<=ty;i++)
      {
       for(int j=fx;j<=tx;j++)
       {

        // if( ((ny+i<=y && y>0)|| y==0) && ((nx+j<=x && x>0)|| x==0))
       {
                       int n=(i-fy)*tx+j;
        printf("%d %d %d ;",pixels[n].r ,pixels[n].g ,pixels[n].b);

       }
       }
       printf("\n");
      }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }


void renderer13(int fx=1,int fy=1,int tx=-1,int ty=-1,int x=0,int y=0,int ca=0)
   {
  if(tx<0)
     tx=width;
   if(ty<0)
     ty=height;


 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=fy;i<=ty;i++)
      {
       for(int j=fx;j<=tx;j++)
       {

        // if( ((ny+i<=y && y>0)|| y==0) && ((nx+j<=x && x>0)|| x==0))
       {


         Color u=pixels[(i-1)*width+j];
         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,x+j,y+i,COLOR);


       }
       }
      }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }

void renderer12(int fx=1,int fy=1,int tx=-1,int ty=-1,int x=0,int y=0,int ca=0)
   {
  if(tx<0)
     tx=width;
   if(ty<0)
     ty=height;


 //cout<<"hello"<<endl;
HWND myconsole =GetConsoleWindow();

   //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;
    //Choose any color
    COLORREF COLOR;





      for(int i=fy;i<=ty;i++)
      {
       for(int j=fx;j<=tx;j++)
       {

         if( ((ny+i<=y && y>0)|| y==0) && ((nx+j<=x && x>0)|| x==0))
       {


          Color u=color.trc(pixels[(i-1)*width+j].color);
         COLOR=RGB(u.r,u.g,u.b);
        SetPixel(mydc,nx+j,ny+i,COLOR);


       }
       }
      }

   ReleaseDC(myconsole, mydc);
   //cin.ignore();

   }



void renderer14(int fx=1,int fy=1,int tx=-1,int ty=-1,int x=0,int y=0,int ca=0)
{
if(system_type==1)
renderer12(fx,fy,tx,ty,x,y,ca);
else
renderer13(fx,fy,tx,ty,x,y,ca);

}



void flip(int c)
{


   int ni;
      image ri;
      ri=*image_copy();

      for(int i=1;i<=height;i++)
    for(int j=1;j<=width;j++)
         {
              if(c=='h')
             ni=(i-1)*width+(width-j+1);


             if(c=='v')
             ni=(height-i+1)*width+j;


            pixels[(i-1)*width+j]=ri.pixels[ni];


         }
delete ri.pixels;
}



void inverse_colors()
{



      for(int i=1;i<=height;i++)
    for(int j=1;j<=width;j++)
         {

        pixels[(i-1)*width+j].color=256-pixels[(i-1)*width+j].color%256;

         pixels[(i-1)*width+j].r=255-pixels[(i-1)*width+j].r%256;
         pixels[(i-1)*width+j].g=255-pixels[(i-1)*width+j].g%256;
         pixels[(i-1)*width+j].b=255-pixels[(i-1)*width+j].b%256;


         //pixels[(i-1)*width+j]=color.trc(nc);





         }
}



double*** pictureTodouble()
{
    double*** rez=(double***)malloc(sizeof(double**)*3);
    for(int i=0;i<3;i++)
    rez[i]=(double**)malloc(sizeof(double*)*height);

     for(int i=0;i<3;i++)
    for(int j=0;j<height;j++)
      rez[i][j]=(double*)malloc(sizeof(double)*width);

      for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    rez[0][i][j]=choose(i+1,j+1).r;

         for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    rez[1][i][j]=choose(i+1,j+1).g;

    for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    rez[2][i][j]=choose(i+1,j+1).b;
return rez;
}




void doubleTopic(int h,int w, double** rds,double** grs,double** bls)
{

    operator()(h,w);


      for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    choose(i+1,j+1).r=rds[i][j];

         for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    choose(i+1,j+1).g=grs[i][j];

    for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
    choose(i+1,j+1).b=bls[i][j];

}








Color* transI()
{
Color* np=new Color[(width+1)*(height+1)];
for(int i=1;i<=height;i++)
   for(int j=1;j<=width;j++)
   np[index(j,i)]=pixels[index(i,j)];
   return np;


}

void transmI()
{
Color* np=new Color[(width+1)*(height+1)];

int w=width,h=height;

for(int i=1;i<=h;i++)
   for(int j=1;j<=w;j++)
   {
   np[(j-1)*h+i]=pixels[(i-1)*w+j];

   }

   pixels=np;
   int aux=width;
   width=height;
   height=aux;
}

double*reds()
{
   double* re=new double[width*height+2];
    for(int i=1;i<=width*height;i++)
   re[i]=pixels[i].r;
   re[0]=width*height;
return re;
}

double*greens()
{
     double* re=new double[width*height+2];
    for(int i=1;i<=width*height;i++)
   re[i]=pixels[i].g;

re[0]=width*height;

return re;

}


double*blue()
{
       double* re=new double[width*height+2];
    for(int i=1;i<=width*height;i++)
   re[i]=pixels[i].b;
   re[0]=width*height;
return re;

}

double*alphas()
{
     double* re=new double[width*height+2];
    for(int i=1;i<=width*height;i++)
   re[i]=pixels[i].a2;
   re[0]=width*height;

return re;

}

double*colors()
{
     double* re=new double[width*height+2];
    for(int i=1;i<=width*height;i++)
   re[i]=pixels[i].color;
   re[0]=width*height;
return re;
}






void show_structure()
{

    for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {
     cl(1,1,pixels[index(i,j)].color);
      cout<<index(i,j)<<"now: "<<pixels[index(i,j)].r<<" "<<pixels[index(i,j)].g<<" "<<pixels[index(i,j)].b<<" "<<pixels[index(i,j)].color<<" ";
     cl(1,1,RGB(pixels[index(i,j)].r,pixels[index(i,j)].g,pixels[index(i,j)].b));
      cout<<"real"<<" ";
      cl(1,1,pixels[index(i,j)].r+pixels[index(i,j)].g+pixels[index(i,j)].b);
      cout<<"try"<<endl;


      }

cout<<endl;

}

}







   void filter(int a)
   {
      if(a==128)
      for(int i=1;i<=height;i++)
      {
       for(int j=1;j<=width;j++)
       {
      float u=pixels[index(i,j)].Ylin();

      if(u<20)pixels[index(i,j)].color=0;
       else
      if(u<50)pixels[index(i,j)].color=112;
       else
      if(u<255/2)pixels[index(i,j)].color=128;
      if(u>255/2)pixels[index(i,j)].color=255;
      }

   }

   }

image get(int x=1,int y=1,int w=0,int h=0)
   {
      image res;
      if(w==0)w=width;
      if(h==0)h=height;

      res(w,h);
      Color b;

      b.s(0,0,0);
      res.set_bkc(b);

      for(int i=x;i<=x+w;i++)
         for(int j=y;j<=y+h;j++)

      res.choose(i,j)=this->choose(i,j);

   }


void set_grey1()
{
   for(int i=1;i<=height*width;i++)
   {
      float rn,gn,bn;
      rn=pixels[i].liniar_lumY2()*255;
      gn=pixels[i].liniar_lumY2()*255;
      bn=pixels[i].liniar_lumY2()*255;
      pixels[i].r=rn;
      pixels[i].g=gn;
      pixels[i].b=bn;
      pixels[i].RGBc5();

   }
}





};







typedef MOUSEHOOKSTRUCT MouseSS;

void turn_a(float& x,float&y,float angle,float rad)
{

 x=x+rad*Math.cosa(angle);
 y=y+rad*Math.sina(angle);


}



float lerp(float a, float b, float amt)
{


if(amt<=100 && amt>1)
   amt=map12(amt,(float)0,(float)100,(float)0,(float)1);


return a+(b-a)*amt;



;}



int mouseX()
{


POINT p;

HWND a;
GetCursorPos(&p);


RECT rect;

HWND hwnd=GetConsoleWindow();

GetWindowRect(hwnd, &rect);






return p.x-rect.left-12;

}







struct Mouse
{


POINT mp={0,0};
int sets=0;

HWND R;
LPRECT lr;


 void find_pos()
{

int t=200;
cout<<"please move the cursor up Î to the left corner of the window"<<endl;
system("pause");
   GetCursorPos(&mp);
cout<<"gata";
system("cls");
sets=1;

}


void set_pos()
{

   POINT u={0,0};

R=GetConsoleWindow();
ClientToScreen(R,&u);
mp=u;
sets=1;

}



};


int mouseY()
{

      RECT rect;
HWND hwnd=GetConsoleWindow();

GetWindowRect(hwnd, &rect);


POINT p;
HWND a;
GetCursorPos(&p);

return p.y-rect.top-30;


}




int wmouseX(Mouse* a)
{
POINT p;


if(a->sets==1)
{

GetCursorPos(&p);

return p.x-a->mp.x;
}
   cout<<"mouse invalid"<<endl;
return mouseX();

}



int wmouseY(Mouse* b)
{
POINT p;
if(b->sets==1)
{

HWND a;
GetCursorPos(&p);
ScreenToClient(a,&p);

return p.y-b->mp.y;
}
else cout<<"mouse invalid"<<endl;
return mouseY();
}




int mouse_pressed()
{
   if((GetKeyState(VK_LBUTTON) & 0x80)  !=0 || (GetKeyState(VK_RBUTTON) & 0x80)!=0 )
   return 1;

   return 0;



}

void mouse_pressedd(void (*f)(double u)=NULL,double u=0)
{
   if((GetKeyState(VK_LBUTTON) & 0x80)  !=0 || (GetKeyState(VK_RBUTTON) & 0x80)!=0 )
  {
     cout<<"pressed"<<endl;
  if(f)
  f(u);

  }



}



void mouse_draggedd(void (*f)(double u)=NULL,double u=0,int hm=100)
{


int du=0;
du=(GetKeyState(VK_LBUTTON) & 0x80);
if(du==0)
du=(GetKeyState(VK_RBUTTON) & 0x80);




int i=hm;
int ni=0;
  while(du!=0&& ni<i)
{//cout<<"dragged"<<endl;
  du=0;
  system("cls");

  if(f)
  {
     cout<<"f"<<endl;
     f(u);
  }

  du=(GetKeyState(VK_LBUTTON) & 0x80);
  if(du==0)
  du=(GetKeyState(VK_RBUTTON) & 0x80);

  //cout<<du<<endl;
Sleep(100);
ni++;

}


}


void mouse_switch(void (*f)(double u)=NULL,double u=0)
{
int du=0;
   if((GetKeyState(VK_LBUTTON) & 0x80)!=0 || (GetKeyState(VK_RBUTTON) & 0x80)!=0 )
   {
      du=1;
  cout<<"switched_up"<<endl;
system("cls");
      while((GetKeyState(VK_LBUTTON) & 0x80)!=0 ||(GetKeyState(VK_RBUTTON) & 0x80)!=0 );
        // cout<<"kiki do you love me?"<<endl;

int k=0;

      while(du!=0)
      {

      if((GetKeyState(VK_LBUTTON) & 0x80)!=0 ||(GetKeyState(VK_RBUTTON) & 0x80)!=0 )
      du=0;
      if(du!=0)
        { k++;
           f(k);
        }
        else
        {
      cout<<"switched_down"<<k<<endl;
system("pause");
system("cls");
        }
   }}}


void mouse_switch(void (*f)(int u)=NULL,int u=0)
{
int du=0;
   if((GetKeyState(VK_LBUTTON) & 0x80)!=0 || (GetKeyState(VK_RBUTTON) & 0x80)!=0 )
   {
      du=1;
  cout<<"switched_up"<<endl;
system("cls");
      while((GetKeyState(VK_LBUTTON) & 0x80)!=0 ||(GetKeyState(VK_RBUTTON) & 0x80)!=0 );
        // cout<<"kiki do you love me?"<<endl;

int k=0;

      while(du!=0)
      {

      if((GetKeyState(VK_LBUTTON) & 0x80)!=0 ||(GetKeyState(VK_RBUTTON) & 0x80)!=0 )
      du=0;
      if(du!=0)
        { k++;
           f(k);
        }
        else
        {
      cout<<"switched_down"<<k<<endl;
system("pause");
system("cls");
        }
   }}}







void mouse_released(void (*f)(double u)=NULL,double u=0)
{

if(!mouse_pressed())
if(f)
f(u);
}


struct Sprite
{
   Llist<image> source;

   int animated=false;

   int used_animation=0;

   image* Animate()
   {

      if(animated)
      {

         if(used_animation<source.nr)
         {

            used_animation++;

            image* rs;
         rs=&source[used_animation];


         }

      if(used_animation>=source.nr)
       used_animation=0;

      }
      else
      {
         if(source.nr>0)
         {
         image* rs;
         rs=&source[1];
         return rs;
         }



      }

    return NULL;
   }







};


double** sepia(int nr=3)
{

 return make_mat<double>(3,3,.393,.769,.189,
                         .349,.686,.168,
                         .272,.534,.131);

}

double** grey_mat(int nr=3)
{

return  make_mat<double>(3,3,.333,.333,.333,
                             .333,.333,.333,
                             .333,.333,.333);

}












double** Average_ker(int n=3,float k=1)
{
   double** G=new double*[n+2];
   for(int i=1;i<=n;i++)
   G[i]=new double[n+2];


   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
   G[i][j]=k/(n*n);

   return G;
}
template<typename T>
double** Variance_filt(T A,int d1,int d2,int n=3,float k=1)
{
   double** G=new double*[d1+2];
   for(int i=0;i<=d1;i++)
   G[i]=new double[d2+2];
    int ne=0;
   for(int i=0;i<d1;i++)
    for(int j=0;j<d2;j++)
    { ne=0;
         double avg=0;
         double avgv=0;
       for(int i2=0;i2<n;i2++)
       for(int j2=0;j2<n;j2++)
                  if(i+i2-1>=0 && i+i2-1<d1 && j+j2-1>=0 && j+j2-1<d2)
                  {  ne++;
                     avg+=A[i+i2-1][j+j2-1];
                  }

           avg=avg/(ne);

            for(int i2=0;i2<n;i2++)
       for(int j2=0;j2<n;j2++)
             if(i+i2-1>=0 && i+i2-1<d1 && j+j2-1>=0 && j+j2-1<d2)
                avgv+=(A[i+i2-1][j+j2-1]-avg)*(A[i+i2-1][j+j2-1]-avg);
             avgv=avgv/ne;
            G[i][j]=avgv;
    }

   return G;
}







double** Gaussian(int n,double sigma=0)
{
   double** G=new double*[n+2];

   for(int i=1;i<=n;i++)
   G[i]=new double[n+2];

   //float sigma=
   if(!sigma)
   sigma=0.3*(n/2-1)+0.8;
 // 1.0;
  //;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {

       float is=(n/2-i+1);
       float js=(n/2-j+1);

      G[i][j]=exp(-(is*is +js*js)/(2*sigma*sigma))/(2*pi*sigma*sigma);
    }




 float q=1.01/G[1][1];

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      G[i][j]=floor(G[i][j]*q);
    }




   return G;


}







template<typename T>
double nr_matrix(T a,int n,int m=0)
{
   if(m==0)
      m=n;
      double d=0;
      for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    d+=a[i][j];

   return d;
}
double** Gabor_filter(double mag,int x,int  y,double sigma,double theta,double gamma,double lambda,double psi)
{





    double** gf=(double**)malloc(sizeof(double)*(y+1));
    for(int i=0;i<=y;i++)
        gf[i]=(double*)malloc(sizeof(double)*(x+1));

    for(int i=0;i<y;i++)
    for(int j=0;j<x;j++)
    {

        int i_s=i-y/2;

        int j_s=j-x/2;



         double i_t=j_s*cos(theta)+i_s*sin(theta);
         double j_t=-j_s*sin(theta)+i_s*cos(theta);
        gf[i][j]=mag*exp(-i_t*i_t/(sigma*sigma)-j_t*j_t*gamma*gamma/(sigma*sigma))*cos(2*pi*i_t/lambda+psi);



    }

return gf;


}




template<typename T>
double matrix_mean(T a,int n,int m=0)
{
   if(m==0)
      m=n;
      double d=0;
      for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    d+=a[i][j];
    d=d/(n*m);

   return d;
}

///nr must be odd
double** sobel_x(double* x=NULL,int nr=3)
{
   double** G=new double*[nr+2];
   for(int i=1;i<=nr;i++)
   G[i]=new double[nr+2];

   for(int i=1;i<=nr;i++)
    for(int j=1;j<=nr;j++)
   {
   if(nr%2==1)
     {
         float sgn=(nr/2+1)-j;

        if(x==NULL)
      G[i][j]=sgn*(nr/2+1-abs(nr/2+1-i));
       else
       {
          int p=i%(nr/2+1);
          if(p==0)
            p=nr/2+1;

          G[i][j]=sgn*x[p];
       }






     }
   }

return G;
}


///nr must be odd
double** sobel_y(double* x=NULL,int nr=3)
{
   double** G=new double*[nr+2];
   for(int i=1;i<=nr;i++)
   G[i]=new double[nr+2];


 for(int i=1;i<=nr;i++)
    for(int j=1;j<=nr;j++)
   {
  if(nr%2==1)
      {
         float sgn=(nr/2+1)-i;

           if(x==NULL)
          G[i][j]=sgn*(nr/2+1-abs(nr/2+1-j));
           else
           {
          int p=j%(nr/2+1);
          if(p==0)
            p=nr/2+1;


              G[i][j]=sgn*x[p];

           }




          }}

   return G;

}
double** kirsch_base(double* x=NULL,int nr=3)
{
   double** G=new double*[nr+2];
   for(int i=1;i<=nr;i++)
   G[i]=new double[nr+2];
 for(int i=1;i<=nr;i++)
  for(int j=1;j<=nr;j++)
    G[i][j]=0;

    for(int i=1;i<=nr;i++)
      {G[1][i]=5;
       G[nr][i]=-3;
      }

    for(int j=2;j<nr;j++)
   {G[j][1]=-3;
    G[j][nr]=-3;
   }


   return G;

}


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

template<typename T>
void rotate_matrix_45(T a,int n,int m)
{
    int cM=m-1,cm=0,cN=n-1,cn=0;
do{
    double k=a[cn][cm];

    for(int i=cm;i<=cM;i++)
     a[cn][i]=a[cn][i+1];

     double k2=a[cN][cm];

      for(int i=cN;i>cn;i--)
      a[i][cm]=a[i-1][cm];

    a[cn+1][cm]=k;



      k=a[cN][cM];
    for(int i=cM;i>cm;i--)
      a[cN][i]=a[cN][i-1];

      a[cN][cm+1]=k2;


    for(int i=cn;i<cN;i++)
    a[i][cM]=a[i+1][cM];
     a[cN-1][cM]=k;

     cN=cN-1;
     cM=cM-1;
     cm=cm+1;
     cn=cn+1;

}while(cN>cn && cm<cM);



}
template<typename T>
void rotate_matrix_452(T a,int n,int m)
{
    int cM=m,cm=1,cN=n,cn=1;
do{
    double k=a[cn][cm];

    for(int i=cm;i<=cM;i++)
     a[cn][i]=a[cn][i+1];

     double k2=a[cN][cm];

      for(int i=cN;i>cn;i--)
      a[i][cm]=a[i-1][cm];

    a[cn+1][cm]=k;



      k=a[cN][cM];
    for(int i=cM;i>cm;i--)
      a[cN][i]=a[cN][i-1];

      a[cN][cm+1]=k2;


    for(int i=cn;i<cN;i++)
    a[i][cM]=a[i+1][cM];
     a[cN-1][cM]=k;

     cN=cN-1;
     cM=cM-1;
     cm=cm+1;
     cn=cn+1;

}while(cN>cn && cm<cM);



}
template<typename T>
double*** Kirsch_matrixes(T A,int n)
{
    double*** rez=(double***)malloc(sizeof(double**)*(4*n-3));
    for(int i=0;i<4*n-3;i++)
     rez[i]=(double**)malloc(sizeof(double*)* (n+1));

      for(int i=0;i<4*n-3;i++)
       for(int j=0;j<n+1;j++)
      rez[i][j]=(double*)malloc(sizeof(double)*(n+1));

      int k=0;

      while(k<4*n-4)
      {

      for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      rez[k][i][j]=A[i][j];





      rotate_matrix_452(A,n,n);
      k++;
      }
return rez;
}


void Export_image(image I,char* fln)
{
    FILE* fl=fopen(fln,"w");
    int n=I.height*I.width;
    fprintf(fl,"%d %d %d\n",n,I.height,I.width);

    for(int i=1;i<=I.height;i++)
    for(int j=1;j<=I.width;j++)
     fprintf(fl,"%d %d %d\n",I.pixels[(i-1)*I.width+j].r,I.pixels[(i-1)*I.width+j].g,I.pixels[(i-1)*I.width+j].b);

     fclose(fl);
}

void Import_image(image* I,char* fln)
{
    FILE* fl=fopen(fln,"r");
  int n;
    fscanf(fl,"%d %d %d",&n,&I->height,&I->width);
I->operator()(I->height,I->width);




    for(int i=1;i<=I->height;i++)
    for(int j=1;j<=I->width;j++)
     fscanf(fl,"%d %d %d",&I->pixels[(i-1)*I->width+j].r,&I->pixels[(i-1)*I->width+j].g,&I->pixels[(i-1)*I->width+j].b);

     fclose(fl);
}











#endif // MY_IMAGE_H
