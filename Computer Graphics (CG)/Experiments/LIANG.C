#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void drawline(float x, float y, float p, float q)
{
    setcolor(1);
    setlinestyle(1,0,1);
    line(x,y,p,q);
}
void clipline(float t1,float t3,float x1,float y1, float dx,float dy)
{
    float x,y,p,q;

    x=x1+(t1 * dx);
    y=y1+(t1 * dy);
    p=x1+(t3 * dx);
    q=y1+(t3 * dy);
    drawline(x,y,p,q);
}
void main()
{
    int gd=DETECT,gm;
    int i,j=1,k=1;
    float p[4],q[4],t[4],r[4],s[4],x1,y1,x2,y2,dx,dy,xmin,ymin,xmax,ymax,t1,t3;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("\nEnter window coordinates:");
    scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
    printf("\nEnter line end points:");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    rectangle(xmin,ymax,xmax,ymin);
    line(x1,y1,x2,y2);
    dx=x2-x1;
    dy=y2-y1;
    p[1]=-(x2-x1);
    p[2]=(x2-x1);
    p[3]=-(y2-y1);
    p[4]=(y2-y1);
    q[1]=x1-xmin;
    q[2]=xmax-x1;
    q[3]=y1-ymin;
    q[4]=ymax-y1;
    t[1]=q[1]/p[1];
    t[2]=q[2]/p[2];
    t[3]=q[3]/p[3];
    t[4]=q[4]/p[4];
    for(i=1;i<=4;i++)
    {
        if(p[i]<0)
        {
            r[j]=t[i];
            j++;
        }
        if(p[i]>0)
        {
            s[k]=t[i];
            k++;
        }
    }

    t1=(float)max(r[1],r[2]);
    t1=(float)max(0,t1);
    t3=(float)min(s[1],s[2]);
    t3=(float)min(1,t3);
    delay(4000);
    
    cleardevice();
    if(t1<t3)
    {
        setcolor(WHITE);
        rectangle(xmin,ymax,xmax,ymin);
        clipline(t1,t3,x1,y1,dx,dy);
    }
    getch();
}
