/*
 * distinct-subsequences.cpp
 *
 *  Created on: 2018年7月20日
 *      Author: garvin
 */

/*Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).
Here is an example:
S ="rabbbit", T ="rabbit"
Return3. */



class Solution {
public:
    int numDistinct(string S, string T) {
        int sizes = S.length();
        int sizet = T.length();
        int **record = new int*[sizet];
        for(int i=0; i<sizet; i++){
            record[i] = new int[sizes];
        }
        record[0][0] = (S[0]==T[0] ? 1 : 0);
        for(int i=1; i<sizes; i++){
            if(S[i]==T[0])
                record[0][i] = record[0][i-1] +1;
            else
                record[0][i] = record[0][i-1];
        };
        for(int i=1; i<sizet; i++)    record[i][0] = 0;

        for(int i=1; i<sizet; i++){
            for(int j=1; j<sizes; j++){
                if(T[i]==S[j])
                    record[i][j] = record[i][j-1]+record[i-1][j-1];
                else
                    record[i][j] = record[i][j-1];
            }
        }

        return record[sizet-1][sizes-1];
    }
};
