/*
 * 路灯.cpp
 *
 *  Created on: 2018年8月15日
 *      Author: garvin
 */

/*一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai ，
每盏灯可以覆盖到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，
但是为了省电，要使这个d最小，请找到这个最小的d。

输入描述:
每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。
第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。

输出描述:
输出答案，保留两位小数。*/

/*
 * 插入到set中
 * 对set进行遍历（迭代器自增，相当于中序遍历底层容器rbtree）
 * 记录路灯之间最大距离
 * 还要记录两侧距离最近的路灯距离
 */

#include<iostream>
#include<set>

using namespace std;

int main(){
    int n, l;
    while(cin>>n>>l){
        set<int> s;
        int a;
        for(int i=0; i<n; i++){
            cin>>a;
            s.insert(a);
        }
        float Max = *(s.begin())-0;
        int recordlast = *(s.begin());
        for(set<int>::iterator item = s.begin(); item!=s.end(); item++){
            if(item == s.begin())
                continue;
            Max = Max > *item-recordlast ? Max : *item-recordlast;
            recordlast = *item;
        }
        Max = Max/2 > l-recordlast ? Max/2 : l-recordlast;
        printf("%.2f\n", (float)Max);
    }
    return 0;
}
