void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   while(root)
   {
       if(root->key == key)
       {
           if(root->left)
           pre = root->left;
           if(root->right)
           suc = root->right;
           root=root->left;
       }
       else if(root->key< key)
       {
               pre=root;
               root=root->right;
       }
        else{
               suc=root;
               root=root->left;
        }
   }

}