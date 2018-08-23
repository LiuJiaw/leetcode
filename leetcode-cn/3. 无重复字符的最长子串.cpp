/*
 * 3. 无重复字符的最长子串.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 无重复字符的最长子串是 "abc"，其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Max=0;
        int times=0;
        bool exict[256]={false};
        int loc[256]={0};
        for(int i=0;s[i]!='\0';i++){
            if(exict[s[i]] == false){
                times++;
                exict[s[i]]=true;
                if(Max<times){
                    Max = times;
                }
                loc[s[i]]=i;
            }
            else{
                for(int j=i-times;j<loc[s[i]];j++){
                    exict[s[j]]=false;
                }
                times-=(times-i+loc[s[i]]);
                loc[s[i]]=i;
            }
        }
        return Max;
    }
};


