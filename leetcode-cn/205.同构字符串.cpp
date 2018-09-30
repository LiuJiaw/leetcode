/*
 * 205.同构字符串.cpp
 *
 *  Created on: 2018年9月30日
 *      Author: garvin
 */

/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true

示例 2:

输入: s = "foo", t = "bar"
输出: false

示例 3:

输入: s = "paper", t = "title"
输出: true

说明:
你可以假设 s 和 t 具有相同的长度。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> ss, st;
        int sizes = s.size(), sizet = t.size();
        if(sizes != sizet)
            return false;
        vector<int> recs, rect;
        int indexs = 0, indext = 0;
        for(int i=0; i<sizes; i++){
            if(ss.find(s[i]) == ss.end()){
                ss[s[i]] = indexs++;
                recs.push_back(indexs);
            }
            else
                recs.push_back(ss[s[i]]);
            if(st.find(t[i]) == st.end()){
                st[t[i]] = indext++;
                rect.push_back(indext);
            }
            else
                rect.push_back(st[t[i]]);
        }
        for(int i=0; i<sizes; i++)
            if(recs[i] != rect[i])
                return false;
        return true;
    }
};

