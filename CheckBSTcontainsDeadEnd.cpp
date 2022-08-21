// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
void inorder(Node* root,unordered_set<int>& s)
{
    if(root==NULL)
    return;
    inorder(root->left,s);
    s.insert(root->data);
    inorder(root->right,s);
}
bool check(Node* root,unordered_set<int>& s){
    if(root==NULL)
    return false;
    if(root->left==NULL && root->right==NULL)
    {
        int temp = root->data;
        if(s.count(temp-1) && s.count(temp+1))
        return true;
    }
    return (check(root->left,s) || check(root->right,s));
    
}
bool isDeadEnd(Node *root)
{
    unordered_set<int> s;
    s.insert(0);
    inorder(root,s);
    return check(root,s);
}