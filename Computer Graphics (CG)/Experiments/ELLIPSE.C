#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
    int gd=DETECT,gm,i,j;
    float rx,ry,xc,yc,x,y,p;
    clrscr();

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    line(320,0,320,480);
    line(0,240,640,240);

    printf("Enter radius along x and y: ");
    scanf("%f%f",&rx,&ry);
    printf("Enter Center of the ellipse: ");
    scanf("%f%f",&xc,&yc);

    x=0.0;
    y=ry;

    // Region 1
    p=(ry*ry)+(rx*rx*0.25)-(rx*rx*ry);
    while((2.0*x*ry*ry)<(2.0*y*rx*rx))
    {
        putpixel(320+(x+xc),240-(y+yc),10);
        putpixel(320+(xc-x),240-(yc-y),11);
        putpixel(320+(x+xc),240-(yc-y),12);
        putpixel(320+(xc-x),240-(y+yc),13);
        if(p<0)
        {
            ++x;
            p=p+(2.0*x*ry*ry)+(ry*ry);
        }
        else
        {
            ++x;
            --y;
            p=p+(2.0*x*ry*ry)-(2.0*y*rx*rx)+(ry*ry);
        }
    }

    //Region 2:
    p=(ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y*y+1.0-2.0*y))-(rx*rx*ry*ry);
    while(y>0)
    {
        putpixel(320+(x+xc),240-(y+yc),10);
        putpixel(320+(xc-x),240-(yc-y),11);
        putpixel(320+(x+xc),240-(yc-y),12);
        putpixel(320+(xc-x),240-(y+yc),13);
        if(p<0)
        {
            ++x;
            --y;
            p=p+(2.0*x*ry*ry)+(rx*rx)-(2.0*y*rx*rx);
        }
        else
        {
            --y;
            p=p-(2.0*y*rx*rx)+(rx*rx);
        }
    }
    getch();
    closegraph();
}