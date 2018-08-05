/*
 * 不要二.cpp
 *
 *  Created on: 2018年8月5日
 *      Author: garvin
 */

/*二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。 */

#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    int W, H;
    cin>>W>>H;
    int ans = 0;
    if(W%4==0 || H%4==0)
        ans = (W*H)/2;
    else if(W%2==0 && H%2==0)
        ans = ((W*H)/4+1)/2*4;
    else{
        ans = (W*H+2)/2;
    }
    cout<<ans<<endl;
    return 0;
}
