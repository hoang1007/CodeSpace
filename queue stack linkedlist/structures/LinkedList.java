package structures;

public class LinkedList<T> extends BaseList<T> {
    public void pushFront(T item) {
        super.pushFront(item);
    }

    public void pushBack(T item) {
        super.pushBack(item);
    }

    public T popFront() {
        return super.popFront();
    }

    public T popBack() {
        return super.popBack();
    }

    public void insert(int index, T value) {
        if (index < 0 || index >= length)
            throw new IllegalArgumentException("Index out of range");

        if (index == 0)
            pushFront(value);
        else if (index == length - 1)
            pushBack(value);
        else {
            Node prev = head;
            for (int i = 0; i < index - 1; i++)
                prev = prev.next;
            Node node = new Node(value);
            node.next = prev.next;
            prev.next = node;
        }
    }

    public T remove(int index) {
        if (index < 0 || index >= length)
            throw new IllegalArgumentException("Index out of range");
        if (index == 0)
            return popFront();
        if (index == length - 1)
            return popBack();

        Node prev = head;
        for (int i = 0; i < index - 1; i++)
            prev = prev.next;
        T oldvalue = prev.next.value;
        prev.next = prev.next.next;

        return oldvalue;
    }
}
