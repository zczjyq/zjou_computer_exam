import java.util.*;

public class Main {
    static double fact(int u) {
        if (u == 1) return 1.0;
        return fact(u - 1) * (double)u;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String m1 = cin.next(), n1 = cin.next();
        try {
            int m = Integer.valueOf(m1);
            int n = Integer.valueOf(n1);
            if (m < 0 || n < 0) System.out.println("不能负数");
            else System.out.printf("result=%.2f", fact(n) / fact(m) / fact(n - m));
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("请输入数值");
        }
        cin.close();
    }
}