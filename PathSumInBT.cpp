 int path_sum(TreeNode* root, long long int sum)
    {
        if(!root) {
            return 0;
        }
        sum -= root->val;
        if(sum == 0)
        return 1+path_sum(root->left, sum) + path_sum(root->right, sum);
        else
        return path_sum(root->left, sum) + path_sum(root->right, sum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        return path_sum(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }