import java.io.*;
import java.lang.*;
import java.util.*;

class PayOutOfBounds extends Exception
{
    PayOutOfBounds()
    {
        //System.out.println(" ** Salary is out of bound! ** \n");
    }
}

class Salary 
{
    float getSalary()
    {
        Scanner sc = new Scanner(System.in);
        float salary = 0;
        boolean continueInput = true;
        while(continueInput)
        {
            try {
                System.out.print("\nEnter salary for the selected option: ");
                salary = sc.nextFloat();
                continueInput = false;
            } 
            catch(InputMismatchException e) {
                sc.nextLine();
                System.out.println("\n ** Types do not match. Enter salary in numbers! **");
            }
        }
        return salary;
    }
}

class BasicPay
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        float salary;
        int option = 0;
        
        System.out.println("\nEnter the designation: \n[1] Clerk \n[2] Superintendent");
        
        boolean continueInput = true;
        while(continueInput)
        {
            try {
                System.out.print("Enter [1] or [2]:  ");
                option = sc.nextInt();
                continueInput = false;
            } 
            catch(InputMismatchException e) {
                sc.nextLine();
                System.out.println("\n ** Enter 1 or 2! ** ");
            }
        }
        

        Salary s = new Salary();
        salary = s.getSalary();
        if(option == 1)
        {
            try {
                if(salary < 3000 || salary > 10000)
                    throw new PayOutOfBounds();
                else    
                    System.out.println("The entered salary of the Clerk is " + salary);
            }
            catch(PayOutOfBounds e) {
                    System.out.println(" ** Salary out of bounds. **");
            }
        }
        
        else if(option == 2)
        {
            try {
                if(salary < 12000 || salary > 15000)
                    throw new PayOutOfBounds();
                else    
                    System.out.println("The entered salary of the Superintendent is " + salary);
            }
            catch(PayOutOfBounds e) {
                    System.out.println(" ** Salary out of bounds **");
            }
        }
    }
}