#include <bits/stdc++.h>
using namespace std;

void subSeq(char *in,char *out,int i,int j){
    if (in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<" ";
        return;
    }
    out[j]=in[i];
    subSeq(in,out,i+1,j+1);

    subSeq(in,out,i+1,j);
}

int main()
{
    int n;
    cin>>n;
    char arr[n];
    char out[100];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    subSeq(arr,out,0,0);
    
}