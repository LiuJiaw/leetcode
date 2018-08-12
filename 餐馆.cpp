/*
 * 餐馆.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: garvin
 */

/* 某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数；
 有m批客人，每批客人有两个参数:b人数，c预计消费金额。
 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大

 输入描述:
输入包括m+2行。 第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000)
第二行为n个参数a,即每个桌子可容纳的最大人数,以空格分隔,范围均在32位int范围内。
接下来m行，每行两个参数b,c。分别表示第i批客人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。

输出描述:
输出一个整数,表示最大的总预计消费金额*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct info{
    info(int b_, int c_){
        b = b_;
        c = c_;
    }
    int b;
    int c;
    friend bool operator<(struct info r, struct info s){
        if(r.c<s.c)    return true;
        else if(r.c==s.c){
            float tmp1 = (float)r.c/r.b;
            float tmp2 = (float)s.c/s.b;
            if(tmp1<tmp2)    return true;
        }
        return false;
    }
};

bool gettable(int num, vector<int>& vec){
    int size = vec.size();
    if(num>vec.back() )
        return false;
    if(num<=vec.front()){
        vec.erase(vec.begin());
        return true;
    }
    int low = 0, high = size-1;
    int middle;
    while(low<=high){
        middle = (low+high)/2;
        if(vec[middle] == num){
            vec.erase(vec.begin()+middle);
            return true;
        }
        else if(vec[middle]<num && vec[middle+1]>=num){
            vec.erase(vec.begin()+middle+1);
            return true;
        }
        else if(vec[middle]<num && vec[middle+1]<num)
            low = middle+1;
        else
            high = middle-1;
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vec;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    int b, c;
    priority_queue<info> pq;
    for(int i=0; i<m; i++){
        cin>>b>>c;
        pq.push(info(b, c));
    }
    long long int ans = 0;
    while( !vec.empty() && !pq.empty() ){
        info tmp = pq.top();
        pq.pop();
        if(gettable(tmp.b, vec)){
            ans+=tmp.c;
        }
    }
    cout<<ans<<endl;
    return 0;
}
