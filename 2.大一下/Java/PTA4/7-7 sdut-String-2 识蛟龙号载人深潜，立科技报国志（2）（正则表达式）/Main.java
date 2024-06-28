import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Pattern pattern = Pattern.compile("[0-9]+");
        while (cin.hasNext()) {
            String string = cin.nextLine();
            if (string.equals("end"))
                break;
            Matcher matcher = pattern.matcher(string);
            int sum = 0;
            while (matcher.find()) {
                sum += Integer.valueOf(matcher.group());
            }
            System.out.println(sum);
        }
        cin.close();
    }
}