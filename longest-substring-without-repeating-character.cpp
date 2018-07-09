/*
 * longest-substring-without-repeating-character.cpp
 *
 *  Created on: 2018年7月9日
 *      Author: garvin
 */

/* Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 For "bbbbb" the longest substring is "b", with the length of 1.*/

/*
 * 这道题WA了很多次
 * 原因是在判断map中是否有该字符并更新start时
 * 没有判断当前start和该字符出现的上一次位置的大小
 * 可能之前会出现重复字符导致一大段字符被抛弃的情况，
 * 但此时树中被抛弃字符的出现位置并没有更新
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int size = s.size();
        int start = 0;
        int end = 0;
        int Max = 0;
        map<char, int> record;
        for(int i=0; i<size; i++){
            if(record.find(s[i]) != record.end()){
                start = max(record[s[i]]+1, start);
            }
            record[s[i]] = i;
            end = i;
            Max = max(end-start+1, Max);
        }
        return Max;
    }
};

