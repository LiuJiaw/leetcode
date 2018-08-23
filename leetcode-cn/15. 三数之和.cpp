/*
 * 15. 三数之和.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


class Solution {
public:
    void getans(vector<vector<int> >& ans, vector<int>& nums, int index){
        int start = 0, end = nums.size()-1;
        if(nums[index] == nums[index-1])
            start = index-1;
        while(start < index && end > index){
            while( start<index && start!=0 && nums[start] == nums[start-1] )
                start++;
            while( end>index && end!=nums.size()-1 && nums[end] == nums[end+1])
                end--;
            if(start >= index || end <= index)
                break;
            if(nums[start]+nums[end]+nums[index] == 0){
                vector<int> tmp;
                tmp.push_back(nums[start]);
                tmp.push_back(nums[index]);
                tmp.push_back(nums[end]);
                ans.push_back(tmp);
                start++, end--;
            }
            else if(nums[start]+nums[end]+nums[index] < 0)
                start++;
            else
                end--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        if(size<=0)
            return ans;
        for(int i=1; i<size-1; i++){
            if(i>1 && nums[i]==nums[i-1] && nums[i]==nums[i-2])
                continue;
            getans(ans, nums, i);
        }
        return ans;
    }
};

