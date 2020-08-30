//Given a non negative integer number num. For every numbers i in the range 0 ≤ 
//i ≤ num calculate the number of 1's in their binary representation and return th
//em as an array. 
//
// Example 1: 
//
// 
//Input: 2
//Output: [0,1,1] 
//
// Example 2: 
//
// 
//Input: 5
//Output: [0,1,1,2,1,2]
// 
//
// Follow up: 
//
// 
// It is very easy to come up with a solution with run time O(n*sizeof(integer))
//. But can you do it in linear time O(n) /possibly in a single pass? 
// Space complexity should be O(n). 
// Can you do it like a boss? Do it without using any builtin function like __bu
//iltin_popcount in c++ or in any other language. 
// Related Topics Dynamic Programming Bit Manipulation 
// 👍 2914 👎 175


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1);
        bits[0] = 0;
        int n2 = 1;
        for(int i = 1; i<=num; i++){
            if(i == n2){
                bits[i] = 1;
                n2 *=2;
            }else
                bits[i] = 1 + bits[i-n2/2];
        }
        return bits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
