public class Stack {
    private LinkedList baseList;
    public Stack() {
        baseList = new LinkedList();
    }

    public void push(int value) {
        baseList.pushFront(value);
    }

    public int remove() {
        int topElement = baseList.getFront();
        baseList.removeFront();
        return topElement;
    }

    public int length() {
        return baseList.getLength();
    }
    
    public int getTop() {
        return baseList.getFront();
    }

    public void print() {
        for (int i = 0; i < baseList.getLength(); i++) {
            System.out.print(baseList.getAt(i) + " ");
        }
        System.out.println();
    }
}
