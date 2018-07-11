/*
 * minimum-path-sum.cpp
 *
 *  Created on: 2018年7月11日
 *      Author: garvin
 */

/* Given a m x n grid filled with non-negative numbers,
 find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time. */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int hang = grid.size();
        if(hang == 0)
            return 0;
        int lie = grid[0].size();
        int **record = new int*[hang];
        for(int i=0; i<hang; i++){
            record[i] = new int[lie];
        }
        for(int i=0; i<hang; i++){
            for(int j=0; j<lie; j++){
                if(i == 0 && j ==0){
                    record[i][j] = grid[i][j];
                }
                else if(i == 0){
                    record[i][j] = record[i][j-1] + grid[i][j];
                }
                else if(j == 0){
                    record[i][j] = record[i-1][j] + grid[i][j];
                }
                else{
                    record[i][j] = grid[i][j] + (record[i][j-1] > record[i-1][j] ? record[i-1][j] : record[i][j-1]);
                }
            }
        }
        return record[hang-1][lie-1];
    }
};
