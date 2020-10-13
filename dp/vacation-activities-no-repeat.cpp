#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<pair<ll,ll>,ll> mp;

ll vacation(ll n,vector<vector<ll>> p){
    if(n==1) return max(max(p[0][0],p[0][1]),p[0][2]);

    ll dp[3];
    dp[0] = max(p[0][1],p[0][2]);
    dp[1] = max(p[0][0],p[0][2]);
    dp[2] = max(p[0][1],p[0][0]);

    for(int i=1;i<n;i++){
        ll a = dp[0],b = dp[1],c =dp[2];
        dp[0] = max(p[i][0]+b,p[i][0]+c);
        dp[1] = max(p[i][1]+a,p[i][1]+c);
        dp[2] = max(p[i][2]+b,p[i][2]+a);
        /* cout<<i<<" "<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl; */
    }

    return max(max(dp[0],dp[1]),dp[2]);
}

int main(){

    int n;
    cin>>n;
    vector<vector<ll>> p(n,vector<ll>(3,0));

    for(int i=0;i<n;i++)
        cin>>p[i][0]>>p[i][1]>>p[i][2];


    cout<<vacation(n,p)<<endl;

    return 0;
}
