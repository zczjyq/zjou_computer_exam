import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        try {
            int a = cin.nextInt();
            int b = cin.nextInt();
            if (b == 0) {
                System.out.println("zero division error");
            } else {
                System.out.printf("%.2f", a * 1.0 / b);
            }
        } catch (Exception e) {
            System.out.println("the input is not numerical");
            // TODO: handle exception
        }
        cin.close();
    }
}