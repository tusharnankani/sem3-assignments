import java.io.*;
import java.lang.*;
import java.util.*;

class NoMatchException extends Exception 
{
    NoMatchException()
    {
        // System.out.println("Strings doesn't match!");
    }
}


class StringException {
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        try {
            System.out.print("Enter a string:  ");
            String str = br.readLine();
            try {
                if(str.equals("India"))
                    System.out.println("\nMatch found!");
                else
                    throw new NoMatchException();
            }
            catch(NoMatchException e) {
                System.out.println("\nString " + str + " doesn't match!");
            }
        }
        catch(InputMismatchException e)
        {
            System.out.println("Types do not match. Please enter a string!");
        }
    }
}
