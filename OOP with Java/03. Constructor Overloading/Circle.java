import java.io.*;
class Circle
{
    int radius;
    Circle()
    {
        int r=7;
        radius=r;
        System.out.println("Radius="+r);
    }
    double circumference()
    {
        System.out.println("Circumference:"+2*3.14*radius);
        return(2*3.14*radius);
    }
    double area()
    {
        System.out.println("Area:"+3.14*radius*radius);
        return (3.14*radius*radius);
    }
    public static void main(String a[])
    {
        Circle c=new Circle();
        c.circumference();
        c.area();
    }
}	