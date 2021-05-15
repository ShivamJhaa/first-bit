#include <bits/stdc++.h>
using namespace std;
const int inf=(int)1e9;
int memo[10000];

int Solve(int n)
{
    if (n==1)
    return 0;
    if (memo[n]!=-1)
    return memo[n];
    int q1=inf,q2=inf,q3=inf;
    if (n%3==0)  q1=1+Solve(n/3);
    if (n%2==0)  q2=1+Solve(n/2);

    q3=1+Solve(n-1);

    memo[n]=min(q1,min(q2,q3));

    return memo[n];
}

int Solve_DP(int n)
{
    int dp[1000]={};
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    for (int i=4;i<=n;++i)
    {
        int q1=inf;
        int q2=inf;
        int q3=inf;

        if (i%3==0)
        q1=1+dp[i/3];
        if (i%2==0)
        q2=1+dp[i/2];
        q3=1+dp[i-1];

        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);
    int ans=Solve(n);

    cout<<ans<<endl;
    int ans2=Solve_DP(n);
    cout<<ans2<<endl;

    return 0;
}