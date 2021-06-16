import java.util.Scanner;

class Rectangle{
	double length, width;
	public void getInformation() {
		Scanner sc = new Scanner(System.in);
		length = sc.nextDouble();
		width = sc.nextInt();
        sc.close();
	}
	public void display() {
		System.out.println("Area: " + length*width);
		System.out.println("Perimeter: " + 2*(length + width));
	}
}

public class temp {
	public static void main(String[]args) {
		Rectangle r = new Rectangle();
		r.getInformation();
		r.display();
	}
}