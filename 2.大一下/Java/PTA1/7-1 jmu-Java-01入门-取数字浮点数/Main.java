import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			String num = cin.next();
			int res = 0;
			for (int i = 0; i < num.length(); i ++ ) {
				int nums = num.charAt(i) - '0';
				if (nums >= 0 && nums <= 9) {
					res += nums;
				}
			}
			System.out.println(res);
		}
        cin.close();
	}
}