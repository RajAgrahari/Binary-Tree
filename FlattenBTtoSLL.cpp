//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 void preorder(TreeNode* root,vector<TreeNode*>& pre)
    {
        if(root)
        {
            pre.push_back(root);
            preorder(root->left,pre);
            preorder(root->right,pre);
        }
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        preorder(root,pre);
        for(int i=1; i<pre.size();i++)
        {
            root->right = pre[i];
            root->left=NULL;
            root=root->right;
        }
        root=NULL;
    }