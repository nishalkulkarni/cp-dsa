#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main(){
    ll n,k;
    cin>>n>>k;

    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    dp[0][0] = 1; 

    for(int i=1;i<=n;i++){
        vector<ll> presum(k+1,0);            
        presum[0] = dp[i-1][0];
        for(int j=1;j<=k;j++)
            presum[j] = (dp[i-1][j] + presum[j-1])%MOD;

        for(int j=0;j<=k;j++){
            ll current = presum[j];
            ll unreachable = j-a[i-1]-1;
            if(unreachable>=0){
                current = (current+MOD-presum[unreachable])%MOD;
            }
            dp[i][j] = current;
        }
    }

    cout<<dp[n][k]<<endl;

    return 0;
}
