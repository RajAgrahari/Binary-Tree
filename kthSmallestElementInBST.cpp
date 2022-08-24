// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
void inorder(TreeNode* root,vector<int>& v,int k)
    {
        if(k==0)
        return;
        if(root)
        {
            inorder(root->left,v,k);
            v.push_back(root->val);
            k--;
            inorder(root->right,v,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v,k);
        return v[k-1];
    }