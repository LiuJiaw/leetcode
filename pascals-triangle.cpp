/*
 * pascals-triangle.cpp
 *
 *  Created on: 2018年7月19日
 *      Author: garvin
 */

/* Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows <= 0)
            return ans;

        vector<int> row;
        row.push_back(1);
        ans.push_back(row);
        for(int i=1; i<numRows; i++){
            row.push_back(1);
            for(int j=i-1; j>0; j--){
                row[j] = row[j]+row[j-1];
            }
            ans.push_back(row);
        }
        return ans;
    }
};


