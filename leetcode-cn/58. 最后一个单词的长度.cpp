/*
 * 58. 最后一个单词的长度.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        if(size<=0)
            return 0;
        int result = 0;
        bool isfind = false;
        for(int i=size-1; i>=0; i--){
            if( (s[i] == ' ' || s[i]<'A' || s[i]>'Z'&&s[i]<'a' || s[i]>'z') && isfind == false)
                continue;
            else if(s[i] == ' ' || s[i]<'A' || s[i]>'Z'&&s[i]<'a' || s[i]>'z')
                break;
            else{
                result++;
                isfind = true;
            }
        }
        return result;
    }
};


