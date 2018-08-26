/*
 * 38. 报数.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n ，输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。

示例 1:
输入: 1
输出: "1"

示例 2:
输入: 4
输出: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        string result;
        queue<int> q;
        q.push('1');
        while(--n >0 ){
            int size = q.size();
            char num = '0';
            int times = 0;
            for(int i=0; i<size; i++){
                if(i==0){
                    num = q.front();
                    times = 1;
                    q.pop();
                    continue;
                }
                if(q.front() == num){
                    times++;
                }
                else{
                    q.push(times+'0');
                    q.push(num);
                    times=1;
                    num = q.front();
                }
                q.pop();
            }
            q.push(times+'0');
            q.push(num);
        }
        while(!q.empty()){
            result += q.front();
            q.pop();
        }
        return result;
    }
};


