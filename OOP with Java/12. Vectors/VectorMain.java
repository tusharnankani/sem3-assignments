import java.util.*;  

public class VectorMain {  
    public static void main(String args[]) {  
        //Create an empty vector with initial capacity 4  
        Vector<String> vec = new Vector<String>(4);  
        //Adding elements to a vector  
        vec.add("Apple");  
        vec.add("Banana");  
        vec.add("Guava");  
        vec.add("Spinach");  

        //Check size and capacity  
        System.out.println("Size is: "+vec.size());  
        System.out.println("Default capacity is: "+vec.capacity());  

        //Display Vector elements  
        System.out.println("Vector element is: "+vec);  

        vec.addElement("Juice");  
        vec.addElement("Flour");  
        vec.addElement("Rice");  

        //Again check size and capacity after two insertions  
        System.out.println("Size after addition: "+vec.size());  
        System.out.println("Capacity after addition is: "+vec.capacity());  

        //Display Vector elements again  

        //Checking if Tiger is present or not in this vector         
        if(vec.contains("Chickoo"))  
        {  
            System.out.println("Chickoo is present at the index " +vec.indexOf("Chickoo"));  
        }  
        else  
        {  
            System.out.println("Chickoo is not present in the list.");  
        }  

        //Get the first element  
        System.out.println("The first item of the list is = "+vec.firstElement());   
        //Get the last element  
        System.out.println("The last item of the list is = "+vec.lastElement());   
    }  
}  