import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String name = cin.next();
        int age = cin.nextInt();
        String name2 = cin.next();
        int age2 = cin.nextInt();
        String gString = cin.next();
        System.out.println("Student[name=" + name + ",age=" 
        + String.valueOf(age) + "]\n"
                + "Undergraduate[name=" + name2 
                + ",age=" + String.valueOf(age2) + ",major=" + gString + "]");
        cin.close();
    }
}