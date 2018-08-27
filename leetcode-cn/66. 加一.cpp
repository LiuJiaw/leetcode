/*
 * 66. 加一.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        bool jinwei = true;
        int size = digits.size();
        if(size<=0)
            return result;
        for(int i=size-1; i>=0 && jinwei == true; i--){
            result[i] = (result[i]+jinwei)%10;
            if(result[i] == 0){
                jinwei = true;
            }
            else
                jinwei = false;
        }
        if(jinwei == true)
            result.insert(result.begin(), 1);
        return result;
    }
};


