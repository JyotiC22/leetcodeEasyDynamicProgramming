//Given a non-empty string s and a dictionary wordDict containing a list of non-
//empty words, determine if s can be segmented into a space-separated sequence of 
//one or more dictionary words. 
//
// Note: 
//
// 
// The same word in the dictionary may be reused multiple times in the segmentat
//ion. 
// You may assume the dictionary does not contain duplicate words. 
// 
//
// Example 1: 
//
// 
//Input: s = "leetcode", wordDict = ["leet", "code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
// 
//
// Example 2: 
//
// 
//Input: s = "applepenapple", wordDict = ["apple", "pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pe
//n apple".
//             Note that you are allowed to reuse a dictionary word.
// 
//
// Example 3: 
//
// 
//Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//Output: false
// 
// Related Topics Dynamic Programming 
// 👍 4801 👎 241


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for (int i = 0; i <=s.size() ; ++i) {
            for (auto j :wordDict) {
                if (dp[i])
                {
                    if (s.substr(i,j.size()).compare(j)==0)
                    {
                        dp[i+j.size()]= true;
                    }
                }
            }

        }
        return dp[s.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
