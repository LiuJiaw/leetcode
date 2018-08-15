/*
 * 平均年龄.cpp
 *
 *  Created on: 2018年8月15日
 *      Author: garvin
 */

/*已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，
假设每年离职率为x，x>0&&x<1,每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。
从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。

输入描述:
输入W Y x N

输出描述:
输出第N年后的平均年龄*/

/*
 * 还是要注意一下精度问题
 * float或double与整形的equal判断
 */

#include<iostream>

using namespace std;

int main(){
    int W, N;
    float Y, x;
    float ans;
    while(cin>>W>>Y>>x>>N){
        ans = Y;
        for(int i=0; i<N; i++){
            ans += 1;
            ans = ans*(1-x) + 21*x;
        }
        int result;
        if(ans - int(ans) >= 0.001)
            result = (int)ans +1;
        else
            result = (int)ans;
        cout<<result<<endl;
    }

    return 0;
}
