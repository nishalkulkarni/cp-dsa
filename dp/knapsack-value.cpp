#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,w;
    cin>>n>>w;

    vector<vector<ll>> a(n,vector<ll>(2,0));
    ll total_value=0;
    for(ll i =0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        total_value += a[i][1];
    }
    
    ll dp[total_value+1];

    for(int j=0;j<=total_value;j++)
        dp[j] = 1e18;
    
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=total_value;j>=a[i][1];j--){
            dp[j] = min(dp[j],dp[j-a[i][1]]+a[i][0]);
        }

        /* for(int j=0;j<=total_value;j++){ */
        /*     cout<<dp[j]<<" "; */
        /* }cout<<endl; */

    }

    ll ans = 0;
    for(int i=0;i<=total_value;i++){
        if(dp[i]<=w){
            ans = max(ans,(ll)i);
        }
    }
    cout<<ans<<endl;

    return 0;
}
