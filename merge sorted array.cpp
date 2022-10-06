class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        for(int i=0;i<m;i++){
           // if(nums1[i]){
                ans.push_back(nums1[i]);
           // }
        }
        for(int i=0;i<n;i++){
           // if(nums2[i]!=0){
                ans.push_back(nums2[i]);
           // }
        }
        sort(ans.begin(),ans.end());
        nums1.clear();
        nums1=ans;
    }
};
