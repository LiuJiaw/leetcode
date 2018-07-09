/*
 * two-sum.cpp
 *
 *  Created on: 2018年7月9日
 *      Author: garvin
 */

/* Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/

/*
 * 利用map，实值是其序号下标，键值是target-numbers[i]
 * 每次拿到一个数，先在map中查找
 * 若找到则得到答案，没有的话则将其放入到map中
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if(numbers.size()<=1)
            return ans;
        map<int, int> record;
        int size = numbers.size();
        for(int i=0; i<size; i++){
            if(record.find(numbers[i]) == record.end()){
                record[target-numbers[i]] = i+1;
            }
            else{
                ans.push_back( record[numbers[i]] );
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};


