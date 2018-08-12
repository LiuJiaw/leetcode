/*
 * 最大的奇约数.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: garvin
 */

/*小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。
一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。

输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)

输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)*/

#include<iostream>

using namespace std;

/*
//本方法超时，只能AC 60%
//最终方法参考评论区，只能说，数字真奇妙
int get(int num){
    while(true){
        num = num>>1;
        if(num&1)
            break;
    }
    return num;
}

int main(){
    int N;
    cin>>N;
    long long int ans = 0;
    ans += ( ((N+1)/2) * ((N+1)/2) );
    for(int i=1; i<=N/2; i++){
        ans+=get(2*i);
    }
    cout<<ans<<endl;
    return 0;
}
*/

int main(){
    long long int N;
    cin>>N;
    long long int ans = 0;
    while(N){
        ans += ( ((N+1)/2) * ((N+1)/2) );
        N /= 2;
    }
    cout<<ans<<endl;
}
