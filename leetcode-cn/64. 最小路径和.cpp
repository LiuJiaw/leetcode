/*
 * 64. 最小路径和.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size_h = grid.size();
        if(size_h<=0)
            return 0;
        int size_l = grid[0].size();
        if(size_l<=0)
            return 0;

        vector<int> tmp(size_l, 0);
        vector<vector<int> > record(size_h, tmp);

        record[0][0] = grid[0][0];
        for(int i=1; i<size_h; i++)
            record[i][0] = record[i-1][0]+grid[i][0];
        for(int i=1; i<size_l; i++)
            record[0][i] = record[0][i-1]+grid[0][i];
        for(int i=1; i<size_h; i++){
            for(int j=1; j<size_l; j++){
                record[i][j] = min(record[i-1][j], record[i][j-1])+grid[i][j];
            }
        }
        return record[size_h-1][size_l-1];
    }
};


