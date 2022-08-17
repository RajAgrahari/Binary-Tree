#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BTNode{
    public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode(T data){
        this->data=data;
    }
};

BTNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data:";
    cin>>rootData;
    if(rootData==-1)
    return NULL;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BTNode<int>* f = q.front();
        q.pop();

        int leftChildData;
        cout<<"Enter the left child of "<<f->data<<":";
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
           BTNode<int>* leftChild = new BTNode<int>(leftChildData);
           q.push(leftChild);
           f->left=leftChild;
        }
        else
        f->left=NULL;

        int rightChildData;
        cout<<"Enter the right child "<<f->data<<":";
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BTNode<int>* rightChild = new BTNode<int>(rightChildData);
           q.push(rightChild);
           f->right=rightChild;
        }
        else
        f->right=NULL;
    }
    return root;
}

bool helper(BTNode<int>* leftTree,BTNode<int>* rightTree)
{
    if(leftTree==NULL && rightTree==NULL)
    return true;
    if(leftTree!=NULL && rightTree==NULL)
    return false;
    if(leftTree==NULL && rightTree!=NULL)
    return false;
    if(leftTree->data!=rightTree->data)
    return false;
    return (helper(leftTree->left,rightTree->right) && helper(leftTree->right,rightTree->left));
}
bool isSymmetricTree(BTNode<int>* root)
{
  if(root==NULL)
  return true;
  return helper(root->left,root->right);
}
int main()
{
     BTNode<int>* root=takeInputLevelWise();//1 2 3 4 5 -1 6 10 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout<<endl;
    cout<<isSymmetricTree(root)<<endl;
    return 0;
}