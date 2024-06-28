import java.util.*;

class Person {
    private String name;
    private boolean gender;
    private int age;
    private int id;
    public static int mid = 0;
    static {
        System.out.println("This is static initialization block");
    }
    public Person() {
        super();
        System.out.println("This is constructor");
        System.out.println(this.name + "," + String.valueOf(age) + "," + String.valueOf(gender) + "," + String.valueOf(id));
    }

    public Person(String name, boolean gender, int age) {
        super();
        this.name = name;
        this.gender = gender;
        this.age = age;
    }
    
    {
        this.id = mid;
        mid ++;
        System.out.println("This is initialization block, id is " + String.valueOf(id));
    }
    
    @Override
    public String toString() {
        return "Person [name=" + name + ", age=" + age + ", gender=" + gender + ", id=" + id + "]";
    }
    
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Person> list = new ArrayList<Person>();
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for (int i = 0; i < n; i ++ ) {
            String name = cin.next();
            int age = cin.nextInt();
            boolean gender = cin.nextBoolean();
            Person person = new Person(name, gender, age);
            list.add(person);
        }
        Collections.reverse(list);
        for (Person person : list) {
            System.out.println(person);
        }
        Person oPerson = new Person();
        System.out.println(oPerson);
        cin.close();
    }
}