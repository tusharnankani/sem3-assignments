import java.io.*;
import java.util.*;

class Employee 
{
    String name;
    int id, hours;
    static String company = "XYZ";
    static int perhr = 100;

    // EMPTY CONSTRUCTOR FOR `temp` USED FOR SWAPPING;
    Employee()
    {
    }

    Employee(String n, int i, int hrs)
    {
        name = n;
        id = i;
        hours = hrs;
    }

    void displayData(Employee E)
    {
        System.out.print("\t ");
        System.out.print(E.name);
        System.out.print(" \t ");
        System.out.print(E.id);
        System.out.print("\t");
        System.out.print(company);
        System.out.print("\t\t  ");
        System.out.print(E.hours);
        System.out.print("\t ");
        System.out.print(E.hours * perhr);
        System.out.print("\n");
    }

    void sortbyID(Employee E[])
    {
        // Note: Nothing is passed to this `Employee()` as we are also creating an empt CONSTRUCTOR above;
        Employee temp = new Employee();

        for(int i = 0; i < E.length - 1; i++)
        {
            for(int j = 0; j < E.length - i - 1; j++)
            {
                if(E[j].id > E[j + 1].id)
                {
                    // SWAPPING THE WHOLE OBJECT, on the basis of id;
                    temp = E[j];
                    E[j] = E[j + 1];
                    E[j + 1] = temp;
                }
            }
        }

        for(int i = 0; i < E.length; i++)
            E[i].displayData(E[i]);
    }
    
}


class EmployeeMain {

    public static void main(String args[])throws IOException
    {
        Scanner s = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("\nEnter the number of employees: ");
        int n = s.nextInt();
        // Array of Objects.
        Employee e[] = new Employee[n];
        for(int i = 0; i < n; i++)
        {
            System.out.print("\nEnter the name of employee " + (i + 1) + " :  ");
            String name = br.readLine();
            
            System.out.print("Enter the ID of employee " + (i + 1) + "   :  ");
            int id = s.nextInt();
            
            System.out.print("Enter hours of employee " + (i + 1) + "    :  ");
            int hrs = s.nextInt();
            
            e[i] = new Employee(name, id, hrs);
        }
        
        System.out.println("\tNAME \t ID \tCOMPANY \tHOURS \tSALARY \n");
        System.out.println("---------------------------------------------------------------");
        for(int i = 0; i < n; i++)
            e[i].displayData(e[i]);   
            
        System.out.println("\nAfter Sorting:");
        System.out.println("\n\tNAME \t ID \tCOMPANY \tHOURS \tSALARY \n");
        System.out.println("---------------------------------------------------------------");
        e[0].sortbyID(e);
    }  
}
