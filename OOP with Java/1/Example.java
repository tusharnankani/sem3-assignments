import java.io.*;
class Example
{
	public static void main(String args[])throws IOException
	{
		// InputStreamReader i = new InputStreamReader(System.in);
		// BufferedReader br = new BufferedReader(i);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Enter Name:");
		String name = br.readLine();
		System.out.println("My name is: " + name);

		System.out.println("Enter your roll no:");
		int RollNo = Integer.parseInt(br.readLine());
		System.out.println("Roll no. is: " + RollNo);
	}
}