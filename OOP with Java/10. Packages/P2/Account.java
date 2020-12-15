package P2;
import P1.Person;
import java.io.*;
import java.lang.*;
import java.util.*;

public class Account extends Person {
    float salary;

    public Account(float s, String n, int a) {
        super(n, a);
        salary = s;
    }

    public void display() {
        super.display();
        System.out.println("The salary of the person is: Rs. " + salary);
    }
}