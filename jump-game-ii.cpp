/*
 * jump-game-ii.cpp
 *
 *  Created on: 2018年7月19日
 *      Author: garvin
 */


/* Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A =[2,3,1,1,4]
The minimum number of jumps to reach the last index is2. (Jump1step from index 0 to 1, then3steps to the last index.) */

class Solution {
public:
    int jump(int A[], int n) {
        if(n<=0)
            return 0;
        int *record = new int[n];
        for(int i=0; i<n; i++) record[i] = 0;
        for(int i=0; i<n; i++){
            for(int j=1; i+j<n && j<=A[i]; j++){
                if(record[i+j]==0)
                    record[i+j] = record[i]+1;
                else
                    record[i+j] = min(record[i+j], record[i]+1);
            }
        }
        return record[n-1];
    }
};
