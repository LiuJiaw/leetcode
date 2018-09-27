/*
 * 169.求众数.cpp
 *
 *  Created on: 2018年9月27日
 *      Author: garvin
 */

/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3

示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int result = nums[0];
        int restimes = 1;
        for(int i=1; i<size; i++){
            if(nums[i] == result)
                restimes++;
            else
                restimes--;
            if(restimes == 0)
                result = nums[i], restimes++;
        }
        for(int i=0; i<size; i++)
            if(nums[i] == result)
                restimes++;
        if(restimes > size/2)
            return result;
        return -1;
    }
};


