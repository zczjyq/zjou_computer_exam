import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i ++ ) {
			nums[i] = cin.nextInt();
		}
		int max = 0, index = 0;
		for (int i = 0; i < n; i ++ ) {
			int count = 0;
			for (int j = 0; j < n; j ++ ) {
				if (nums[i] == nums[j]) {
					count ++ ;
				}
			}
			if (max < count) {
				max = count; 
				index = nums[i];
			}
		}
		System.out.printf("%d %d", index, max);
		cin.close();
	}
}