/*
 * 74. 搜索二维矩阵.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
 * 使用类似lower_bound的算法，找出第一个小于target的行头
 * 再使用二分，在该行找出target
 */

/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。

示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true

示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

class Solution {
public:
    int gethang(vector<vector<int>>& matrix, int target){
        int sizeh = matrix.size();
        int sizel = matrix[0].size();
        if(target<matrix[0][0])
            return -1;
        if(target>=matrix[sizeh-1][sizel-1])
            return sizeh-1;
        int start = 0, end = sizeh-1;
        int middle;
        while(start<=end){
            middle = start + (end-start)/2;
            if(middle == sizeh-1 || matrix[middle][0] <= target && matrix[middle+1][0] > target)
                break;
            else if(matrix[middle][0] < target && matrix[middle+1][0] <=target)
                start = middle +1;
            else
                end = middle-1;

        }
        return middle;
    }
    bool getlie(vector<int>& matrix, int target){
        int size = matrix.size();
        int start = 0, end = size-1;
        int middle;
        while(start<=end){
            middle = start+(end-start)/2;
            if(matrix[middle] == target)
                return true;
            else if(matrix[middle] > target)
                end = middle-1;
            else
                start = middle+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sizeh = matrix.size();
        if(sizeh <= 0)
            return false;
        int sizel = matrix[0].size();
        if(sizel <= 0)
            return false;
        int hang;
        hang = gethang(matrix, target);
        if(hang == -1)
            return false;
        return getlie(matrix[hang], target);

    }
};


