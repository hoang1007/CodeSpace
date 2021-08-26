package com.dsatrain.Sort;

import java.util.Arrays;

public class sort {
    public static int[] bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i; j < arr.length - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    utilities.swap(arr, j + 1, j);
                }
            }
        }

        return arr;
    }

    public static int[] selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }

            utilities.swap(arr, i, minIdx);
        }

        return arr;
    }

    public static int[] insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int store = arr[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (arr[j] > store)
                    arr[j + 1] = arr[j];
                else break;
            }

            arr[j + 1] = store;
        }

        return arr;
    }

    private static int[] quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot = utilities.partition(arr, low, high);

            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }

        return arr;
    }

    public static int[] quickSort(int[] arr) {
        return quickSort(arr, 0, arr.length - 1);
    }

    public static int[] heapSort(int[] arr) {
        for (int i = arr.length / 2 - 1; i >= 0; i--)
            utilities.heapify(arr, arr.length, i);
        
        for (int i = arr.length - 1; i >= 0; i--) {
            utilities.swap(arr, 0, i);
            utilities.heapify(arr, i, 0);
        }
        
        return arr;
    }

    public static int[] mergeSort(int[] arr) {
        if (arr.length == 1) return arr;

        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);

        left = mergeSort(left);
        right = mergeSort(right);

        return utilities.merge(left, right);
    } 
}
