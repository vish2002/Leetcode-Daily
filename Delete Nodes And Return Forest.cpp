// 1110. Delete Nodes And Return Forest
// LeetCode : Medium 17-07-2024

TreeNode* helper(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& ans) {
    if (!root) return nullptr;

    root->left = helper(root->left, to_delete, ans);
    root->right = helper(root->right, to_delete, ans);

    if (to_delete.find(root->val) != to_delete.end()) {
        if (root->left) ans.push_back(root->left);
        if (root->right) ans.push_back(root->right);
        return nullptr;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
    vector<TreeNode*> ans;

    if (root && to_delete_set.find(root->val) == to_delete_set.end()) {
        ans.push_back(root);
    }

    helper(root, to_delete_set, ans);
    return ans;
}
