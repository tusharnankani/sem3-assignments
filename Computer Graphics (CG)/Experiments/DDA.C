#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
    int gd=DETECT,gm;
    int i,x0,y0,x1,y1,x,y,ch;
    float dx,dy,steps,xinc,yinc;
    initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");

    printf("\nEnter x0 and y0: ");
    scanf("%d%d",&x0,&y0);
    printf("\nEnter x1 and y1: ");
    scanf("%d%d",&x1,&y1);

    printf("\n[1]:Normal Line\n[2]:Dotted Line\n[3]:Dashed Line\n[4]:Thick Line");
    printf("\nEnter your choice");
    scanf("%d",&ch);

    line(0,240,640,240);
    line(320,0,320,480);

    setbkcolor(0);
    dx = x1-x0;
    dy = y1-y0;
    if(dx >= dy)
      steps = dx;
    else
      steps = dy;

    xinc = dx / steps;
    yinc = dy / steps;
    x = x0;
    y = y0;
    i = 1;

    switch(ch)
    {
    //Normal
      case 1:
      {
	i=1;
	while(i<=steps)
	  {
	    putpixel(320+x,240-y,15);
	    x+=xinc;
	    y+=yinc;
	    i++;
	  }
      }
      break;
      // Dotted
      case 2:
      {
	while(i<=steps)
	{
	  if(i%2==0)
	    putpixel(320+x,240-y,15);
	    x+=xinc;
	    y+=yinc;
	    i++;
	}
      }
      break;
      // Dashed
      case 3:
      {
	while(i<=steps)
	{
	  if(i%6!=0)
	  putpixel(320+x,240-y,15);
	  x+=xinc;
	  y+=yinc;
	  i++;
	}
      }
      break;
      // Thick
      case 4:
      {
	while(i<=steps)
	{
	  putpixel(320+x-1,240-y-1,15);
	  putpixel(320+x,240-y,15);
	  putpixel(320+x+1,240-y+1,15);
	  x+=xinc;
	  y+=yinc;
	  i++;
	}
      }
      break;
      default:
	  printf("\nINVALID CHOICE");
      break;
      }
    getch();
    closegraph();
}
