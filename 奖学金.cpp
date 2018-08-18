/*
 * 奖学金.cpp
 *
 *  Created on: 2018年8月18日
 *      Author: garvin
 */

/*小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。
每门课由平时成绩和考试成绩组成，满分为r。
现在他知道每门课的平时成绩为ai ,若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。
同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。

输入描述:
第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，
接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1

输出描述:
一行输出答案。*/

#include<iostream>
#include<queue>

using namespace std;

struct record{
    record(int a_, int b_){
        a = a_;
        b = b_;
    }
    int a;
    int b;
    friend bool operator<(record r1, record r2){
        if(r1.b>r2.b)
            return true;
        return false;
    }
};

int main(){
    long long int n, r, avg;
    while(cin>>n>>r>>avg){
        long long int left = n*avg;
        priority_queue<record> pq;
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            pq.push(record(a, b));
            left -= a;
        }
        long long int result = 0;
        while(left>0){
            record rc = pq.top();
            pq.pop();
            if(left > r-rc.a){
                left -= (r-rc.a);
                result += ((r-rc.a)*rc.b);
            }
            else{
                result += (left*rc.b);
                left = 0;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
