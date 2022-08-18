// https://leetcode.com/problems/invert-binary-tree/
TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return root;
        TreeNode* temp;
        temp=root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }