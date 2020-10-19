#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin>>n>>k;

    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> dp(k+1,0);

    for(int i=a[0];i<=k;i++){
        bool found = false; 
        for(auto j:a){
            if(j>i) 
                break;
            if(dp[i-j] == 0){
                found = true;
                break;
            }
        }
        if(found) 
            dp[i] = 1;
    }
    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
