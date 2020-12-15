class minMax
{
      public static void main(String ar[])
      {
            	int x,y,min;
            	x=Integer.parseInt(ar[0]);
            	y=Integer.parseInt(ar[1]);
 		if(x > y)
		{
			min = y;
			max = x;
		}
		else
		{
			min = x;
			max = y;
		}
		System.out.println("Minimum number: " + min);
		System.out.println("Maximum number: " + max);
      }
}