/*
 * 279.完全平方数.cpp
 *
 *  Created on: 2018年10月4日
 *      Author: garvin
 */

/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.

示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> record(n+1, INT_MAX);
        record[0] = 0, record[1] = 1, record[2] = 2, record[3] = 3;
        for(int i=4; i<=n; i++){
            for(int j=1; ; j++){
                if(i-j*j<0)
                    break;
                record[i] = min(record[i], record[i-j*j]+1);
            }
        }
        return record[n];
    }
};


