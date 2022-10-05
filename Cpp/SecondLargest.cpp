//Given an array Arr of size N, print second largest element from an array.

class Solution{
public:	
	// Function returns the second
	// largest elements
int print2largest(int arr[], int n) {
	    // code here
	    int max=INT_MIN;
	    int max_ind=0;
	    for(int i=0; i<n; i++){
	        if(arr[i]>max){
	            max=arr[i];
	            max_ind=i;
	        }
	    }
	    max=INT_MIN;
	    int sec_lar=-1;
	    for(int i=0; i<n; i++){
	        if(arr[i]!=arr[max_ind]){
	            if(arr[i]>max){
	                max=arr[i];
	                sec_lar=i;
	            }
	        }
	    }
	    if(sec_lar==-1){
	        return -1;
	    }
	    else{
	        return max;
	    }
	}
};
