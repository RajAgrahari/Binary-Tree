class Solution {
public:
    void helper(TreeNode* root,vector<int>& seq)
    {
        if(root==NULL)
        return;
        if(root->left == NULL && root->right == NULL)
        {
            seq.push_back(root->val);
            return;
        }
        helper(root->left,seq);
        helper(root->right,seq);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> temp1,temp2;
        helper(root1,temp1);
        helper(root2,temp2);
        if(temp1.size()==temp2.size())
        {
            for(int i=0;i<temp1.size();i++)
            {
                if(temp1[i]!=temp2[i])
                return false;
            }
        }
        else
        return false;

        return true;
    }
};
