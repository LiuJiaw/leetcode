/*
 * word-break.cpp
 *
 *  Created on: 2018年7月19日
 *      Author: garvin
 */

/* Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s ="leetcode",
dict =["leet", "code"].
Return true because"leetcode"can be segmented as"leet code". */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int size = s.length();
        bool *record = new bool[size];
        for(int i=0; i<size; i++){
            record[i] = false;
            for(int j=0; j<=i; j++){
                string tmp(s, j, i-j+1);
                if( (j==0||record[j-1]) && dict.find(tmp)!=dict.end()){
                    record[i] = true;
                    break;
                }
            }
        }
        return record[size-1];
    }
};
