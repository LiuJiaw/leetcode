/*
 * unique-paths.cpp
 *
 *  Created on: 2018年7月8日
 *      Author: garvin
 */

 /*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there? */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *record = new int[m*n];
        for(int i=0; i<n; i++)
            record[i] = 1;
        for(int j=0; j<m; j++)
            record[j*n] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                record[i*n+j] = record[(i-1)*n+j] + record[i*n+j-1];
            }
        }
        return record[n*m-1];
    }
};


/*Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as1and0respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
 [0,0,0],
 [0,1,0],
 [0,0,0]
]
The total number of unique paths is2.
Note: m and n will be at most 100. */

/*
 * 首先和上一题一样，计算出第一行和第一列个位置到达路径个数
 * 由于障碍物的存在，当第一行或第一列某个位置中出现一个障碍物，后续个位置全部不可达
 * 除去第一行和第一列，其余各点到达路径个数为所左位置与上位置之和
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        int hang = obstacleGrid.size();
        int lie = obstacleGrid[0].size();
        int **record = new int*[hang];
        for(int i=0; i<hang; i++)
            record[i] = new int[lie];

        bool firsthang = false;
        bool firstlie = false;
        for(int i=0; i<hang; i++){
            if(obstacleGrid[i][0] == 1){
                firsthang = true;
                record[i][0] = 0;
                continue;
            }
            record[i][0] = firsthang ? 0 : 1;
        }
        for(int j=0; j<lie; j++){
            if(obstacleGrid[0][j] == 1){
                firstlie = true;
                record[0][j] = 0;
                continue;
            }
            record[0][j] = firstlie ? 0 : 1;
        }

        for(int i= 1; i<hang; i++){
            for(int j=1; j<lie; j++){
                if(obstacleGrid[i][j] == 1)
                    record[i][j] = 0;
                else
                    record[i][j] = record[i-1][j] + record[i][j-1];
            }
        }
        return record[hang-1][lie-1];
    }
};
