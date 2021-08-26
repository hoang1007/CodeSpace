import java.util.List;
import java.util.ArrayList;

public class HeapTree {
    List<Integer> baselist;

    public HeapTree() {
        baselist = new ArrayList<>();
    }

    void heapify(int node) {
        int left = 2 * node + 1, right = 2 * node + 2;
        int largest = node;

        if (left < baselist.size() && baselist.get(left) > baselist.get(largest))
            largest = left;
        if (right < baselist.size() && baselist.get(right) > baselist.get(largest))
            largest = right;

        if (largest != node) {
            Utilities.swap(baselist, largest, node);
            heapify(largest);
        }
    }

    public void add(int k) {
        baselist.add(k);
        
        for (int i = baselist.size() / 2; i >= 0; i--)
            heapify(i);
    }

    public int removeRoot() {
        Utilities.swap(baselist, 0, baselist.size() - 1);
        int oldRoot = baselist.remove(baselist.size() - 1);
        heapify(0);

        return oldRoot;
    }

    private void preOrder(int node) {
        if (node >= baselist.size())
            return;
        int left = 2 * node + 1, right = 2 * node + 2;
        System.out.print(baselist.get(node) + " ");

        preOrder(left);
        preOrder(right);
    }

    public void preOrder() {
        preOrder(0);
        System.out.println();
    }
}

class Utilities {
    public static void swap(List<Integer> list, int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }
}