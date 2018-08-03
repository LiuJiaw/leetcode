/*
 * 找出n个数里最小的k个.cpp
 *
 *  Created on: 2018年8月3日
 *      Author: garvin
 */

/*找出n个数里最小的k个*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int part(vector<int>& vec, int first, int last) {
    int value = vec[first];
    while (first < last) {
        while (first < last && vec[last] >= value)
            last--;
        vec[first] = vec[last];
        vec[last] = value;
        while (first < last && vec[first] <= value)
            first++;
        vec[last] = vec[first];
        vec[first] = value;
    }
    vec[first] = value;
    return first;
}

int main() {
    int x;
    vector<int> vec;
    while (cin >> x){
        vec.push_back(x);
    }
    int k = vec.back();
    int size = vec.size() - 1;
    if (k == size) {
        sort(vec.begin(), vec.end() - 1);
    }
    else {
        int Index = 0;
        int first = 0;
        int last = size - 2;
        while ((Index = part(vec, first, last)) != k - 1) {
            if (Index < k-1)
                first = Index + 1;
            else
                last = Index - 1;
        }
        sort(vec.begin(), vec.begin() + k);
    }
    for (int i = 0; i < k; i++) {
        cout << vec[i];
        if(i!=k-1)
            cout<<" ";
    }
    cout << endl;
    return 0;
}


