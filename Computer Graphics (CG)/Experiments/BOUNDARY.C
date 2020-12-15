#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void boundaryFill4(int, int, int, int);

void main()
{
    int gd=DETECT,gm,x1,y1,x2,y2,x3,y3,x4,y4,x,y;
    int edgecolour,newcolour;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("\nEnter coordinates of rectangle: \n");
    printf("Enter x1 and y1: ");
    scanf("%d%d",&x1,&y1);
    printf("Enter x2 and y2: ");
    scanf("%d%d",&x2,&y2);
    printf("Enter x3 and y3: ");
    scanf("%d%d",&x3,&y3);
    printf("Enter x4 and y4: ");
    scanf("%d%d",&x4,&y4);

    printf("Enter seed pixel: ");
    scanf("%d%d",&x,&y);
    printf("Enter edge colour: ");
    scanf("%d",&edgecolour);
    printf("Enter fill colour: ");
    scanf("%d",&newcolour);

    setcolor(edgecolour);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x1,y1);

    boundaryFill4(x,y,newcolour,edgecolour);

    getch();
}

void boundaryFill4(int x,int y,int newcolour,int edgecolour)
{
    if((getpixel(x,y)!=newcolour)&&(getpixel(x,y)!=edgecolour))
    {
        putpixel(x,y,newcolour);
        delay(1);
        boundaryFill4(x+1,y,newcolour,edgecolour);
        boundaryFill4(x-1,y,newcolour,edgecolour);
        boundaryFill4(x,y+1,newcolour,edgecolour);
        boundaryFill4(x,y-1,newcolour,edgecolour);
    }
}