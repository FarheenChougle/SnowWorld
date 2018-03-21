#include<graphics.h>';
#include<conio.h>
#include<stdio.h>
#include<math.h>
void whitepixel(int color) {
	int i, j = 0, x, y=0;
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

	for (i = 50; i < 700; i = i + 50) {
		x = i;
		for(j=50;j<500;j=j+50)
		{
		y = 50 + j;

		/* put pixel at the given position */
		putpixel(x, y, color);
	     }
	     }
	     }
 void snowflake()
 {
 int i;
  for (i = 0; i < 100; i++) {
		whitepixel(WHITE);
		delay(100);
		whitepixel(BLACK);
		delay(100);
	}
 }
 void displayMan(int x,int y)
{   setcolor(WHITE);
    circle(x,y,10);         //face
    line(x,y+10,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x+20,y+40,x+30,y+30);
    line(x,y+30,x,y+70);        //body
    line(x+30,y+30,x+30,y-90);  //umbrella
    setfillstyle(SOLID_FILL, WHITE);
    pieslice(x+30,y-30,0,180,55);
}
void leg()
{
line(240,450,220,470);
	    line(240,450,260,470);
}
void wave()
{
//int x2,y2,x1,y1,x,y,xn,yn;
//double r11,r12,th;
//th=0.00000023;
ddaline(500,430,460,400);
ddaline(600,430,635,400);
//r11=cos((th*3.1428)/180);
//r12=sin((th*3.1428)/180);
//r21=(-sin((th*3.1428)/180));
//r22=cos((th*3.1428)/180);
//printf("%lf  %lf  %lf  %lf",r11,r12,r21,r22);
/*xn=((x2*r11)-(y2*r12));
yn=((x2*r12)+(y2*r11));
line(600,430,xn,yn);
  */
}

void walking()
{
int x=50,d=0,p=1,y=380,i=0;
 while(x!=0)
    {
	cleardevice();
	moon(25+i);
	i+=1;
	displayMan(x,380);
 if(p)
	{
	    if(d<20)
		d+=4;
	    else
		p=0;
	    line(x,y+70,x-d,y+90);
	    line(x,y+70,x+d,y+90);
	}
	else
	{
	    if(d>0)
		d-=4;
	    else
		p=1;
	    line(x,y+70,x-d,y+90);
	    line(x,y+70,x+d,y+90);
	}
	delay(1000);
	x=(x+10)%250;
    }
 }
void birds()
{
 setcolor(WHITE);
	arc(50, 50, 0, 160, 10);
	arc(70, 50, 20, 180, 10);
	arc(150, 100, 0, 150, 10);
	arc(170, 100, 10, 180, 10);
	arc(250, 125, 0, 160, 10);
	arc(270, 125, 20, 180, 10);
	arc(340,75,0,160,10);
	arc(360,75,20,180,10);
}
/*void moonbig()
{
int i;
for(i=0;i<=20;i+=5)
{
moon(25+i);
}
} */
int moon(int r)
{    int x,y ;
cleardevice();
  x = getmaxx() - 50;
	y = 70;
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, r);
       floodfill(x, y, WHITE);
  delay(100);

	return;
	}
void bezierc(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
float ss=0.2;
int Bx,By,p0[2],p1[2],p2[2],p3[2];
p0[0]= x1;
p0[1]= y1;
p1[0]= x2;
p1[1]= y2;
p2[0]= x3;
p2[1]= y3;
p3[0]=x4 ;
p3[1]= y4;
for(ss=0;ss<=1;ss+=0.0005)
{
Bx=pow((1-ss),3) * p0[0] + 3*ss*pow((1-ss),2) * p1[0] + 3*ss*ss*(1-ss)*p2[0] + pow(ss,3) * p3[0];
By=pow((1-ss),3) * p0[1] + 3*ss*pow((1-ss),2) * p1[1] + 3*ss*ss*(1-ss)*p2[1] + pow(ss,3) * p3[1];
//printf("%0.2f \n", ss);
putpixel(Bx,By,5);
}
}
void gb(int x1,int y1,int x2,int y2)
{
int dx,dy,x,y,s1,s2,p,temp,ex,i;
dx=abs(x2-x1);
dy=abs(y2-y1);
x=x1;
y=y1;
s1=x2-x1;
s2=y2-y1;
if(s1<0)
s1=-1;
else if(s1>0)
s1=1;
if(s2<0)
s2=-1;
else if(s2>0)
s2=1;
if(dy>dx)
{
 temp=dx;
 dx=dy;
 dy=temp;
 ex=1;
}
else  {
ex=0;  }
p=(2*dy)-dx;
putpixel(x,y,WHITE);
for(i=1;i<=dx;i++){
while(p>=0)
{
 if(ex==1)
 x+=s1;
 else
 y+=s2;
p-=(2*dx);
}
if(ex==1)
y+=s2;
else
x+=s1;
p+=(2*dy);
putpixel(x,y,WHITE);
}
}
void midpoint();
int ddaline(int x1, int y1, int x2, int y2) {

	int s, m, dx, dy;
	float xi, yi, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) > abs(dy))
		s = abs(dx); else
		s = abs(dy);
	xi = dx / (float) s;
	yi = dy / (float) s;
	x = x1;
	y = y1;
	putpixel(x1 + 0.5, y1 + 0.5, 15);
	for (m = 0; m < s; m++) {
		x += xi;
		y += yi;
		putpixel(x + 0.5, y + 0.5, 15);
	}
	return;
}
void snowman()
{
wave();
midpoint(550,430,50);
circle(550,430,50);
setcolor(WHITE);
setfillstyle(1,WHITE);
floodfill(550,430,WHITE);

midpoint(550,355,25);
circle(550,355,25);
setcolor(WHITE);
setfillstyle(1,WHITE);
floodfill(550,355,WHITE);
bezierc(535,365,540,375,560,375,565,365);
putpixel(550,355,4);
putpixel(549,355,4);
putpixel(551,355,4);
putpixel(550,354,4);
putpixel(550,356,4);

putpixel(540,350,4);

putpixel(560,350,4);
}
/*void snowman()
{
wave();
midpoint(550,429,50);
midpoint(550,354,25);

setcolor(WHITE);
setfillstyle(1,WHITE);
floodfill(550,430,WHITE);

midpoint(550,355,25);
circle(550,355,25);
setcolor(WHITE);
setfillstyle(1,WHITE);
floodfill(550,355,WHITE);


putpixel(550,355,4);
putpixel(549,355,4);
putpixel(551,355,4);
putpixel(550,354,4);
putpixel(550,356,4);

putpixel(540,350,4);

putpixel(560,350,4);
} */
void house()
{
gb(0,250,getmaxx(),250);
gb(getmaxx()-150,250,getmaxx()-150,230);
gb(getmaxx()-80,250,getmaxx()-80,230);
gb(getmaxx()-115,210,getmaxx()-170,240);
gb(getmaxx()-115,210,getmaxx()-60,240);
setfillstyle(1,LIGHTRED);
floodfill(1,1,WHITE);

}
void christmas()
{
 ddaline(400,430,400,480);
 ddaline(380,480,380,430);
 ddaline(380,430,400,430);
 setcolor(GREEN);
 setfillstyle(1,BROWN);
 floodfill(390,450,WHITE);

 ddaline(400,430,450,430);
 ddaline(380,430,330,430);
 ddaline(330,430,390,380);
 ddaline(450,430,390,380);
setcolor(GREEN);
 setfillstyle(1,GREEN);
 floodfill(390,420,WHITE);


 ddaline(340,380,440,380);
 ddaline(340,380,390,340);
 ddaline(440,380,390,340);
 setcolor(GREEN);
 setfillstyle(1,GREEN);
 floodfill(400,350,WHITE);


 ddaline(350,340,430,340);
 ddaline(350,340,390,310);
 ddaline(430,340,390,310);
 setcolor(GREEN);
 setfillstyle(1,GREEN);
 floodfill(400,330,WHITE);

 ddaline(360,310,420,310);
 ddaline(360,310,390,290);
 ddaline(420,310,390,290);
 setcolor(GREEN);
 setfillstyle(1,GREEN);
 floodfill(400,300,WHITE);

 }
 int call()
 {
  moon(45);
  displayMan(240,380);
  leg();
  house();
setcolor(WHITE);
snowman();
birds();
christmas();
return;
}
void main()
{
int gd=DETECT,gm;
float pk;
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
walking();
call();
setfillstyle(1,DARKGRAY);
floodfill(0,251,WHITE);
snowflake();
getch();
}
void floodFill(int x,int y,int oldcolor,int newcolor)
{
    if(getpixel(x,y) == oldcolor)
    {
	putpixel(x,y,newcolor);
	floodFill(x+1,y,oldcolor,newcolor);
	floodFill(x,y+1,oldcolor,newcolor);
	floodFill(x-1,y,oldcolor,newcolor);
	floodFill(x,y-1,oldcolor,newcolor);
    }
}
void midpoint(int xc,int yc,int r)
{
int pk,i,x,y;
pk=1.25-r;
x=0;
y=r;
do
{
if(pk<0)
{
x=x+1;
pk=pk+2*x+1;
}
else
{
x=x+1;
y=y-1;
pk=pk+2*x-2*y+10;
}
putpixel(xc+x,yc+y,255);
putpixel(xc-y,yc-x,255);
putpixel(xc+y,yc-x,255);
putpixel(xc-y,yc+x,255);
putpixel(xc+y,yc+x,255);
putpixel(xc-x,yc-y,255);
putpixel(xc+x,yc-y,255);
putpixel(xc-x,yc+y,255);
}
while(x<y);
}