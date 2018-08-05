/*
 * 两种排序方法.cpp
 *
 *  Created on: 2018年8月5日
 *      Author: garvin
 */

/*考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成

输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
如果根据长度排列而不是字典序排列输出"lengths",
如果两种方式都符合输出"both"，否则输出"none"*/

#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n;
	cin>>n;
	string s1, s2;
	bool lexicographically=true, lengths=true;
	cin>>s1;
	for(int i=1; i<n; i++){
		cin>>s2;
		if(!lexicographically && !lengths)
			continue;
		if(lexicographically){
			if(s2<s1)
				lexicographically = false;
		}
		if(lengths){
			if(s2.length()<s1.length())
				lengths = false;
		}
		s1 = s2;
	}
	if(lexicographically && lengths)
		cout<<"both"<<endl;
	else if(lexicographically && !lengths)
		cout<<"lexicographically"<<endl;
	else if(!lexicographically && lengths)
		cout<<"lengths"<<endl;
	else
		cout<<"none"<<endl;
	return 0;
}
