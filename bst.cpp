#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node * left;
    node * right;

    node (int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }

};

node *InsertInBST(node* root,int data)
{
    if (root==NULL)
    return new node(data);

    //Recursive case

    if (data<=root->data)
    {
        root->left=InsertInBST(root->left,data);
    }
    else {
        root->right=InsertInBST(root->right,data);
    }

    return root;
}

node *build()
{
    int d;
    cin>>d;

    node* root=NULL;
    while (d!=-1)
    {
        root=InsertInBST(root,d);
        cin>>d;
    }

    return root;
    
}

void bfs(node * root)
{
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *f=q.front();
        if (f==NULL)
        {
            cout<<endl;
            q.pop();
            if (!q.empty())
            q.push(NULL);
        }
        else{
        cout<<f->data<<" ";
        q.pop();

        if (f->left)
        {
            q.push(f->left);

        }
        if (f->right)
        {
            q.push(f->right);
        }
        }

    }

    return;

}

void inorder(node *root)
{
    if (root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool Search(node *root,int data)
{
    if (root==NULL)
    return false;

    if (root->data==data)
    return true;

    //Recursive case

    if (data<root->data)
    return Search(root->left,data);
    else 
    return Search(root->right,data);
}

node * deleteInBST(node *root,int data){
    if (root==NULL)
    return NULL;

    else if (data<root->data){
    root->left= deleteInBST(root->left,data);
    return root;
    }

    else if (data==root->data)
    {
        //We have 3 cases here
        //1. If the node doesn't have any chlidren-Leaf Node
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //2. If the node have only 1 children
        if (root->left!=NULL && root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        if (root->right!=NULL && root->left==NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }

        //3. If the node have 2 children
        node *replace=root->right;
        while(replace->left!=NULL)
        {
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deleteInBST(root->right,replace->data);
        return root;

    }
    else {
        root->right=deleteInBST(root->right,data);
        return root;
    }
}

bool IsBSt(node *root,int minV=INT32_MIN,int maxV=INT32_MAX)
{
    if (root==NULL)
    return true;

    if (root->data>=minV && root->data<=maxV && IsBSt(root->left,minV,root->data) && IsBSt(root->right,root->data,maxV))
    return true;

    return false;
}

int main()
{
    node *root=build();
    bfs(root);
    cout<<endl;

    inorder(root);
    cout<<endl;
    /*int s;
    cin>>s;*/
    /*if (Search(root,s))
    cout<<"DATA is PResent"<<"\n";
    else 
    cout<<"Not Present"<<"\n";*/
    /*root=deleteInBST(root,s);
    inorder(root);
    cout<<endl;
    bfs(root);
    cout<<endl;*/

    if (IsBSt(root))
    cout<<"yes"<<endl;
    else 
    cout<<"No"<<endl;


    return 0;
}