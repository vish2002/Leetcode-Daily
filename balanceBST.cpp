
//Convert BST To Balanced BST
// Leetcode : Medium 26-06-24

// Divide and conquer Approach 
void inorder(TreeNode* root,vector<int> &ans)
    {
        if(!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode*balancedBST(vector<int> ans)
    {
        if(ans.empty())return nullptr;
        int mid=ans.size()/2;
        TreeNode*root=new TreeNode(ans[mid]);
        root->left=balancedBST(vector<int>(begin(ans),begin(ans)+mid));
        root->right=balancedBST(vector<int>(begin(ans)+mid+1,end(ans)));
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return balancedBST(ans);
    }

// Another method using Binary Search 
    void inorder(TreeNode* root,vector<int> &ans)
    {
        if(!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode*balancedBST(vector<int> ans,int low,int high)
    {
        if(low>high)return nullptr;
        
        int mid=low+(high-low)/2;
        TreeNode*root=new TreeNode(ans[mid]);
        root->left=balancedBST(ans,low,mid-1);
        root->right=balancedBST(ans,mid+1,high);
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size()-1;
        return balancedBST(ans,0,n);
    }
