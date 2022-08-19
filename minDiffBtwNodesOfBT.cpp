//  https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 void inorder(vector<int>& v,TreeNode* root)
    {
        if(root==NULL)
        return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    int getMinimumDifference(TreeNode* root) {
       vector<int> v;
        inorder(v,root);
        int ans = INT_MAX;
        for(int i=1;i<v.size();i++)
            ans = min(ans,v[i]-v[i-1]);
        return ans;
    }
// alternate solution
void inorder(TreeNode* root,int& ans,int& prev)
{
    if(root)
    {
        inorder(root->left,prev);
        if(prev!=-1)
        ans = min(ans,root->val - prev);
        prev = root->val;
        inorder(root->right,ans,prev)
    }
}
int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        inorder(root,ans,prev);
        return ans;
    }
