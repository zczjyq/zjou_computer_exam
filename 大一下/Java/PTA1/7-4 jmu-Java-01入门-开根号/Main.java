import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            double num = cin.nextDouble();
            if (num < 0) {
                System.out.println("NaN");
                continue;
            }
            double res = 0, eps = 0.0001;
            while (res * res < num && Math.abs(res * res - num) > eps) {
                res += eps;
            }
            System.out.printf("%.6f\n", res);
        }
        cin.close();
    }
}