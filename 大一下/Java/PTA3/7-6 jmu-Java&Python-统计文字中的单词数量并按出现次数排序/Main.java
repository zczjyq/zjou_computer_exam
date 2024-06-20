import java.util.*;

public class Main {
	public static void main(String[] args) {
		Map<String, Integer> map = new HashMap<>();
		Scanner cin = new Scanner(System.in);
		while (true) {
			String string = cin.nextLine();
			if (string.equals("!!!!!")) break;
			string = string.toLowerCase();
			string = string.replaceAll("[!.,:*?]", " ");
			String[] words = string.split("\\s+");
			for (String word : words) {
				if (!word.isEmpty()) {
					map.put(word, map.getOrDefault(word, 0) + 1);
				}
			}
			
		}
		List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());

		Collections.sort(list, (o1, o2) -> {
				if (o2.getValue().equals(o1.getValue())) return o1.getKey().compareTo(o2.getKey());
				return o2.getValue().compareTo(o1.getValue());
		});
		
		System.out.println(list.size());
        for (int i = 0; i < Math.min(list.size(), 10); i ++ ) {
        	System.out.println(list.get(i).getKey() + "=" + list.get(i).getValue());
        }
		cin.close();
 	}
}