#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int sign(int x, int y)
{
    if(x>y)
        return 1;
    else if(y>x)
        return -1;
        
    return 0;
}

void bres(int x0, int y0, int x1, int y1)
{
    int i,x,y,dx,dy,s1,s2,swap=0,p;

    dx=abs(x1-x0);
    dy=abs(y1-y0);
    s1=sign(x1,x0);
    s2=sign(y1,y0);

    if(dy>dx)
    {
        int temp=dx;
        dx=dy;
        dy=temp;

        swap=1;
    }
    x=x0;
    y=y0;
    p=2*dy-dx;

    for(i=0;i<dx;++i)
    {

        putpixel(320+x,240-y,RED);
        if(p>=0)
        {
            if(swap==1)
                x+=s1;
            else
                y+=s2;

            p=p+2*dy-2*dx;
        }
        else
        {
            if(swap==1)
                y+=s2;
            else
                x+=s1;

            p=p+2*dy;
        }
    }
}

void main()
{
    int gd=DETECT,gm,i;
    int x0,y0,x1,y1;
    clrscr();
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    line(320,0,320,480);
    line(0,240,640,240);

    printf("Enter x0: ");
    scanf("%d",&x0);
    printf("Enter y0: ");
    scanf("%d", &y0);

    printf("Enter x1: ");
    scanf("%d",&x1);
    printf("Enter y1: ");
    scanf("%d", &y1);
    
    bres(x0,y0,x1,y1);
    getch();
    closegraph();

}

