// 538. Convert BST to Greater Tree
// Leetcode : Medium 25-06-2024

// Better Approach
void inorder(TreeNode* root,int &sum)
   {
    if(root == NULL)return;
    inorder(root->right,sum);
    sum+=root->val;
    root->val=sum;
    inorder(root->left,sum);
   }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        inorder(root,sum);
        return root;
    }

// Brute force Approach 

void inorder(TreeNode* root,vector<int> &ans)
{
    if(root==NULL)return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
int sum(int x,vector<int> &ans)
{
    bool flag=false;
    int summa=0;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==x)flag=true;
        if(flag)summa+=ans[i];
    }
    return summa;
}
void preorder(TreeNode* root,vector<int> &ans)
{
    if(root==NULL)return;
    root->val=sum(root->val,ans);
    preorder(root->left,ans);
    preorder(root->right,ans);
    
}
    TreeNode* convertBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        preorder(root,ans);
        return root;
    }
