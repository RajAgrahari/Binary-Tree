// time complexity of functions hasnext() and next() is O(1) and space compexity of O(N)
class BSTIterator {
public:
    vector<int> v;
    int itr;
    void inorder(TreeNode* root,vector<int>& v)
    {
          if(root)
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    BSTIterator(TreeNode* root) {
       inorder(root,v);
        itr=0;
    }
    
    int next() {
      if(itr==0)
      
       return v[itr++];
       return v[itr++];
    }
    
    bool hasNext() {
        if(itr>=v.size())
        return false;
        return true;
    }
};

//striver's solution in TC:O(1) and SC:O(H)
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /*@return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /*@return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};
