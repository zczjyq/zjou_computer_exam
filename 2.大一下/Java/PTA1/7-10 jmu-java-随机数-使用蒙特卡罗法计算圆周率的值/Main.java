import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long seed = cin.nextLong();
        int n = cin.nextInt();
        Random random = new Random(seed);
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            double x = random.nextDouble() * 2 - 1, y = random.nextDouble() * 2 - 1;
            if (Math.pow(x, 2.0) + Math.pow(y, 2.0) <= 1) {
                res ++ ;
            }
        }
        System.out.println(res / (double)n * 4.0);
         cin.close();
    }
}