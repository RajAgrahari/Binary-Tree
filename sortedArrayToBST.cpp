// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 TreeNode* createBST(vector<int> &nums,int l,int h){
        if(l>h || h<0)
        return NULL;
        int mid = l+((h-l+1)/2);
        TreeNode* parent = new TreeNode(nums[mid]);
        parent->left = createBST(nums,l,mid-1);
        parent->right = createBST(nums,mid+1,h);
        return parent;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return createBST(nums,0,n-1);
    }