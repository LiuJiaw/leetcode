/*
 * 62&63. 不同路径.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 2:

输入: m = 7, n = 3
输出: 28
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0)
            return 0;
        int **record = new int*[m];
        for(int i=0; i<m; i++)
            record[i] = new int[n];
        record[0][0] = 1;
        for(int i=1; i<m; i++)
            record[i][0] = 1;
        for(int i=0; i<n; i++)
            record[0][i] = 1;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                record[i][j] = record[i][j-1]+record[i-1][j];
        int result = record[m-1][n-1];
        for(int i=0; i<m; i++)
            delete record[i];
        delete record;
        return result;
    }
};


/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int size_h = obstacleGrid.size();
        if(size_h <=0)
            return 0;
        int size_l = obstacleGrid[0].size();
        if(size_l<=0)
            return 0;
        vector<int> vec(size_l, 0);
        vector<vector<int> > record(size_h, vec);
        if(obstacleGrid[0][0] == 1)
            return 0;
        record[0][0] = 1;
        bool isfind = false;
        for(int i=1; i<size_h && obstacleGrid[i][0]==0; i++){
            record[i][0] = 1;
        }
        for(int i=1; i<size_l && obstacleGrid[0][i]==0; i++){
            record[0][i] = 1;
        }
        for(int i=1; i<size_h; i++){
            for(int j=1; j<size_l; j++){
                if(obstacleGrid[i][j] == 1)
                    continue;
                record[i][j] = (obstacleGrid[i][j-1]==0 ? record[i][j-1]:0) + (obstacleGrid[i-1][j]==0 ? record[i-1][j]:0);
            }
        }
        return record[size_h-1][size_l-1];
    }
};


