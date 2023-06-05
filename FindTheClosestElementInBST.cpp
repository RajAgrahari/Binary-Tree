//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
void helper(Node* root,int& mi,int k)
	{
	    if(root==NULL)
	    return;
	    mi = min(mi,abs(root->data - k));
	    helper(root->left,mi,k);
	    helper(root->right,mi,k);
	}
    int minDiff(Node *root, int k)
    {
        int mi = INT_MAX;
        helper(root,mi,k);
        return mi;
    }
