#include <bits/stdc++.h>
using namespace std;
 
static void UnionArray(int arr1[], int arr2[], int l1,
                       int l2)
{
    // Taking max element present in either array
    int m = arr1[l1 - 1];
    int n = arr2[l2 - 1];
    int ans = 0;
    if (m > n)
        ans = m;
    else
        ans = n;
 
    // Finding elements from 1st array (non duplicates
    // only). Using another array for storing union elements
    // of both arrays Assuming max element present in array
    // is not more than 10^7
    int newtable[ans + 1];
    memset(newtable, 0, sizeof(newtable));
    // First element is always present in final answer
    cout << arr1[0] << " ";
 
    // Incrementing the First element's count in it's
    // corresponding index in newtable
    ++newtable[arr1[0]];
 
    // Starting traversing the first array from 1st index
    // till last
    for (int i = 1; i < l1; i++) {
        // Checking whether current element is not equal to
        // it's previous element
        if (arr1[i] != arr1[i - 1]) {
            cout << arr1[i] << " ";
            ++newtable[arr1[i]];
        }
    }
 
    // Finding only non common elements from 2nd array
    for (int j = 0; j < l2; j++) {
        // By checking whether it's already resent in
        // newtable or not
        if (newtable[arr2[j]] == 0) {
            cout << arr2[j] << " ";
            ++newtable[arr2[j]];
        }
    }
}
 
// Driver Code
int main()
{
    int arr1[] = { 1, 2, 2, 2, 3 };
    int arr2[] = { 2, 3, 4, 5 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
 
    UnionArray(arr1, arr2, n, m);
 
    return 0;
}
