import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i ++ ) {
			String num = cin.next();
			try {
				int a = Integer.valueOf(num);
				nums[i] = a;
			} catch (Exception e) {
				i -- ;
				System.out.println(e);
			}
		}
        cin.close();
		System.out.println(Arrays.toString(nums));
	}
}