/*
 * 电话号码分身.cpp
 *
 *  Created on: 2018年8月18日
 *      Author: garvin
 */

/*继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：
首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替
（"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），
然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。

输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。

输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int num[10] = {0};
        int a[26] = {0};
        string s;
        cin>>s;
        int Size = s.size();
        for(int i=0; i<Size; i++){
            a[s[i]-'A']++;
        }
        num[0] = a[25];
        num[6] = a[23];
        num[7] = a[18]-num[6];
        num[5] = a[21]-num[7];
        num[4] = a[5]-num[5];
        num[8] = a[6];
        num[9] = a[8]-num[5]-num[6]-num[8];
        num[3] = a[17]-num[0]-num[4];
        num[2] = a[19]-num[3]-num[8];
        num[1] = a[14]-num[0]-num[2]-num[4];

        vector<int> record;
        for(int i=8; i<=9; i++){
            for(int j=0; j<num[i]; j++)
                record.push_back(i-8);
        }
        for(int i=0; i<=7; i++){
            for(int j=0; j<num[i]; j++)
                record.push_back(i+2);
        }
        string result = "";
        for(int i=0; i<record.size(); i++){
            result += ('0'+record[i]);
        }
        if(result == "")
            result = "0";
        cout<<result<<endl;
    }
    return 0;
}
