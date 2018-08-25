/*
 * 41.缺失的第一个正数.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
 * 将数值为k的数字往数组的k-1位置上放
 * 当然，超出数组表示范围和k-1上本来就是k的除外
 * 最后遍历数组，找出第一个k-1位置上不是k的
 */

/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(size <=0)
            return 1;
        for(int i=0; i<size; ){
            if(nums[i] == i+1)
                i++;
            else{
                if(nums[i]>size || nums[i]<=0)
                    i++;
                else{
                    if(nums[nums[i]-1] == nums[i])
                        i++;
                    else
                        swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        int result = 0;
        for(result=0; result<size; result++)
            if(nums[result]!=result+1)
                break;
        return result+1;
    }
};


