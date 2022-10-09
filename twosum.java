class Solution {
    public int[] twoSum(int[] nums, int target)
    {
        int l = nums.length;
        int[] a = new int[2];
        int i , j ;
        for(i = 0 ; i < l ; i++)
        {
            for(j = 1 ; j < l ; j++)
            {
                if(((nums[i] + nums[j]) == target) && (i != j))
                {
                    a[0] = i ;
                    a[1] = j ;
                    return a;
                }
            }
        }
        return a;
    }
}
