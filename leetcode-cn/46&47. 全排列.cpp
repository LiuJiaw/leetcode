/*
 * 46&47. 全排列.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    void getresult(vector<vector<int> >& result, vector<int>& nums, int index){
        if(index == nums.size()){
            result.push_back(nums);
        }
        for(int i=index; i<nums.size(); i++){
            int tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            getresult(result, nums, index+1);
            tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        int size = nums.size();
        if(size<0)
            return result;
        getresult(result, nums, 0);
        return result;
    }
};

/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。
示例:
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    void getresult(vector<vector<int> >& result, vector<int>& nums, int index){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }
        int size = nums.size();
        for(int i=index; i<size; i++){
            sort(nums.begin()+index, nums.end());
            if(i!=index && (nums[i]==nums[index] || nums[i]==nums[i-1]) )
                continue;
            swap(nums[index], nums[i]);
            getresult(result, nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > result;
        if(size<=0)
            return result;
        sort(nums.begin(), nums.end());
        getresult(result, nums, 0);
        return result;
    }
};


