/*
 * 97. 交错字符串.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/


class Solution {
public:
    bool check(const string& s1, int index1, const string& s2, int index2, const string& s3, int index3){
        if(index3 == s3.size()){
            if(index1 == s1.size() && index2 == s2.size())
                return true;
            return false;
        }
        if(index1 == s1.size()){
            if(s2[index2] == s3[index3])
                return check(s1, index1, s2, index2+1, s3, index3+1);
            return false;
        }
        if(index2 == s2.size()){
            if(s1[index1] == s3[index3])
                return check(s1, index1+1, s2, index2, s3, index3+1);
            return false;
        }
        if(s1[index1] == s2[index2]){
            if(s1[index1] == s3[index3])
                return check(s1, index1+1, s2, index2, s3, index3+1) || check(s1, index1, s2, index2+1, s3, index3+1);
            return false;
        }
        else if(s1[index1] != s3[index3] && s2[index2] != s3[index3])
            return false;
        else if(s1[index1] == s3[index3])
            return check(s1, index1+1, s2, index2, s3, index3+1);
        else
            return check(s1, index1, s2, index2+1, s3, index3+1);
    }
    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, 0, s2, 0, s3, 0);
    }
};
