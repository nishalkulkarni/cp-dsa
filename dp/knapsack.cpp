#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,w;
    cin>>n>>w;

    vector<vector<ll>> a(n,vector<ll>(2,0));
    for(ll i =0;i<n;i++)
        cin>>a[i][0]>>a[i][1];

    ll dp[w+1];

    for(int j=0;j<=w;j++)
        dp[j] = 0;

    for(int i=0;i<n;i++){
        for(int j=w;j>=a[i][0];j--){
            dp[j] = max(dp[j],dp[j-a[i][0]]+a[i][1]);
        }

        /* for(int j=0;j<=w;j++){ */
        /*     cout<<dp[j]<<" "; */
        /* }cout<<endl; */

    }

    cout<<dp[w]<<endl;

    return 0;
}
