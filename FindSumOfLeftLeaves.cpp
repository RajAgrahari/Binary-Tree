// https://leetcode.com/problems/sum-of-left-leaves/
 void helper(TreeNode* root,int& sum)
    {
        if(root==NULL)
        return;
        if(root->left && root->left->left == NULL && root->left->right == NULL)
        sum += root->left->val;
        
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
        return 0;
        int sum=0;
        helper(root,sum);
       return sum;
    }