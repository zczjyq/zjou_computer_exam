import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long time = cin.nextLong();
        GregorianCalendar g = new GregorianCalendar();
        g.setTimeInMillis(time);
        System.out.println(g.get(GregorianCalendar.YEAR) + "-" + g.get(GregorianCalendar.MONTH) + "-" + g.get(GregorianCalendar.DAY_OF_MONTH));
        cin.close();
    }
}