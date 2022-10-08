class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1=0,index2=0;
        int median1=0,median2=0;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<=(n+m)/2;i++){
            median1=median2;
            if(index1==n){
                median2=nums2[index2];
                index2++;
            }
            else if(index2==m){
                median2=nums1[index1];
                index1++;
            }
            else if(nums1[index1]<nums2[index2]){
                median2=nums1[index1];
                index1++;
            }
            else{
                median2=nums2[index2];
                index2++;
            }
        }
        if((n+m)%2==0)
            return (median1+median2)/2.0;
        
        return median2;
    }
};
