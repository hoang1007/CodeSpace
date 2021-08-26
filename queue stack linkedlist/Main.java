public class Main {
    public static void main(String[] args) {
        int[] tokens = new int[] { 1, 2, 3, 4, 5, 6, 7 };

        Stack stack = new Stack();
        for (int i : tokens) {
            stack.push(i);
        }

        stack.print();
    }
}
