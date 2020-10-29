#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void display(int x,int y,int xc,int yc);

void main()
{
    int gd = DETECT, gm;
    float d;
    int r,xc,yc,x,y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    line(0,240,640,240);
    line(320,0,320,480);

    r = 15;
    xc = yc = 20;
    printf("\nThe radius: %d", r);
    printf("\nThe coordinates of the centre: %d  %d", xc, yc);


    x=0;
    y=r;
    d=1.25-r;
    do {
	    printf("\nCoordinates: %d  %d", x, y);
        display(x,y,xc,yc);
        if(d<0)
        {
            x=x+1;
            y=y;
            d=d+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            d=d+2*(x-y)+1;
        }
    } while(x<y);
    getch();
}

void display(int x,int y,int xc,int yc)
{
    putpixel(320+(xc+x),240-(yc+y),4);
    putpixel(320+(xc+x),240-(yc-y),4);
    putpixel(320+(xc-x),240-(yc+y),4);
    putpixel(320+(xc-x),240-(yc-y),4);
    putpixel(320+(xc+y),240-(yc+x),4);
    putpixel(320+(xc+y),240-(yc-x),4);
    putpixel(320+(xc-y),240-(yc+x),4);
    putpixel(320+(xc-y),240-(yc-x),4);
}