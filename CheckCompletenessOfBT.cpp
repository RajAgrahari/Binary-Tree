// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
bool isCompleteTree(TreeNode* root) 
{
        if(root==NULL)
        return true;
         queue<TreeNode*> q;
         q.push(root);
         bool f = false;
         while(!q.empty())
         {
             int size = q.size();
             while(size--)
             {
                  TreeNode* n = q.front();
                  q.pop();
                  if(!n)
                  {
                      f=true;
                  }
                  else{
                      if(f)
                      return false;
                      q.push(n->left);
                      q.push(n->right);
                  }
                  
             }
         }
         return true;
 }
