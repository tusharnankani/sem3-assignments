class Largest { 
    public static void main(String ar[])
    {
        int x,y,z;
        
        x=Integer.parseInt(ar[0]);
        y=Integer.parseInt(ar[1]);
        z=Integer.parseInt(ar[2]);
        int max = ((x > y) ? ((x > z) ? x : ((y > z) ? y : z)) : ((y > z) ? y : ((z > x) ? z : x)));
        System.out.println("The greatest 3 numbers: " + max);
    }  
}
