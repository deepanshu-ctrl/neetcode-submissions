/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,map<Node*,Node*> &old){
        if(node==nullptr) return nullptr;
        if(old.count(node)) return old[node];
        Node* cop=new Node(node->val);
        old[node]=cop;
        for(Node* nei:node->neighbors){
            cop->neighbors.push_back(solve(nei,old));
        }
        return cop;
    }
    Node* cloneGraph(Node* node) {
         map<Node*,Node*>old;
         return solve(node,old);
    }
};
