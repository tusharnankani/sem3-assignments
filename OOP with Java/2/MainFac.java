import java.io.*;
import java.lang.*;
class Factorial
{
	int f, num;

	void getNum()throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number: ");
		num = Integer.parseInt(br.readLine());
	}
	void fact()
	{
		f = 1;
		for(int i = 2; i <= num; i++)
			f *= i;
	}
	void printf()
	{
		System.out.println("The factorial of " + num + " is " + f);
	}
      	
}

class MainFac{

	public static void main(String ar[])throws IOException
      	{
            	Factorial ans = new Factorial();
		ans.getNum();
		ans.fact();
		ans.printf();
      	}
}