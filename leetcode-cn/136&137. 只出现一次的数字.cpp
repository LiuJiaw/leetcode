/*
 * 136&137. 只出现一次的数字.cpp
 *
 *  Created on: 2018年9月15日
 *      Author: garvin
 */

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1

示例 2:

输入: [4,1,2,1,2]
输出: 4
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3

示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> record(32, 0);
        int size = nums.size();
        for(int i=0; i<size; i++){
            for(int j=0; j<32; j++){
                record[j] += ( nums[i]&(1<<j) ? 1 : 0 );
            }
        }
        for(int i=0; i<32; i++){
            record[i] %= 3;
        }
        int tmp = 1;
        int result = 0;
        for(int i=0; i<32; i++){
            result += tmp*record[i];
            tmp *= 2;
        }
        return result;
    }
};


