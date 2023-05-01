//https://practice.geeksforgeeks.org/problems/079dee7e7db7a784ed73f604e3cf1712432edf79/1
string helper(Node* root,vector<Node*>& ans,unordered_map<string,int>& mp)
    {
        if(root==NULL)
        return "";
        string encode = to_string(root->data)+'#';
        for(auto& child:root->children)
        encode += (helper(child,ans,mp)+'#');
        
        if(++mp[encode] == 2)
        ans.push_back(root);
        return encode;
    }
    int duplicateSubtreeNaryTree(Node *root)
    {
        vector<Node*> ans;
        unordered_map<string,int> mp;
        helper(root,ans,mp);
        return ans.size();
    }
