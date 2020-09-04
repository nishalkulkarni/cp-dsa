#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// O(|s|) online algorithm
vector<int> prefix(string s){
    int n = s.length();
    vector<int> pi(n,0);

    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 && s[i] != s[j])
            j = pi[j-1];

        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){

    string s = "aabaaab";
    int n = s.size();

    cout<<s<<endl;

    auto pi = prefix(s);

    for(auto i:pi)
        cout<<i<<" ";
    cout<<endl;

    // kmp substring search in O(n+m) and O(n) memory use s+#
    // -------------------------------

    // # of occurences of each prefix for same string
    vector<int> ans(n+1);
    for(int i=0;i<n;i++)
        ans[pi[i]]++;
    for(int i=n-1;i>0;i--)
        ans[pi[i-1]] += ans[i];
    for(int i=0;i<=n;i++)
        ans[i]++;
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;

    // # of occurences of each prefix in another string t
    // s+#+t -> compute prefix function -> get pi[i] for i>=n+1 
    // rest same as above
    
    // number of different substring in a string by appending a char --> t=s+c
    // reverse t compute pi max
    // number of new substrings = |s|+1-piMax
    
    // Compressing a string
    //  k=n−pi[n−1]. 
    //  if k divides n, then k will be the answer, otherwise there doesn't exists an effective compression and the answer is n.

    return 0;
}
