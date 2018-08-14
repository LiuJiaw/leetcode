/*
 * 蘑菇阵.cpp
 *
 *  Created on: 2018年8月14日
 *      Author: garvin
 */

/*现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，
A在(1,1),B在(n,m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，
在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),
问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？

输入描述:
第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。

输出描述:
输出一行，代表所求概率(保留到2位小数)*/

/*
 * 这道题一开始WA了很多次
 * 后来参考讨论区发现，概率并不能用通路除以总路线数
 * 因为每条路线概率并不相等
 * 所以我们可以用一个二维数组来记录每一格到达的概率
 * 其中，毒蘑菇地区看做不可达点
 */

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    bool **map = new bool*[25];
    float **route = new float*[25];
    for(int i=0; i<25; i++){
        map[i] = new bool[25];
        route[i] = new float[25];
    }
    int N, M, K;
    while(cin>>N>>M>>K){
        for(int i=0; i<25; i++){
            for(int j=0; j<25; j++){
                map[i][j] = false;
                route[i][j] = 0.0;
            }
        }
        int x, y;
        while(K--){
            cin>>x>>y;
            map[x][y] = true;
        }
        route[1][1] = map[1][1] ? 0 : 1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(map[i][j] == true)
                    route[i][j] = 0;
                else{
                    if(i == 1 && j == 1)
                        continue;
                    if(i == 1){
                        if(N > 1)
                            route[i][j] += route[i][j-1]/2;
                        else
                            route[i][j] += route[i][j-1];
                        continue;
                    }
                    if(j == 1){
                        if(M > 1)
                            route[i][j] += route[i-1][j]/2;
                        else
                            route[i][j] += route[i-1][j];
                        continue;
                    }
                    if(i == N)
                        route[i][j] += route[i][j-1];
                    else
                        route[i][j] += route[i][j-1]/2;
                    if(j == M)
                        route[i][j] += route[i-1][j];
                    else
                        route[i][j] += route[i-1][j]/2;
                }
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<route[N][M]<<endl;
    }
    delete[] map;
    delete[] route;
    return 0;
}
