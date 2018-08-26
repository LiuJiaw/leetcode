/*
 * 33. 搜索旋转排序数组.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
 * 写了一份，感觉有点绕
 * 而后修改了一下
 * 这道题有一个变种，就是元素可重复
 * 以后遇到再更一下
 */

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start= 0, end = nums.size()-1;
        int middle;
        while(start<=end){
            /*
            middle = end+(start-end)/2;
            if(nums[middle] == target)
                return middle;
            if(nums[middle]>nums[start] && nums[middle]<nums[end]){
                if(nums[middle] > target)
                    end = middle-1;
                else
                    start = middle+1;
            }
            else if(nums[middle]>nums[start] && nums[middle]>nums[end]){
                if(nums[middle] > target && nums[start]>target)
                    start = middle+1;
                else if(nums[middle] > target && nums[start]<=target)
                    end = middle-1;
                else
                    start = middle+1;
            }
            else{
                if(nums[middle] < target && nums[end]<target)
                    end = middle-1;
                else if(nums[middle] < target && nums[end]>=target)
                    start = middle+1;
                else
                    end = middle-1;
            }
            */
            middle = end+(start-end)/2;
            if(nums[middle] == target)
                return middle;
            if(nums[start]>nums[middle]){
                if(target<nums[middle] || target>nums[middle] && target>nums[end])
                    end = middle-1;
                else
                    start = middle+1;
            }
            else{
                if(target>nums[middle] || target<nums[middle] && target<nums[start])
                    start = middle+1;
                else
                    end = middle-1;
            }
        }
        return -1;
    }
};

