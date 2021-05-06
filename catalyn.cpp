#include <bits/stdc++.h>
using namespace std;

//Calculating the catalyn series

int dp[1000]={0};

int Catalyn(int n)
{
    if (n==0)
    return 1;

    if (dp[n]!=0)
    {
        return dp[n];
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        ans+=Catalyn(i-1)*Catalyn(n-i);
    }

    dp[n]=ans;

    return ans;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<=n;i++){
        cout<<Catalyn(i)<<" ,";
    }

    return 0;
}