#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int gd = DETECT, gm;
	int s = 50, i, j;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			rectangle(i*s, j*s, (i + 1) * s, (j + 1) * s);
			if(((i % 2 == 0)&&(j % 2 != 0))||((i % 2 != 0)&&(j % 2 == 0)))
			{
				floodfill(i * s + s / 2, j * s + s / 2, WHITE);
			}
		}
	}
	getch();
	closegraph();
	return 0;
}