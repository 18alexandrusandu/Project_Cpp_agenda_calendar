#include<iostream>
#include<fstream>
#include"math-motions/math_sandus.h"
#include<string.h>
#include<time.h>
#include"encoding.h"
using namespace std;




int main()
{


srand(time(NULL));

ifstream f("encod.txt");
cout<<"merge"<<endl;
char s[50];
f.getline(s,49);

f.close();
int op;

ifstream g(s);

char s1[100],*s2,s3[100];

g>>op;
if(op==1)
{

   g.get();
   g.getline(s1,99);
   g.get();

   char* s2=encode(s1);
   g.close();

   ofstream g2(s);
   g2<<s2<<endl;
   g2.close();

}

if(op==2)
{
   g.get();
   g.getline(s1,99);
//cout<<s1<<endl;

   g.getline(s3,99);
//cout<<s3<<endl;
   g.close();

   ofstream g2(s);
   g2<<issame(s1,s3);

   g2.close();

}




}
