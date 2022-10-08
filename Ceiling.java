/* Ceiling of a no.
a = [3,5,7,9]
target = 6
ans = 7
greater than target element but the smallest or equal to the target element
*/
import java.util.Scanner;

public class Binary3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int[] arr = new int[l];
        for(int i = 0 ; i < l ; i++)
        {
            arr[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        System.out.println(binarysearch(arr , target));
    }
    static int binarysearch(int arr[] , int target)
    {
        int start = 0;
        int end = arr.length - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(target == arr[mid])
                return arr[mid];
            else if(arr[mid] < target)
                start = mid + 1;
            else if(arr[mid] > target)
                end = mid - 1;
        }
        return arr[start];
    }
}
