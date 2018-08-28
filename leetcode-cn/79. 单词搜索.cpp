/*
 * 79. 单词搜索.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

class Solution {
public:
    bool check(vector<vector<char> >& board, vector<vector<bool> >& isused, string& word, int indexh, int indexl, int indexs){
        if(indexs == word.size())
            return true;
        int sizeh = board.size();
        int sizel = board[0].size();
        if(indexh<0 || indexh>=sizeh || indexl<0 || indexl >=sizel || board[indexh][indexl] != word[indexs] || isused[indexh][indexl] == true)
            return false;
        isused[indexh][indexl] = true;
        bool result = check(board, isused, word, indexh-1, indexl, indexs+1) ||
            check(board, isused, word, indexh+1, indexl, indexs+1) ||
            check(board, isused, word, indexh, indexl+1, indexs+1) ||
            check(board, isused, word, indexh, indexl-1, indexs+1);
        isused[indexh][indexl] = false;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()<=0)
            return true;
        int sizeh = board.size();
        if(sizeh <= 0)
            return false;
        int sizel = board[0].size();
        if(sizel <= 0)
            return false;
        bool result = false;
        vector<bool> tmp(sizel, false);
        vector<vector<bool> > isused(sizeh, tmp);
        for(int i=0; i<sizeh && !result; i++){
            for(int j=0; j<sizel && !result; j++){
                if(board[i][j] == word[0])
                    result = check(board, isused, word, i, j, 0);
            }
        }
        return result;
    }
};


