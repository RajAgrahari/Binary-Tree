//https://practice.geeksforgeeks.org/problems/df12afc57250e7f6fc101aa9c272343184fe9859/1
 unordered_map<int,int> solve(Node* root, int k, int &ans){
        unordered_map<int,int>M1, M2;
        if(!root) return M1;
        M1 = solve(root->left,k,ans);
        M2 = solve(root->right,k,ans);
        for(auto i: M2){
            M1[i.first] += i.second;
        }
        M1[root->data]++;
        if(M1.size() <= k) ans++;
        return M1;
    }
    int goodSubtrees(Node *root,int k)
    {
       int ans = 0;
        solve(root, k, ans);
        return ans;
    }
