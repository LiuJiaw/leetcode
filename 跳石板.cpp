/*
 * 跳石板.cpp
 *
 *  Created on: 2018年8月10日
 *      Author: garvin
 */

/*小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1*/

/*
 * 一开始70%AC，卡在时间复杂度上
 * 后来改变判断条件，比如求10000的公约数
 * 循环至100即可，之前循环到5000，并没有必要
 * 这是因为在检查2是否为10000公约数时，顺带检查5000即可
 */

#include<iostream>
#include<limits.h>

using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int *record = new int[M+1];
    for(int i=0; i<=M; i++)
        record[i] = INT_MAX;
    record[N] = 0;
    for(int i=N; i<M-1; i++){
        if(record[i] == INT_MAX)
            continue;
        for(int j=2; j*j<=i; j++){
            if(i+j > M)
                break;
            if(i%j == 0){
                record[i+j] = min(record[i]+1, record[i+j]);
                if(i+i/j<=M)
                    record[i+i/j] = min(record[i]+1, record[i+i/j]);
            }
        }
    }
    if(record[M] == INT_MAX)
        cout<<"-1"<<endl;
    else
        cout<<record[M]<<endl;
    return 0;
}
