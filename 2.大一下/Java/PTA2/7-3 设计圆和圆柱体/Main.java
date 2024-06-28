import java.util.*;

class Circle {
    private double radius;

    public Circle(double radius) {
        super();
        this.radius = radius;
    }
    
    public Circle() {
        super();
        this.radius = 0;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
    
    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }
    
    public double getPerimeter() {
        return Math.PI * 2 * this.radius;
    }

    @Override
    public String toString() {
        return "Circle(r:" + radius + ")";
    }    
}

class Cylinder {
    private double height;
    private Circle circle;
    
    public Cylinder(double height, Circle circle) {
        super();
        this.height = height;
        this.circle = circle;
    }
    
    public Cylinder() {
        super();
        this.height = 0;
        this.circle = new Circle();
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public Circle getCircle() {
        return circle;
    }

    public void setCircle(Circle circle) {
        this.circle = circle;
    }
    
    public double getArea() {
        return this.circle.getArea() * 2 + this.height * circle.getPerimeter();
    }
    
    public double getVolume() {
        return circle.getArea() * this.height;
    }

    @Override
    public String toString() {
        return "Cylinder(h:" + height + ",Circle(r:" + circle.getRadius() + "))";
    }
    
    
}

public class Main{
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for(int i = 0; i < n; i++) {
            String str = input.next();
            if(str.equals("Circle")) {
                Circle c = new Circle(input.nextDouble());
                System.out.println("The area of " + c.toString() + " is " + String.format("%.2f",c.getArea()));
                System.out.println("The perimeterof " + c.toString() + " is "+ String.format("%.2f",c.getPerimeter()));
            } else if(str.equals("Cylinder")) {
                Cylinder r = new Cylinder(input.nextDouble(), new Circle(input.nextDouble()));
                System.out.println("The area of " + r.toString() + " is " + String.format("%.2f",r.getArea()));
                System.out.println("The volume of " + r.toString() + " is " + String.format("%.2f",r.getVolume()));
            }
        }
        input.close();
    }
}