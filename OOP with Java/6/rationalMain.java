import java.io.*;
import java.util.*;

class Rational
{
    float num, den;
    Rational(float n, float d)
    {
        num = n;
        den = d;
    }

    void displayRational(Rational R)
    {
        System.out.print(R.num + " / " + R.den);
    }

    void addRational(Rational R1, Rational R2)
    {
        float ansn, ansd;
        if(R1.den != R2.den) {
            ansn = R1.den * R2.num + R2.den * R1.num;
            ansd = R1.den * R2.den;
        }
        else {
            ansn = R1.num + R2.num;
            ansd = R1.den;
        }

        Rational ans = new Rational(ansn, ansd);
        System.out.print("\n\nThe addition of  ");
        displayRational(R1);
        System.out.print("  +  ");
        displayRational(R2);
        System.out.print("   is   ");
        displayRational(ans);
    }
    void subRational(Rational R1, Rational R2)
    {
        float ansn, ansd;
        if(R1.den != R2.den) {
            ansn = R2.den * R1.num - R1.den * R2.num ;
            ansd = R1.den * R2.den;
        }
        else {
            ansn = R1.num - R2.num;
            ansd = R1.den;
        }

        Rational ans = new Rational(ansn, ansd);
        System.out.print("\n\nThe subtraction of  ");
        displayRational(R1);
        System.out.print("  -  ");
        displayRational(R2);
        System.out.print("   is   ");
        displayRational(ans);
    }
    void mulRational(Rational R1, Rational R2)
    {
        float ansn, ansd;

        ansn = R2.num * R1.num;
        ansd = R1.den * R2.den;

        Rational ans = new Rational(ansn, ansd);
        System.out.print("\n\nThe multiplication of  ");
        displayRational(R1);
        System.out.print("  *  ");
        displayRational(R2);
        System.out.print("   is   ");
        displayRational(ans);
    }
    void divRational(Rational R1, Rational R2)
    {
        float ansn, ansd;

        ansn = R2.den * R1.num;
        ansd = R1.den * R2.num;

        Rational ans = new Rational(ansn, ansd);
        System.out.print("\n\nThe division of  ");
        displayRational(R1);
        System.out.print("  /  ");
        displayRational(R2);
        System.out.print("   is   ");
        displayRational(ans);
    }
}

class rationalMain {
    public static void main(String ar[])throws IOException
    {
        Scanner s = new Scanner(System.in);
        
        System.out.println("\nEnter the first rational number a / b");
        System.out.print("\nEnter a:  ");
        int a = s.nextInt();
        
        System.out.print("Enter b:  ");
        int b = s.nextInt();
        
        Rational r1 = new Rational(a, b);
        System.out.print("\nThe rational number entered is ");
        r1.displayRational(r1);
        
        
        System.out.println("\n\nEnter the second rational number c / d");
        System.out.print("\nEnter c:  ");
        a = s.nextInt();
        
        System.out.print("Enter d:  ");
        b = s.nextInt();
        Rational r2 = new Rational(a, b);
        System.out.print("\nThe rational number entered is:  ");
        r2.displayRational(r2);
        System.out.println();

        r1.addRational(r1, r2);
        r1.subRational(r1, r2);
        r1.mulRational(r1, r2);
        r1.divRational(r1, r2);
        System.out.println();
    }
}