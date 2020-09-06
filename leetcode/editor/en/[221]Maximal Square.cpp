//Given a 2D binary matrix filled with 0's and 1's, find the largest square cont
//aining only 1's and return its area. 
//
// Example: 
//
// 
//Input: 
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output: 4
// Related Topics Dynamic Programming 
// 👍 3356 👎 88


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0)
            return 0;
        vector<int> cur;
        int m=matrix.size(),n=matrix[0].size();
        for (int i = 0; i <n ; ++i) {
            cur.push_back(0);
        }
        int sz=0,pre=0;
        for (int i = 0; i <m ; ++i) {
            for (int j = 0; j <n ; ++j) {
                int temp=cur[j];
                if (!i ||!j ||matrix[i][j]=='0' )
                {
                  cur[j]=matrix[i][j]-'0';
                } else{
                    cur[j]=min(pre,min(cur[j],cur[j-1]))+1;
                }
                sz=max(sz,cur[j]);
                pre=temp;
            }
        }
        return sz*sz;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
