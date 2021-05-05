#include <bits/stdc++.h>
using namespace std;


void printSpan(int arr[],int n)
{
    stack<int>s;
    int ans[100]={};

    for (int i=0;i<n;i++)
    {
        int curP=arr[i];
        while(s.empty()==false && arr[s.top()]<curP)
        {
            s.pop();
        }
        int betterDay= s.empty()?0:s.top();
        int span=i-betterDay;
        ans[i]=span;
        s.push(i);
    }
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}

/*
void Solve(int arr[],int n)
{
    int ans[n]={1};
    stack<int>s;

    for (int i=0;i<n;i++)
    {
        if (s.empty())
        s.push(i);
        else if (arr[i]<=arr[s.top()])
        {
            ans[i]=i-s.top();
            s.push(i);
        }
        else 
        {
            while(arr[s.top()]<arr[i])
            {
                s.pop();
            }
            ans[i]=i-s.top();
            s.push(i);
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}   
*/     

int main()
{
    int arr[]= {100, 80, 60, 70, 60, 75, 85};
    int n=sizeof(arr)/sizeof(int);

    //Solve(arr,n);
    printSpan(arr,n);

    return 0;
}