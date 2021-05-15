#include <bits/stdc++.h>
using namespace std;

long long int fib(int n)
{
    long long int dp[1000]={};
    dp[0]=0;
    dp[1]=1;

    for (int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    long long int ans=fib(n);
    cout<<ans<<endl;

    return 0;
}