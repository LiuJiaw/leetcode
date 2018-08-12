/*
 * 优雅的点.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: garvin
 */

/*
 小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。
 小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。

输入描述:
输入为一个整数，即为圆半径的平方,范围在32位int范围内。

输出描述:
输出为一个整数，即为优雅的点的个数
*/

#include<iostream>

using namespace std;

int getanotherr(int rfang, int rhigh, int i){
    int high = rhigh, low = i;
    int middle;
    while(low<=high){
        int middle = (high-low)/2 + low;
        if(i*i + middle*middle == rfang)
            return middle;
        else if(i*i + middle*middle <rfang && i*i+(middle+1)*(middle+1)>=rfang )
            return middle+1;
        else if(i*i + middle*middle <rfang && i*i+(middle+1)*(middle+1)<rfang)
            low = middle+1;
        else
            high = middle-1;
    }
    return -1;
}

int main(){
    int rfang;
    cin>>rfang;
    int ans=0;
    int rhigh=0;

    for(rhigh=0; rhigh*rhigh<rfang; rhigh++);

    for(int i=0; i*i<(rfang/2+1); i++){
        int r2 = getanotherr(rfang, rhigh, i);
        if(r2*r2 + i*i == rfang){
            if(i==0 || r2==i)
                ans+=4;
            else
                ans+=8;
        }
    }
    cout<<ans<<endl;
    return 0;
}

