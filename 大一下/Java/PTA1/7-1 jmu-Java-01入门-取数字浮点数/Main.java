import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String a = cin.nextLine();
            int res = 0;
            for (int i = 0; i < a.length(); i ++ ) {
                if (a.charAt(i) >= '0' && a.charAt(i) <= '9')
                    res += a.charAt(i) - '0';
            }
            System.out.println(res);
        }
        cin.close();
    }
}