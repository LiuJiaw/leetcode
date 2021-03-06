/*
 * 接雨水.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
 * 需要先确定最高的地方，相当于挡板的作用
 * 有了后面这个保证不漏水的后盾，从左从右分别向中间计算即可
 * 相当于算无数个小罐子的总和
 */

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6*/

class Solution {
public:
    int trap(vector<int>& height) {
        int highest = 0, index = 0;
        int size = height.size();
        for(int i=0; i<size; i++){
            if(height[i]>highest){
                highest = height[i];
                index = i;
            }
        }
        int highestleft = 0, highestright = 0;
        int result = 0;
        for(int i=0; i<index; i++){
            highestleft = max(highestleft, height[i]);
            result += highestleft-height[i];
        }
        for(int i=size-1; i>index; i--){
            highestright = max(highestright, height[i]);
            result += highestright-height[i];
        }
        return result;
    }
};

