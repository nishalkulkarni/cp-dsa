#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n,ll a[],vector<vector<ll>> &dp){
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            ll down = dp[j+1][i-j];
            ll right = dp[j][i-j+1];
            if(i%2)
                dp[j][i-j] = min(-a[j]+down,-a[n-i+j-1]+right);
            else
                dp[j][i-j] = max(a[j]+down,a[n-i+j-1]+right);
        }
    }

    return dp[0][0];
}

int main(){
    ll n;
    cin>>n;

    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        if(n%2)
            dp[i][n-1-i] = a[i];
        else
            dp[i][n-1-i] = -a[i];
    }
    
    cout<<solve(n,a,dp)<<endl;
    
    return 0;
}
