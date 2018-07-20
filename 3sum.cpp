/*
 * 3sum.cpp
 *
 *  Created on: 2018年7月20日
 *      Author: garvin
 */

/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)*/


/*
 * 这道题先对所有数字进行排序
 * 然后从第一个数开始，依次做a
 * b和c从a后面的数字中选，因为挑选的条件为和为-a，且序列是有序的
 * 所有一前一后往中间夹着找
 * 需要注意的是，无论对a,b还是c，只要碰到相同的元素，就往下略
 * 也省去了二维vector去重的过程
 * 还要注意找到符合条件的三个数后，b和c要往中间走，我因为忘记这一步操作
 * 超内存了好几次，关键是还一直没发现这个低级错误，心累
 * 看来疲倦的时候真的不能编代码
 */


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size()<3)
            return ans;

        int size = num.size();
        sort(num.begin(), num.end());

        int indexa = 0, indexb =0, indexc =0;
        vector<int> tmp;
        for(int indexa = 0; indexa < size-2; indexa++){
            indexb = indexa+1, indexc = size-1;
            while(indexb<indexc){
                if(num[indexa]+num[indexb]+num[indexc]>0)
                    indexc--;
                else if(num[indexa]+num[indexb]+num[indexc]<0)
                    indexb++;
                else{
                    tmp.clear();
                    tmp.push_back(num[indexa]);
                    tmp.push_back(num[indexb++]);
                    tmp.push_back(num[indexc--]);
                    ans.push_back(tmp);
                    while(indexb<indexc && num[indexb] == num[indexb-1])
                        indexb++;
                    while(indexb<indexc && num[indexc] == num[indexc+1])
                        indexc--;
                }
            }
            while(indexa < size-2 && num[indexa]==num[indexa+1])
                indexa++;
        }
        return ans;
    }
};


/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.
   For example, given array S = {-1 2 1 -4}, and target = 1.
   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        sort(num.begin(), num.end());
        int indexa =0, indexb=0, indexc=0;
        int ans = num[0]+num[1]+num[2];

        for(indexa=0; indexa<size-2; indexa++){
            indexb=indexa+1, indexc=size-1;
            while(indexb<indexc){
                int Sum = num[indexa]+num[indexb]+num[indexc];
                if(Sum == target)
                    return target;
                else if(Sum > target)
                    indexc--;
                else if(Sum < target)
                    indexb++;
                if( abs(Sum-target)<abs(ans-target) )
                    ans = Sum;
            }
            while(indexa<size-2 && num[indexa]==num[indexa+1])
                indexa++;
        }
        return ans;
    }
};

