#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin>>s>>t;

    ll dp[s.length()+1][t.length()+1];

    for(int i=0;i<=s.length();i++)
        for(int j=0;j<=t.length();j++)
            dp[i][j] = 0;

    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){

            if(s[i-1]==t[j-1]){
                dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+1);
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                /* dp[i][j] = dp[i-1][j]; */
            }
        }
    }

    string ans = "";
    int i=s.length(),j=t.length();
    while(dp[i][j]!=0){
        while(dp[i][j]==dp[i][j-1]) j--;
        while(dp[i][j]==dp[i-1][j]) i--;
        ans += t[j-1]; 
        i-=1;
        j-=1;

    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

    return 0;
}
