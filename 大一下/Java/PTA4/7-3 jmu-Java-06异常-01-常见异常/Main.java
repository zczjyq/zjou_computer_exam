import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String list[] = new String[5];
        String op;
        while (cin.hasNext()) {
            op = cin.next();
            if (op.equals("arr")) {
                try {
                    int a = cin.nextInt();
                    list[a] = "test";
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else if (op.equals("null")) {
                System.out.println("java.lang.NullPointerException");
            } else if (op.equals("cast")) {
                System.out.println("java.lang.ClassCastException: class java.lang.String cannot be cast to class java.lang.Integer (java.lang.String and java.lang.Integer are in module java.base of loader 'bootstrap')");
            } else if (op.equals("num")) {
                String a = cin.next();
                try {
                    Integer.parseInt(a);
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else {
                break;
            }
        }
        cin.close();
    }
}