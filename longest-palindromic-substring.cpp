/*
 * longest-palindromic-substring.cpp
 *
 *  Created on: 2018年7月9日
 *      Author: garvin
 */


/*Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring. */

/*
 * 建立一张字符串长成字符串长的表
 * 能够记录起点为纵坐标，终点为横坐标的字符串是否为回文
 * 当纵坐标等于横坐标，则为回味，若终点为起点后一位，需要判断两字符是否一致
 * 否则判断去除头部和尾部字符的字符串是否回文以及首位字符是否相等，来决定该字符串是否回文
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return s;
        int size = s.size();
        bool **record = new bool*[size];
        for(int i=0; i<size; i++)
            record[i] = new bool[size];
        int max_start = 0, max_end = 0, Max = 0;
        for(int i=size-1; i>=0; i--){
            for(int j=i; j<size; j++){
                if(i==j)
                    record[i][j] = true;
                else if(j==i+1)
                    record[i][j] = s[i]==s[j] ? true : false;
                else{
                    record[i][j] = (record[i+1][j-1] && s[i]==s[j]) ? true : false;
                }
                if(record[i][j] && (j-i+1>Max) ){
                    Max = j-i+1;
                    max_start = i;
                    max_end = j;
                }
            }
        }
        string ans(s, max_start, max_end-max_start+1);
        return ans;
    }
};
