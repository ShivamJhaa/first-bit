#include <bits/stdc++.h>
using namespace std;

void Solve(){

    int n;
    cin>>n;
    int arr[n];
    int curSum=0;
    int Mod[n]={0};
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        curSum+=arr[i];
        int x=(curSum%n+n)%n;
        Mod[x]++;

    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (Mod[i]>1);
        ans+=(Mod[i]*(Mod[i]-1))/2;
    }
    ans+=Mod[0];
    cout<<ans<<endl;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Solve();
    }
    return 0;
}