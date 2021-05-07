#ifndef TEXT_THING_H
#define TEXT_THING_H
#include"my_image.h"
#include"special_arrays.h"
#include"math_sandus.h"



struct Letters
{
 image tu[70];


 int SizeL;
 int ws,hs;
 int wa,ha;


 image use;
 char* c;


int text(char* s,int w,int h,int sizeL,int ii,int jj)
{
  int k=len(s,'\0')-1;
  for(int i=1;i<=k;i++)
   if(letter(s[k],w,h,sizeL,ii,jj))return 10;
}

int letter(char a,int ii,int jj,int x=0,int y=0,int sizeL=1)
 {

    Special_arrays::Char u;
    u="C:/Users/andercou/Desktop/FONTS/";
    u+=a;


    if((a>='A' && a<='Z')||(a>='0' &&  a<='9')){u+=".jpg";}
   if( a>='a' && a<='z')
    {u+="(2).jpg";}

    cout<<u.word;
    use.load_image5(u.word);
    use.reshapeI(use.height/sizeL,use.width/sizeL);

    for(int i=1;i<=use.height;i++)
   for(int j=1;j<=use.width;j++)
    if(use.choose(i,j).color<17&& ii==i+x && jj==j+y)
      return 2;
 }

};









#endif // TEXT_THING_H
