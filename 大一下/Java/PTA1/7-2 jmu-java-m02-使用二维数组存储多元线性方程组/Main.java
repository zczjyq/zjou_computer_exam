import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        double[][] nums = new double[n][n + 1];
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                nums[i][j] = cin.nextDouble();
            }
        }
        System.out.println(Arrays.deepToString(nums));
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                if (j == 0) System.out.printf("%.1f", nums[i][j]);
                else if (j == n) System.out.printf(" = %.1f\n", nums[i][j]);
                else System.out.printf(", %.1f", nums[i][j]);
            }
        }
        cin.close();
    }
}