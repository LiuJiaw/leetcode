/*
 * container-with-most-water.cpp
 *
 *  Created on: 2018年7月20日
 *      Author: garvin
 */


/* Given n non-negative integers a1 , a2 , ..., an , where each represents a point at coordinate (i, ai ).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai ) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container. */

/*
 * 一开始暴力搜
 * 结果发现可以用贪心
 * 头和尾小的那一方向中间走
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        int ans = INT_MIN;
        int start = 0, end = size-1;
        while(start<end){
            ans = max( (end-start)*min(height[start], height[end]), ans);
            height[start] > height[end] ? end-- : start++ ;
        }
        return ans;
    }
};

