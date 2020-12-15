#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm;
	int i = 0, j=0, k = 1;
	clrscr();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	while(j<getmaxx())
	{
		for(i = k;i<300;i++)
		{
			rectangle(0,420,getmaxx(),425);
			floodfill(10,422,CYAN);
			pieslice(300+j,i+100,0,360,20);
			delay(15);
			cleardevice();
			if(kbhit())
				exit();
		}
		for(i=300; i > k; i--)
		{
			rectangle(0,420,getmaxx(),425);
			floodfill(10,422,CYAN);
			pieslice(300+j,i+100,0,360,20);
			delay(35);
			cleardevice();
			if(kbhit())
				exit();
		}
		j = j + 1;
		k *= 2;
	}
	getch();
	closegraph();
	return 0;
}