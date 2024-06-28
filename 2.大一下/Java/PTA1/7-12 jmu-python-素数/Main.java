import java.util.*;

public class Main {
    static boolean is_prime(int v) {
        if (v < 2) return false;
        for (int i = 2; i <= v / i; i ++ ) {
            if (v % i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int v = cin.nextInt();
        if (is_prime(v)) {
            System.out.println(String.valueOf(v) + " is prime");
        } else {
            System.out.println(String.valueOf(v) + " is not prime");
        }
        cin.close();
    }
}