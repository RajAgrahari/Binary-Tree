 vector<int> verticalOrder(Node *root)
    {
        if(root==NULL)
        return {};
        map<int,vector<Node*>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            mp[it.second].push_back(it.first);
            if(it.first->left!=NULL)
            q.push({it.first->left,it.second-1});
            if(it.first->right!=NULL)
            q.push({it.first->right,it.second+1});
        }
        vector<int> ans;
        for(auto itr : mp) {
            for(int i=0;i<itr.second.size();i++)
            {
                ans.push_back(itr.second[i]->data); 
            }
        }
        return ans; 
    }