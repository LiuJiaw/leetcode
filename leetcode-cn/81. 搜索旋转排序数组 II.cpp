/*
 * 81. 搜索旋转排序数组 II.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true

示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
            return false;
        int start = 0, end = size-1;
        int middle = start + (end-start)/2;
        if(nums[start] == nums[end] && nums[start] == nums[middle]){
            for(int i=0; i<size; i++)
                if(nums[i] == target)
                    return true;
            return false;
        }
        while(start <= end){
            middle = start + (end-start)/2;
            if(nums[middle] == target)
                return true;
            if(nums[start] == nums[middle])
                start = middle+1;
            else if(nums[end] == nums[middle])
                end = middle-1;
            else if(nums[start] < nums[middle] && (nums[middle] <= target || target < nums[start]) )
                start = middle+1;
            else if(nums[start] < nums[middle])
                end = middle -1;
            else if(nums[start] > nums[middle] && (nums[middle] > target || target>=nums[start]) )
                end = middle -1;
            else
                start = middle+1;
        }
        return false;
    }
};
