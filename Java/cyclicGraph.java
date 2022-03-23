<<<<<<< HEAD
import java.util.*;

public class cyclicGraph {
    public static void main(String[] args)   {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Vertec and Edge\n");
        String v = sc.nextLine();
        int e = sc.nextInt();

        String[] vertices = vertices(v);    //Split vertices from String to Array

        HashMap<String,ArrayList<String>> adjacencyList = new HashMap<String,ArrayList<String>>();
        for(int i=0;i<e;i++) {
            String fv = sc.nextLine();
            String sv = sc.nextLine();
            adjacencyList.put(fv, new ArrayList<String>());
            adjacencyList.get(fv).add(sv);
        }
        sc.close();

        //Print Area
        printArray(vertices);//Print Array Elements
        printGraph(adjacencyList);  //Graph Print
    }

    //Graph Print
    static void printGraph(HashMap<String,ArrayList<String>> adjacency)    {
        for(HashMap.Entry<String,ArrayList<String>> entry : adjacency.entrySet())   {
            System.out.println(entry.getKey()+" ");
            for(int i=0;i<entry.getValue().size();i++) {
                System.out.println(entry.getValue().get(i)+" ");
            }
            System.out.println("\n");
        }
    }

    //Split vertices from String to Array
    static String[] vertices(String v)    {
        String[] vertices = v.split(";");
        return vertices;
    }

    //Print Array Elements
    static void printArray(String[] vertices)    {
        for(String v : vertices) {
            System.out.println(v+" ");
        }
        System.out.println("\n");
    }

}
=======
import java.util.*;

public class cyclicGraph {
    public static void main(String[] args)   {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Vertec and Edge\n");
        String v = sc.nextLine();
        int e = sc.nextInt();

        String[] vertices = vertices(v);    //Split vertices from String to Array

        HashMap<String,ArrayList<String>> adjacencyList = new HashMap<String,ArrayList<String>>();
        for(int i=0;i<e;i++) {
            String fv = sc.nextLine();
            String sv = sc.nextLine();
            adjacencyList.put(fv, new ArrayList<String>());
            adjacencyList.get(fv).add(sv);
        }
        sc.close();

        //Print Area
        printArray(vertices);//Print Array Elements
        printGraph(adjacencyList);  //Graph Print
    }

    //Graph Print
    static void printGraph(HashMap<String,ArrayList<String>> adjacency)    {
        for(HashMap.Entry<String,ArrayList<String>> entry : adjacency.entrySet())   {
            System.out.println(entry.getKey()+" ");
            for(int i=0;i<entry.getValue().size();i++) {
                System.out.println(entry.getValue().get(i)+" ");
            }
            System.out.println("\n");
        }
    }

    //Split vertices from String to Array
    static String[] vertices(String v)    {
        String[] vertices = v.split(";");
        return vertices;
    }

    //Print Array Elements
    static void printArray(String[] vertices)    {
        for(String v : vertices) {
            System.out.println(v+" ");
        }
        System.out.println("\n");
    }

}
>>>>>>> d430e7484d1a6fea6c0fcdb61b54cae3c9cd8776
