import static java.lang.Math.PI;

public class Circle extends Shape {
    private double radius;

    public Circle(String name, double radius) {
        super(name);
        this.radius = radius;
    }

    public double getCircumference() {
        return 2 * PI * radius;
    }

    @Override
    public double getArea() {
        return PI * (radius * radius);
    }
}
