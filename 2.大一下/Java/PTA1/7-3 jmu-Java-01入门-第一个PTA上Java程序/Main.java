import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int a = cin.nextInt(), b = cin.nextInt();
            if (Math.abs(a) > 1000) {
                System.out.println("|a|>1000\n");
            } else {
                System.out.println(a + b);
            }
        }
        cin.close();
    }
}