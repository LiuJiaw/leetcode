/*
 * 174.地下城游戏.cpp
 *
 *  Created on: 2018年9月28日
 *      Author: garvin
 */

/*
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。



编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
-2 (K) 	-3 	3
-5 	-10 	1
10 	30 	-5 (P)



说明:

    骑士的健康点数没有上限。
    任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int sizeh = dungeon.size();
        if(sizeh <= 0)
            return 0;
        int sizel = dungeon[0].size();
        if(sizel <= 0)
            return 0;
        vector<int> tmp(sizel, INT_MIN);
        vector<vector<int>> record(sizeh, tmp);
        vector<vector<int>> record1(sizel, tmp);
        record[0][0] = dungeon[0][0];
        record1[0][0] = dungeon[0][0];
        for(int i=1; i<sizel; i++){
            record[0][i] = record[0][i-1] + dungeon[0][i];
            record1[0][i] = dungeon[0][i]<0 ? min(record[0][i], record1[0][i-1])
                : record1[0][i-1];
        }
        for(int j=1; j<sizeh; j++){
            record[j][0] = record[j-1][0] + dungeon[j][0];
            record1[j][0] = dungeon[j][0]<0 ? min(record[j][0], record1[j-1][0])
                : record1[j-1][0];
        }
        for(int i=1; i<sizeh; i++){
            for(int j=1; j<sizel; j++){
                record[i][j] = max(record[i][j-1], record[i-1][j]) + dungeon[i][j];
                record1[i][j] = dungeon[i][j]<0 ? min(max(record1[i-1][j], record1[i][j-1]), record[i][j]) : max(record1[i-1][j], record1[i][j-1]);
            }
        }
        return -1*record1[sizeh-1][sizel-1] + 1;
    }
};

