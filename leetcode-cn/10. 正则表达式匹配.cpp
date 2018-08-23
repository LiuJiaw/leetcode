/*
 * 10. 正则表达式匹配.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * 之前牛客上做了这道题，所以顺手a掉
 * 思路是，假如下一位是'*'，当前为匹配（即字符相同或为'.'）的话，可能是s串往下走一位或p串走两位(走过*)
 * 						当前为不匹配，则p串往下走两位
 * 		 假如下一位不是‘*’，匹配就一致往下一位，不匹配返回false
 */

/*
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。

匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。

示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。

示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。

示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0 && p.size()==0)
            return true;
        if(s.size()!=0 && p.size()==0)
            return false;
        int sizes = s.size();
        int sizep = p.size();
        if(sizep>1 && p[1] == '*'){
            if(sizes == 0 || s[0]!=p[0]&&p[0]!='.')
                return isMatch(s.substr(0), p.substr(2));
            else
                return isMatch(s.substr(0), p.substr(2)) || isMatch(s.substr(1), p.substr(0));
        }
        else{
            if(sizes == 0)
                return false;
            if(s[0]==p[0] || p[0]=='.')
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
    }
};

