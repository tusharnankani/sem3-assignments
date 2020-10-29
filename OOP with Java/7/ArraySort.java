import java.io.*;
import java.lang.*;
import java.util.*;

class ArrayNotSortedException extends Exception
{
    ArrayNotSortedException()
    {
        System.out.println("\nThe elements are not sorted!");
    }
}

class Bubble
{
	void readArray(int[] a)throws IOException
	{
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("\nEnter " + a.length + " numbers:  ");
		Scanner s = new Scanner(System.in);
		for(int i = 0; i < a.length; i++)
			a[i] = s.nextInt();
	}

	void displayArray(int[] a)
	{
        for(int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
		System.out.println("");	
	}


	int[] ascending(int[] a)
	{
		for(int i = 0; i < a.length - 1; i++)
		{
            for(int j = 0; j < a.length - i - 1; j++)
			{
				if(a[j] > a[j + 1])
				{
                    int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
        }	
        return a;
    }
    
    boolean isSorted(int[] a)
    {
        boolean ok = true;
        for(int i = 0; i < a.length - 1; i++)
        {
            if(a[i] > a[i + 1])
                ok = false;
        }
        return ok;
    }
}

class ArraySort {
    public static void main(String args[])throws IOException
	{
        int n;
		Scanner s = new Scanner(System.in);
		System.out.print("\nEnter the size of the array: ");
		n = s.nextInt();
		
		int[] a = new int[n];	
        
		Bubble x = new Bubble();
		
		x.readArray(a);
        System.out.print("\nThe elements entered were:  ");
        x.displayArray(a);
        
        
        try {
            if(x.isSorted(a))
            {
                System.out.print("\nThe elements are already sorted:  ");
                x.displayArray(a);
            }
            else
                throw new ArrayNotSortedException();
        }
        catch(ArrayNotSortedException e)
        {
            int[] b = x.ascending(a);
            System.out.print("\nThe sorted elements are:  ");
            x.displayArray(b);
        }
    }
}
