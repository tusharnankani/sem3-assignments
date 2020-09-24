import java.io.*;
import java.lang.*;
class Go
{
	double ans = 0, pi = 3.142;
	int choice = 0;
	int display()throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("[0] Right angled Triangle");
		System.out.println("[1] Square");
		System.out.println("[2] Rectangle");
		System.out.println("[3] Circle");
		System.out.println("[4] Cuboid");
		System.out.print("Enter the shape whose area is to be calculated: ");
		choice = Integer.parseInt(br.readLine());
		return choice;	
	}
	void compute()throws IOException
	{
		int c = display();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		if(c == 0)
		{
			double a, b;
			System.out.print("Enter the HEIGHT of the triangle: ");
			a = Integer.parseInt(br.readLine());
			System.out.print("Enter the BASE of the triangle: ");
			b = Integer.parseInt(br.readLine());
			ans = area(a, b);
		}
		else if(c == 1)
		{
			int a;
			System.out.print("Enter the side of the square: ");
			a = Integer.parseInt(br.readLine());
			ans = area(a);
		}
		else if(c == 2)
		{
			int a, b;
			System.out.print("Enter the Length of the Rectangle: ");
			a = Integer.parseInt(br.readLine());
			System.out.print("Enter the Breadth of the Rectangle: ");
			b = Integer.parseInt(br.readLine());
			ans = area(a, b);
		}
		else if(c == 3)
		{
			double a;
			System.out.print("Enter the radius of the circle: ");
			a = Integer.parseInt(br.readLine());
			ans = area(a);
		}

		else if(c == 4)
		{
			int a, b, d;
			System.out.print("Enter the Length of the Cuboid: ");
			a = Integer.parseInt(br.readLine());
			System.out.print("Enter the Breadth of the Cuboid:");
			b = Integer.parseInt(br.readLine());
			System.out.print("Enter the Height of the Cuboid: ");
			d = Integer.parseInt(br.readLine());
			ans = area(a, b, d);
		}
		putAns();
	}

	double area(double a, double b)
	{
		return (0.5 * a * b);
	}
	int area(int a)
	{
		return a * a;
	}
	int area(int a, int b)
	{
		return a * b;
	}
	double area(double a)
	{
		return (pi * a * a);
	}
	int area(int a, int b, int d)
	{
		return (2 * (a * b + b * d + d * a));
	}

	void putAns()
	{
		System.out.println("The area of the selected shape is " + ans);
	}
      	
}


class AreaShape
{
	public static void main(String ar[])throws IOException
	{
		Go r = new Go();
		r.compute();
		r.display();
	}
}
