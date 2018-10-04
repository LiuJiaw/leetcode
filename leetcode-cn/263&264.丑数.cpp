/*
 * 263.丑数.cpp
 *
 *  Created on: 2018年10月4日
 *      Author: garvin
 */

/*
编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例 1:

输入: 6
输出: true
解释: 6 = 2 × 3

示例 2:

输入: 8
输出: true
解释: 8 = 2 × 2 × 2

示例 3:

输入: 14
输出: false
解释: 14 不是丑数，因为它包含了另外一个质因数 7。

说明：

    1 是丑数。
    输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
*/

class Solution {
public:
    bool isUgly(int num) {
        while(num && num % 2 == 0)
            num /= 2;
        while(num && num % 3 == 0)
            num /= 3;
        while(num && num % 5 == 0)
            num /= 5;
        return num == 1;
    }
};

/*
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

说明:

    1 是丑数。
    n 不超过1690。
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> record(n+5, 0);
        record[0] = 1;
        int index_2, index_3, index_5;
        index_2 = index_3 = index_5 = 0;
        for(int i=1; i<n; i++){
            int value_2 = record[index_2]*2;
            int value_3 = record[index_3]*3;
            int value_5 = record[index_5]*5;
            record[i] = min(value_2, min(value_3, value_5));
            while(record[index_2]*2<=record[i])
                index_2++;
            while(record[index_3]*3<=record[i])
                index_3++;
            while(record[index_5]*5<=record[i])
                index_5++;
        }
        return record[n-1];
    }
};


