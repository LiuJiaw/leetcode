/*
 * 75. 颜色分类.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */

/*
 * 只需遍历一次
 * 需要两个变量记录0、2最靠近中心的位置
 * 循环遍历从头至尾遍历，若为0，放到前面，若为2，放到后面
 */

/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int index0 = 0, index2 = size-1;
        for(int i=0; i<=index2; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[index0]), index0++;
            }
            else if(nums[i] == 2)
                swap(nums[i], nums[index2]), index2--, i--;
        }
    }
};
