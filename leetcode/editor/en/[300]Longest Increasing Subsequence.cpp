//Given an unsorted array of integers, find the length of longest increasing sub
//sequence. 
//
// Example: 
//
// 
//Input: [10,9,2,5,3,7,101,18]
//Output: 4 
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the 
//length is 4. 
//
// Note: 
//
// 
// There may be more than one LIS combination, it is only necessary for you to r
//eturn the length. 
// Your algorithm should run in O(n2) complexity. 
// 
//
// Follow up: Could you improve it to O(n log n) time complexity? 
// Related Topics Binary Search Dynamic Programming 
// 👍 5237 👎 115


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (auto num:nums ){
            findLIS(&LIS,num);
        }
        return LIS.size();
    }

private:
    void findLIS(vector<int> *LIS,int num)
    {
        auto a = lower_bound(LIS->begin(), LIS->end(), num);
        if (a==LIS->end())
        {
            LIS->push_back(num);
        } else{
            *a=num;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

