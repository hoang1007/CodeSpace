import structures.*;

public class Main {
    public static void main(String[] args) {
        String[] tokens = new String[] { "ao", "ma", "ca", "na", "da"};

        LinkedList<String> links = new LinkedList<String>();

        for (var item : tokens) {
            links.pushBack(item);
        }

        links.print();
        links.insert(1, "that day");
        links.print();
        links.remove(1);
        links.print();
    }
}
