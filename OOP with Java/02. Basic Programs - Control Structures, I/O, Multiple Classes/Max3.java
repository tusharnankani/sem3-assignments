import java.io.*;
import java.lang.*;
import java.util.*;

class Max3 {
    int x, y, z, max;
    Scanner s = new Scanner(System.in);

    void getNums()
    {
        System.out.print("Enter 3 numbers: \t");
        x = s.nextInt();
        y = s.nextInt();
        z = s.nextInt();
    }

    int getMax()
    {
        max = ((x > y) ? ((x > z) ? x : ((y > z) ? y : z)) : ((y > z) ? y : ((z > x) ? z : x)));
        return max;
    }
}

class Maximum 
{
    public static void main(String args[])
    {
        Max3 m = new Max3();
        m.getNums();
        int ans = m.getMax();
        System.out.println("The maximum of given 3 numbers is: " + ans);
    }
}
