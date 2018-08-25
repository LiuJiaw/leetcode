/*
 * 39&40. 组合总和.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

    所有数字（包括 target）都是正整数。
    解集不能包含重复的组合。

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/

class Solution {
public:
    void getresult(vector<vector<int> >& result, vector<int>& record, const vector<int>& candidates, int target, int index){
        if(target==0){
            result.push_back(record);
            return;
        }
        if(target<0 || index>=candidates.size())
            return;
        record.push_back(candidates[index]);
        getresult(result, record, candidates, target-candidates[index], index);
        record.erase(record.end()-1);
        getresult(result, record, candidates, target, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if(candidates.size()<=0)
            return result;
        vector<int> record;
        getresult(result, record, candidates, target, 0);
        return result;
    }
};

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]*/

class Solution {
public:
    void getresult(const vector<int>& candidates, vector<vector<int> >& result, vector<int>& record, int index, int sum, const int target){
        if(sum>target || (index == candidates.size() && sum!=target) )
            return;
        if(sum == target){
            result.push_back(record);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i!=index && candidates[i]==candidates[i-1])
                continue;
            record.push_back(candidates[i]);
            sum += candidates[i];
            getresult(candidates, result, record, i+1, sum, target);
            sum -= candidates[i];
            record.erase(record.end()-1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if(candidates.size()<=0)
            return result;
        vector<int> record;
        sort(candidates.begin(), candidates.end());
        getresult(candidates, result, record, 0, 0, target);
        return result;
    }
};

