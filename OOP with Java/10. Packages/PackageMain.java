import P3.*;
import java.io.*;
import java.lang.*;
import java.util.*;

class PackageMain {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

        int age, experience;
        float salary;
        String name;

        System.out.print("\nEnter name: ");
        name = br.readLine();
        while(true) {
            try {
                System.out.print("\nEnter age: ");
                age = sc.nextInt();
                break;
            }
            catch(InputMismatchException e)
            {
                sc.nextLine();
                System.out.println("Types do not match. Please enter a number!");
            }
        }
        while(true) {
            try {
                System.out.print("\nEnter experience: ");
                experience = sc.nextInt();
                break;
            }
            catch(InputMismatchException e)
            {
                sc.nextLine();
                System.out.println("Types do not match. Please enter a number!");
            }
        }
        while(true) {
            try {
                System.out.print("\nEnter Salary: ");
                salary = sc.nextInt();
                break;
            }
            catch(InputMismatchException e)
            {
                sc.nextLine();
                System.out.println("Types do not match. Please enter a number!");
            }
        }

        Admin ad = new Admin(experience, salary, name, age);
        ad.display();
    }
}
