/*
 * permutations.cpp
 *
 *  Created on: 2018年7月8日
 *      Author: garvin
 */

/*Given a collection of numbers, return all possible permutations.
For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1].*/

/*
 * 全排列算法
 * 基本思想是，比如一个长度为5的vector
 * 5个元素依次做首元素，然后对剩下的四个元素进行全排列
 * 一直递归到仅剩一个元素，此时即为一个满足结果
 * 将该结果放入二维vector
 */

class Solution {
public:
    void getans(vector<vector<int>>& ans, vector<int>& num, int has){
        if(has == num.size()-1){
            ans.push_back(num);
            return;
        }
        int size = num.size();
        for(int i=0; i<size-has; i++){
            if(num[has+i] == num[has] && i!=0)
                continue;
            int tmp = num[has+i];
            num[has+i] = num[has];
            num[has] = tmp;
            getans(ans, num, has+1);
            tmp = num[has+i];
            num[has+i] = num[has];
            num[has] = tmp;
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        int size = num.size();
        if(size == 0 || size == 1){
            ans.push_back(num);
            return ans;
        }
        getans(ans, num, 0);
        return ans;
    }
};

