/*
 * 78. 子集.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


class Solution {
public:
    void getresults(const vector<int>& nums, vector<vector<int> >& results, vector<int>& result, int index){
        if(index == nums.size()){
            results.push_back(result);
            return;
        }
        getresults(nums, results, result, index+1);
        result.push_back(nums[index]);
        getresults(nums, results, result, index+1);
        result.erase(result.end()-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > results;
        int size = nums.size();
        vector<int> result;
        getresults(nums, results, result, 0);
        return results;
    }
};

