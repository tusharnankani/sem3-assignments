#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main(void)
{
int gdriver = DETECT, gmode, errorcode;
int a, b, r, left, top, right, bottom, i, x, y;
//int clr = 1;
float PI = 3.14;
/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "C://turboc3//bgi");
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch();
exit(1); /* terminate with an error code */
}
setbkcolor(LIGHTGRAY);

setcolor(RED);
rectangle(100,100,450,150);
setfillstyle(SOLID_FILL,RED);
floodfill(101,101,RED);

setcolor(WHITE);
rectangle(100,150,450,200);
setfillstyle(SOLID_FILL,WHITE);
floodfill(101,151,WHITE);

setcolor(GREEN);
rectangle(100,200,450,250);
setfillstyle(SOLID_FILL,GREEN);
floodfill(101,201,GREEN);

setcolor(BROWN);
rectangle(90,100,100,500);
setfillstyle(SOLID_FILL,BROWN);
floodfill(90,100,BROWN);


a=275;
b=175;
r=25;
setcolor(BLUE);
circle(a,b,r);

for(i=0; i<=360; i+=15)
{
x=r*cos(i*PI/180);
y=r*sin(i*PI/180);
line(a,b,a+x,b-y);
}

/* clean up */
getch();
closegraph();
return 0;
}