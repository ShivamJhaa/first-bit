#include <bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int>&s,int x){
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    InsertAtBottom(s,x);
    s.push(y);
}

void RevRec(stack<int>&s)
{
    int n=s.size();
    if (n==0)
    return;

    else{
        int x=s.top();
        s.pop();
        RevRec(s);
        InsertAtBottom(s,x);
    }
}

int main()
{
    stack<int>s;
    for (int i=0;i<=5;i++)
    {
        s.push(i*i);
    }
    RevRec(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}