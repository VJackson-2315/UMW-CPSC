public abstract class Polygon extends Shape {
    private int numSides;

    public Polygon(String name, int numSides) {
        super(name);
        this.numSides = numSides;
    }

    public abstract double getPerimeter();

    public int getNumSides() {
        return numSides;
    }
}
