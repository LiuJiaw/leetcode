/*
 * anagrams.cpp
 *
 *  Created on: 2018年7月7日
 *      Author: garvin
 */

/*Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case. */

/*
 * 一开始没读懂题，竟然还没有例子...
 * For example:
 * Input:　　["tea","and","ate","eat","den"]
 * Output: ["tea","ate","eat"]
 * 思路：将每个字符串的每个字符排序，排序后相同的字符串符合anagrams
 * 因此，将每一种排序后的字符串作为键值，实值为装有排序前的原型的vector
 * 判断unordered_map中的每一项的vector项数即可
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> record;
        vector<string> ans;
        int size = strs.size();

        for(int i=0; i<size; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            record[tmp].push_back(strs[i]);
        }

        for(auto item = record.begin(); item!= record.end(); item++){
            if(item->second.size()>1){
                ans.insert(ans.end(), item->second.begin(), item->second.end());
            }
        }
        return ans;
    }
};
