import java.util.*;
public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array");
        int n=sc.nextInt();
        System.out.println("Enter the array which is sorted");
        int arr[]= new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        System.out.println("Enter the element te be searched");
        int d=sc.nextInt();
        //HERE STARTS THE MAIN LOGIC OF BINARY SEARCH
        int mid,first=0,last=n-1;
        boolean b=true;
        while(first<=last)
        { mid=(first+last)/2;
            if(arr[mid]==d)
            {   b=false;
                System.out.println("Element found at postion "+(mid+1));
                break;
            }
            else if(arr[mid]>d)
                last=mid-1;
            else if(arr[mid]<d)
                first=mid+1;


        }
        if(b)
        System.out.println("Element not found");

    }
}
