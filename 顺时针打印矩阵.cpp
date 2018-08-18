/*
 * 顺时针打印矩阵.cpp
 *
 *  Created on: 2018年8月18日
 *      Author: garvin
 */

/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，
如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10. */

class Solution {
public:
    void getresult(const vector<vector<int> >& matrix, vector<int>& result,
                  int x1, int y1, int x2, int y2){
        if(x1<=x2 && y1<=y2){
            for(int i=y1; i<=y2; i++)
                result.push_back(matrix[x1][i]);
            for(int i=x1+1; i<=x2; i++)
                result.push_back(matrix[i][y2]);
            if(x1+1<=x2 && y1<=y2-1)
                getresult(matrix, result, x2, y2-1, x1+1, y1);
        }
        else if(x1>=x2 && y1>=y2){
            for(int i=y1; i>=y2; i--)
                result.push_back(matrix[x1][i]);
            for(int i=x1-1; i>=x2; i--)
                result.push_back(matrix[i][y2]);
            if(x1-1>=x2 && y1>=y2+1)
                getresult(matrix, result, x2, y2+1, x1-1, y1);
        }
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int hang = matrix.size();
        int lie = matrix[0].size();
        vector<int> result;
        result.reserve(hang*lie);
        getresult(matrix, result, 0, 0, hang-1, lie-1);
        return result;
    }
};
