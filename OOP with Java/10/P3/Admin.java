package P3;
import P2.*;
import java.io.*;
import java.lang.*;
import java.util.*;

public class Admin extends Account {
    int experience;
    public Admin(int e, float s, String n, int a) {
        super(s, n, a);
        experience = e;
    }
    public void display() {
        super.display();
        System.out.println("The experience of the person is: " + experience + " years.");
    }
}