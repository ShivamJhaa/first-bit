#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
    cout<<"Enter the length of the array"<<endl;
    int i,x;
    cin>>x;
    cout<<"\nEnter the elments of the array"<<endl;
    int arr[x];
    for (i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    int asize= sizeof(arr)/sizeof(arr[0]);
    cout<<"the array before sorting is "<<endl;
    for(i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
    sort (arr,arr+asize);
    cout<<"The array after sorting is\n";
    for (i=0;i<x;i++)
    cout<<arr[i]<<" ";
    return 0;
}