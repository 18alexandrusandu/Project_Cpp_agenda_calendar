#include<iostream>
#include<time.h>
#include<fstream>
#include<string.h>
#include"polinoame.h"
using namespace std;

int bigger(int a,int b)
{
    if(a>b)
        return 1;
    return 0;
}

void add_space(int n)
{
    for(int i=1; i<=n; i++)
        cout<<" ";

}


int bisect(int an)
{
    if(an%4==0 && (an%100!=0 || an%400==0 ))
    {

        return 1;
    }

    return 0;

}
int jul_bisect(int an)
{
    if(an%4==0 && an>4)
        return 1;

 if(an%3==0 && an<=-9)
 {
    return 1;
 }

    return 0;
}


int nr_days(int e,int an,int i=1)
{
   if(an>=-45)
   {
    if(e==2)
    {
        if(i==1)
        {
            if(bisect(an))
                return 29;
        }
        else
        {
             ;
            cout<<"bisect"<<endl;
            if(jul_bisect(an))
                return 29;
        }


        return 28;
    }
    else if( (e<8 && e%2==1) || (e>=8 && e%2==0))
        return 31;
    else
        return 30;
   }
   else
       if(e==2)
    {
        if(i==1)
        {
            if(bisect(e))
                return 29;
        }
        else
        {
             ;
            cout<<"bisect"<<endl;
            if(jul_bisect(e))
                return 29;
        }


        return 28;
    }
    else if( (e<8 && e%2==1) || (e>=8 && e%2==0))
        return 31;
    else
        return 30;




}




int begin_year(int start_year,int start_day, int end_year,int t=1)
{

    if(start_year<end_year)
    {

        for(int i=start_year; i<end_year; i++)
        {


            if( (!bisect(i)&& t==1)||(!jul_bisect(i)&& t!=1))
            {
                start_day=(start_day+1)%7;
                if(start_day==0)
                    start_day=7;

            }
            else
            {
                start_day=(start_day+2)%7;
                if(start_day==0)
                    start_day=7;
            }

        }

    }
    else
        for(int i=start_year-1; i>=end_year; i--)
        {

            if(i!=0)
                if( (!bisect(i)&& t==1) || (!jul_bisect(i)&& t!=1))
                {
                    start_day=(start_day-1)%7;
                    if(start_day==0)
                        start_day=7;

                }
                else
                {
                    start_day=(start_day-2)%7;
                    if(start_day<=0)
                        start_day=7+start_day;
                }


        }


    return start_day;
}


int week_day(int day,int mnt,int an,int bdw)
{

    int nd=0;

    int off;


    for(int i=1; i<mnt; i++)
    {
        nd+=nr_days(i,an);
    }



    return (bdw-1+nd+day)%7;



}






int restish(int f,int b)
{

    if(f==b)
        return b;
    else
        return f%b;

}

struct data_calendar
{
    int an;

    int protect=0;
    char pasw[255];

    resturi zi_saptamana;
    resturi luna;
    resturi zi;

    void make_data(int an2,int mon)
    {
        an=an2;
        zi_saptamana.n=7;
        luna.n=12;
        luna=mon;
        int e=luna+1;
        if(e==2)
        {
            if(
                (an>1582 && bisect(an)) ||
                (an<=1582 && jul_bisect(an))
            )
                zi.n=29;
            else
                zi.n=28;
        }
        else if((e<8 && e%2==1) || (e>=8 && e%2==0))
            zi.n=31;
        else
            zi.n=30;
    }

    void set_day(int dy)
    {
        if(dy>zi.n)
        {
            if(luna.x+1>12)
                make_data( an+1,1);
            else
                make_data(an,luna.x+1);

            zi=dy;

        }
        else
            zi=dy;
        zi_saptamana=week_day(dy,luna.x,an,begin_year(an,2,2019,bigger(an,1582)));
    }


    void set_month(int mt)
    {
        if(mt>12)
            make_data(an+mt/12,mt);
        else
            luna=mt;
    }

    int operator ==(data_calendar d)
    {

        int c=1;
        if(d.an!=an)
            c=0;
        if(d.luna.x!=d.luna.x)
            c=0;
        if(d.zi.x!=zi.x)
            c=0;
        return c;
    }





};


struct sticky_notes
{
    Llist<data_calendar> dt;
    Llist<char*> notes;

    int nr_notes()
    {
        return notes.size();
    }

    void add_note(int year,int month,int day,char* text,int pr=0,char* psw=NULL)
    {
        data_calendar nd;


        nd.make_data(year,month);
          nd.set_day(day);


                  if(pr)
        {
           nd.protect=1;
           strcpy(nd.pasw,psw);

        }



        dt.add(nd);

        char* nt=new char[strlen(text)+2];
        strcpy(nt,text);
        notes.add(nt);
    }


    void see_all_notes(int year,int month,int day)
    {
        int k=1;
        data_calendar nd;
        nd.make_data(year,month);
        nd.set_day(day);
        int psw=0;

        cout<<endl<<endl<<"Notes:"<<endl<<endl;

        for(int i=1; i<=dt.nr; i++)
        {
            if(dt[i]==nd)
            {


                cout<<k<<". ";
                if(dt[i].protect==0)
                cout<<notes[i]<<endl;
                else
                {

                  cout<<"protected"<<endl;
                  cout<<"do you want to input the pasword? YES-1/NO-0";
                  cin>>psw;
                  if(psw)
                  {
                     char try_pass[256];
                     cout<<"pasword:";
                     cin.get();
                     cin.get(try_pass,255);
                     cin.get();

               ofstream f;
                f.open("encod.txt");
                f<<"calendar.txt"<<endl;
                f.close();

                f.open("calendar.txt");

                f<<2<<endl;
                f<<try_pass<<endl;
                f<<dt[i].pasw<<endl;



                f.close();

                system("encoding.exe");

                system("pause");
               int num;
                ifstream g("calendar.txt");
                g>>num;
                g.close();

                     if(num)
                     {  //schimb culoare
                        cl(1,1,10);
                     cout<<"password correct:"<<endl;
                        cl(1,1,15);
                     cout<<notes[i]<<endl;
                     }
                     else
                     {        cl(1,1,12);
                          cout<<"pasword incorrect"<<endl;
                              cl(1,1,15);
                     }



                  }

                }



                  cout<<endl;

                k++;
            }

        }

   if(k==1)
cout<<"None"<<endl;

    }


    void see_years(int year)
    {

          ;
        cout<<"notes in "<<year<<":"<<endl<<endl;

        int k=1;
        for(int i=1; i<=dt.nr; i++)
            if(dt[i].an==year)
            {


                cout<<"date:"<<dt[i].zi.x<<"."<<dt[i].luna.x<<"."<<dt[i].an<<endl;
                cout<<k<<". ";
                if(dt[i].protect==0)
                cout<<notes[i]<<endl;
                else
                cout<<"protected"<<endl;


                k++;
                cout<<endl;
            }

         if(k==1)
            cout<<"None"<<endl;


    }



    void see_months(int year,int month)
    {
        int k=1;
          ;
        cout<<"notes on "<<month<<":"<<endl<<endl;
        for(int i=1; i<=dt.nr; i++)
            if(dt[i].an==year && dt[i].luna.x==month)
            {

                cout<<"date:"<<dt[i].zi.x<<"."<<dt[i].luna.x<<"."<<dt[i].an<<endl;
                 cout<<k<<". ";
                if(dt[i].protect==0)
                cout<<notes[i]<<endl;
                else
                cout<<"protected"<<endl;
                k++;
                cout<<endl;
            }



            if(k==1)
            cout<<"None"<<endl;

    }

    void see_everything()
    {

        cout<<endl<<"all notes"<<endl;

        if(dt.nr!=0)
        for(int i=1; i<=dt.nr; i++)
        {
              cout<<"date:"<<dt[i].zi.x<<"."<<dt[i].luna.x<<"."<<dt[i].an<<endl;
              if(dt[i].protect==0)
              cout<<notes[i]<<endl;
              else
              cout<<"protected"<<endl;
              cout<<endl;
        }
        else
         cout<<"None"<<endl;


    }


};


struct calendar
{


   Llist<data_calendar> heighlight;
    sticky_notes mementos;


    void add_memento(int year,int month,int day,char* text,int psw=0,char* paw=NULL)
    {
        mementos.add_note(year, month,day,text,psw,paw);
    }





    void delete_memento(int year,int month,int day,int i=0)
    {
        int n=mementos.dt.nr;
        if(i==0)
        {

            for(int j=1; j<=n; j++)
                if(mementos.dt[j].an==year && mementos.dt[j].zi.x==day && mementos.dt[j].luna.x==month)
                {
                    mementos.dt.delete_ind(j);
                    j--;
                    mementos.notes.delete_ind(j);
                    n--;
                }
        }
        else
        {
            for(int j=1; j<=n; j++)
                if(mementos.dt[j].an==year && mementos.dt[j].zi.x==day && mementos.dt[j].luna.x==month)
                {
                    if(i==1)
                    {
                        mementos.dt.delete_ind(j);
                        mementos.notes.delete_ind(j);
                          j--;
                        n--;
                    }
                    else
                        i--;
                }

        }
    }

    void delete_all_memento()
    {
        int n=mementos.dt.nr;



        for(int j=1; j<=n; j++)
        {
            mementos.dt.delete_ind(j);
            j--;
            mementos.notes.delete_ind(j);
            n--;
        }


    }

    void delete_all_memento_month(int mnt,int yr)
    {
        int n=mementos.dt.nr;

        for(int j=1; j<=n; j++)
            if(mementos.dt[j].luna.x==mnt && mementos.dt[j].an==yr)
            {
                mementos.dt.delete_ind(j);
                j--;
                mementos.notes.delete_ind(j);
                n--;
            }
    }

    void delete_all_memento_year(int yr)
    {
        int n=mementos.dt.nr;

        for(int j=1; j<=n; j++)
            if(mementos.dt[j].an==yr)
            {
                mementos.dt.delete_ind(j);
                j--;
                mementos.notes.delete_ind(j);
                n--;
            }
    }


    void see_year(int year)
    {
        mementos.see_years(year);
    }

    void see_month(int year,int month)
    {
        mementos.see_months(year,month);
    }


    void see_mementos(int year,int month,int day)
    {
        mementos.see_all_notes(year, month,day);
    }

    void make_heighlight(int yr=0,int mnt=0,int dy=0)
    {
         heighlight.nr=0;
       if(yr==0 && mnt==0 && dy==0)
       {
          for(int i=1;i<=mementos.dt.nr;i++)
          heighlight.add(mementos.dt[i]);
       }
       else
       {

         if(yr!=0 && mnt==0)
       {
            for(int i=1;i<=mementos.dt.nr;i++)
               if(mementos.dt[i].an==yr)
          heighlight.add(mementos.dt[i]);
       }

            if(yr!=0 && mnt!=0 && dy==0)
       {
            for(int i=1;i<=mementos.dt.nr;i++)
               if(mementos.dt[i].an==year && mementos.dt[i].luna.x==mnt)
          heighlight.add(mementos.dt[i]);
       }

            if(yr!=0 && mnt!=0 && dy!=0)
       {
            for(int i=1;i<=mementos.dt.nr;i++)
               if(mementos.dt[i].an==yr && mementos.dt[i].luna.x==mnt && mementos.dt[i].luna.x && mementos.dt[i].zi.x==dy)
          heighlight.add(mementos.dt[i]);
       }
    }
    }
int isheighlighted(int yr,int mnt,int dy)
{

   int c=0;

for(int i=1;i<=heighlight.nr;i++)
   { if(heighlight[i].an==yr && heighlight[i].luna.x==mnt  && heighlight[i].zi.x==dy)
      c=1;
   }
   return c;
}



    void see_mementos()
    {
        mementos.see_everything();
    }

    int ref_year=2019;
    int ref_day_week=2;

    int year=2019;

    int ref_year2=1582;
    int ref_day_week2=1;

    int week_dayc(int day,int mnt,int an)
    {
        if(year>1582)
            return week_day(day,mnt,an,begin_year(ref_year,ref_day_week,an));
        else
            return week_day(day,mnt,an,begin_year(ref_year2,ref_day_week2,an));
    }


    void show_month(int i,int other=0,int yr=0)
    {
        if(other==1)
            year=yr;
            int ki=i;
        cl(1,1,15);
        i=restish(i,12);
        if(year>=1583)
        {
            //cout<<i<<" "<<week_dayc(1,i,year)<<endl;

            int bd=week_dayc(1,i,year);
            if(bd==0)
                bd=7;


            int nd=nr_days(i,year);

            int j=0;
             ;

            cout<<"L  M  M  J  V  S  S"<<endl;
             ;

            for(int i=1; i<=7; i++)
            {

                if(i<bd)
                    cout<<" "<<"  ";
                else
                {
                   j++;
                   cl(1,isheighlighted(year,ki,j),12);
                    cout<<j<<"  ";

                   cl(1,1,15);
                    bd++;
                }
            }


            bd=1;


            j++;
            cout<<endl;

            while(j<=nd)
            {
                    cl(1,isheighlighted(year,ki,j),12);
                cout<<j<<" ";
                     cl(1,1,15);
                if(j<10)
                    cout<<" ";

                j++;
                if(bd%7==0)
                {
                    cout<<endl;

                }

                bd=restish(bd+1,7);


            }


        }
        else
        {
            cout<<i<<" "<<week_dayc(1,i,year)<<endl;

            int bd= week_day(1,1,year,begin_year(ref_year2,ref_day_week2,year,2));

            if(bd==0)
                bd=7;

            int nd=nr_days(i,year,2);

            int j=0;

            cout<<"L  M  M  J  V  S  S"<<endl;
            for(int i=1; i<=7; i++)
            {
                if(i<bd)
                    cout<<" "<<"  ";
                else
                {
                      cl(1,isheighlighted(year,ki,j),12);
                cout<<j<<" ";
                     cl(1,1,15);
                     j++;
                    bd++;
                }
            }


            bd=1;


            j++;
            cout<<endl;

            while(j<=nd)
            {
                cl(1,isheighlighted(year,ki,j),12);
                cout<<j<<" ";
                  cl(1,1,7);
                if(j<10)
                    cout<<" ";

                j++;
                if(bd%7==0)
                    cout<<endl;

                bd=restish(bd+1,7);

            }
        }
        cout<<endl;
    }

    void show_year(int other=0,int yr=0)
    {
         system("cls");
        if(other==1)
            year=yr;
         if(bisect(year))
            cout<<"this year is bisect"<<endl;
        cout<<"year:"<<year<<endl;
        for(int i=1; i<=12; i++)
        {
            cout<<"Month "<<i<<endl;

            show_month(i);
            cout<<endl<<endl;
        }

        cout<<"      ^  V   \n ";
              system("pause");


           if(GetAsyncKeyState(VK_DOWN))
               show_year(1,year+1);
            if(GetAsyncKeyState(VK_UP))
               show_year(1,year-1);


    }





    void show_years(int a,int b,int rate=10000)
    {
        for(int i=a; i<=b; i++)
        {
            year=i;

            show_year();
            Sleep(rate);
            system("cls");

        }

    }

    void send_update()
    {
         ofstream cal("cal.txt");

         cal<<mementos.nr_notes()<<endl;

      for(int i=1;i<=mementos.dt.nr;i++)
      {
                cal<<mementos.dt[i].protect<<endl;

                if(mementos.dt[i].protect)
                cal<<mementos.dt[i].pasw<<endl;


                cal<<mementos.dt[i].zi.x<<" "<<mementos.dt[i].luna.x<<" "<<mementos.dt[i].an<<endl;
                cal<<mementos.notes[i]<<endl;
      }
cal.close();

    }



    void update()
    {
        ifstream cal2("cal.txt");


        char txt2 [250];
        int nu,pr;

        if(cal2>>nu)
        {

            for(int i=1; i<=nu; i++)
            {
                char* txt=NULL;

                cal2>>pr;


                if(pr)
                {

                cal2.get();
                    cal2.getline(txt2,250);
                }

                int yr,mnt,dy;


                cal2>>dy>>mnt>>yr;



                txt=new char[251];
                cal2.get();
                cal2.get(txt,250);
                cal2.get();


                mementos.add_note(yr,mnt,dy,txt,pr,txt2);

            }

        }
cal2.close();

}





    void interfaces(int up=0)
    {
        int c=1,d2=0;
        char texts[255];

        if(up)
        update();


        do
        {
            make_heighlight();
            cout<<"choose your option:"<<endl<<endl;

            cout<<"exit 0"<<endl;

            cout<<"see year 1"<<endl;

            cout<<"see month 2"<<endl;

            cout<<"make note 3"<<endl;

            cout<<"see notes on date 4"<<endl;

            cout<<"see notes on month 5"<<endl;

            cout<<"see notes on year 6"<<endl;

            cout<<"see all notes 7"<<endl;

            cout<<"delete note on date 8"<<endl;

            cout<<"delete all notes on month 9"<<endl;

            cout<<"delete all note in year 10"<<endl;

            cout<<"delete all notes 11"<<endl;

            cout<<"make protected note 12"<<endl;

            cin>>c;
            system("cls");


            switch(c)
            {


            case 0:
               {
                send_update();
                exit(1);
                  ;break;
               }



            case 1:
            {

                cout<<"year:";
                cin>>year;

                show_year();
                cout<<endl;
                break;
            }

            case 2:
            {
                int mnt;

                cout<<"year:";
                cin>>year;


                cout<<"month:";
                cin>>mnt;
               cout<<endl<<endl;
                show_month(mnt);
                cout<<endl<<endl;
                break;
            }

            case 3:
            {

                cout<<" warning:limit of note is 255 characters"<<endl;
                int mnt,dts;


                cout<<"year:";
                cin>>year;


                cout<<"month:";
                cin>>mnt;


                cout<<"day:";
                cin>>dts;

                cout<<"input reseved"<<endl<<endl;


                show_month(mnt,1,year);


                cout<<endl<<endl<<"add text:"<<endl;


                cin.get();
                cin.get(texts,254);
                cin.get();

                add_memento(year,mnt,dts,texts);
                break;
            }

            case 4:

            {
                int mnt,day;

                cout<<"year:";
                cin>>year;

                cout<<"month:";
                cin>>mnt;

                cout<<"day:";
                cin>>day;

           make_heighlight(year,mnt,day);
                show_month(mnt);
              cout<<"the week day is:";

             int wd=week_dayc(day,mnt,year);
                switch(wd)
                {
                    case 1:cout<<"Monday"<<endl;
                   break;
                   case 2:cout<<"Tuesday"<<endl;
                   break;
                    case 3:cout<<"Wednesday"<<endl;
                   break;
                   case 4:cout<<"Thursday"<<endl;
                   break;
                    case 5:cout<<"Friday"<<endl;
                   break;
                   case 6:cout<<"Saturday"<<endl;
                   break;
                  case 7:cout<<"Sunday"<<endl;
                   break;
                   default: cout<<"some day of the week"<<endl;
                }


                see_mementos(year,mnt,day);
                break;
            }
            case 5:
            {
                int mnt,dt;

                cout<<"year:";

                cin>>year;

                cout<<"month:";

                cin>>mnt;

                show_month(mnt);
                see_month(year,mnt);



                break;
            }
            case 6:
            {
                int mnt,dt;

                cout<<"year:";

                cin>>year;

                see_year(year);

                break;
            }
            case 7:
            {

                see_mementos();
                break;
            }

            case 8:
            {
                int mnt,dt;
                 ;
                cout<<"year:";
                cin>>year;

                 ;
                cout<<"month:";
                cin>>mnt;

                 ;
                cout<<"day:";
                cin>>dt;


                show_month(mnt);
                  cout<<"the week day is:";
             int wd=week_dayc(dt,mnt,year);
                switch(wd)
                {
                    case 1:cout<<"Monday"<<endl;
                   break;
                   case 2:cout<<"Tuesday"<<endl;
                   break;
                    case 3:cout<<"Wednesday"<<endl;
                   break;
                   case 4:cout<<"Thursday"<<endl;
                   break;
                    case 5:cout<<"Friday"<<endl;
                   break;
                   case 6:cout<<"Saturday"<<endl;
                   break;
                  case 7:cout<<"Sunday"<<endl;
                   break;
                   default: cout<<"some day of the week"<<endl;
                }



                see_mementos(year,mnt,dt);

                 ;
                cout<<"choose witch note to eliminate"<<endl;
                 ;
                cout<<"to eliminate all notes input 0"<<endl;
                 ;
                int i;
                cin>>i;
                delete_memento(year,mnt,dt,i);
                break;
            }

            case 9:
            {
                int mnt,dt;
                 ;
                cout<<"year:";
                cin>>year;
                 ;

                cout<<"month:";
                cin>>mnt;

                show_month(mnt);
                  cout<<endl;
                see_month(year,mnt);
                 ;
                cout<<"do you want to delete all notes"<<endl;
                int i;
                 ;
                cin>>i;
                if(i!=0)
                    delete_all_memento_month(year,mnt);
                break;
            }

            case 10:
            {
                int mnt,dt;
                 ;

                cout<<"year:";
                cin>>year;

                show_year();
                cout<<endl;
                see_year(year);

                 ;
                cout<<"do you want to delete all notes DA:1/ NU:0"<<endl;

                int i;

                 ;
                cin>>i;

                if(i!=0)
                    delete_all_memento_year(year);
                break;
            }
            case 11:
            {



                see_mementos();

                cout<<"do you want to delete all notes DA:1/ NU:0"<<endl;
                int i;

                cin>>i;
                if(i!=0)
                    delete_all_memento();
                break;
            }

             case 12:
            {
              cout<<" warning:limit of note is 255 characters"<<endl;
                int mnt,dts;
                char paw[260];

                cout<<"year:";
                cin>>year;


                cout<<"month:";
                cin>>mnt;


                cout<<"day:";
                cin>>dts;
                cout<<"input reseved"<<endl<<endl;


                show_month(mnt,1,year);


                cout<<endl<<endl<<"add pasword:"<<endl;


                cin.get();
                cin.get(paw,254);
                cin.get();
                ofstream f;

                f.open("encod.txt");
                f<<"calendar.txt"<<endl;
                f.close();

                 f.open("calendar.txt");
                f<<1<<endl;
                f<<paw<<endl;
                f.close();
                system("encoding.exe");

                system("pause");

                ifstream g("calendar.txt");
                g.getline(paw,254);
                g.get();
                g.close();


                cout<<endl<<endl<<"add text:"<<endl;
                cin.get(texts,254);
                cin.get();

                add_memento(year,mnt,dts,texts,1,paw);

            }







            }

           send_update();

            cout<<endl<<"done?"<<endl;
            cin>>d2;


            system("cls");

        }
        while(c);
    }




};










int main()
{

    calendar a;
   a.year=-30;

   HWND myconsole =GetConsoleWindow();

   HDC mydc = GetDC(myconsole);






   RECT rect;
   int width ;
   int height;



if(GetWindowRect(myconsole, &rect))
{

   width = rect.right - rect.left;
   height = rect.bottom - rect.top;
}



   cout<<width<<" "<<height<<endl;



a.interfaces(1);


}

















