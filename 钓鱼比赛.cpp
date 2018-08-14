/*
 * 钓鱼比赛.cpp
 *
 *  Created on: 2018年8月14日
 *      Author: garvin
 */


/*ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，
cc一直在坐标(x,y)的格子钓鱼，而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的概率大？为多少？

输入描述:
第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1)

输出描述:
输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)*/

/*
 * 主要是概率问题吧
 * 钓t分钟，至少钓一次的概率为1-一次都没钓到的概率
 * 最后输出的时候控制格式即可
 */

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n, m, x, y, t;
    while(cin>>n>>m>>x>>y>>t){;
        float P1=0, P2=0;
        for(int i=0; i<n*m; i++){
            float p;
            cin>>p;
            if(i==(x-1)*m+y-1)
                P1 = p;
            P2 += p;
        }
        P2 /= (n*m);
        P2 = 1-P2;
        P1 = 1-P1;
        if(P1>P2)
            cout<<"ss"<<endl;
        else if(P1<P2)
            cout<<"cc"<<endl;
        else
            cout<<"equal"<<endl;
        float P = min(P1, P2);
        float ans = 1.0;
        for(int i=0; i<t; i++)
            ans *= P;
        ans = 1-ans;
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
