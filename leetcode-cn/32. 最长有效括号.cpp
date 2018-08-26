/*
 * 32. 最长有效括号.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"

示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        vector<int> vec;
        for(int i=0; i<size; i++){
            if(s[i] == '(')
                vec.push_back(-1);
            else{
                bool isfind = false;
                for(int j=vec.size()-1; j>=0 && vec[j]!=-2; j--){
                    if(vec[j] == -1){
                        vec[j] = 2;
                        isfind = true;
                        break;
                    }
                }
                if(!isfind)
                    vec.push_back(-2);
            }
        }
        int result = 0, tmp =0;
        for(int i = 0; i<vec.size(); i++){
            if(vec[i] == -1 || vec[i] == -2){
                result = max(result, tmp);
                tmp = 0;
            }
            else
                tmp += vec[i];
        }
        result = max(result, tmp);
        return result;
    }
};


