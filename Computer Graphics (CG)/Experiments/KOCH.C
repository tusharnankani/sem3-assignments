#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void koch(float x1,float y1,float x2, float y2,int i)
{
    float x3,y3,x4,y4,x,y,theta;
    theta=60*(3.14/180);
    x3=(2*x1+x2)/3;
    y3=(2*y1+y2)/3;
    x4=(x1+2*x2)/3;
    y4=(y1+2*y2)/3;
    x=x3+(x4-x3)*cos(theta) + (y4-y3)*sin(theta);
    y=y3-(x4-x3)*sin(theta)+(y4-y3)*cos(theta);
    if(i>0)
    {
        koch(x1,y1,x3,y3,i-1);
        koch(x3,y3,x,y,i-1);
        koch(x,y,x4,y4,i-1);
        koch(x4,y4,x2,y2,i-1);
    }
    else
    {
        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}

void main()
{
    int gd = DETECT, gm;
    int n;
    float x1,x2,y1,y2;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    printf("\nEnter the end points of the line: ");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    printf("\nEnter the number of iterations: ");
    scanf("%d",&n);
    koch(x1,y1,x2,y2,n);
    getch();
}