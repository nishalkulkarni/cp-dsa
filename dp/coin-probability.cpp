#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    
    double dp[n+1][n+1];

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][i] = dp[i-1][i-1]*p[i-1];
        dp[0][i] = dp[0][i-1]*(1-p[i-1]);
    }

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dp[i][j] = p[j-1]*dp[i-1][j-1] + (1-p[j-1])*dp[i][j-1];


    double ans = 0;
    for(int i=n/2 +1;i<=n;i++) 
        ans+=dp[i][n];

    printf("%0.15f\n",ans);
    return 0;
}
