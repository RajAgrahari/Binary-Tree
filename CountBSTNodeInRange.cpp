// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
void helper(Node* root,int l,int h,int& count)
    {
        if(root==NULL)
        return;
        if(root->data>=l && root->data<=h)
        count++;
        helper(root->left,l,h,count);
        helper(root->right,l,h,count);
    }
    int getCount(Node *root, int l, int h)
    {
        if(root==NULL)
        return 0;
        int count=0;
        helper(root,l,h,count);
        return count;
    }