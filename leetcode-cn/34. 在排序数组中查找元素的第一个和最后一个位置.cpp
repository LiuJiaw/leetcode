/*
 * 34. 在排序数组中查找元素的第一个和最后一个位置.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
 * 这道题，二分找到target后，向前向后探索
 * 其实如果target重复多次的话，复杂度蛮高的，将近O(n)
 * 可以使用algorithm中的lower_bound和upper_bound
 * 前者可以找到第一个大于等于target的，相当于值为target中的第一个
 * 后者可以找到第一个大于target的，相当于值为target中最后一个的下一个
 * 找到的两个迭代器之间部分(前者含，后者不含)即可
 */

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int start = 0, end = nums.size()-1;
        int middle =0;
        while(start<=end){
            middle = end+(start-end)/2;
            if(nums[middle] == target)
                break;
            else if(nums[middle]>target)
                end = middle-1;
            else
                start = middle+1;
        }
        if(nums[middle]!=target){
            result.push_back(-1);
            result.push_back(-1);
        }
        else{
            int first, last;
            first = last = middle;
            while(first>=start && nums[first]==nums[middle])
                first--;
            while(last<=end && nums[last]==nums[middle])
                last++;
            result.push_back(first+1);
            result.push_back(last-1);
        }
        return result;
    }
};


