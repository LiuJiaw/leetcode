/*
 * 小米Git.cpp
 *
 *  Created on: 2018年8月20日
 *      Author: garvin
 */
/*
git是一种分布式代码管理工具，git通过树的形式记录文件的更改历史，
比如： base'<--base<--A<--A' ^ | --- B<--B' 小米工程师常常需要寻找两个分支最近的分割点，
即base.假设git 树是多叉树，请实现一个算法，计算git树上任意两点的最近分割点。
（假设git树节点数为n,用邻接矩阵的形式表示git树：字符串数组matrix包含n个字符串，每个字符串由字符'0'或'1'组成，
长度为n。matrix[i][j]=='1'当且仅当git树种第i个和第j个节点有连接。节点0为git树的根节点。）

示例1
输入
[01011,10100,01000,10000,10000],1,2
输出
1*/

class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    struct node{
        int father;
        vector<int> child;
    };
    void getchild(const vector<string>& matrix, vector<node >& record, set<int>& hasreach, int father){
        int size = matrix.size();
        for(int i=0; i<size; i++){
            if(matrix[father][i] == '1' && hasreach.find(i)==hasreach.end()){
                record[i].father = father;
                record[father].child.push_back(i);
                hasreach.insert(i);
            }
        }
        for(int i=0; i<record[father].child.size(); i++)
            getchild(matrix, record, hasreach, record[father].child[i]);
    }
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int n = matrix.size();
        if(n==0)
            return -1;
        vector<node > record;
        record.resize(n);
        record[0].father = 0;
        set<int> hasreach;
        hasreach.insert(0);
        getchild(matrix, record, hasreach, 0);
        vector<int> record1, record2;
        while(indexA!=0){
            record1.push_back(indexA);
            indexA = record[indexA].father;
        }
        while(indexB!=0){
            record2.push_back(indexB);
            indexB = record[indexB].father;
        }
        int result = 0;
        for(int i=1; i<=record1.size() && i<=record2.size(); i++){
            if(record1[record1.size()-i] == record2[record2.size()-i])
                result = record1[record1.size()-i];
            else
                break;
        }
        return result;
    }
};


