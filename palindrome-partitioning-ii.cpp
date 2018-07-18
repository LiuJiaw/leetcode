/*
 * palindrome-partitioning-ii.cpp
 *
 *  Created on: 2018年7月18日
 *      Author: garvin
 */

/* Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s ="aab",
Return1since the palindrome partitioning["aa","b"]could be produced using 1 cut. */



class Solution {
public:
    int minCut(string s) {
        if(s == "")  return 0;
        int size = s.size();
        bool **record = new bool*[size];
        int **ans = new int*[size];
        for(int i=0; i<size; i++)
            record[i] = new bool[size], ans[i] = new int[size];

        for(int i= size-1; i>=0; i--)
            for(int j = size-1; j>=i; j--)
                record[i][j] = s[i]==s[j] && (j-i<2||record[i+1][j-1]);

        for(int i= size-1; i>=0; i--){
            for(int j = i; j<size; j++){
                if(record[i][j]){
                    ans[i][j] = 0;
                    continue;
                }
                ans[i][j] = INT_MAX;

                for(int k=i; k<j; k++){
                    if(record[i][k]&&record[k+1][j]){
                        ans[i][j] = min(ans[i][j], ans[i][k]+ans[k+1][j]+1);
                        record[i][j] = true;
                    }
                }
            }
        }
        return ans[0][size-1];
    }
};
