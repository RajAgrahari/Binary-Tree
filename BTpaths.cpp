//  https://leetcode.com/problems/binary-tree-paths/
 void helper(vector<string>& v,string s,TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            string temp = to_string(root->val);
            s+=temp;
            v.push_back(s);
            return;
        }
        string temp = to_string(root->val);
        s+=temp;
        s+="->";
        helper(v,s,root->left);
        helper(v,s,root->right);  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        helper(v,"",root);
        return v;
    }