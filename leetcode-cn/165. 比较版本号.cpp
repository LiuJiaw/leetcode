/*
 * 165. 比较版本号.cpp
 *
 *  Created on: 2018年9月22日
 *      Author: garvin
 */

/*
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。

 . 字符不代表小数点，而是用于分隔数字序列。

例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。

示例 1:

输入: version1 = "0.1", version2 = "1.1"
输出: -1

示例 2:

输入: version1 = "1.0.1", version2 = "1"
输出: 1

示例 3:

输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        int size1 = version1.size(), size2 = version2.size();
        int tmp = 0;
        for(int i=0; i<size1; i++){
            if(version1[i] == '.'){
                vec1.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp = tmp*10 + version1[i] - '0';
        }
        vec1.push_back(tmp);
        tmp = 0;
        for(int i=0; i<size2; i++){
            if(version2[i] == '.'){
                vec2.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp = tmp*10 + version2[i] - '0';
        }
        vec2.push_back(tmp);
        int index1 = 0, index2 = 0;
        while(index1 < vec1.size() && index2 < vec2.size()){
            if(vec1[index1] < vec2[index2])
                return -1;
            if(vec1[index1] > vec2[index2])
                return 1;
            index1++, index2++;
        }
        while(index1 < vec1.size() && vec1[index1] == 0)
            index1++;
        while(index2 < vec2.size() && vec2[index2] == 0)
            index2++;
        if(index1 < vec1.size())
            return 1;
        if(index2 < vec2.size())
            return -1;
        return 0;
    }
};


