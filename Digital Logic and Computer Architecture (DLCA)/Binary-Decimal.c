#include <conio.h>
#include <stdio.h>
#include <math.h>

void binary()
{
    // Decimal to Binary;
    int n, a[50], i, flag = 0;
    printf("\nEnter a decimal number:\t");
    scanf("%d", &n);

    // for positive;
    if(n > 0)
    {
        for(i=0; n>0; i++)
        {
            a[i] = n % 2;
            n = n / 2;
        }
        printf("The binary number is: \t");
        for(i = i - 1; i >= 0; i--)
        {
            printf("%d", a[i]);
        }
    }
    // For negative;
    else
    {
        n *= -1;
        for(i = 0; n>0; i++)
        {
            a[i] = n % 2;
            n = n / 2;
        }
        //
        a[i] = 0;
        int t = i;

        // debug
        for(i = t; i >= 0; i--)
            printf("%d", a[i]);
        printf("\n");
        // debug

        for(i = t; i >= 0; i--)
            a[i] = !a[i];
            // 1 --> 0

        // debug
        for(i = t; i >= 0; i--)
            printf("%d", a[i]);
        printf("\n");
        // debug

        int carry = 0;

        if(a[0] == 1) {
            a[0] = 0;
            carry = 1;
        }
        else {
            a[0] = 1;
            carry = 0;
        }
        for(i = 1; i <= t; i++) {
            if(a[i] && carry)
                a[i] = 0, carry = 1;
            else if(a[i] == 0 && carry)
                a[i] = 1, carry = 0;
        }

        printf("The binary number is: \t");
        if(carry)
            printf("1");
        for(i = t; i >= 0; i--)
            printf("%d", a[i]);
    }



}
void decimal()
{
    int ans = 0, i = 0, r, n;
    printf("Enter a binary number:\t");
    scanf("%d", &n);
    while (n!=0)
    {
        r = n%10;
        n /= 10;
        ans += r * pow(2,i);
        ++i;
    }
    printf("The decimal number is:\t");
    printf("%d", ans);
}


void main()
{
    printf("Choose one of the following options:\n");
    printf("[0] Binary to Decimal.\n");
    printf("[1] Decimal to Binary.\n");
    printf("Enter Your choice [0] or [1]: \t");
    int choice;
    scanf("%d", &choice);
    if(choice)
        binary();
    else
        decimal();
}




/*-5
5
1010
0101
1010
1011

7
0111
1000
1001

16
010000
101111
110000
*/
