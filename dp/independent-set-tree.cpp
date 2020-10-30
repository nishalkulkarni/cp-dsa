#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 1e9+7;

int main(){

    ll n;
    cin>>n;

    vector<ll> adj[n];

    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    vector<pair<ll,ll>> bw(n,{0,0}); 

    stack<ll> temp,to_process;
    temp.push(0);
    vector<bool> visited(n,false);
    visited[0] = true;

    while(!temp.empty()){
        ll t = temp.top();
        temp.pop();
        if(adj[t].size()==1 && t!=0)
            bw[t] = {1,1};
        else
            to_process.push(t);
        for(auto i:adj[t]){
            if(!visited[i]){
                visited[i] = true;
                temp.push(i);
            }
        }
    }

    while(!to_process.empty()){
        ll cur = to_process.top();
        to_process.pop();

        ll white = 1;
        ll black = 1;
        for(auto i:adj[cur]){
            if(bw[i].first !=0 && bw[i].second!=0){
                white = ((white%M) * (bw[i].first+bw[i].second)%M)%M;
                black = ((black%M) * (bw[i].second)%M)%M;
            }
        }
        bw[cur] = {black,white};
    }

    ll ans = (bw[0].first + bw[0].second)%M;
    cout<<ans<<endl;

    return 0;
}
