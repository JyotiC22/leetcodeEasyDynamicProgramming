//Given a positive integer n, find the least number of perfect square numbers (f
//or example, 1, 4, 9, 16, ...) which sum to n. 
//
// Example 1: 
//
// 
//Input: n = 12
//Output: 3 
//Explanation: 12 = 4 + 4 + 4. 
//
// Example 2: 
//
// 
//Input: n = 13
//Output: 2
//Explanation: 13 = 4 + 9. Related Topics Math Dynamic Programming Breadth-first
// Search 
// 👍 3250 👎 198


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n) {
        if(n==0)
            return 0;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for (int i = 2; i <=n ; ++i) {
            dp[i]=i;
        }
        for (int i = 2; i <=n ; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
