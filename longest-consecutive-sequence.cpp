/*
 * longest-consecutive-sequence.cpp
 *
 *  Created on: 2018年7月4日
 *      Author: garvin
 */



/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.

Your algorithm should run in O(n) complexity. */

/*
 * 使用unorder_map，将vector中元素加入
 * 若在unorder_map中找到某元素，则从该元素开始向两边（数值）延伸，直到找不到为止
 * 记录并更新最长连续段
 */

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0 || num.size() == 1){
            return num.size();
        }
        unordered_set<int> s(num.begin(), num.end());
        vector<int>::iterator item;
        int Max = 0, length = 0;
        for(item = num.begin(); item!=num.end(); item++){
            if(s.find(*item) !=s.end()){
                s.erase(*item);
                length++;
                int left = (*item)-1;
                int right = (*item)+1;
                while(s.find(left) != s.end()){
                    s.erase(left);
                    length++;
                    left--;
                }
                while(s.find(right) != s.end()){
                    s.erase(right);
                    length++;
                    right++;
                }
                Max = max(Max, length);
                length = 0;
            }
        }
        return Max;
    }
};


