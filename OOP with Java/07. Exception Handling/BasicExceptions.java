import java.util.*;
class BasicExceptions
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        int []arr=new int[5];
        try{
            System.out.println(arr[7]);
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("length of the array is 5!");
        }
        try{
            int a=1,b=0;
            int c=a/b;
        }
        catch(ArithmeticException e)
        {
            System.out.println("Can't divide a number by 0!");
        }
        try{
            System.out.println("Enter a number");
            int a=sc.nextInt();
        }
        catch(InputMismatchException e)
        {
            System.out.println("Types dont match!");
        }

    }
}