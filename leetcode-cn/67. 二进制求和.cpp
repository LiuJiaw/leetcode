/*
 * 67. 二进制求和.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"

示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/


class Solution {
public:
    string addBinary(string a, string b) {
        int sizea = a.size(), sizeb = b.size();
        if(sizea == 0)
            return b;
        if(sizeb == 0)
            return a;
        string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        bool jinwei = false;
        int index = 0;
        int tmp = 0;
        for(; index<sizea && index<sizeb; index++){
            tmp = jinwei+a[index]-'0'+b[index]-'0';
            jinwei = tmp > 1 ? true : false;
            result += ( tmp % 2 +'0');
        }
        if(index == sizea){
            for(; index<sizeb; index++){
                tmp = jinwei+b[index]-'0';
                jinwei = tmp > 1 ? true : false;
                result += ( tmp % 2 +'0');
            }
        }
        else if(index == sizeb){
            for(; index<sizea; index++){
                tmp = jinwei+a[index]-'0';
                jinwei = tmp > 1 ? true : false;
                result += ( tmp % 2 +'0');
            }
        }
        if(jinwei)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};

