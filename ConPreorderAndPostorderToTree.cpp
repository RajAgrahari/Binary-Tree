 TreeNode* construct(vector<int>& pre,int psi,int pei, vector<int>& post,int ppsi,int ppei)
    {
     
        if(psi>pei)
        return NULL;
        
       
        TreeNode* root = new TreeNode(pre[psi]);
        if(psi==pei)
        return root;
        
    
        int idx=ppsi;
        while(post[idx]!=pre[psi+1])
            idx++;
        int tnel = idx-ppsi+1;
      
        root -> left = construct(pre, psi+1,psi+tnel,post,ppsi, idx);
        
        root -> right = construct(pre,psi+tnel+1,pei,post,idx+1,ppei-1);
        
    
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        
        return construct(preorder,0,n-1, postorder, 0, n - 1);
    }