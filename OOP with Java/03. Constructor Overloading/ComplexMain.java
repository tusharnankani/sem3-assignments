import java.io.*;

class Complex
{
	float real,img;
	Complex(float r,float i)
	{
		real=r;
		img=i;
	}
	
	void addComplex(Complex c1,Complex c2)
	{
		c1.real+=c2.real;
		c1.img+=c2.img;
	}
	void display()
	{
		System.out.println(real+" + i"+img);
	}
}

class ComplexMain
{
	public static void main(String a[]) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		float x,y;
		System.out.print("Enter real part of c1: ");
		x=Float.parseFloat(br.readLine());
		System.out.print("Enter imaginary part of c1: ");
		y=Float.parseFloat(br.readLine());
		Complex c1=new Complex(x,y);
		Complex c2=new Complex(4.5f,6.2f);
		c1.addComplex(c1,c2);
		c1.display();
	}
}
