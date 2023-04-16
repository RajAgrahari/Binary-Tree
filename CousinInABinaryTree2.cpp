//https://leetcode.com/problems/cousins-in-binary-tree-ii/
TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int x=0;
        unordered_map<int,long long> mp;
        while(!q.empty())
        {
            int size = q.size();
            long long sum=0;
            while(size--)
            {
                TreeNode* n = q.front();
                q.pop();
                sum += (n->val);
                if(n->left)
                q.push(n->left);
                if(n->right)
                q.push(n->right);
            }
            mp[x] = sum;
            x++;
        }
        
        queue<TreeNode*> q1;
        root->val = 0;
        q1.push(root);
        q1.push(NULL);
        x=1;
        while(!q1.empty())
        {
            TreeNode* n = q1.front();
            q1.pop();
            if(n==NULL)
            {
                x++;
                if(!q1.empty())
                q1.push(NULL);
            }
            else{
                if(n->left)
                mp[x] -= n->left->val;
                if(n->right)
                mp[x] -= n->right->val;
                long long temp1=0,temp2=0;
                if(n->left)
                {
                    temp1 = n->left->val;
                    n->left->val = mp[x];
                    q1.push(n->left); 
                }
                if(n->right)
                {
                    temp2 = n->right->val;
                    n->right->val = mp[x];
                    q1.push(n->right);
                }
                if(n->left)
                mp[x] += temp1;
                if(n->right)
                mp[x] += temp2;
                
            }
        }
        return root;
        
        
    }
