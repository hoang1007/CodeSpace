package structures;

public abstract class BaseList<T> {
    public class Node {
        T value;
        Node next;

        public Node(T value) {
            this.value = value;
        }
    }

    Node head, tail;
    public int length;
    public BaseList() {
        head = tail = null;
        length = 0;
    }

    protected void pushFront(T value) {
        Node node = new Node(value);
        if (head == null)
            tail = node;
        else 
            node.next = head;

        head = node;
        length++;
    }

    protected T popFront() {
        if (head == null)
            throw new IllegalStateException("List is empty");
        T oldvalue = head.value;
        head = head.next;
        length--;
        return oldvalue;
    }

    protected void pushBack(T value) {
        Node node = new Node(value);
        if (tail == null)
            head = node;
        else
            tail.next = node;
        tail = node;
        length++;
    }

    protected T popBack() {
        if (tail == null)
            throw new IllegalStateException("List is empty");
        T oldvalue = tail.value;
        Node newTail = head;
        for (; newTail.next != tail; newTail = newTail.next)
            ;
        newTail.next = null;
        tail = newTail;
        length--;
        return oldvalue;
    }

    public void print() {
        for (Node itr = head; itr != null; itr = itr.next)
            System.out.print(itr.value + " ");
        System.out.println();
    }

    public boolean isEmpty() {
        return length == 0;
    }
}