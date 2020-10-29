#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int i = n-1; i>-1;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j] = 0;
            else{
                dp[i][j] = LONG_MAX;
                ll su = 0;
                for(int k=i;k<=j;k++) su += a[k];
                for(int k=i;k<=j-1;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + su);
                }
            }

        }
    }

    cout<<dp[0][n-1]<<endl;


    return 0;
}
