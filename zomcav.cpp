#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll c[n+1],h[n+1],arr[n+1]={};
        for (int i=1;i<=n;i++)
        {
            cin>>c[i];
            ll x,y;
            x=i-c[i];
            y=i+c[i];
            if (x>0 && x<=n)
            arr[x]+=1;
            if (y>0 && y<=n)
            arr[y]-=1;
        }
        for (int i=1;i<=n;i++)
        {
            cin>>h[i];
        }

        long long int x=0,ans[n+1]={};
        for (int i=1;i<=n;i++)
        {
            x+=arr[i];
            ans[i]=x;
        }
        bool shiv=false;
        for (int i=1;i<=n;i++)
        {
            if (ans[i]<h[i])
            shiv=true;
        }
        if (shiv)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
       


    }
    
}