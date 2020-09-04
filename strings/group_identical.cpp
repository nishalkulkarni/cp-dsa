#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll compute_hash(string const& s){
    const int p = 31, m = 1e9+9;
    ll hash_value = 0, p_pow = 1;
    
    for(char c:s){
        hash_value = (hash_value + (c-'a'+1)*p_pow)%m;
        p_pow = (p_pow*p)%m;
    }
    return hash_value;
}

// O(nm+nlogn)
vector<vector<int>> group_identical_strings(vector<string> const& s){
    int n = s.size();
    vector<pair<long long, int>> hashes(n);

    for(int i=0;i<n;i++){
        hashes[i] = {compute_hash(s[i]), i};
    }

    sort(hashes.begin(),hashes.end());

    vector<vector<int>> groups;
    for(int i=0;i<n;i++){
        if(i==0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}


int main(){
    
    vector<string> names = {"nishal","pranav","suyasha","nishal","pranav","nishal"};

    /* cout<<compute_hash("nishal")<<endl; */
    
    auto gp = group_identical_strings(names);
    
    for(auto i:gp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}
