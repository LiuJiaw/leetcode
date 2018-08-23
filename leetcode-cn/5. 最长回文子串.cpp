/*
 * 5. 最长回文子串.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * 注意两种形式吧， aba和abba
 * 选定一个字符(或两个)作为中心点
 * 向两侧扩散判断
 */

/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/


class Solution {
public:
    void getresult(const string& s, string& result, int ms, int me){
        int size = s.size();
        int resultsize = result.size();
        while(ms>=0 && me<size && s[ms]==s[me]){
            ms--, me++;
        }
        ms++, me--;
        if(me-ms+1 > resultsize){
            string tmp(s, ms, me-ms+1);
            result = tmp;
        }
    }
    string longestPalindrome(string s) {
        string result;
        if(s == "")
            return result;
        int size = s.size();
        for(int i=0; i<size; i++)
            getresult(s, result, i, i);
        for(int i=0; i<size-1; i++)
            getresult(s, result, i, i+1);
        return result;
    }
};

