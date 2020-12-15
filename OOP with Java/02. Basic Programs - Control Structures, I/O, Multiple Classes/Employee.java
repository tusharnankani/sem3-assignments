import java.io.*;
import java.lang.*;
class Employee
{
	String name, dept, des, id;

	void getEmp()throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a employee name: ");
		name = br.readLine();
		System.out.println("Enter a employee id: ");
		id = br.readLine();
		System.out.println("Enter a employee Department: ");
		dept = br.readLine();
		System.out.println("Enter a employee Designation:");
		des = br.readLine();
	}
	void putEmp()
	{
		System.out.println("Employee name: "+ name);
		System.out.println("Employee id: " + id);
		System.out.println("Employee Department: " + dept);
		System.out.println("Employee Designation: " + des);
	}
      	public static void main(String ar[])throws IOException
      	{
            	Employee e = new Employee();
		e.getEmp();
		e.putEmp();
      }
}