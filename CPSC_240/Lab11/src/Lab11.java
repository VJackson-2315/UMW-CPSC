import java.util.ArrayList;

public class Lab11 {
    public static void main(String[] args) {
        /* make a big list of shapes */
        ArrayList<Shape> shapes = new ArrayList<>();
        shapes.add(new Circle("Circle 1", 5));
        shapes.add(new Circle("Circle 2", 12));
        shapes.add(new Circle("Circle 3", 24));
        shapes.add(new Circle("Circle 4", 2));
        shapes.add(new Circle("Circle 5", 18));
        shapes.add(new Rectangle("Rectangle 1", 3, 5));
        shapes.add(new Rectangle("Rectangle 2", 12, 15));
        shapes.add(new Rectangle("Rectangle 3", 8, 8));
        shapes.add(new Rectangle("Rectangle 4", 45, 17));
        shapes.add(new Rectangle("Rectangle 5", 20, 36));
        shapes.add(new Triangle("Triangle 1", 5, 18, 2, 6));
        shapes.add(new Triangle("Triangle 2", 19, 22, 9, 11));
        shapes.add(new Triangle("Triangle 3", 80, 9, 30, 6));
        shapes.add(new Triangle("Triangle 4", 25, 42, 13, 9.5));
        shapes.add(new Triangle("Triangle 5", 26, 56, 40, 11));
        for (Shape s: shapes) {
            s.display();
        }

        /* now we have some plain polygons */
        ArrayList<Polygon> polys = new ArrayList<>();
        polys.add(new Triangle("Triangle 6", 2, 3, 4, 5));
        polys.add(new Triangle("Triangle 7", 12, 30, 44, 35));
        polys.add(new Triangle("Triangle 8", 9, 8, 14, 21));
        polys.add(new Rectangle("Rectangle 6", 20, 30));
        polys.add(new Rectangle("Rectangle 7", 11, 6.5));
        polys.add(new Rectangle("Rectangle 8", 20.2, 88));
        for (Polygon p: polys) {
            System.out.println("Perimeter = " + p.getPerimeter());
        }
    }
}