import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String a = cin.nextLine();
        BigInteger bigInteger = new BigInteger(a);
        
        while (cin.hasNext()) {
            String b = cin.nextLine();
            if (b.equals("e") || b.equals("E")) break;
            BigInteger bigInteger2 = new BigInteger(b);
            bigInteger = bigInteger.add(bigInteger2);
        }
        cin.close();
        System.out.println(bigInteger);
    }
}