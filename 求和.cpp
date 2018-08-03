/*
 * 求和.cpp
 *
 *  Created on: 2018年8月3日
 *      Author: garvin
 */


/*输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来*/


#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

void get(vector<int>& record, int Index, int n, int left) {
    if (left == 0) {
        int size = record.size();
        for (int i = 0; i < size; i++){
            cout << record[i];
            if(i != size-1)
                cout<<" ";
        }
        cout << endl;
        return;
    }
    if (left < 0 || Index > n)
        return;
    record.push_back(Index);
    get(record, Index + 1, n, left - Index);
    record.pop_back();
    get(record, Index + 1, n, left);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> record;
    get(record, 1, n, m);
    return 0;
}
