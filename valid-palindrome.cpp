/*
 * valid-palindrome.cpp
 *
 *  Created on: 2018年7月6日
 *      Author: garvin
 */


/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama"is a palindrome.
"race a car"is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.*/

/*使用非递归方式实现
 * 逐个比较下标为start， end的字符
 * 遇到非数字且非字母的字符，跳过
 */

class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            while( !( (s[start]>='A'&&s[start]<='Z')||(s[start]>='a'&&s[start]<='z')||(s[start]>='0'&&s[start]<='9') ) ){
                start++;
            }
            while( !( (s[end]>='A'&&s[end]<='Z')||(s[end]>='a'&&s[end]<='z')||(s[end]>='0'&&s[end]<='9') ) ){
                end--;
            }
            if(start>=end)
                break;
            if( !(s[start]==s[end] || s[start]==(s[end]+'A'-'a') || s[start]==(s[end]+'a'-'A')) )
                return false;
            start++;
            end--;
        }
        return true;
    }
};



