/*
 * combination-sum.cpp
 *
 *  Created on: 2018年7月8日
 *      Author: garvin
 */

/* Given a set of candidate numbers ( C ) and a target number ( T ), find all unique combinations in C where the candidate numbers sums to T .
The same repeated number may be chosen from C unlimited number of times.
Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
    The solution set must not contain duplicate combinations.
For example, given candidate set2,3,6,7and target7,
A solution set is:
[7]
[2, 2, 3] */

/*
 * 每个元素都有放入或者不放入两种可能
 * 当放入时，还可能继续放入，因此下标不后移
 * 当不放入时，下标往后移一个
 */

class Solution {
public:
    void getans(vector<vector<int>>& ans, vector<int>& record, vector<int>& candidates, int target, int index){
        if(target<0)
            return;
        if(index == candidates.size() && target==0){
            ans.push_back(record);
            return;
        }
        if(index == candidates.size() && target!=0)
            return;
        record.push_back(candidates[index]);
        getans(ans, record, candidates, target-candidates[index], index);
        record.pop_back();
        getans(ans, record, candidates, target, index+1);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        if(target<0 || candidates.size()==0)
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> record;
        getans(ans, record, candidates, target, 0);
        return ans;
    }
};


/*Given a collection of candidate numbers ( C ) and a target number ( T ), find all unique combinations in C where the candidate numbers sums to T .
Each number in C may only be used once in the combination.
Note:
   All numbers (including target) will be positive integers.
   Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
   The solution set must not contain duplicate combinations.
For example, given candidate set10,1,2,7,6,1,5and target8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] */

/*
 * 每个元素只能使用一次，
 * 所以不管有没有选择某元素，其下标都要加一
 * 此外还要进行去重处理
 * 避免【1,1】1 的测试得出【【1】,[1]】的错误答案
 */

class Solution {
public:
    void getans(vector<vector<int>>& ans, vector<int>& num, vector<int>& record, int target, int index){
        if(target<0)
            return;
        if(index==num.size() && target==0){
            if( find(ans.begin(), ans.end(), record) == ans.end() )
                ans.push_back(record);
            return;
        }
        if(index==num.size() && target!=0)
            return;
        record.push_back(num[index]);
        getans(ans, num, record, target-num[index], index+1);
        record.pop_back();
        getans(ans, num, record, target, index+1);
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if(target<=0 || num.size()==0)
            return ans;
        vector<int> record;
        sort(num.begin(), num.end());
        getans(ans, num, record, target, 0);
        return ans;
    }
};
