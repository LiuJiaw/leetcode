/*
 * roman-to-integer.cpp
 *
 *  Created on: 2018年7月8日
 *      Author: garvin
 */

/* Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999. */

/*
 * 参照百度百科，罗马数字的规则为:
 * 相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
 * 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
 * 小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；
 * 在一个数的上面画一条横线，表示这个数增值 1,000 倍
 * 单这道题的规则有所简化，只要某数字小于其下一位，那么它贡献的是一个负值，否则贡献的为正值
 */

class Solution {
public:
    int romanToInt(string s) {
        int size = s.size();
        vector<int> record;
        record.reserve(size+1);
        for(int i=0; i<size; i++){
            switch(s[i]){
                case 'I':
                    record[i] = 1;
                    break;
                case 'X':
                    record[i] = 10;
                    break;
                case 'C':
                    record[i] = 100;
                    break;
                case 'M':
                    record[i] = 1000;
                    break;
                case 'V':
                    record[i] = 5;
                    break;
                case 'L':
                    record[i] = 50;
                    break;
                case 'D':
                    record[i] = 500;
                    break;
            }
        }

        int ans = 0;
        for(int i=0; i<size-1; i++){
            if(record[i]<record[i+1])
                ans-=record[i];
            else
                ans+=record[i];
        }
        ans+=record[size-1];
        return ans;
    }
};


