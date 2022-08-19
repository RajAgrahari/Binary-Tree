// https://leetcode.com/problems/balanced-binary-tree/
 int height(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1)
            return false;
        return (isBalanced(root->left)&&isBalanced(root->right));
    }