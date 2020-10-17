#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main(){

    ll h,w;
    cin>>h>>w;
    int a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char ch;
            cin>>ch;
            if(ch=='.') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }

    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(i==h-1 && j==w-1) 
                a[i][j] = 1;
            else if(i==h-1 && j!=w-1 && a[i][j]==-1)
                a[i][j] = a[i][j+1];
            else if(i!=h-1 && j==w-1 && a[i][j]==-1)
                a[i][j] = a[i+1][j];
            else if(a[i][j]==-1) 
                a[i][j] = (a[i+1][j] +a[i][j+1])%mod;
        }
    }

    cout<<a[0][0]<<endl;
    return 0;
}
