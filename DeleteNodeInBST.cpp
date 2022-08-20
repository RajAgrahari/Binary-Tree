
int minValue(TreeNode* root){
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root->val;
    }
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        else if(root->val<key)
            root->right = deleteNode(root->right,key);
        else{
            if(root->left==NULL)
                return root->right;
            else if(root->right==NULL)
                return root->left;
            root->val=minValue(root->right);
            root->right=deleteNode(root->right,root->val);
        }
        return root;
}