Node* connect(Node* root) {
        if(root==NULL)
        return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* f = q.front();
            q.pop();
            if(f==NULL)
            {
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                f->next = q.front();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        return root;
    }