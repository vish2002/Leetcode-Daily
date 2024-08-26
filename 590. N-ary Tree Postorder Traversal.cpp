// 590. N-ary Tree Postorder Traversal
// Leetcode : Easy 26-08-2024

class Solution {
public:
vector<int> result;
    
    void traverse(Node* root) {
        if(!root)
            return;
        
        for(Node*& x : root->children) {
            traverse(x);
        }
        
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        result.clear();
        traverse(root);
        return result;
    }
};
