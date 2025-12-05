public class Triangle extends Polygon {
    private double base;
    private double height;
    private double sideA;
    private double sideB;

    public Triangle(String name, double base, double height, double sideA, double sideB) {
        super(name, 3);
        this.base = base;
        this.height = height;
        this.sideA = sideA;
        this.sideB = sideB;
    }

    @Override
    public double getArea() {
        return 0.5 * base * height;
    }

    @Override
    public double getPerimeter() {
        return base + sideA + sideB;
    }
}
