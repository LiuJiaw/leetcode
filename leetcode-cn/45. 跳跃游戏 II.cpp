/*
 * 45. 跳跃游戏 II.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
 * 以前做类似的题目，一直用一个数组记录当前位置的最小步数
 * 但这道题数值较大，会超时
 * 我使用了两个变量，相当于人的两只脚
 * 第一个位置的数值确定前脚的落脚地
 * 在后脚迈向前脚的过程中，也就是遍历从当前位置到前脚的落脚地的数组的过程，记录最大的值
 * 不要忘记最大的值在后脚迈进的过程有损耗
 * 后脚落在前脚位置后，前脚可以直接迈出之前记录的最大的值
 * 之后的过程以此类推
 * 也就转化成需要迈几步的问题
 * 最后一步没走完，也算一步
 */

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明:

假设你总是可以到达数组的最后一个位置。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int size = nums.size();
        int maxindex1=nums[0], maxindex2=0;
        int result = 0;
        for(int i=1; i<size; i++){
            maxindex2 = max(--maxindex2, nums[i]);
            if(--maxindex1==0){
                result++;
                if(i!=size-1)
                    maxindex1 = maxindex2;
                else
                    maxindex1 = -1;
                maxindex2 = 0;
            }
        }
        if(maxindex1!=-1)
            result++;
        return result;
    }
};

