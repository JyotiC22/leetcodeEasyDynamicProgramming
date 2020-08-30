//Given a string, your task is to count how many palindromic substrings in this 
//string. 
//
// The substrings with different start indexes or end indexes are counted as dif
//ferent substrings even they consist of same characters. 
//
// Example 1: 
//
// 
//Input: "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
// 
//
// 
//
// Example 2: 
//
// 
//Input: "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//
// 
//
// Note: 
//
// 
// The input string length won't exceed 1000. 
// 
//
// Related Topics String Dynamic Programming 
// 👍 2904 👎 120


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0; i<n; ++i){
            for(int k=i,j=i; k<n&&j>=0; ++k,--j)
                if(s[k]==s[j])
                    ++ans;
                else
                    break;
            for(int k=i,j=i-1; k<n&&j>=0; ++k,--j)
                if(s[k]==s[j])
                    ++ans;
                else
                    break;
        }
        return ans;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)
