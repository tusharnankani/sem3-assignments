import java.io.*;
import java.lang.*;
import java.util.*;

class ArrayOper
{

	void readArray(int[] a)throws IOException
	{
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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
	
	void largest(int[] a)
	{
		int mx = a[0];
		for(int i = 0; i < a.length; i++)
			mx = Math.max(a[i], mx);

		System.out.println("The maximum element in the array is " + mx);	
	}
	
	void smallest(int[] a)
	{
		int mn = a[0];
		for(int i = 0; i < a.length; i++)
			mn = Math.min(a[i], mn);

		System.out.println("The minimum element in the array is " + mn);
	}

}

class Main
{
	public static void main(String args[])throws IOException
	{
		int n;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the size of the array: ");
		n = s.nextInt();
		
		int[] a = new int[n];	
	
		ArrayOper x = new ArrayOper();
		
		x.readArray(a);
		x.displayArray(a);
		x.largest(a);
		x.smallest(a);
	}
}