import java.util.*;

class Person {
    private String num;
    private String name;
    private int age;
    private String gender;
    
    public Person(String num, String name, int age, String gender) {
        this.num = num;
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public String getNum() {
        return num;
    }

    public void setNum(String num) {
        this.num = num;
    }

    @Override
    public int hashCode() {
        return Objects.hash(age, gender, name, num);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Person other = (Person) obj;
        return age == other.age && Objects.equals(gender, other.gender) && Objects.equals(name, other.name)
                && Objects.equals(num, other.num);
    }

    @Override
    public String toString() {
        return num + " " + name + " " + age + " " + gender;
    }
    
}

public class Main {
    public static void main(String[] args) {
        Map<String, Person> map = new HashMap<>();
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for (int i = 0; i < n; i ++ ) {
            String nums = cin.next(), name = cin.next();
            int age = cin.nextInt();
            String gender = cin.next();
            map.put(nums, new Person(nums, name, age, gender));
        }
        List<Person> list = new ArrayList<Person>(map.values());
        System.out.println(list.size());
        Collections.sort(list, (o1, o2) -> {
            return o1.getNum().compareTo(o2.getNum());
        });
        for (Person person : list) {
            System.out.println(person);
        }
        cin.close();
    }
}