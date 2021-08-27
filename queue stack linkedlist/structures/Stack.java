package structures;

public class Stack<T> extends BaseList<T> {
    public void push(T value) {
        super.pushFront(value);
    }

    public T pop() {
        return super.popFront();
    }
}