 //Function to serialize a tree into vector.
 void helper(Node* root,vector<int>& v)
    {
        if(root==NULL)
        {
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);
        helper(root->left,v);
        helper(root->right,v);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> v;
        helper(root,v);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* helper2(vector<int>& A,int& index)
    {
        if(index==A.size())
        return NULL;
        int data=A[index];
        index++;
        if(data==-1)
        return NULL;
        Node* root=new Node(data);
        root->left=helper2(A,index);
        root->right=helper2(A,index);
        return root;
    }
    Node * deSerialize(vector<int> &A)
    {
       int index=0;
       return helper2(A,index);
    }