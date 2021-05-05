#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;

    node (int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }


};

node *buildTree()
{
    int d;
    cin>>d;
    if (d==-1)
    return NULL;

    node *root = new node(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;

}

int height(node * root)
{
    if (root==NULL)
    return 0;

    int ls=height(root->left);
    int rs=height(root->right);

    return max(ls,rs)+1;
}
void printKthLevel(node *root,int k)
{
    if (root==NULL)
    return;

    if (k==1)
    {
        cout<<root->data<<" ";
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

void printAllLevel(node *root)
{
    int h=height(root);

    for (int i=1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
}

void printTreePre(node *root)
{
    if (root==NULL)
    return;

    cout<<root->data<<" ";
    printTreePre(root->left);
    printTreePre(root->right);
}

void printTreePost(node *root)
{
    if (root==NULL)
    return;

    printTreePost(root->left);
    printTreePost(root->right);
    cout<<root->data<<" ";


}

void printTreeIn(node *root)
{
    if (root==NULL)
    return;
    printTreeIn(root->left);
    cout<<root->data<<" ";
    printTreeIn(root->right);


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

int NoofNode(node *root)
{
    if (root==NULL)
    return 0;

    return 1+NoofNode(root->left)+NoofNode(root->right);
}
int SumofNode(node *root)
{
    if (root==NULL)
    return 0;

    return (root->data)+SumofNode(root->left)+SumofNode(root->right);
}

int DiameterRec(node *root)
{
    if (root==NULL)
    return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    int op1=h1+h2;
    int op2=DiameterRec(root->left);
    int op3=DiameterRec(root->right);

    return max(op1,max(op2,op3));

}
class Pair
{
    public:
    int height;
    int diameter;
};
Pair fastDiameter(node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter=p.height=0;
        return p;
    }
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);

    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}

int replaceSum(node *root)
{
    if (root==NULL)
    return 0;

    if (root->right==NULL && root->right==NULL)
    return root->data;

    int leftSum=replaceSum(root->left);
    int rightSum=replaceSum(root->right);

    int temp=root->data;
    root->data=leftSum+rightSum;

    return temp + root->data;
}

int main()
{
    node *root=buildTree();

    //printAllLevel(root);
    bfs(root);
    //cout<<NoofNode(root)<<endl;
    //cout<<SumofNode(root);
    //cout<<DiameterRec(root)<<endl;
    Pair p=fastDiameter(root);
    cout<<p.diameter<<endl;
    cout<<p.height<<endl;

    return 0;
}