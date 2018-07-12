/*
 * pascals-triangle-ii.cpp
 *
 *  Created on: 2018年7月12日
 *      Author: garvin
 */

/* Given an index k, return the k th row of the Pascal's triangle.

For example, given k = 3,
Return[1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? */

/*
 * 针对每一行，行首与行尾都为1，
 * 剩余元素从后向前更新，更新后下表k的值为更新前下标k的值加上更新前下表为k-1的值
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0){
            ans.push_back(1);
            return ans;
        }

        ans.push_back(1);
        ans.push_back(1);
        if(rowIndex == 1){
            return ans;
        }

        ans.resize(rowIndex+1);

        for(int i=2; i<=rowIndex; i++){
            ans[i] = 1;
            ans[0] = 1;
            for(int j=i-1; j>0; j--){
                ans[j] = ans[j] + ans[j-1];
            }
        }
        return ans;
    }
};
