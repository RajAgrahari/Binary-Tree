//https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1
void minSumFromTarget(Node* target,int sum,int& mi)
    {
        if(target==NULL)
        {
            return ;
        }
        sum += target->data;
        if(target->left==NULL && target->right==NULL)
        {
            mi = min(mi,sum);
            return;
        }
        minSumFromTarget(target->left,sum,mi);
        minSumFromTarget(target->right,sum,mi);
    }
    Node* sumTillTarget(Node* root,int target,int& sum)
    {
        if(root==NULL)
        return NULL;
        sum += root->data;
        if(root->data == target)
        return root;
        else if(root->data > target)
        return sumTillTarget(root->left,target,sum);
        else
        return sumTillTarget(root->right,target,sum);
    }
    int maxDifferenceBST(Node *root,int target)
    {
        int sum = 0;
        Node* target_node = sumTillTarget(root,target,sum);
        if(target_node == NULL)
        return -1;
        sum -= target;
        int sum1 = 0,mi=INT_MAX;
        minSumFromTarget(target_node,sum1,mi);
        mi -= target;
        return sum-mi;
        
    }
