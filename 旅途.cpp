/*
 * 旅途.cpp
 *
 *  Created on: 2018年8月15日
 *      Author: garvin
 */


/*原来是要到醋溜站台乘坐醋溜快车到醋溜港”，亮亮解出了地图隐藏的秘密，赶紧奔向醋溜站台，
但到了之后，亮亮忧桑地发现，从醋溜站台到醋溜港沿途的每个车站都有很多美女被他飒爽的英姿所吸引，
只要经过车站就会被这些漂亮的女孩搭讪，但是现在亮亮一心想要寻找楚楚街而没空去搭理她们，
所以亮亮希望在抵达醋溜港的时候被搭讪的次数最少。问亮亮抵达醋溜港最少会被搭讪多少次？

输入描述:
第一行包含两个整数N(2<=N<=5000),M(1<=M<=50000)。
N表示公有N个汽车站，M表示公有M条公路，起点为1，终点为N。
第二行包含N个整数(0<=K<=10000)，第i个整数表示在第i站有K个美女想要搭讪亮亮。
接下来M行，每行包含两个整数P(1<=P<=N),Q(1<=Q<=N),代表P,Q两个站是有班车直达的。

输出描述:
一个整数，即亮亮抵达醋溜港最少需要被搭讪的次数。*/


/*
 * 一开始用动态规划写的
 * 发现可能会有回头的车
 * 也就是说无法确定已走过的车站是否花费最少
 * 第一次写迪杰斯特拉算法，不是很熟
 * 不过也算有经验了...
 */


#include<iostream>
#include<limits.h>
#include<vector>
#include<set>

using namespace std;

int main(){
    int N, M;
    while(cin>>N>>M){
        vector<int> cost;
        cost.resize(N+1);
        for(int i=1; i<=N; i++)
            cin>>cost[i];
        vector<vector<int> > map;
        map.resize(N+1);
        for(int i=0; i<M; i++){
            int P, Q;
            cin>>P>>Q;
            map[P].push_back(Q);
            map[Q].push_back(P);
        }
        set<int> visited;
        visited.insert(1);
        vector<int> record;
        record.resize(N+1);
        record[1] = cost[1];
        for(int i=2; i<=N; i++)
            record[i] = INT_MAX;
        for(int i=0; i<map[1].size(); i++){
            record[map[1][i]] = record[1] + cost[map[1][i]];
        }
        while(visited.count(N) == 0){
            int tmp = INT_MAX;
            int Index = -1;
            for(int i=1; i<=N; i++){
                if(visited.count(i)==0){
                    if(record[i] < tmp){
                        tmp = record[i];
                        Index = i;
                    }
                }
            }
            visited.insert(Index);
            for(int i=0; i<map[Index].size(); i++){
                record[map[Index][i]] = min(record[map[Index][i]], record[Index]+cost[map[Index][i]]);
            }
        }
        cout<<record[N]<<endl;
    }
    return 0;
}
