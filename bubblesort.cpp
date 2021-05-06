#include <bits/stdc++.h>
using namespace std;

void Sorted(int arr[],int n)
{
    if (n==1)
    return;

    for (int i=0;i<=n-2;i++)
    {
        if (arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    Sorted(arr,n-1);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Sorted(arr,n);
    for (int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}