/*
 * 151. 翻转字符串里的单词.cpp
 *
 *  Created on: 2018年9月20日
 *      Author: garvin
 */

/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例:

输入: "the sky is blue",
输出: "blue is sky the".

说明:

    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/

class Solution {
public:
    void Reverse(string &s, int start, int end){
        end--;
        while(start<end){
            swap(s[start++], s[end--]);
        }
    }
    void handlestr(string& str){
    	string tmp;
    	int index = 0;
    	while(index<str.size() && str[index] == ' ')
    		index++;
    	for(; index<str.size(); index++){
    		if(str[index] != ' ')
    			tmp += str[index];
    		else{
    			if(tmp[tmp.size()-1] == ' ')
    				continue;
    			else
    				tmp += ' ';
    		}
    	}
    	if (tmp[tmp.size() - 1] == ' ')
    		tmp.erase(tmp.end() - 1);
    	swap(str, tmp);
    }
    void reverseWords(string &s) {
        int size = s.size();
        int start = 0;
        for(int i=0; i<size; i++){
            if(s[i] != ' ')
                continue;
            Reverse(s, start, i);
            start = i+1;
            while(s[start] == ' ')
                start ++;
            i = start;
        }
        Reverse(s, start, size);
        Reverse(s, 0, size);
        handlestr(s);
    }
};

