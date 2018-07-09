/*
 * zigzag-conversion.cpp
 *
 *  Created on: 2018年7月9日
 *      Author: garvin
 */

 /*The string"PAYPALISHIRING"is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line:"PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3)should return"PAHNAPLSIIGYIR".*/


class Solution {
public:
    string convert(string s, int nRows) {
        if(s == "" || nRows <= 1)
            return s;
        vector<vector<char>> record;
        record.resize(nRows);
        int size = s.size();
        bool fangxiang = true;
        int index = 0;
        for(int i=0; i<size; i++){
            record[index].push_back(s[i]);
            if(fangxiang == true){
                index++;
                if(index == nRows-1)
                    fangxiang = false;
            }
            else{
                index--;
                if(index == 0)
                    fangxiang = true;
            }
        }
        string ans = "";
        for(int i= 0; i<nRows; i++){
            int row_size = record[i].size();
            for(int j = 0; j<row_size; j++){
                ans += record[i][j];
            }
        }
        return ans;
    }
};

