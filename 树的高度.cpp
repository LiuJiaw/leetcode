/*
 * 树的高度.cpp
 *
 *  Created on: 2018年8月12日
 *      Author: garvin
 */


/*现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度

输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号

输出描述:
输出树的高度，为一个整数*/

/*
 * 这道题是真的坑...
 * 题目说的是合法的二叉树
 * 结果给的是多叉树，还要去掉多余的枝
 * 怪不得ac率这么低...
 */

#include <iostream>
#include <vector>

using namespace std;

int getHeight(vector<vector<int>> arr, int index){
    if (arr[index].size() == 0)
        return 1;
    int left = 0, right = 0;
    if (arr[index].size() >= 1)
        left = getHeight(arr, arr[index][0]);
    if (arr[index].size() >= 2)
        right = getHeight(arr, arr[index][1]);
    return 1 + (left > right ? left : right);
}

int main(){
    int n;
    while (cin >> n){
        vector<vector<int>> arr(n, vector<int>());
        int count = 1;
        while (count < n){
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
            count++;
        }
        if (n == 0)
            cout << 0 << endl;
        else{
            int rootIndex = 0;
            int height = getHeight(arr, rootIndex);
            cout << height << endl;
        }
    }
    return 0;
}

