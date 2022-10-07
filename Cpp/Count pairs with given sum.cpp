//Count pairs with given sum
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>m;
        int count=0;
        for(int i=0;i<n;i++){
            if(m[arr[i]]>0){
                count=count+m[arr[i]];
            }
            if(arr[i]<=k)
            m[k-arr[i]]++;
        }
       return count; 
    }
};
