public class LinkedList {
    public class Node {
        private int value;
        public Node next;

        public Node(int value) {
            this.value = value;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }
    }

    Node head, tail;
    private int length = 0;

    LinkedList() {
        head = tail = null;
    }

    public void pushFront(int value) {
        Node node = new Node(value);
        if (tail == null)
            tail = node;
        else 
            node.next = head;
        
        head = node;
        length++;
    }

    public void pushBack(int value) {
        Node node = new Node(value);
        if (head == null)
            head = node;
        else 
            tail.next = node;
        tail = node;
        length++;
    }

    public void insert(int index, int value) {
        if (index >= length || index < 0) {
            throw new IllegalArgumentException("Index out of range");
        }

        // find the node is front of the node that contains value
        Node pre = head, node = new Node(value);
        for (; index > 1; index--, pre = pre.next)
            ;
        node.next = pre.next;
        pre.next = node;
        length++;
    }

    public void removeFront() {
        if (head == null) {
            return;
        }
        head = head.next;
        length--;
    }

    public void removeBack() {
        if (head == null) {
            return;
        }
        // find previous of tail
        Node itr = head;
        for (; itr.next != tail; itr = itr.next)
            ;
        itr.next = null;
        length--;
    }

    public boolean isEmpty() {
        return length == 0;
    }

    public int find(int value) throws Exception {
        int indexFound = 0;
        for (Node itr = head; itr != null; itr = itr.next, indexFound++)
            if (itr.value == value)
                return indexFound;
        throw new Exception("Can't found value in list");
    }

    public int getLength() {
        return length;
    }

    public int getAt(int index) {
        if (head == null)
            throw new IllegalArgumentException("List is empty");
        if (index < 0 || index >= length)
            throw new IllegalArgumentException("Index out of range");
        
        if (index == length - 1)
            return tail.value;

        Node itr = head;
        for (int i = 0; i < length; i++, itr = itr.next)
            if (i == index)   break;
        return itr.value;
    }

    public int getBack() {
        if (tail == null)
            throw new IllegalArgumentException("List is empty");
        return tail.value;
    }
    public int getFront() {
        if (head == null)
            throw new IllegalArgumentException("List is empty");
        return head.value;
    }
}