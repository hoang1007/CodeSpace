package structures;

public class Queue<T> extends BaseList<T> {
    public void enqueue(T value) {
        super.pushBack(value);
    }

    public T dequeue() {
        return super.popFront();
    }
}
