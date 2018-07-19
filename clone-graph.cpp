/*
 * clone-graph.cpp
 *
 *  Created on: 2018年7月19日
 *      Author: garvin
 */

/* Clone an undirected graph. Each node in the graph contains alabeland a list of itsneighbors.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use#as a separator for each node, and,as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph{0,1,2# 1,2# 2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by#.
    First node is labeled as0. Connect node0to both nodes1and2.
    Second node is labeled as1. Connect node1to node2.
    Third node is labeled as2. Connect node2to node2(itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    void search(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*>& m){
        if(m.find(node) != m.end())
            return;
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        m[node] = newnode;
        int size = node->neighbors.size();
        for(int i=0; i<size; i++){
            search(node->neighbors[i],m);
            newnode->neighbors.push_back(m[node->neighbors[i]]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        search(node, m);
        return m[node];
    }
};
