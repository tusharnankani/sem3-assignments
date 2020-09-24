import java.io.*;
class marks
{
      public static void main(String ar[])throws IOException
      {
            	int marks;
		char grade = 'F';
            	
 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		System.out.println("Enter the student's marks: ");
		marks=Integer.parseInt(br.readLine());
		if(marks > 90 && marks <= 100)
			grade = 'A';
		else if(marks > 80 && marks <= 90)
			grade = 'B';
		else if(marks > 70 && marks <= 80)
			grade = 'C';
		else if(marks > 60 && marks <= 70)
			grade = 'D';
		else if(marks >= 0 && marks <= 60)
			grade = 'E';
		else{
			System.out.println("INAVALID MARKS");
			System.exit(0);
		}
		System.out.println("Grade: " + grade);
      }
}