#include<conio.h>
#include<stdio.h>

int i, j, n, a[50], num;

void welcome()
{
    // welcome message;
    printf("\nWELCOME TO THE ARRAY MANIPULATION CENTER!\n");

    // array to be manipulated;
    printf("\nEnter the size of the array:\t");
    scanf("%d", &n);
    printf("Enter the %d elements of the array:\t", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void options()
{
    // Operations;
    printf("\nNow, enter the operation number you want to perform with this array: \n");
    printf("0. Search\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Merge\n");
    printf("4. Sort\n");
    printf("Enter a number from 0 to 4, inclusive: \t");
    scanf("%d", &num);
    printf("\n");
}

void search()
{
    int b, index = -1;
    printf("Enter the element to be found:\t");
    scanf("%d", &b);
    for(i = 0; i < n; i++)
    {
        if(a[i] == b)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
        printf("Element not found!");
    else
        printf("The number %d was found at the position %d, considering a 0-indexed array.\n", n, index);
}

void insert()
{
    int val, pos;
    printf("Enter the element to be inserted:\t");
    scanf("%d", &val);
    printf("\nEnter the index position (according to 0-indexed; between 0 and %d, inclusive) to be inserted:\t", n);
    scanf("%d", &pos);
    for(i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = val;
    printf("The modified array is: \t");
    // NOTE: the array size is changed to n + 1;
    for(i = 0; i < n + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void delete()
{
    int pos;
    printf("\nEnter the index position (according to 0-indexed; between 0 and %d, inclusive) to be deleted:\t", n - 1);
    scanf("%d", &pos);
    for(i = pos; i < n; i++)
        a[i] = a[i + 1];
    printf("The modified array is: \t");
    // NOTE: the array size is changed to n - 1;
    for(i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void merge()
{
    int m, b[20];
    printf("Enter the size of the array to be merged: \t");
    scanf("%d", &m);
    printf("Enter the %d elements of the array to be merged:\t", m);
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for(i = n; i < n + m; i++)
        a[i] = b[i - n];

    printf("The size of the merged array is %d.\n", n + m);
    for(i = 0; i < n + m; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void sort()
{
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The sorted array is: \t");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int cont()
{
    int t;
    printf("\nIf you want to continue, press [1], else [0]:\t");
    scanf("%d", &t);
    return t;
}

void end()
{
    printf("\nThank you for using our services!\nSee you again!\n");
}

void main()
{
    welcome();

    int t = 1;
    // loop until the user stops;
    while(t)
    {
        options();
        switch (num)
        {
            case 0:
                search();
                break;
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                merge();
                break;
            case 4:
                sort();
                break;

            default:
                printf("Option not valid!");
        }
        t = cont();
    }
    end();
    getch();
}
