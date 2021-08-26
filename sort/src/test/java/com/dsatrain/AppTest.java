package com.dsatrain;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import com.dsatrain.Sort.ArrayComparer;
import com.dsatrain.Sort.sort;
import com.dsatrain.Sort.utilities;

/**
 * Unit test for simple App.
 */
class AppTest {
    /**
     * Rigorous Test.
     */

    @Test
    void testApp() {
        assertEquals(1, 1);
    }

    @Test
    void testBubble() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.bubbleSort(test)));
    }

    @Test
    void testSelection() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.selectionSort(test)));
    }

    @Test
    void testInsertion() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.insertionSort(test)));
    }

    @Test
    void testSwap() {
        int[] a = {1, 2, 3};
        utilities.swap(a, 0, 1);

        assertTrue(ArrayComparer.compare(a, new int[] {2, 1, 3}));
    }

    @Test
    void testQuickSort() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.quickSort(test)));
    }

    @Test
    void testHeapSort() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.heapSort(test)));
    }

    @Test
    void testMergeSort() {
        int[] test = new int[] {5, 1, 2, 3, 6, 4};
        int[] dst = new int[] {1, 2, 3, 4, 5, 6};

        assertTrue(ArrayComparer.compare(dst, sort.mergeSort(test)));
    }
}
