//Given an integer array nums, find the contiguous subarray within an array (con
//taining at least one number) which has the largest product. 
//
// Example 1: 
//
// 
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
// 
//
// Example 2: 
//
// 
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray. 
// Related Topics Array Dynamic Programming 
// 👍 4640 👎 168


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.size()<1)
            return 0;
        int currentMax=nums[0];
        int currentMin=nums[0];
        int best=nums[0];
        for (int i = 1; i <nums.size() ; ++i) {
            int  maxresult=currentMax*nums[i];
            int   minresult=currentMin*nums[i];
            currentMax=max(nums[i],max(maxresult,minresult));
            currentMin=min(nums[i],min(maxresult,minresult));
            best=max(best,currentMax);
        }
        return best;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
