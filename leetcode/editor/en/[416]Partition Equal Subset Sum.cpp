//Given a non-empty array containing only positive integers, find if the array c
//an be partitioned into two subsets such that the sum of elements in both subsets
// is equal. 
//
// Note: 
//
// 
// Each of the array element will not exceed 100. 
// The array size will not exceed 200. 
// 
//
// 
//
// Example 1: 
//
// 
//Input: [1, 5, 11, 5]
//
//Output: true
//
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
// 
//
// 
//
// Example 2: 
//
// 
//Input: [1, 2, 3, 5]
//
//Output: false
//
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//
// 
// Related Topics Dynamic Programming 
// 👍 2967 👎 74


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%2==1)
            return false;
        sum/=2;
        int countable[sum+1];
        for (int i = 0; i <=sum ; ++i) {
            countable[i]= false;
        }
        countable[0]=true;
        for (int num:nums) {
            for (int i = sum; i >=num; --i) {
                if (countable[i-num])
                    countable[i]=true;
            }
        }
        return countable[sum];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
