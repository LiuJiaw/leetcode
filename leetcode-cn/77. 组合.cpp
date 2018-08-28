/*
 * 77. 组合.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    void getresults(vector<vector<int> >& results, vector<int>& result, int index, int n, int k){
        if(result.size() == k){
            results.push_back(result);
            return;
        }
        if(index == n+1)
            return;
        for(int i=index; i<=n; i++){
            result.push_back(i);
            getresults(results, result, i+1, n, k);
            result.erase(result.end()-1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > results;
        if(n<k)
            return results;
        vector<int> result;
        getresults(results, result, 1, n, k);
        return results;
    }
};


