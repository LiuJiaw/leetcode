/*
 * reverse-integer.cpp
 *
 *  Created on: 2018年7月4日
 *      Author: garvin
 */

/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321*/

/*
 * 首先判断符号
 * 由于将数字逆序，所以希望将x的后面的数字首先提取出来
 * 提取出来的数字成为ans的高位数字
 */

class Solution {
public:
    int reverse(int x) {
        bool fuhao = true;
        int ans = 0;
        if(x<0){
            fuhao = false;
            x = -x;
        }
        while(x){
            int tmp = x%10;
            x /= 10;
            ans *=10;
            ans +=tmp;
        }
        return fuhao == true ? ans : -ans ;
    }
};

