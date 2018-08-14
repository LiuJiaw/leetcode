/*
 * 扫描透镜.cpp
 *
 *  Created on: 2018年8月14日
 *      Author: garvin
 */

/*在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,而且蘑菇是隐形的.只 有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,于是他回了一趟战争学院,买了2个扫描透镜,一个 扫描透镜可以扫描出(3*3)方格中所有的蘑菇,然后兰博就可以清理掉一些隐形的蘑菇. 问:兰博最多可以清理多少个蘑菇?
注意：每个方格被扫描一次只能清除掉一个蘑菇。

输入描述:
第一行三个整数:N,M,K,(1≤N,M≤20,K≤100),N,M代表了草地的大小;
接下来K行,每行两个整数x,y(1≤x≤N,1≤y≤M).代表(x,y)处提莫种了一个蘑菇.
一个方格可以种无穷个蘑菇.

输出描述:
输出一行,在这一行输出一个整数,代表兰博最多可以清理多少个蘑菇.*/

/*
 * 用了最简单粗暴的方法...
 * 依次假设两个点，然后求蘑菇个数
 */

#include<iostream>

using namespace std;

int getans(int **record, int N, int M, int x1, int y1, int x2, int y2){
    int ans = 0;
    for(int i=x1-1; i<=x1+1; i++){
        for(int j=y1-1; j<=y1+1; j++){
            if(i<=0 || i>N || j<=0 || j>M)
                continue;
            if(record[i][j] > 0)
                ans++;
        }
    }
    for(int i=x2-1; i<=x2+1; i++){
        for(int j=y2-1; j<=y2+1; j++){
            if(i<=0 || i>N || j<=0 || j>M)
                continue;
            if( record[i][j]>1 || record[i][j]>0&&(abs(i-x1)>=2||abs(j-y1)>=2) )
                ans++;
        }
    }
    return ans;
}

int main(){
    int N, M, K;
    int **record = new int*[25];
    for(int i=0; i<25; i++)
        record[i] = new int[25];
    while(cin>>N>>M>>K){
        for(int i=0; i<25; i++)
            for(int j=0; j<25; j++)
                record[i][j] = 0;
        for(int i=0; i<K; i++){
            int x, y;
            cin>>x>>y;
            record[x][y]++;
        }
        int ans = 0;
        for(int a=1; a<=N; a++)
            for(int b=1; b<=M; b++)
                for(int c=1; c<=N; c++)
                    for(int d=1; d<=M; d++){
                        ans = max(ans, getans(record, N, M, a, b, c, d));
                    }
        cout<<ans<<endl;
    }
    return 0;
}
