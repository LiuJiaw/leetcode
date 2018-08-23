/*
 * 6. Z字形变换.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * 一个装着numRows个string的vector
 * 蛇皮走位放字母...
 * 一个变量是当前下标， 另一个记录方向
 * 到头了更换方向即可
 */

/*
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
P   A   H   N
A P L S I I G
Y   I   R

之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:
string convert(string s, int numRows);

示例 1:
输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:
输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:
P     I    N
A   L S  I G
Y A   H R
P     I
*/


class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(size <= numRows || numRows == 1)
            return s;
        vector<string> record;
        record.resize(numRows);
        int index = 0, direct = 1;
        for(int i=0; i<size; i++){
            record[index] += s[i];
            if(direct == 1)
                index++;
            else
                index--;
            if(index == numRows-1)
                direct = 0;
            if(index == 0)
                direct = 1;
        }
        string result = "";
        for(int i=0; i<numRows; i++)
            result += record[i];
        return result;
    }
};

