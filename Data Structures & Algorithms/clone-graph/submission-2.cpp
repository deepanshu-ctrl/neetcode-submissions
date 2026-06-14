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
    Node* solve(Node* node,unordered_map<Node*,Node*> &old){
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
        if(!node) return nullptr;
         unordered_map<Node*,Node*>old;

         queue<Node*>q;
         old[node]=new Node(node->val);
         q.push(node);
         while(!q.empty()){
            Node* c=q.front();
            q.pop();
            for(Node* nei:c->neighbors){
                if(old.find(nei)==old.end()){
                    old[nei]=new Node(nei->val);
                    q.push(nei);
                }
                old[c]->neighbors.push_back(old[nei]);
            }
         }
         return old[node];
        //  return solve(node,old);
    }
};
