/*
 * 数组中的逆序对.cpp
 *
 *  Created on: 2018年8月18日
 *      Author: garvin
 */

/* 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
 即输出P%1000000007 */

class Solution {
public:
    void check(vector<int>& data, int start, int end, int& result){
        if(end - start == 0)
            return;
        else if(end - start == 1){
            if(data[start]>data[end]){
                result++;
                int tmp = data[start];
                data[start] = data[end];
                data[end] = tmp;
            }
            return;
        }
        check(data, start, (start+end)/2, result);
        check(data, (start+end)/2+1, end, result);

        int start1 = start, start2 = (start+end)/2+1;
        vector<int> tmp;
        while(start1!=(start+end)/2+1 && start2!=end+1){
            if(data[start1]<=data[start2]){
                tmp.push_back(data[start1]);
                start1++;
            }
            else{
                tmp.push_back(data[start2]);
                start2++;
                result += ( (start+end)/2+1-start1 );
                result %= 1000000007;
            }
        }
        while(start1!=(start+end)/2+1)
            tmp.push_back(data[start1++]);
        while(start2!=end+1)
            tmp.push_back(data[start2++]);
        for(int i=start; i<=end; i++){
            data[i] = tmp[i-start];
        }
    }
    int InversePairs(vector<int> data) {
        if(data.size()<=1)
            return 0;
        int Size = data.size();
        int result = 0;
        check(data, 0, Size-1, result);
        return result;
    }
};
