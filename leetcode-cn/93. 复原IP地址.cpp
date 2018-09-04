/*
 * 93. 复原IP地址.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

class Solution {
public:
    void getresults(vector<string>& results, string result, const string& s, int index, int left){
        int size = s.size();
        if(left == 0 && index == size) {
            results.push_back(result);
            return;
        }
        string tmp(result);
        if(index+1<=size){
            if(index!=0)
                result += '.';
            result += s.substr(index, 1);
            getresults(results, result, s, index+1, left-1);
            result = tmp;
        }
        if(index+2<=size && s[index]!='0'){
            if(index!=0)
                result += '.';
            result += s.substr(index, 2);
            getresults(results, result, s, index+2, left-1);
            result = tmp;
        }
        if(index+3<=size && s[index]!='0'){
            int num = atoi(s.substr(index, 3).c_str());
            if(num<=255){
                if(index!=0)
                    result += '.';
                result += s.substr(index, 3);
                getresults(results, result, s, index+3, left-1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s){
        int size = s.size();
        vector<string> results;
        if(size<4 || size>12)
            return results;
        string result;
        getresults(results, result, s, 0, 4);
        return results;
    }
};
