/*
 * 地牢逃脱.cpp
 *
 *  Created on: 2018年8月10日
 *      Author: garvin
 */


/*
给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，
牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，
要求每一步都不可以超过地牢的边界，也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。
牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。

输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。
接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。
接下来的一行，包含两个整数 x0, y0，表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。
之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，
接下来的 k 行，每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）

输出描述:
输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。
以下测试用例中，牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
*/


/*
 * 一开始使用递归，超时
 * 后来参考评论区改用栈，ac
 */

#include<iostream>
#include<queue>

using namespace std;

/*void func(int x, int y, char **map, int **record, const int& n, const int& m,
          int times, int& leftnum, int **action, const int& k){
    if(x<0 || x>=n || y<0 || y>=m || map[x][y] == 'X')
        return;
    //cout<<"x="<<x<<"y="<<y<<"leftnum="<<leftnum<<endl;
    if(record[x][y] == -1){
        record[x][y] = times;
        leftnum--;
    }
    else{
        if(times < record[x][y])
            record[x][y] = times;
        else
            return;
    }
    for(int i=0; i<k; i++){
        func(x+action[i][0], y+action[i][1], map, record, n, m, times+1,
            leftnum, action, k);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    //cout<<"n="<<n<<"m="<<m<<endl;
    char **map = new char*[n];
    int **record = new int*[n];
    int leftnum = 0;
    for(int i=0; i<n; i++)
        map[i] = new char[m], record[i] = new int[m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] != 'X')
                leftnum++;
            record[i][j] = -1;
        }
    }
    //cout<<leftnum<<endl;
    int x0, y0;
    cin>>x0>>y0;
    //cout<<"x0="<<x0<<"y0="<<y0<<endl;
    int k;
    cin>>k;
    //cout<<"k="<<k<<endl;
    int **action = new int*[k];
    for(int i=0; i<k; i++)
        action[i] = new int[2];
    for(int i=0; i<k; i++)
        cin>>action[i][0]>>action[i][1];

    int times = 0;
    func(x0, y0, map, record, n, m, times, leftnum, action, k);
    if(leftnum > 0)
        cout<<-1<<endl;
    else{
        int Max = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(record[i][j] > Max)
                    Max = record[i][j];
            }
        cout<<Max<<endl;
    }
    return 0;
}*/

struct point{
    point(int x_, int y_){
        x = x_;
        y = y_;
    }
    int x;
    int y;
};

int main(){
    int n, m;
        cin>>n>>m;
        char **map = new char*[n];
        bool **record = new bool*[n];
        int leftnum = 0;
        for(int i=0; i<n; i++)
            map[i] = new char[m], record[i] = new bool[m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>map[i][j];
                if(map[i][j] != 'X')
                    leftnum++;
                record[i][j] = false;
            }
        }
        int x0, y0;
        cin>>x0>>y0;
        int k;
        cin>>k;
        int **action = new int*[k];
        for(int i=0; i<k; i++)
            action[i] = new int[2];
        for(int i=0; i<k; i++)
            cin>>action[i][0]>>action[i][1];

        queue<point> q;
        q.push(point(x0, y0));
        leftnum--;
        record[x0][y0] = true;
        int ans = 0;
        while(!q.empty() && leftnum){
            int size = q.size();
            while(size--){
            point pt = q.front();
            q.pop();
            for(int i=0; i<k; i++){
                int x_ = pt.x+action[i][0];
                int y_ = pt.y+action[i][1];
                if(x_>=0 && x_<n && y_>=0 && y_<m && map[x_][y_]!='X' && record[x_][y_]==false)
                    q.push(point(x_,y_)), leftnum--, record[x_][y_] = true;
            }
            }
            ans++;
        }
        if(leftnum > 0)
            cout<<"-1"<<endl;
        else
        cout<<ans<<endl;
}
