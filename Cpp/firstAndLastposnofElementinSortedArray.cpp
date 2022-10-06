class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
int s=0;
        int e=nums.size()-1;
        int mid=0;
        int p=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
            p=mid;
                e=mid-1;
            }
              if(nums[mid]>target){
          
                e=mid-1;
            }
               if(nums[mid]<target){
          
                s=mid+1;
            }
            
        }
        return p;
    }
        int lastOcc(vector<int>& nums, int target){
int s=0;
        int e=nums.size()-1;
        int mid=0;
        int p=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
            p=mid;
                s=mid+1;
            }
              if(nums[mid]>target){
          
                e=mid-1;
            }
               if(nums[mid]<target){
          
                s=mid+1;
            }
            
        }
        return p;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ans;
        ans.push_back(firstOcc(nums,target));
        ans.push_back(lastOcc(nums,target));
        return ans;
    }
};
