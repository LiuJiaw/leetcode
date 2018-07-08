/*
 * rotate-image.cpp
 *
 *  Created on: 2018年7月8日
 *      Author: garvin
 */

/* You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place? */

/*首相将每一行反转
 * 然后沿着反对角线进行对称
 */


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());

        for(int i=0; i<n;i++){
            for(int j=0;j<n-i-1;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = tmp;
            }
        }
    }
};


