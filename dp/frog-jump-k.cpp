#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll frog(ll h[],ll n,ll k){
    ll ms[n];
    ms[0] = 0;
    ms[1] = abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        ll d1 = ms[i-1] + abs(h[i-1]-h[i]);
        for(int j=2;j<=k && i-j>=0;j++){
            ll d2 = ms[i-j] + abs(h[i-j]-h[i]);
            d1 = min(d1,d2);
        }
        ms[i] = d1;
    }

    return ms[n-1];
}


int main(){
    ll n,k;
    cin>>n>>k;
    ll h[n];
    for(ll i=0;i<n;i++) cin>>h[i];
    cout<<frog(h,n,k)<<endl;
    return 0;
}
