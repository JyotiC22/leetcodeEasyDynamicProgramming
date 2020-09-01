//You are given a list of non-negative integers, a1, a2, ..., an, and a target, 
//S. Now you have 2 symbols + and -. For each integer, you should choose one from 
//+ and - as its new symbol. 
//
// Find out how many ways to assign symbols to make sum of integers equal to tar
//get S. 
//
// Example 1: 
//
// 
//Input: nums is [1, 1, 1, 1, 1], S is 3. 
//Output: 5
//Explanation: 
//
//-1+1+1+1+1 = 3
//+1-1+1+1+1 = 3
//+1+1-1+1+1 = 3
//+1+1+1-1+1 = 3
//+1+1+1+1-1 = 3
//
//There are 5 ways to assign symbols to make the sum of nums be target 3.
// 
//
// 
// Constraints: 
//
// 
// The length of the given array is positive and will not exceed 20. 
// The sum of elements in the given array will not exceed 1000. 
// Your output answer is guaranteed to be fitted in a 32-bit integer. 
// 
// Related Topics Dynamic Programming Depth-first Search 
// 👍 2898 👎 119


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        return sum<s||(s+sum)%2==1?0:findNoOfWays(nums,(s+sum)>>1);
    }
    int findNoOfWays(vector<int>& nums,int s)
    {
      int  dp[s+1];
        for (int i = 0; i <=s ; ++i) {
            dp[i]=0;
        }
      dp[0]=1;
        for (int num:nums) {
            for (int i = s; i >=num ; --i) {
                dp[i]+=dp[i-num];
            }
        }
        return dp[s];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
