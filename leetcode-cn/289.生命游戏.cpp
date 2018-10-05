/*
 * 289.生命游戏.cpp
 *
 *  Created on: 2018年10月5日
 *      Author: garvin
 */

/*
根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

    如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
    如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
    如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
    如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

示例:

输入:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
*/

class Solution {
public:
    int check(vector<vector<int>>& board, int i, int j){
        int sizeh = board.size();
        int sizel = board[0].size();
        if(i<0||i>=sizeh || j<0||j>=sizel)
            return 0;
        if(board[i][j] == 1 || board[i][j] == 3)
            return 1;
        return 0;
    }
    void change(vector<vector<int>>& board, int i, int j){
        int num = 0;
        num += check(board, i-1, j-1);
        num += check(board, i, j-1);
        num += check(board, i+1, j-1);
        num += check(board, i-1, j);
        num += check(board, i+1, j);
        num += check(board, i-1, j+1);
        num += check(board, i, j+1);
        num += check(board, i+1, j+1);
        if(board[i][j] == 0 && (num<2||num>3))
            board[i][j] = 0;
        else if(board[i][j] == 1 && (num<2||num>3))
            board[i][j] = 3;
        else if(board[i][j] == 1 && (num==2||num==3))
            board[i][j] = 1;
        else if(board[i][j] == 0 && (num == 3))
            board[i][j] = 2;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int sizeh = board.size();
        if(sizeh <= 0 )
            return ;
        int sizel = board[0].size();
        if(sizel <= 0)
            return ;
        for(int i=0; i<sizeh; i++){
            for(int j=0; j<sizel; j++){
                change(board, i, j);
            }
        }
        for(int i=0; i<sizeh; i++){
            for(int j=0; j<sizel; j++){
                if(board[i][j] == 0 || board[i][j] == 3)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        }
    }
};
