/*
 * 118&119. 杨辉三角 II.cpp
 *
 *  Created on: 2018年9月10日
 *      Author: garvin
 */

/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex+1);
        result[0]=1;
        for(int i=1; i<=rowIndex; i++){
            result[i] = 1;
            for(int j=i-1; j>0; j--){
                result[j] = result[j]+result[j-1];
            }
        }
        return result;
    }
};

