//https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
class bstitr{
    stack<TreeNode*> st;
    public:
    bstitr(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
    void next()
    {
        TreeNode* cur = st.top()->right;
        st.pop();
        while(cur)
        {
           st.push(cur);
           cur = cur->left;
        }
    }
    bool hasnext()
    {
        return (!st.empty());
    }
    int current()
    {
        return st.top()->val;
    }
};
class Solution {
public:
    int getMinimumDifference(TreeNode* root) 
    {
        bstitr bst(root);
        int ans = INT_MAX;
        while(bst.hasnext())
        {
            int a = bst.current();
            bst.next();
            int b = 0;
            if(bst.hasnext())
            b = bst.current();
            ans = min(ans,abs(a-b));
        }
        return ans;
    }
};
