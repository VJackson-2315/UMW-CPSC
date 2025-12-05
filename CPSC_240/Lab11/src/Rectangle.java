public class Rectangle extends Polygon {
    private double length;
    private double width;

    public Rectangle(String name, double length, double width) {
        super(name, 4);
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }

    @Override
    public double getPerimeter() {
        return (2*length) + (2*width);
    }
}