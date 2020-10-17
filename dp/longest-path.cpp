#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> to(n+1); 
    vector<vector<ll>> from(n+1); 

    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        to[x].push_back(y);
        from[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        to[0].push_back(i);
        from[i].push_back(0);
    }

    vector<pair<ll,ll>> vp(n+1);
    for(int i=0;i<=n;i++){
        vp[i].second = to[i].size();
        vp[i].first = from[i].size();
    }


    ll total_max = 0;
    queue<ll> q;
    q.push(0);
    vector<ll> maxpath(n+1,0);
    while(q.size()!=0){
        ll f = q.front();
        q.pop();
        for(auto j:to[f]){
            vp[j].first--;
            maxpath[j] = max(maxpath[j],maxpath[f]+1); 
            total_max = max(total_max,maxpath[j]);
            if(vp[j].first==0){
                q.push(j);
            }
        }
    }

    cout<<total_max-1<<endl;
    return 0;
}
