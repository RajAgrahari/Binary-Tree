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
//left view of BT
void printLeftViewUtil(BTNode<int>* root,vector<int>& v,int level)
{
    if((root)==NULL)
    return;
    if(level==v.size())
    {
      v.push_back(root->data);
    }
    printLeftViewUtil(root->left,v,level+1);
    printLeftViewUtil(root->right,v,level+1);
}
void printLeftView(BTNode<int>* root)
{
    vector<int> v;
    printLeftViewUtil(root,v,0);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"->";
}
//right view of BT
void printRightViewUtil(BTNode<int>* root,vector<int>& v,int level)
{
    if((root)==NULL)
    return;
    if(level==v.size())
    {
      v.push_back(root->data);
    }
    printRightViewUtil(root->right,v,level+1);
    printRightViewUtil(root->left,v,level+1);
}
void printRightView(BTNode<int>* root)
{
    vector<int> v;
    printRightViewUtil(root,v,0);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"->";
}
//Top View Of BT
vector<int> topView(BTNode<int> *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,BTNode<int>*> mp; 
        queue<pair<BTNode<int>*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            if(mp.find(it.second) == mp.end()) mp.insert({it.second,it.first}); 
            
            if(it.first->left != NULL) {
                q.push({it.first->left, it.second-1}); 
            }
            if(it.first->right != NULL) {
                q.push({it.first->right,it.second + 1}); 
            }
            
        }
        
        for(auto it : mp) {
            ans.push_back(it.second->data); 
        }
        return ans; 
    }
//Bottom view of BT
vector<int> bottomView(BTNode<int> *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
         map<int,BTNode<int>*> mp; 
        queue<pair<BTNode<int>*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            mp[it.second]=it.first; 
            
            if(it.first->left != NULL) {
                q.push({it.first->left, it.second-1}); 
            }
            if(it.first->right != NULL) {
                q.push({it.first->right, it.second+1}); 
            }
            
        }
        
        for(auto it : mp) {
            ans.push_back(it.second->data); 
        }
        return ans; 
    }
int main()
{
    BTNode<int>* root=takeInputLevelWise();
    cout<<endl;
    levelOrderTraversal(root);
    printLeftView(root);
    cout<<endl;
    printRightView(root);
    cout<<endl;
    vector<int> ans;
    ans = topView(root);
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;
    ans = bottomView(root);
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}