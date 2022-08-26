    // https://practice.geeksforgeeks.org/problems/largest-bst/1
    int count(Node* root)
    {
        if(root==NULL)
        return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool isBST(Node* root,int ub,int lb)
    {
         if(!root)
           return true;
         if(root->data>=ub||root->data<=lb){
           return false;
          }
         else 
         return isBST(root->left,root->data,lb)&&isBST(root->right,ub,root->data);
          
    }
    int largestBst(Node *root)
    {
        if(root==NULL)
        return 0;
        
        if(isBST(root,INT_MAX,INT_MIN))
        return count(root);

        return max(largestBst(root->left),largestBst(root->right));
    }