/*
 * 马戏团.cpp
 *
 *  Created on: 2018年8月20日
 *      Author: garvin
 */

/*搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，
精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。
考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。
小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。
现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。

输入描述:
首先一个正整数N，表示人员个数。
之后N行，每行三个数，分别对应马戏团员编号，体重和身高。

输出描述:
正整数m，表示罗汉塔的高度。*/

/*
 * 这道题，哎
 * 题目中说，站在自己肩膀上的人，应该比自己瘦且比自己矮，或相等...
 * 实际上，1，既比自己瘦又比自己矮  2，体重身高完全相等   3，身高相等，体重更轻
 * 以上三类人都可以站在自己肩膀上
 * 出题人语文绝了...
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct record{
    int weight;
    int height;
    record(int h, int w){
        height = h;
        weight = w;
    }
    friend bool operator<(record r1, record r2){
        if(r1.height < r2.height || (r1.height==r2.height && r1.weight<=r2.weight) )
            return true;
        return false;
    }
};

int main(){
    int N;
    while(cin>>N){
        vector<record> vec;
        for(int i=0; i<N; i++){
            int index, w, h;
            cin>>index>>w>>h;
            vec.push_back(record(h, w));
        }
        sort(vec.begin(), vec.end());
        vector<int> rec(N, 0);
        for(int i=0; i<N; i++){
            if(rec[i] == 0){
                rec[i] = 1;
            }
            for(int j=i+1; j<N; j++){
                if( (vec[j].height>vec[i].height && vec[j].weight>vec[i].weight) ||
                  (vec[j].height==vec[i].height && vec[j].weight>=vec[i].weight) )
                    rec[j] = max(rec[j], rec[i]+1);
            }
        }
        int result = 0;
        for(int i=0; i<N; i++){
            result = max(result, rec[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}
