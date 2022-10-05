import java.util.*;
import java.util.Arrays;

public class CycleSort {
    public static void main(String args[]) {
        System.out.println(
                "This program is for sorting given range of numbers from 1 to N,so please enter numbers from 1 to N");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter element:");
            arr[i] = sc.nextInt();

        }
        sort(arr);
        printSortedArray(arr, n);
        sc.close();
    }

    static void sort(int arr[]) {
        int p = 0;
        while (p < arr.length) {
            int correctindex = arr[p] - 1;
            if (arr[p] != arr[correctindex]) {
                swapElements(arr, p, correctindex);
            } else {
                p++;
            }
        }

    }

    static void swapElements(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    static void printSortedArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");

        }
    }
}
