import java.util.*;

abstract class Rect {
    double l, h, z;

    public Rect(double l, double h, double z) {
        super();
        if (l <= 0 || h <= 0 || z <= 0) {
            this.l = 0;
            this.h = 0;
            this.z = 0;
        } else {
            this.l = l;
            this.h = h;
            this.z = z;
        }
    }
    
    double length () {
        return 2 * (l + z);
    }
    
    abstract double area();
}

class Cubic extends Rect {

    public Cubic(double l, double h, double z) {
        super(l, h, z);
        // TODO Auto-generated constructor stub
    }

    @Override
    double area() {
        // TODO Auto-generated method stub
        return (l * h + h * z + z * l) * 2;
    }
    
    double v() {
        return l * h * z;
    }
}

class Pyramid extends Rect {

    public Pyramid(double l, double h, double z) {
        super(l, h, z);
        // TODO Auto-generated constructor stub
    }

    @Override
    double area() {
        // TODO Auto-generated method stub
        return h * l + (Math.sqrt(z * z + l * l / 4) * h) + (Math.sqrt(h * h / 4 + z * z) * l);
    }
    
    double v() {
        return l * h * z / 3;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for (int i = 0; i < n; i ++ ) {
            double l = cin.nextDouble(), h = cin.nextDouble(), z = cin.nextDouble();
            Cubic cubic = new Cubic(l, h, z);
            Pyramid pyramid = new Pyramid(l, h, z);
            System.out.printf("%.2f %.2f %.2f %.2f\n", cubic.area(), cubic.v(), pyramid.area(), pyramid.v());
        }
        cin.close();
    }
}