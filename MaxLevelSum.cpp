// https://practice.geeksforgeeks.org/problems/4b7ff87c26ed23b3f63c25c611690213d44fb6aa/1
int maxLevelSum(Node* root) 
{
        queue<Node*> q;
        q.push(root);
        int ans = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            int sum=0;
            while(size--)
            {
                Node* node = q.front();
                q.pop();
                sum += node->data;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            ans = max(ans,sum);
        }
        return ans;
}
