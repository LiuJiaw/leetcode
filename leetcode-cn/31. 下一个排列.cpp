/*
 * 31. 下一个排列.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
 * 多写几个例子可知
 *
 */

/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int index = 0;
        for(index = nums.size()-2; index>=0; index--){
            if(nums[index]<nums[index+1])
                break;
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int index2 = 0;
        for(index2=nums.size()-1; nums[index2]<=nums[index]; index2--)
            ;
        while(nums[index2]==nums[index2-1])
            index2--;
        swap(nums[index], nums[index2]);
        sort(nums.begin()+index+1, nums.end());
        return;
    }
};
