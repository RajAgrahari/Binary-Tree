// https://leetcode.com/problems/find-duplicate-subtrees/
string helper(TreeNode* root,vector<TreeNode*>& ans,unordered_map<string,int>& mp)
    {
        if(root==NULL)
        return "";

        string encode = to_string(root->val) + '#' + helper(root->left,ans,mp) + '#' +helper(root->right,ans,mp);
        if(++mp[encode] == 2)
        ans.push_back(root);
        return encode;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;
        helper(root,ans,mp);
        return ans;
    }
