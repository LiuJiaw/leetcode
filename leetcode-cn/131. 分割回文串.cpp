/*
 * 131. 分割回文串.cpp
 *
 *  Created on: 2018年9月14日
 *      Author: garvin
 */

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    void getresults(vector<vector<string>>& results, vector<string>& result, string& s, int index,
                    vector<vector<bool>>& ishuiwen){
        int size = s.size();
        if(index == size){
            results.push_back(result);
            return;
        }
        for(int i=index; i<size; i++){
            if(ishuiwen[index][i]){
                result.push_back(s.substr(index, i-index+1));
                getresults(results, result, s, i+1, ishuiwen);
                result.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
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
        vector<vector<string>> results;
        vector<string> result;
        getresults(results, result, s, 0, ishuiwen);
        return results;
    }
};


