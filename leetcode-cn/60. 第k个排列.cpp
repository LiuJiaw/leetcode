/*
 * 60. 第k个排列.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

给定 n 和 k，返回第 k 个排列。

说明：

    给定 n 的范围是 [1, 9]。
    给定 k 的范围是[1,  n!]。

示例 1:

输入: n = 3, k = 3
输出: "213"

示例 2:

输入: n = 4, k = 9
输出: "2314"
*/

class Solution {
public:
    void getresult(string s, string& result, int& left, int index){
        int size = s.size();
        if(index == size){
            left--;
            result = s;
            return;
        }
        for(int i=index; i<size; i++){
            swap(s[index], s[i]);
            getresult(s, result, left, index+1);
            if(left == 0)
                return;
            //swap(s[index], s[i]);
        }
    }
    string getPermutation(int n, int k) {
        string result = "";
        for(int i=1; i<=n; i++)
            result += ('0'+i);
        string s(result);
        getresult(s, result, k, 0);
        return result;
    }
};


