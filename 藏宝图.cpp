/*
 * 藏宝图.cpp
 *
 *  Created on: 2018年8月3日
 *      Author: garvin
 */

/* 牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，
 藏宝盒上有一个机关，机关每次会显示两个字符串 s 和 t，
 根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。注意，子序列不要求在原字符串中是连续的，
 例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。 */

#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;


int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int size1 = s1.size();
    int size2 = s2.size();
    int Index = 0;
    for(int i=0; i<size1; i++){
        if(s1[i] == s2[Index])
            Index++;
        if(Index == size2)
            break;
    }
    if(Index == size2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


