/*
 * 120. 三角形最小路径和.cpp
 *
 *  Created on: 2018年9月10日
 *      Author: garvin
 */

/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> record(size, 0);
        for(int i=0; i<size; i++){
            for(int j=i; j>=0; j--){
                if(j==0)
                    record[0] = triangle[i][0]+record[0];
                else if(i==j)
                    record[j] = triangle[i][j]+record[j-1];
                else
                    record[j] = min(record[j], record[j-1])+triangle[i][j];
            }
        }
        int result = INT_MAX;
        for(int i=0; i<size; i++)
            result = min(result, record[i]);
        return result;
    }
};

