#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll frog(ll h[],ll n){
    ll ms[n];
    ms[0] = 0;
    ms[1] = abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        ll d1 = ms[i-1] + abs(h[i-1]-h[i]);
        ll d2 = ms[i-2] + abs(h[i-2]-h[i]);
        ms[i] = min(d1,d2);
    }

    return ms[n-1];
}


int main(){
    ll n;
    cin>>n;
    ll h[n];
    for(ll i=0;i<n;i++) cin>>h[i];
    cout<<frog(h,n)<<endl;
    return 0;
}
