/*
 * 大数相乘.cpp
 *
 *  Created on: 2018年8月25日
 *      Author: garvin
 */

/*
 * 大数相乘也算是高频面试题了
 * 之前一直没有具体实现ac过
 * 结果发现...耗得时间比一道hard都长...
 * 一直有改不尽的bug
 * 于是借鉴了网上的代码，不得不说，简洁明了
 */

/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

说明：
    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        string res(l1+l2,'0');
        if(l1==0||l2==0)
            return "";
        for(int i=l1-1;i>=0;i--){
            int add=0;
            for(int j=l2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=res[i+j+1]+add+mul%10-'0';
                res[i+j+1]='0'+sum%10;
                add=mul/10+sum/10;
            }
            res[i]+=add;
        }
        for(int i=0;i<l1+l2;i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
    }
};


