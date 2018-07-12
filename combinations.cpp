/*
 * combinations.cpp
 *
 *  Created on: 2018年7月12日
 *      Author: garvin
 */

/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/


/*
 * WA了很多次，到后面心态崩了
 * 就是一个回溯法，不过返回的vector顺序不对也无法AC
 * 一开始我是从后面遍历，比如n=4,k=2代表从前四个数中取2个
 * 可以去尝试取第四个数，然后从前三个中取一个；或取第三个数，从前两个中取一个
 * 然而返回的顺序不对，一直WA，很难受，只能从前面开始找...
 */


class Solution {
public:
    void choose(int start, int end, int k, vector<vector<int>>& ans, vector<int>& record ){
        if(k == 0)
        {
            ans.push_back(record);
            return;
        }
        if(start>end || (end-start+1)<k){
            return;
        }
        for(int j = start; j<=end; j++){
            record.push_back(j);
            choose(j+1, end, k-1, ans, record);
            record.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ans;
        if(n<k || k==0)
            return ans;
        vector<int> record;

        for(int i = 1; i <= n; i++){
            record.push_back(i);
            choose(i+1, n, k-1, ans, record);
            record.pop_back();
        }

        return ans;
    }
};

