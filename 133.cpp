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
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        if(m.count(node)==0){
            m[node]=new UndirectedGraphNode(node->label);
            for(auto e:node->neighbors){
                (m[node]->neighbors).push_back(cloneGraph(e));
            }
        }
        return m[node];
    }
};
