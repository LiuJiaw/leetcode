/*
 * 69. x 的平方根.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
 * 二分，更快一点
 */

/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2

示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int start = 0, end = x/2+1;
        int middle;
        while(start<=end){
            middle = start+(end-start)/2;
            if(middle<=x/middle && (middle+1)>x/(middle+1))
                break;
            else if(middle<x/middle && (middle+1)<=x/(middle+1))
                start = middle+1;
            else
                end = middle-1;
        }
        return middle;
    }
};


