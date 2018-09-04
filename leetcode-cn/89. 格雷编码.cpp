/*
 * 89. 格雷编码.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。
*/

class Solution {
public:
    /*
    vector<int> grayCode(int n) {
        vector<int> guilv(4, 0);
        guilv[0] = 0, guilv[1] = 1, guilv[2] = 3, guilv[3] = 2;
        vector<int> result;
        int guilv_index = 0;
        int start = 0;
        int size = pow(2, n);
        for(int i=0; i<size; i+=4){
            for(int j=0; j<4; j++){
                result.push_back(start + guilv[guilv_index]);
                if(j!=3)
                    guilv_index = (++(guilv_index)) %4;
            }
            start += 4;
        }
        return result;
    }
    */

    void dfs(vector<int>& ans, int cur, int n){
        if(n == 0) {ans.push_back(0); return;}
        if(cur > n) return;
        if(cur == 1){
            ans.push_back(0);
            ans.push_back(1);
            dfs(ans, cur+1, n);
        }else{
            int len = ans.size();
            for(int j = 0; j < len; j++)
                ans.push_back(ans[len-j-1] + pow(2, cur-1));
            dfs(ans, cur+1, n);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        dfs(ans, 1, n);
        return ans;
    }

};
