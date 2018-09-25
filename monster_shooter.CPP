#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
int yg,xg;
int xb,yb;
int xd,yd;
int b=0;

void devil(int xd,int yd)
{

  setcolor(WHITE);
  //body
  setfillstyle(HATCH_FILL,RED);
  circle(xd,yd,40);
  floodfill(xd,yd,WHITE);
 //eyes
  setfillstyle(SOLID_FILL,BLACK);
  circle(xd-15,yd-15,10);
  circle(xd+15,yd-15,10);
  floodfill(xd-15,yd-15,WHITE);
  floodfill(xd+15,yd-15,WHITE);
//thorn
  arc(xd+20,yd-50,180,205,50);
  arc(xd-20,yd-50,335,360,50);

}

void gun(int yg)
{

 setcolor(YELLOW);
 setfillstyle(SOLID_FILL,YELLOW);
 ellipse(20,yg,0,360,20,10);
 fillellipse(20,yg,20,10);
 ::yg=yg;
}

void bullet(int xb,int yb)
{

 ::yb=yg;
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(xb,yb,5);
 floodfill(xb,yb,WHITE);
}

 void move_devil(int xd,int yd)
 {

     delay(500);
     cleardevice();
     devil(xd,yd);
     ::xd=xd;
     ::yd=yd;
     gun(yg);

 }



int collision()
{

  if((xb+5)>=(xd-40)&&yb>yd-40&&yb<yd+40)
  {
     return 1;
  }
  else
  {
     return 0;
  }

}



void shoot(int xb,int xd,int yd)
{

      while(xb<(getmaxx()-5))
   {
      bullet(xb,yg);

      if(collision())
      {
	 moveto(getmaxx()/2,getmaxy()/2);
	 outtextxy(getmaxx()/2,getmaxy()/2,"...YOU'VE...WON...");
	 delay(5000);
	 exit(0);
      }
      xb=xb+5;
      ::xb=xb;
      ::yg=yg;
      delay(0);
     cleardevice();
      gun(yg);
      devil(xd,yd);

}
}

void init()
{
 rectangle(0,0,getmaxx(),getmaxy());
 // rectangle(0,0,getmaxx(),getmaxy());
  /* setfillstyle(HATCH_FILL,BROWN);
   rectangle(0,350,getmaxx(),getmaxy());
   floodfill(1,351,WHITE);
   setfillstyle(SOLID_FILL,GREEN);
   rectangle(0,300,getmaxx(),350);
   floodfill(1,301,WHITE);*/
 gun(getmaxy()/2);
 devil(300,300);
}


void play()
{

	char ch;

	  while(b<10)
	    {

			gotoxy(33,1);
			cout<<"Bullets Left:"<<(10-b);
		 move_devil((random(getmaxx())+20),random(getmaxy()));

		if(kbhit())
		 {
		   ch=getch();

		     if(ch==117)
		       {
			 yg=yg-10;
			 cleardevice();
			 gun(yg);
			// move_devil(xd,yd);
			// ::yg=yg;

			    if(yg<=10)
			    {
			      cleardevice();
			      gun(10);
			      yg=10;
			    }
			}
		    if(ch==100)
		       {
			yg=yg+10;
			cleardevice();
			gun(yg);
		     // move_devil(xd,yd);


			  if(yg>=getmaxy()-10)
			   {
			    cleardevice();
			    gun(getmaxy()-10);
			    yg=getmaxy();
			   }
			}
		    if(ch==115)
		       {
		       xb=xg+20;
		       b++;
		       shoot(xb,xd,yd);
		       }

		    if(ch==27)
		      {
		      exit(0);
		      }
		}


	    }
	     moveto(getmaxx()/2,getmaxy()/2);
	 outtextxy(getmaxx()/2,getmaxy()/2,"...YOU'VE...LOSS...");
	 delay(5000);
	 exit(0);

}


void main()
{

 int gm,gd=DETECT;
 ::yg=200;
 ::xg=20;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 srand(time(0));

 rectangle(0,0,getmaxx(),getmaxy());
 setcolor(YELLOW);
 outtextxy(getmaxx()/4,30,"...the world is coming to an end...");
 outtextxy(getmaxx()/4,80,"...the devil is going to destoy the universe...");

 outtextxy(getmaxx()/4,130,"...destroy the devil before it destroys us...");
 outtextxy(getmaxx()/4,180,"...ALL THE BEST...");
 delay(2000);
 outtextxy(getmaxx()/4,270,"use 's' to shoot the devil");
 outtextxy(getmaxx()/4,310,"use'u' to move gun upward & 'd' to move gun downward");
 outtextxy(getmaxx()/4,360,"You have only 10 bullets");
 outtextxy(getmaxx()/4,450,"press any key to continue....");
// delay(9000);
  getch();
 init();
 play();


 getch();
 closegraph();

}