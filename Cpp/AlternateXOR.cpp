#include <bits/stdc++.h>
using namespace std;
 
#define MAX 100000
 
// Function to find the maximum and the
// minimum elements from the array after
// performing the given operation k times
void xorOnSortedArray(int arr[], int n, int k, int x)
{
 
    // To store the current sequence of elements
    int arr1[MAX + 1] = { 0 };
 
    // To store the next sequence of elements
    // after xoring with current elements
    int arr2[MAX + 1] = { 0 };
    int xor_val[MAX + 1];
 
    // Store the frequency of elements of arr[] in arr1[]
    for (int i = 0; i < n; i++)
        arr1[arr[i]]++;
 
    // Storing all precomputed XOR values so that
    // we don't have to do it again and again
    // as XOR is a costly operation
    for (int i = 0; i <= MAX; i++)
        xor_val[i] = i ^ x;
 
    // Perform the operations k times
    while (k--) {
 
        // The value of count decide on how many elements
        // we have to apply XOR operation
        int count = 0;
        for (int i = 0; i <= MAX; i++) {
            int store = arr1[i];
 
            // If current element is present in
            // the array to be modified
            if (arr1[i] > 0) {
 
                // Suppose i = m and arr1[i] = num, it means
                // 'm' appears 'num' times
                // If the count is even we have to perform
                // XOR operation on alternate 'm' starting
                // from the 0th index because count is even
                // and we have to perform XOR operations
                // starting with initial 'm'
                // Hence there will be ceil(num/2) operations on
                // 'm' that will change 'm' to xor_val[m] i.e. m^x
                if (count % 2 == 0) {
                    int div = ceil((float)arr1[i] / 2);
 
                    // Decrease the frequency of 'm' from arr1[]
                    arr1[i] = arr1[i] - div;
 
                    // Increase the frequency of 'm^x' in arr2[]
                    arr2[xor_val[i]] += div;
                }
 
                // If the count is odd we have to perform
                // XOR operation on alternate 'm' starting
                // from the 1st index because count is odd
                // and we have to leave the 0th 'm'
                // Hence there will be (num/2) XOR operations on
                // 'm' that will change 'm' to xor_val[m] i.e. m^x
                else if (count % 2 != 0) {
                    int div = arr1[i] / 2;
                    arr1[i] = arr1[i] - div;
                    arr2[xor_val[i]] += div;
                }
            }
 
            // Updating the count by frequency of
            // the current elements as we have
            // processed that many elements
            count = count + store;
        }
 
        // Updating arr1[] which will now store the
        // next sequence of elements
        // At this time, arr1[] stores the remaining
        // 'm' on which XOR was not performed and
        // arr2[] stores the frequency of 'm^x' i.e.
        // those 'm' on which operation was performed
        // Updating arr1[] with frequency of remaining
        // 'm' & frequency of 'm^x' from arr2[]
        // With help of arr2[], we prevent sorting of
        // the array again and again
        for (int i = 0; i <= MAX; i++) {
            arr1[i] = arr1[i] + arr2[i];
 
            // Resetting arr2[] for next iteration
            arr2[i] = 0;
        }
    }
 
    // Finding the maximum and the minimum element
    // from the modified array after the operations
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i <= MAX; i++) {
        if (arr1[i] > 0) {
            if (min > i)
                min = i;
            if (max < i)
                max = i;
        }
    }
 
    // Printing the max and the min element
    cout << min << " " << max << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 605, 986 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 548, x = 569;
 
    xorOnSortedArray(arr, n, k, x);
 
    return 0;
}
