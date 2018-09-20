/*
 * 152. 乘积最大子序列.cpp
 *
 *  Created on: 2018年9月20日
 *      Author: garvin
 */

/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max=1, Min=1;
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int tmpmax = Max;
            Max = max(nums[i], max(nums[i]*Max, nums[i]*Min));
            Min = min(nums[i], min(nums[i]*tmpmax, nums[i]*Min));
            result = max(result, Max);
        }
        return result;
    }
};


