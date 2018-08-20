/*
 * 迷雾.cpp
 *
 *  Created on: 2018年8月20日
 *      Author: garvin
 */

/*亮亮深吸一口气，打开了地图，地图上写着(X:12,Y:?)，这可让亮亮犯了愁，这个问号代表了什么意思呢？
亮亮绞尽脑汁也想不出什么思路，忽然他在地图背面发现了一串数字，数字下面写着一段话“这只是一个1~n的混乱排列，
不用在意第i个值”，亮亮眼前一亮，“这个混乱排列中第i个一定是Y的值！”于是，亮亮开始恢复这个混乱排列。

输入描述:
每组数据第一行一个整数n(0<n≤25)，第二行即现在纸上的数字串

输出描述:
一行n个空格隔开的整数，为小明写下的排列。*/

/*
 * 其实就是解析字符串，将之变为1-n的序列
 * 注意不一定是按顺序的
 * 今天做了很多牛客上ac率很低的题
 * 发现题目各种歧义、各种难懂
 * 真是做到想砸键盘
 */

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

bool getresult(const int n, int index, const string& s, vector<int>& result){
    if(n == result.size() && index == s.size())
        return true;
    if(result.size()>=n || index >= s.size())
        return false;

    if(find(result.begin(), result.end(), s[index]-'0')==result.end()){
        result.push_back(s[index]-'0');
        if(getresult(n, index+1, s, result))
            return true;
        result.erase(result.end()-1);
    }

    if( (s[index]=='0'||s[index]=='1')
          && find(result.begin(), result.end(), 10*(s[index]-'0')+s[index+1]-'0')==result.end()){
        result.push_back( 10*(s[index]-'0')+s[index+1]-'0' );
        if(getresult(n, index+2, s, result))
            return true;
        result.erase(result.end()-1);
    }

    return false;
}

int main(){
    int n;
    string s;
    while(cin>>n>>s){
        vector<int> result;
        getresult(n, 0, s, result);
        for(int i=0; i<n; i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
