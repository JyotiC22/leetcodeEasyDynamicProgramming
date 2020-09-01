//Given n, how many structurally unique BST's (binary search trees) that store v
//alues 1 ... n? 
//
// Example: 
//
// 
//Input: 3
//Output: 5
//Explanation:
//Given n = 3, there are a total of 5 unique BST's:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 19 
// 
// Related Topics Dynamic Programming Tree 
// 👍 3655 👎 134


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
      int dp[n+1];
      dp[0]=1;
      dp[1]=1;
        for (int i = 2; i <=n ; ++i) {
            dp[i]=0;
        }
        for (int i = 2; i <=n ; ++i) {
            for (int j = 1; j <=i ; ++j) {
            dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
