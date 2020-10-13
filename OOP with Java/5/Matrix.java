import java.io.*;
import java.lang.*;
import java.util.*;

class operations
{
    Scanner s = new Scanner(System.in);

    void readMatrix(int[][] a)throws IOException
    {
        for(int i = 0; i < a.length; i++)
            for(int j = 0; j < a[i].length; j++)
                a[i][j] = s.nextInt();
    }

    void displayMatrix(int[][] a)throws IOException
    {
        for(int i = 0; i < a.length; i++)
        {
            for(int j = 0; j < a[i].length; j++)
                System.out.print(a[i][j] + "\t");
            System.out.println();
        }
    }

    int[][] addMatrices(int[][] a, int[][] b)throws IOException
    {
        int[][] c = new int[a.length][a[0].length];
        for(int i = 0; i < a.length; i++)
            for(int j = 0; j < a[i].length; j++)
                c[i][j] = a[i][j] + b[i][j];
        return c;
    }

    int[][] subtractMatrices(int[][] a, int[][] b)throws IOException
    {
        int[][] d = new int[a.length][a[0].length];
        for(int i = 0; i < a.length; i++)
            for(int j = 0; j < a[i].length; j++)
                d[i][j] = a[i][j] - b[i][j];
        return d;
    }

    int[][] multiplyMatrices(int[][] a, int[][] b)throws IOException
    {
        int[][] e = new int[a.length][b[0].length];
        int sum = 0;
        for(int i = 0; i < a.length; i++)
        {
            for(int j = 0; j < b[0].length; j++)
            {
                for(int k = 0; k < a[0].length; k++)
                    sum += (a[i][k] * b[k][j]);

                e[i][j] = sum;
                sum = 0;
            }
        }
        return e;
    }

    void transposeMatrix(int[][] a)throws IOException
    {
        int[][] f = new int[a[0].length][a.length];
        for(int i = 0; i < a.length; i++)
            for(int j = 0; j < a[i].length; j++)
                f[j][i] = a[i][j];
        displayMatrix(f);
    }

    boolean checkSymmetric(int[][] a)throws IOException
    {
        boolean ok = true;
        for(int i = 0; i < a.length; i++)
            for(int j = 0; j < a[i].length; j++)
                if(a[i][j] != a[a.length - i - 1][a[0].length - j - 1])
                    ok = false;
        return ok;
    }
}

class Matrix
{
    public static void main(String ar[])throws IOException
    {
        Scanner s = new Scanner(System.in);
        operations x = new operations();

        // FIRST MATRIX INPUT;
        System.out.print("\nEnter the number of rows(m) and columns(n) for the First Matrix:  ");
        int m = s.nextInt();
        int n = s.nextInt();
        int[][] a = new int[m][n]; 

        System.out.println("Enter First Matrix: ");
        x.readMatrix(a);
        System.out.println("\nThe entered matrix is: ");
        x.displayMatrix(a);  
        
        // SECOND MATRIX INPUT
        System.out.print("\nEnter the number of rows(p) and columns(q) for the Second Matrix:  ");
        int p = s.nextInt();
        int q = s.nextInt();
        int[][] b = new int[p][q];
        
        System.out.println("Enter Second Matrix: ");
        x.readMatrix(b);  
        System.out.println("\nThe entered matrix is: ");
        x.displayMatrix(b); 

        // ADDITION
        if(m == p && n == q)
        {
            System.out.println("\nThe addition of the given two matrices are: ");
            int[][] c = x.addMatrices(a, b);
            x.displayMatrix(c);
        }
        else
            System.out.println("\nThe given two matrices cannot be added! ");

        // SUBTRACTION
        if(m == p && n == q)
        {
            System.out.println("\nThe subtraction of the given two matrices are: ");
            int[][] d = x.subtractMatrices(a, b);
            x.displayMatrix(d);
        }
        else
            System.out.println("\nThe given two matrices cannot be subtracted! ");

        // MULTIPLICATION
        if(n == p)
        {
            System.out.println("\nThe multiplication of the given two matrices are: ");
            int[][] e = x.multiplyMatrices(a, b);
            x.displayMatrix(e);
        }
        else
            System.out.println("\nThe given two matrices cannot be multiplied! ");

        // TRANSPOSE
        System.out.print("\nEnter the number of rows(m) and columns(n) for the Matrix whose transpose is to be taken:  ");
        int mm = s.nextInt();
        int nn = s.nextInt();
        int[][] aa = new int[mm][nn]; 

        System.out.println("Enter the Matrix: ");
        x.readMatrix(aa);
        System.out.println("\nThe entered matrix is: ");
        x.displayMatrix(aa);  
        System.out.println("\nThe transpose of the given matrix is: ");
        x.transposeMatrix(aa);

        // SYMMETRIC ABOUT THE DIAGAONAL
        if(x.checkSymmetric(aa))
            System.out.println("\nThe given matrix is symmetric about the diagonal!");
        else
            System.out.println("\nThe given matrix is not symmetric about the diagonal!");
    }

}