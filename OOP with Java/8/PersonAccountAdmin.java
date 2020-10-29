import java.io.*;
import java.lang.*;
import java.util.*;

class Person {
    String name;
    int age;

    Person(String n, int a) {
        name = n;
        age = a;
    }

    void display() {
        System.out.println("\nThe name of the person is: " + name + ".");
        System.out.println("The age of the person is:  " + age + ".");
    }
}

class Account extends Person {
    float salary;

    Account(float s, String n, int a) {
        super(n, a);
        salary = s;
    }

    void display() {
        super.display();
        System.out.println("The salary of the person is: Rs. " + salary);
    }
}

class Admin extends Account {
    int experience;
    Admin(int e, float s, String n, int a) {
        super(s, n, a);
        experience = e;
    }
    void display() {
        super.display();
        System.out.println("The experience of the person is: " + experience + " years.");
    }

}

class PersonAccountAdmin {
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
