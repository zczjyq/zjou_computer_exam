import java.util.*;

class ArrayUtils {
	public static double findMax(double[] arr,int begin, int end) throws IllegalArgumentException{
		if (begin < 0) 
			throw new IllegalArgumentException("begin:" + begin + " < 0");
		if (begin >= end)
			throw new IllegalArgumentException("begin:" + begin + " >= end:" + end);
		if (end > arr.length)
			throw new IllegalArgumentException("end:" + end + " > arr.length");
		double max = -100000 ;
		for (int i = begin; i < end; i ++ ) {
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		double[] nums = new double[n];
		for (int i = 0; i < n; i ++ ) nums[i] = cin.nextDouble();
		while (cin.hasNext()) {
			String a = cin.next();
			if (a.equals("end")) break;
			int num = Integer.valueOf(a);
			int b = cin.nextInt();
			try {
				System.out.println(ArrayUtils.findMax(nums, num, b));
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		try {
		     System.out.println(ArrayUtils.class.getDeclaredMethod("findMax", double[].class,int.class,int.class));
		} catch (Exception e1) {
		} 
		cin.close();
	}
}