//https://leetcode.com/problems/sum-root-to-leaf-numbers/
void helper(TreeNode* root,int temp,int& ans)
    {
        if(root==NULL)
        return;
        if(root->left==NULL && root->right==NULL)
        {
            temp = (temp*10) + root->val;
            ans += temp;
            return;
        }
        temp = (temp*10) + root->val;
        helper(root->left,temp,ans);
        helper(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) 
    {
        int temp=0,ans=0;
        helper(root,temp,ans);
        return ans;
    }
