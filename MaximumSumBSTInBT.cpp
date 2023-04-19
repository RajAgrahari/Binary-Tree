//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
struct Node{
    int sum;
    bool isBST;
    int ma;
    int mi;
};
class Solution {
public:
    struct Node helper(TreeNode* root,int& mxsum)
    {
        struct Node x;
        if(root==NULL)
        {
            x.sum = 0;
            x.isBST = true;
            x.ma = INT_MIN;
            x.mi = INT_MAX;
            return x;
        }
        struct Node left = helper(root->left,mxsum); 
        struct Node right = helper(root->right,mxsum);
        if(left.isBST && right.isBST && left.ma < root->val && right.mi > root->val)
        {
            x.isBST = true;
            mxsum = max(mxsum,root->val+left.sum+right.sum);
            x.sum = root->val+left.sum+right.sum;
            x.ma = max(root->val,right.ma);
            x.mi = min(root->val,left.mi);
        }
        else{
            x.isBST = false;
            x.sum = max(left.sum,right.sum);
            x.ma = INT_MIN;
            x.mi = INT_MAX;
        }
        return x;
    }
    int maxSumBST(TreeNode* root) 
    {
        int mxsum = 0;
        helper(root,mxsum);
        return mxsum;
    }
};
