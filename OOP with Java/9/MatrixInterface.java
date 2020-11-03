import java.io.*;
import java.lang.*;
import java.util.*;

interface Matrix
{
    // All the methods inside an interface are implicitly public and all fields are implicitly public static final
    // by default public static final
    int m = 3, n = 3;
    // by default public
    void readMatrix(int[][] a)throws IOException;
    void displayMatrix(int[][] a);
    int[][] addMatrices(int[][] a, int[][] b);
}

class operations implements Matrix
{
    Scanner s = new Scanner(System.in);

    public void readMatrix(int[][] a)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = s.nextInt();
    }

    public void displayMatrix(int[][] a)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                System.out.print(a[i][j] + "\t");
            System.out.println();
        }
    }

    public int[][] addMatrices(int[][] a, int[][] b)
    {
        int[][] c = new int[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                c[i][j] = a[i][j] + b[i][j];
        return c;
    }
}


class MatrixInterface {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        operations x = new operations();

        // FIRST MATRIX INPUT;
        // System.out.print("\nEnter the number of rows(m) and columns(n) for the First Matrix:  ");
        // int m = s.nextInt();
        // int n = s.nextInt();
        int n = 3, m = 3;
        int[][] a = new int[n][m]; 

        System.out.println("Enter First Matrix: ");
        x.readMatrix(a);
        System.out.println("\nThe entered matrix is: ");
        x.displayMatrix(a);  
        
        // SECOND MATRIX INPUT
        // System.out.print("\nEnter the number of rows(p) and columns(q) for the Second Matrix:  ");
        // int p = s.nextInt();
        // int q = s.nextInt();
        int[][] b = new int[n][m];
        
        System.out.println("Enter Second Matrix: ");
        x.readMatrix(b);  
        System.out.println("\nThe entered matrix is: ");
        x.displayMatrix(b); 

        // ADDITION
        // if(m == p && n == q)
        // {
            System.out.println("\nThe addition of the given two matrices are: ");
            int[][] c = x.addMatrices(a, b);
            x.displayMatrix(c);
        // }
        // else
            // System.out.println("\nThe given two matrices cannot be added! ");

    }
}
