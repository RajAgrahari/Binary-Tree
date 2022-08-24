vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
    	queue<Node*> q;
    	q.push(root);
    	bool flag=false;
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    vector<int> temp;
    	    while(size>0)
    	    {
    	        Node* f=q.front();
    	        q.pop();
    	        temp.push_back(f->data);
    	        if(f->left)
    	        q.push(f->left);
    	        if(f->right)
    	        q.push(f->right);
    	        size--;
    	    }
    	    if(flag)
    	    {
    	        reverse(temp.begin(),temp.end());
    	        ans.insert(ans.end(),temp.begin(),temp.end());
    	        flag=(!flag);
    	    }
    	    else{
    	        ans.insert(ans.end(),temp.begin(),temp.end());
    	        flag=(!flag);
    	    }
    	    
    	    
    	}
    	return ans;
    	    
    }