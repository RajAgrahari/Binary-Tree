// https://leetcode.com/problems/binary-tree-cameras/
 int helper(TreeNode* root,int& count){
        if(root == NULL) 
        return 1;
        
        if(root->left ==  nullptr && root->right == nullptr) 
        return -1;
        
        int l = helper(root->left,count);
        int r = helper(root->right,count);
        if(l == -1 || r == -1)
        {
            count++;
            return 0; 
        }
        else if(l == 0 || r == 0)
        {
            return 1;
        }
        else if(l == 1 && r == 1)
        {
            return -1;
        }
        
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int count=0;
        int v = helper(root,count);
        if(v == -1) 
        return count+1;
        return count;
    }