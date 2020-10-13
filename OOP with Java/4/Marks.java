import java.io.*;
import java.lang.*;
import java.util.*;

class Main3
{
	public static void main(String ar[])
	{
		int n = ar.length;
		int x[] = new int[n];

		for(int i = 0; i < n; i++)
			x[i] = Integer.parseInt(ar[i]);
		int sum = 0, mx = n;
		for(int i = 0; i < 5; i++)
		{
			sum += x[i];
			mx = Math.max(x[i], mx);			
		}
		System.out.println("\nTotal Marks: " + sum);
		System.out.println("\nMaximum Marks: " + mx);
	}
}