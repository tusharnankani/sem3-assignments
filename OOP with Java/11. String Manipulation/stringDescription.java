import java.io.*;
import java.lang.*;
import java.util.*;

class stringMethods
{
    int small = 0, capital = 0, spaces = 0, numbers = 0, special = 0;

    void details(String str)
    {
        for(int i = 0; i < str.length(); ++i)
        {
            int ascii = str.charAt(i);

            if(65 <= ascii && ascii <= 90)
                capital += 1;
            else if(97 <= ascii && ascii <= 122)
                small += 1;
            else if(ascii == 32)
                spaces += 1;
            else if(48 <= ascii && ascii <= 57)
                numbers += 1;
            else
                special += 1;
        }
    }

    void display(String str)
    {
        System.out.println("The entered string is: " + str);
        System.out.println("");
        
        System.out.println("+-----------------------+");
        System.out.println("| Uppercase letters: " + capital + "  |");
        System.out.println("| Lowercase letters: " + small + "  |");
        System.out.println("| Numerical letters: " + numbers + "  |");
        System.out.println("| Special letters  : " + special + "  |");
        System.out.println("| Spaces           : " + spaces + "  |");
        System.out.println("+-----------------------+");
    }
    
}


class stringDescription 
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("\nEnter a string: ");
        String str = s.nextLine();

        stringMethods x = new stringMethods();
        x.details(str);
        x.display(str);
    }
}