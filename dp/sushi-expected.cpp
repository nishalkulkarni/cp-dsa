#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 301;
double dp[MAX+1][MAX+1][MAX+1];

int main(){
    ll n;
    cin>>n;
    double a[n];
    vector<ll> count(4,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        count[a[i]]++;
    }
    
    ll max_ones = count[1]+count[2]+count[3]+1;
    ll max_twos = count[2]+count[3]+1;
    ll max_threes = count[3]+1;

    for(ll k=0;k<max_threes;k++){
        for(ll j=0;j<max_twos;j++){
            for(ll i=0;i<max_ones;i++){
                if(i==0 && j==0 && k==0){
                    dp[i][j][k] = 0;
                }else{
                    dp[i][j][k] = 1.0;

                    if(i)
                        dp[i][j][k] += i*dp[i-1][j][k]/n;
                    if(j)
                        dp[i][j][k] += j*dp[i+1][j-1][k]/n;
                    if(k)
                        dp[i][j][k] += k*dp[i][j+1][k-1]/n;

                    dp[i][j][k] *= n;
                    dp[i][j][k] /= (i+j+k);
                }
            }
        }
    }

    cout<<fixed<<setprecision(15)<<dp[count[1]][count[2]][count[3]]<<endl;
    return 0;
}
