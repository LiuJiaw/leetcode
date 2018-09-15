/*
 * 132. 分割回文串 II.cpp
 *
 *  Created on: 2018年9月15日
 *      Author: garvin
 */

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
*/

class Solution {
public:
    int minCut(string s){
        int size = s.size();
        vector<bool> tmp(size, false);
        vector<vector<bool>> ishuiwen(size, tmp);
        for(int j=0; j<size; j++){
            for(int i=0; i<=j; i++){
                if(i==j)
                    ishuiwen[i][j] = true;
                else if (i == j-1)
                    ishuiwen[i][j] = (s[i] == s[j] ? true : false);
                else{
                    ishuiwen[i][j] = (s[i] == s[j] && ishuiwen[i+1][j-1]) ? true : false;
                }
            }
        }
        vector<int> results(size, INT_MAX);
        for(int i = 0; i<size; i++){
            if(ishuiwen[0][i] == true){
                results[i] = 0;
                continue;
            }
            for(int j=i-1; j>=0; j--){
                if(ishuiwen[j+1][i])
                    results[i] = min(results[i], results[j]+1);
            }
        }
        return results[size-1];
    }
};


