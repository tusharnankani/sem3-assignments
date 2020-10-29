#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int options()
{
    int ch;
    printf("\n1:Flood Fill \n2:Boundary Fill \n3:Exit");
    printf("\nEnter your choice [1 - 3] :  ");
    scanf("%d",&ch);
    return ch;
}


void boundaryFill8(int x,int y,int newcolour,int edgecolour)
{
    if((getpixel(x,y)!=newcolour)&&(getpixel(x,y)!=edgecolour))
    {
        putpixel(x,y,newcolour);
        delay(1);
        boundaryFill8(x+1,y,newcolour,edgecolour);
        boundaryFill8(x-1,y,newcolour,edgecolour);
        boundaryFill8(x,y+1,newcolour,edgecolour);
        boundaryFill8(x,y-1,newcolour,edgecolour);
        boundaryFill8(x+1,y+1,newcolour,edgecolour);
        boundaryFill8(x+1,y-1,newcolour,edgecolour);
        boundaryFill8(x-1,y+1,newcolour,edgecolour);
        boundaryFill8(x-1,y-1,newcolour,edgecolour);
    }
}

void flood(int x,int y,int newcolour,int oldcolour)
{
    if((getpixel(x,y)==oldcolour))
    {
        putpixel(x,y,newcolour);
        delay(1);
        flood(x+1,y,newcolour,oldcolour);
        flood(x,y+1,newcolour,oldcolour);
        flood(x-1,y,newcolour,oldcolour);
        flood(x,y-1,newcolour,oldcolour);
        flood(x+1,y+1,newcolour,oldcolour);
        flood(x+1,y-1,newcolour,oldcolour);
        flood(x-1,y+1,newcolour,oldcolour);
        flood(x-1,y-1,newcolour,oldcolour);
    }
}

void main()
{
    int gd=DETECT,gm,x1,y1,x2,y2,x3,y3,x4,y4,x,y;
    int oldcolour=0,newcolour,edgecolour;
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

    printf("\nEnter seed pixel: ");
    scanf("%d%d",&x,&y);

    switch (options())
    {
        case 1:
        {
            printf("\nEnter fill colour: ");
            scanf("%d",&newcolour);
            setcolor(1);
            line(x1,y1,x2,y2);

            setcolor(2);
            line(x2,y2,x3,y3);

            setcolor(3);
            line(x3,y3,x4,y4);

            setcolor(4);
            line(x4,y4,x1,y1);

            flood(x,y,newcolour,oldcolour);
            getch();
        }
        break;
        
        case 2:
        {
            printf("\nEnter new colour: ");
            scanf("%d",&newcolour);
            printf("Enter edge colour: ");
            scanf("%d",&edgecolour);
            setcolor(edgecolour);

            line(x1,y1,x2,y2);
            line(x2,y2,x3,y3);
            line(x3,y3,x4,y4);
            line(x4,y4,x1,y1);

            boundaryFill8(x,y,newcolour,edgecolour);
            getch();
        }
        break;

        case 3: 
            printf("\nThank You!");
            break;

        default:
            printf("\nInvaild Choice!");
            break;
    }
}

