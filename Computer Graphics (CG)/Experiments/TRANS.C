#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void displayMatrix(int A[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
	for(j = 0; j < 3; j++)
	{
	    printf("%d  ", A[i][j]);
	}
	printf("\n");
    }
}

void main()
{
    int gd = DETECT, gm;
    int x1,x2,x3,y1,y2,y3,tx,ty,i,j,k,T[3][3],ob[3][3],A[3][3];
    float sum;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("\nEnter the coordinates of Polygon:\n");

    printf("\nEnter first coordinates x1 and y1: \t");
    scanf("%d%d", &x1, &y1);
    printf("Enter second coordinates x2 and y2:\t");
    scanf("%d%d", &x2, &y2);
    printf("Enter third coordinates x3 and y3: \t");
    scanf("%d%d", &x3, &y3);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    printf("\nEnter the translations, tx and ty: \t");
    scanf("%d%d",&tx, &ty);

    // ob matrix;
    /*
	x1 y1 1
	x2 y2 1
	x3 y3 1
    */

    // first row;
    ob[0][0] = x1;
    ob[0][1] = y1;
    ob[0][2] = 1;

    // second row;
    ob[1][0] = x2;
    ob[1][1] = y2;
    ob[1][2] = 1;

    // third row;
    ob[0][0] = x3;
    ob[0][1] = y3;
    ob[0][2] = 1;

    printf("\nThe object matrix is: \n");
    displayMatrix(ob);

    // translation matrix;
    /*
	1  0  0
	0  1  0
	tx ty 1
    */
    for(i = 0; i < 3; i++)
    {
	for(j = 0; j < 3; j++)
	{
	    A[i][j] = 0;
	    if(i == j)
	    {
		    T[i][j] = (i == j);
	    }
	}
    }
    T[2][0] = tx;
    T[2][1] = ty;

    printf("\nThe translation matrix is: \n");
    displayMatrix(T);

    sum = 0;
    for(i = 0; i < 3; i++)
    {
	for(j = 0; j < 3; j++)
	{
	    for(k = 0; k < 3; k++)
	    {
		    sum += ob[i][j] * T[j][k];
	    }
	    A[i][j] = sum;
	    sum = 0;
	}
    }

    printf("\nThe final matrix is: \n");
    displayMatrix(A);
    line(A[0][0], A[1][0], A[0][1], A[1][1]);
    line(A[0][1], A[1][1], A[2][0], A[2][1]);
    line(A[2][0], A[2][1], A[0][0], A[1][0]);
    getch();
}

