/*
 * 保留最大的数.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: garvin
 */

/*给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。

输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。
第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。

输出描述:
输出保留下来的结果。

示例1
输入
325 1
输出
35*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    string number;
    int cnt;
    cin>>number>>cnt;
    for(int i=0; i<number.size()-1 && cnt!=0; i++){
        if(number[i]<number[i+1]){
            number.erase(number.begin()+i);
            cnt--;
            i--;
        }
        if(i!=-1 && number[i]<number[i+1])
            i--;
    }
    while(cnt--)
        number.erase(number.end()-1);
    cout<<number<<endl;
    return 0;
}
