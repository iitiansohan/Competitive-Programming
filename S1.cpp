#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode* left,*right;
    TreeNode(int key)
    {
        data=key;
        left=right=nullptr;
    }
};
void printLevelOrder(TreeNode *root)
{
    if(root==NULL)
    {
        cout<<"The root is NULL\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode * Cnode=q.front();
        cout<<Cnode->data<<" ";
        q.pop();
        if(Cnode->left!=nullptr)
        q.push(Cnode->left);
        if(Cnode->right!=nullptr)
        q.push(Cnode->right);
    }
}
void preorder(TreeNode* root)
{
    if(root==NULL)
    {
        cout<<"The binary tree is empty\n";
        return;
    }
    else
    {
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            cout<<s.top()->data<<" ";
            s.pop();
            if(temp->right!=nullptr)
            s.push(temp->right);
            if(temp->left!=nullptr)
            s.push(temp->left);
        }
    }
}
void postorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<TreeNode*> s;
    TreeNode* curr=root;
    while(curr!=nullptr||!s.empty())
    {
        while(curr!=nullptr)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    cout<<"Level-OrderTraversal:---\n";
    printLevelOrder(root);
    cout<<"\n";
    cout<<"Pre-OrderTraversal:---\n";
    preorder(root);  
    cout<<"\n";
    cout<<"Post-OrderTraversal:---\n";
    postorder(root);
    cout<<"\n";
    cout<<"In-OrderTraversal:---\n";
    inorder(root);
}
