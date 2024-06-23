import java.util.*;

class Ring {
    private double innerRadius;
    private double outerRadius;
    
    public Ring(double innerRadius, double outerRadius) {
        super();
        this.innerRadius = innerRadius;
        this.outerRadius = outerRadius;
        System.out.println("constructor");
    }
    
    public Ring() {
        super();
        this.innerRadius = 1;
        this.outerRadius = 3;
        System.out.println("constructor");
    }

    public double getInnerRadius() {
        return innerRadius;
    }
    
    public void setInnerRadius(double innerRadius) {
        this.innerRadius = innerRadius;
    }
    
    public double getOuterRadius() {
        return outerRadius;
    }
    
    public void setOuterRadius(double outerRadius) {
        this.outerRadius = outerRadius;
    }
    
    public int getArea() {
        return (int)((this.outerRadius * this.outerRadius - this.innerRadius * this.innerRadius) * Math.PI);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        double a = cin.nextDouble(), b = cin.nextDouble();
        Ring ring = new Ring(a, b);
        System.out.println(ring.getArea());
        Ring ring2 = new Ring();
        System.out.println(ring2.getArea());
        cin.close();
    }
}