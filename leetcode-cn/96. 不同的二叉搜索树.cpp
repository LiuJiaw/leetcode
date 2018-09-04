/*
 * 96. 不同的二叉搜索树.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        if(n == 2)
            return 2;
        int *record = new int[n+1];
        record[0] = 1, record[1] = 1, record[2] = 2;
        for(int i=3; i<=n; i++){
            int start = 0, end = i-1;
            int result = 0;
            while(start<end){
                result += 2*record[start++]*record[end--];
            }
            if(start == end)
                result += record[start]*record[end];
            record[i] = result;
        }
        return record[n];
    }
};


