import java.io.*;
import java.lang.*;
class Armstrong
{
      public static void main(String ar[])throws IOException
      {
            	int num, len, ans = 0, i, tmp;
            	String numStr;
 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number: ");

		num = Integer.parseInt(br.readLine());

		for(i = 100; i <= num; i++)
		{
			len = 0;
			ans = 0;
			tmp = i;
			while(tmp != 0)
			{
				tmp /= 10;
				len += 1;
			}			
			tmp = i;
			while(tmp != 0)
			{
				ans += Math.pow(tmp % 10, len);
				tmp /= 10;
			}
			if(i == ans)
				System.out.println("Armstrong number: " + ans);	
		}
      }
}