 TreeNode* prev =NULL;
    bool isValidBST(TreeNode* root) {
        if(root!=NULL)
        {
            if(!isValidBST(root->left))
                return false;
            if(prev!=NULL && root->val<=prev->val)
                return false;
            prev=root;
            return isValidBST(root->right);
        }
        return true;
    }
// alternate solution
  bool valid(TreeNode* root, long long low, long long high)
    {
        if(root==NULL)
        {
            return true;
        }
        bool left=valid(root->left,low,root->val);
        bool right=valid(root->right,root->val,high);
        if(left==true && right==true && root->val<high && root->val>low)
        {
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }