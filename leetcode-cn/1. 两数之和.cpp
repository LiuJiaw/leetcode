/*
 * 1. 两数之和.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * 快秋招了，打算把leetcode上的题敲一下
 * 估么时间不太够用了，就主要敲高频easy加所有的medium吧
 *
 * 这道题是第一题
 * 之前的做法是O(n2)的方法
 * 用map重做了一下，键值存target-nums的值，实值是它的下标
 * 复杂度O(nlogn)
 */

/*给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            m[target-nums[i]] = i;
        }
        map<int, int>::iterator item;
        for(int i=0; i<nums.size(); i++){
            item = m.find(nums[i]);
            if( item != m.end() && item->second!=i){
                result.push_back(i);
                result.push_back(item->second);
                break;
            }
        }
        return result;
    }
};

