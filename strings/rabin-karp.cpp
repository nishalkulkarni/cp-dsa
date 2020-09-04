#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// O(|t|+|s|)
vector<int> rabin_karp(string s, string t){
    ll p = 31,m = 1e9+9, S = s.size(), T = t.size();

    vector<ll> p_pow(max(S,T));
    p_pow[0] = 1;

    for(int i=1;i< (int)p_pow.size();i++)
        p_pow[i] = (p_pow[i-1]*p)%m;

    vector<ll> h(T+1,0);
    ll h_s = 0;
    for(int i=0;i<S;i++)
        h_s = (h_s + (s[i] - 'a' +1) * p_pow[i])%m;

    for(int i=0;i<T;i++)
        h[i+1] = (h[i] + (t[i] - 'a' +1) *p_pow[i])%m;
    
    vector<int> occurences;
    for(int i=0;i+S-1<T;i++){
        ll cur_h = (h[i+S] +m -h[i])%m;
        if(cur_h == h_s * p_pow[i] %m)
            occurences.push_back(i);
    }
    return occurences;
}

int main(){

    string s="is",t="nishalashish";

    auto rk = robin_karp(s,t);

    for(auto i:rk)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
