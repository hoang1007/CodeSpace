public class Queue {
    private LinkedList baseList;
    public Queue() {
        baseList = new LinkedList();
    }

    public void enqueue(int value) {
        baseList.pushBack(value);
    }
    public int dequeue() {
        int backElement = baseList.getBack();
        baseList.removeBack();
        return backElement;
    }
    public int length() {
        return baseList.getLength();
    }

    public void print() {
        for (int i = 0; i < baseList.getLength(); i++) {
            System.out.print(baseList.getAt(i) + " ");
        }
        System.out.println();
    }
}
