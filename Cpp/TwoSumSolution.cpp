//Solution for the famous Two Sum problem implemented in C++ using Maps
//Leetcode problem link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> elem_index;
        
        if(nums[0]+nums[1] == target){
            return {0,1};
        } 
        
        elem_index[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            if(elem_index.find(target-nums[i])!=elem_index.end()){
                return {elem_index[target-nums[i]], i};
            }
            else{
                elem_index[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};