/*
 * 130. 被围绕的区域.cpp
 *
 *  Created on: 2018年9月14日
 *      Author: garvin
 */

/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X

运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/

class Solution {
public:
    void fillch(vector<vector<char>>& board, char ch, int x, int y){
        int sizeh = board.size();
        int sizel = board[0].size();
        if(x<0 || x>=sizeh || y<0 || y>= sizel || board[x][y] == 'X' || board[x][y] == ch)
            return;
        board[x][y] = ch;
        fillch(board, ch, x+1, y);
        fillch(board, ch, x, y+1);
        fillch(board, ch, x-1, y);
        fillch(board, ch, x, y-1);
    }
    void solve(vector<vector<char>>& board) {
        int sizeh = board.size();
        if(sizeh == 0)
            return;
        int sizel = board[0].size();
        if(sizel == 0)
            return;
        for(int i=0; i<sizel; i++){
            if(board[0][i] == 'O')
                fillch(board, 'a', 0, i);
            if(board[sizeh-1][i] == 'O')
                fillch(board, 'a', sizeh-1, i);
        }
        for(int i=0; i<sizeh; i++){
            if(board[i][0] == 'O')
                fillch(board, 'a', i, 0);
            if(board[i][sizel-1] == 'O')
                fillch(board, 'a', i, sizel-1);
        }
        for(int i=0; i<sizeh; i++){
            for(int j=0; j<sizel; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'a')
                    board[i][j] = 'O';
            }
        }
    }
};

