/*
 * string-to-integer-atoi.cpp
 *
 *  Created on: 2018年7月12日
 *      Author: garvin
 */



/*Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.*/

/*
 * 春招面试百度的时候，三面面试官就是出了一个atoi的实现
 * 本题的要求是，若为空串，则返回0
 * 删掉开始的空格,识别正负号
 * 如果在任何数字之前为非数字，返回0
 * 若某数字之后为非数字，则返回截止非数字之前的数值
 */


class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL)
            return 0;

        int length = 0;
        for(length = 0; str[length] != '\0'; length++);

        int Index = 0;
        while(str[Index] == ' ')
            Index++;

        bool fuhao = true;
        if(str[Index] == '-') fuhao = false, Index++;
        if(str[Index] == '+') fuhao = true, Index++;

        if(str[Index]>'9' || str[Index]<'0')
            return 0;

        long long int ans = 0;
        while(Index < length){
            if(str[Index] > '9' || str[Index] < '0'){
                break;
            }
            ans = ans*10 + str[Index]-'0';
            Index++;
            if(ans>INT_MAX){
                return fuhao? INT_MAX : INT_MIN;
            }
        }

        return fuhao ? ans : -ans;
    }
};

