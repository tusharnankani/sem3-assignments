import java.util.*;


class stringSort 
{
    void stringArraySort(String[] s)
    {
        for(int i = 0; i < s.length; ++i)
        {
            for(int j = 0; j < s.length - 1; ++j)
            {
                if(s[j].compareTo(s[j + 1]) > 0)
                {
                    String temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
        display(s);
    }
    
    void display(String[] s)
    {
        System.out.println("\nThe sorted order is: ");
        for(int i = 0; i < s.length; ++i)
        {
            System.out.println("Friend " + (i + 1) + ": " + s[i]);
        }
    }
}

class stringNames 
{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("\nEnter number of friends: ");
        int n = sc.nextInt();
        
        String str[] = new String[n];
        StringBuffer sb[] = new StringBuffer[n];
        System.out.print("\nEnter the names of " + n + " friends: \n");
        sc.nextLine();
        for(int i = 0; i < n; ++i)
        {
            System.out.print("Enter the name of friend " + (i + 1) + ": ");
            str[i] = sc.nextLine();
            sb[i] = new StringBuffer(str[i]);            
        }
        
        stringSort x = new stringSort();
        x.stringArraySort(str);
        
        // Arrays.sort(str);
        // System.out.println(Arrays.toString(str));
        
        
        for(int i = 0; i < n; ++i)
        {
            str[i] = new String(sb[i].delete(0, 3));            
        }

        x.stringArraySort(str);
    }
}