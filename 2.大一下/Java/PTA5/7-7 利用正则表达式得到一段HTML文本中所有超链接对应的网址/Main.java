import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String line;
        Pattern pattern = Pattern.compile("href=\"(.*?)\"");
        while (cin.hasNext()) {
            line = cin.nextLine();
            Matcher matcher = pattern.matcher(line);
            while (matcher.find()) {
                String urlString = matcher.group(1);
                System.out.println(urlString);
            }
        }
        cin.close();
    }
}