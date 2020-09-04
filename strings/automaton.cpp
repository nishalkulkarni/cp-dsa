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

// O(n*26)
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}


int main(){

    string s = "aabaaab";
    int n = s.size();


    return 0;
}
