/*
 * 73. 矩阵置零.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int sizeh = matrix.size();
        if(sizeh == 0)
            return;
        int sizel = matrix[0].size();
        vector<bool> vech(sizeh, true), vecl(sizel, true);
        for(int i=0; i<sizeh; i++){
            for(int j=0; j<sizel; j++)
                if(matrix[i][j] == 0)
                    vech[i] = false, vecl[j] = false;
        }
        for(int i=0; i<sizeh; i++){
            for(int j=0; j<sizel; j++){
                if(!vech[i] || !vecl[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

