/*
 * 数列还原.cpp
 *
 *  Created on: 2018年8月3日
 *      Author: garvin
 */

/*牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，
但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，
但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，
请帮助牛牛计算出，符合这个要求的合法排列的数目。 */

#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

bool check(const vector<int>& vec, int k){
    int num = 0;
    int size = vec.size();
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(vec[i]<vec[j])
                num++;
        }
    }
    if(num == k)
        return true;
    return false;
}

bool merge(vector<int>& left, vector<int> vec, int k){
    int size = vec.size();
    int Index = 0;
    for(int i=0; i<size; i++){
        if(vec[i] == 0)
            vec[i] = left[Index++];
    }
    if(check(vec, k))
        return true;
    return false;
}

int getquanpailie(vector<int>& left, vector<int>& vec, int Index, int k){
    int size = left.size();
    if(Index == size-1){
        if( merge(left, vec, k) )
            return 1;
    }
    int ans = 0;
    for(int i= Index; i<size; i++){
        int tmp = left[i];
        left[i] = left[Index];
        left[Index] = tmp;
        ans += getquanpailie(left, vec, Index+1, k);
        tmp = left[i];
        left[i] = left[Index];
        left[Index] = tmp;
    }
    return ans;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> vec;
    int num;
    set<int> s;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
        s.insert(num);
    }
    vector<int> left;
    for(int i=1; i<=n; i++){
        if(s.find(i) == s.end())
            left.push_back(i);
    }
    int ans = getquanpailie(left, vec, 0, k);
    cout<<ans;
    return 0;
}
