/*
 * triangle.cpp
 *
 *  Created on: 2018年7月12日
 *      Author: garvin
 */

/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]*/


/*
 * 思路和之前某道走矩形最短路径思路一致
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0)
            return 0;
        int size = triangle.size();
        int **record = new int*[size];
        for(int j=0; j<size;j++){
            record[j] = new int[j+1];
        }
        for(int i=0; i<size; i++){
            for(int j=0; j<=i; j++){
                if(i==0 && j==0)  record[i][j] = triangle[i][j];
                else if(j==0)  record[i][j] = record[i-1][j]+triangle[i][j];
                else if(i==j)  record[i][j] = record[i-1][j-1]+triangle[i][j];
                else{
                    record[i][j] = triangle[i][j] + min(record[i-1][j-1], record[i-1][j]);
                }
            }
        }
        int Min = INT_MAX;
        for(int i=0; i<size;i++){
            Min = min(Min, record[size-1][i]);
        }
        return Min;
    }
};
