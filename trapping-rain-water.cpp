/*
 * trapping-rain-water.cpp
 *
 *  Created on: 2018年7月23日
 *      Author: garvin
 */

 /*Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it is able to trap after raining.
For example,
Given[0,1,0,2,1,0,1,3,2,1,2,1], return6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

/*
 * 先求出最高高度
 * 然后从数列两边向中间靠拢，由于最高高度的存在，靠拢的过程只需考虑单侧即可
 * 内拢时记录遇到的最大值，即每次到一个新的地方，更新最大值或加上该处所积累的水
 */

class Solution {
public:
    int trap(int A[], int n) {
        if(n<=1)
            return 0;
        int maxindex = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(A[i]>A[maxindex])
                maxindex = i;
        }
        int maxheight = A[0];
        for(int i=1; i<maxindex; i++){
            if(A[i]>maxheight)
                maxheight = A[i];
            else
                ans+=(maxheight-A[i]);
        }
        maxheight = A[n-1];
        for(int i=n-2; i>maxindex; i--){
            if(A[i]>maxheight)
                maxheight = A[i];
            else
                ans+=(maxheight-A[i]);
        }
        return ans;
    }
};

