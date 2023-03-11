// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
void helper(Node* root,map<int,vector<int>>& mp,int i)
{
    if(root==NULL)
    return;
    mp[i].push_back(root->data);
    helper(root->left,mp,i+1);
    helper(root->right,mp,i);
}
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int,vector<int>> mp;
    helper(root,mp,0);
    for(auto it:mp)
    {
        for(int i=0;i<it.second.size();i++)
        {
            ans.push_back(it.second[i]);
        }
    }
    return ans;
}
