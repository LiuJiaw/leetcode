/*
 * 7. 反转整数.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * leetcode上定级为easy
 * 但我判断是否溢出这里WA了很多次
 * result > INT_MAX/10 || (result == INT_MAX/10 && x > 7)
 * result < INT_MIN/10 || (result == INT_MIN/10 && x < -8)
 * 记得以前也做过类似的题目，我使用long long int类型盛装变量，然后判断INT_MAX和INT_MIN
 * 感觉是错的，改正改正
 */

/*给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
输入: 123
输出: 321

 示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0){
            int tmp = x%10;
            x /= 10;
            if(result > INT_MAX/10 || (result == INT_MAX/10 && x > 7) )
                return 0;
            if(result < INT_MIN/10 || (result == INT_MIN/10 && x < -8) )
                return 0;
            result = result*10 + tmp;
        }
        return result;
    }
};

