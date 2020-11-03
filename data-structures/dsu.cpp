#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class DSU{
    ll n;
    ll *p,*r,*sum,*mini;
    public:
    DSU(int n){
        this->n = n;
        p = new ll[n];
        r = new ll[n];
        sum = new ll[n];
        mini = new ll[n];
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
            sum[i] = i;
            mini[i] = i;
        }
    }

    ll get(ll a){
        return p[a]=(p[a]==a?a:get(p[a]));
    }

    void Union(ll a,ll b){
        a = get(a);
        b = get(b);
        if(r[a]==r[b])
            r[a]++;
        if(r[a]>r[b]){
            p[b] = a;
            sum[a] += sum[b];
            mini[a] = min(mini[a],mini[b]);
        }else{
            p[a] = b;
            sum[b] += sum[a];
            mini[b] = min(mini[a],mini[b]);
        }
    }

    void printArr(){
        for(int i=0;i<n;i++) cout<<p[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<r[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<sum[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<mini[i]<<" ";
        cout<<endl;
    }
};
int main(){
    DSU d(6);
    d.printArr();
    d.Union(0,4);
    d.Union(2,0);
    d.Union(1,3);
    cout<<"fdsbkjfbwekhjbfrwkf\n";
    d.printArr();
    return 0;
}
