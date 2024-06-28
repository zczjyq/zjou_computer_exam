import java.util.*;

class Car {
	private int num;
	private String name;
	private int person;
	private double ton;
	private int money;
	
	public Car(int num, String name, int person, double ton, int money) {
		this.num = num;
		this.name = name;
		this.person = person;
		this.ton = ton;
		this.money = money;
	}
	
	public Car() {
		this.num = 0;
		this.name = null;
		this.person = 0;
		this.ton = 0;
		this.money = 0;
	}

	public int getNum() {
		return num;
	}

	public void setNum(int num) {
		this.num = num;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getPerson() {
		return person;
	}

	public void setPerson(int person) {
		this.person = person;
	}

	public double getTon() {
		return ton;
	}

	public void setTon(double ton) {
		this.ton = ton;
	}

	public int getMoney() {
		return money;
	}

	public void setMoney(int money) {
		this.money = money;
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		Car[] car = new Car[11];
        car[1] = new Car(1, "A", 5, 0, 800);
        car[2] = new Car(2, "B", 5, 0, 400);
        car[3] = new Car(3, "C", 5, 0, 800);
        car[4] = new Car(4, "D", 51, 0, 1300);
        car[5] = new Car(5, "E", 55, 0, 1500);
        car[6] = new Car(6, "F", 5, 0.45, 500);
        car[7] = new Car(7, "G", 5, 2.0, 450);
        car[8] = new Car(8, "H", 0, 3, 200);
        car[9] = new Car(9, "I", 0, 25, 1500);
        car[10] = new Car(10, "J", 0, 35, 2000);
		int f = cin.nextInt();
		if (f == 1) {
			int all_person = 0, money = 0;
			double weight = 0;
			int num = cin.nextInt();
			while (num -- != 0) {
				int m = cin.nextInt(), n = cin.nextInt();
				all_person += car[m].getPerson() * n;
				money += car[m].getMoney() * n;
				weight += car[m].getTon() * n;
			}
			System.out.println(all_person + " " + String.format("%.2f", weight) + " " + money);
		} else {
			System.out.println("0 0.00 0");
		}
        cin.close();
	}
}