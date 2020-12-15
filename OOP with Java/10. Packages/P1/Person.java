package P1;
import java.io.*;
import java.lang.*;
import java.util.*;

public class Person {
    String name;
    int age;

    public Person(String n, int a) {
        name = n;
        age = a;
    }

    public void display() {
        System.out.println("\nThe name of the person is: " + name + ".");
        System.out.println("The age of the person is:  " + age + ".");
    }
}
