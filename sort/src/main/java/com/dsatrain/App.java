package com.dsatrain;

import com.dsatrain.Sort.sort;

/**
 * Hello world!
 */
public final class App {
    private App() {
    }

    /**
     * Says hello to the world.
     * @param args The arguments of the program.
     */
    public static void main(String[] args) {
        int[] arr = new int[] {5, 1, 2, 3, 6, 4};

        arr = sort.mergeSort(arr);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
