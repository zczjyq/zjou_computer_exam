import java.math.BigInteger;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger bigInteger = new BigInteger("0");
        while (cin.hasNext()) {
            String numString  =  cin.next();
            if  (numString.equals("e") || numString.equals("E")) break;
            bigInteger = bigInteger.add(new BigInteger(numString));
        }
        System.out.println(bigInteger);
        cin.close();
    }
}