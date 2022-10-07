/* problem to sort an array consisting of 0s, 1s and 2s only.
This problem is also known as the Dutch National Flag Algorithm */

#include<bits/stdc++.h>
using namespace std;

void sortarray(vector<int>& arr,int right){
    int left=0, mid=0, pivot=1;
    while(mid<=right){
        if(arr[mid]<pivot){
            swap(arr[left],arr[mid]);
            left++,mid++;
        }
        else if(arr[mid]>pivot){
            swap(arr[right],arr[mid]);
            right--;
        }
        else
            mid++;
    }
}

int main(){
    vector<int> arr={1,2,0,0,2,1,2};
    int size=arr.size();
    sortarray(arr,size-1);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1) --> no extra space needed