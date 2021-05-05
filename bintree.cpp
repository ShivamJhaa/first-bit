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

class HBPair{
    public:
    int height;
    bool balance;
};

HBPair IsTreeBalance(node *root)
{
    HBPair p;
    if (root==NULL)
    {
        p.height=0;
        p.balance=true;
        return p;
    }

    HBPair left=IsTreeBalance(root->left);
    HBPair right=IsTreeBalance(root->right);

    p.height=max(left.height,right.height)+1;

    if (abs(left.height-right.height)<=1 && left.balance && right.balance)
    {
        p.balance=true;
    }
    else 
    {
        p.balance=false;
    }

    return p;
}

node *BuildTreeFromArray(int *a,int s,int e)
{
    if (s>e)
    return NULL;

    int mid=(s+e)/2;
    node *root=new node(a[mid]);

    root->left=BuildTreeFromArray(a,s,mid-1);
    root->right=BuildTreeFromArray(a,mid+1,e);

    return root;
}

node * buildTreefromPreIn(int *in,int*pre,int s,int e)
{
    static int i=0;
    if (s>e)
    return NULL;

    node *root=new node(pre[i]);

    int index=-1;

    for (int j=s;j<=e;j++)
    {
        if (in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    i++;

    root->left=buildTreefromPreIn(in,pre,s,index-1);
    root->right=buildTreefromPreIn(in,pre,index+1,e);

    return root;
}

int main()
{
    //node *root=buildTree();

    //printAllLevel(root);
    //bfs(root);
    //cout<<NoofNode(root)<<endl;
    //cout<<SumofNode(root);
    //cout<<DiameterRec(root)<<endl;
    /*Pair p=fastDiameter(root);
    cout<<p.diameter<<endl;
    cout<<p.height<<endl;*/

    /*int arr[]={1,2,3,4,5,6,7};
    int n=7;

    node * root=BuildTreeFromArray(arr,0,n-1);

    bfs(root);*/

    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int n=sizeof(in)/sizeof(int);

    node *root=buildTreefromPreIn(in,pre,0,n-1);

    bfs(root);

    return 0;
}