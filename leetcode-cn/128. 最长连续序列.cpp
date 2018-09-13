/*
 * 128. 最长连续序列.cpp
 *
 *  Created on: 2018年9月13日
 *      Author: garvin
 */

/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        unordered_set<int> us;
        for(int i=0; i<nums.size(); i++){
            us.insert(nums[i]);
        }
        
        int result = 0, tmpresult = 0;
        for(int i=0; i<nums.size(); i++){
            tmpresult = 0;
            unordered_set<int>::iterator item = us.find(nums[i]);
            if(item == us.end())
                continue;
            else{
                tmpresult++;
                int j = 1;
                while( (item = us.find(nums[i]+j) ) != us.end())
                    tmpresult++, us.erase(nums[i]+j), j++;
                j = 1;
                while( (item = us.find(nums[i]-j) ) != us.end())
                    tmpresult++, us.erase(nums[i]-j), j++; 
            }
            us.erase(nums[i]);
            result = max(result, tmpresult);
        }
        return result;
    }
};
