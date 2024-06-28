import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int a = cin.nextInt();
            if (a > 100) {
                System.out.println("Poor\n"
                        + "class name=class Grade\n"
                        + "grade value=E");
            } else if (a >= 90) {
                System.out.println("Excellent\n"
                        + "class name=class Grade\n"
                        + "grade value=A");
            } else if (a >= 80) {
                System.out.println("Good\n"
                        + "class name=class Grade\n"
                        + "grade value=B");
            } else if (a >= 70) {
                System.out.println("Average\n"
                        + "class name=class Grade\n"
                        + "grade value=C");
            } else if (a >= 60) {
                System.out.println("Fair\n"
                        + "class name=class Grade\n"
                        + "grade value=D");
            } else{
                System.out.println("Poor\n"
                        + "class name=class Grade\n"
                        + "grade value=E");
            }
        }
        cin.close();
    }
}