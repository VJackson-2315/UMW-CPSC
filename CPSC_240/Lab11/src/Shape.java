public abstract class Shape {
    protected String name;

    public Shape(String name) {
        this.name = name;
    }

    public abstract double getArea();

    public void display() {
        System.out.printf("%s (%f) %n", name, getArea());
    }
}
