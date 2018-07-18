/*
 * interleaving-string.cpp
 *
 *  Created on: 2018年7月16日
 *      Author: garvin
 */


/* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example,
Given:
s1 ="aabcc",
s2 ="dbbca",
When s3 ="aadbbcbcac", return true.
When s3 ="aadbbbaccc", return false. */

/*
 * 起初使用递归，提示超时
 * 然后借鉴了以下评论区，使用动态规划
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if(size1 + size2 != size3)
            return false;
        bool **record = new bool*[size2+1];
        for(int i=0; i<=size2;i++)
            record[i] = new bool[size1+1];

        record[0][0] = true;

        for(int i=1; i<=size1; i++){
            record[0][i] = record[0][i-1] && (s1[i-1]==s3[i-1]);
        }
        for(int i=1; i<=size2; i++){
            record[i][0] = record[i-1][0] && s2[i-1]==s3[i-1];
        }
        for(int i=1; i<=size2; i++){
            for(int j=1; j<=size1; j++){
                record[i][j] = (record[i-1][j]&&s2[i-1]==s3[i+j-1]) || (record[i][j-1]&&s1[j-1]==s3[i+j-1]);
            }
        }

        bool ans = record[size2][size1];
        delete record;
        return ans;
    }
};
