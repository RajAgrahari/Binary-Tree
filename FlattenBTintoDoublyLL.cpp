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
//1 2 3 4 5 -1 6 10 7 -1 -1 -1 -1 -1 -1 -1 -1
//level order traversal => Time : O(N) Space : O(N)
void levelOrderTraversal(BTNode<int>* root)
{
    if(root==NULL)
    return;
    queue<BTNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BTNode<int>* f = q.front();
        q.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{
           cout<<f->data;
           if(f->left!=NULL)
           {
             q.push(f->left);
           }
        
           if(f->right!=NULL)
           {
             q.push(f->right);
           }
        }
    }
}
//Flatten a binary tree
void convertBTintoDLL(BTNode<int>* root,BTNode<int>** prev,BTNode<int>** head)
{
    if(root==NULL)
    return;
    convertBTintoDLL(root->left,&prev,&head);
    if(*prev==NULL)
    *head=root;
    else{
        root->left=*prev;
        (*prev)->right=root;
    }
    (*prev)=root;
    convertBTintoDLL(root->right,&prev,&head);
}
int main()
{
    BTNode<int>* root=takeInputLevelWise();
    cout<<endl;
    levelOrderTraversal(root);
    BTNode<int>* prev=NULL,*head=NULL;
    convertBTintoDLL(root,&prev,&head);
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->right;
    }
    return 0;
}