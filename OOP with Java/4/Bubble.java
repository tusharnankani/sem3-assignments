import java.io.*;
import java.lang.*;
import java.util.*;

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
		System.out.print("\nThe elements entered were:  ");
		for(int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println("");	
	}


	void ascending(int[] a)
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
		displayFinalArray(a);
	}

	void descending(int[] a)
	{
		for(int i = 0; i < a.length - 1; i++)
		{
			for(int j = 0; j < a.length - i - 1; j++)
			{
				if(a[j] < a[j + 1])
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					
				}
			}
		}	
		displayFinalArray(a);
	
	}

	void displayFinalArray(int[] a)
	{
		System.out.print("\nThe sorted elements are:  ");
		for(int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println("");	
	}
}

class Main2
{
	public static void main(String args[])throws IOException
	{
		int n;
		Scanner s = new Scanner(System.in);
		System.out.print("\nEnter the size of the array: ");
		n = s.nextInt();
		
		int[] a = new int[n];	
	
		Bubble x = new Bubble();
		
		x.readArray(a);
		x.displayArray(a);

		int choice = 0;
		System.out.print("\nEnter order: [1] Ascending [2] Descending :   ");
		choice = s.nextInt();
		
		if(choice == 1)
			x.ascending(a);
		else
			x.descending(a);

		// x.displayFinalArray(a);
	}
}