#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Graph {
    ll V, E;
    list<pair<ll, ll>>* adj;

    public:
    Graph(ll V, ll E) {
        this->V = V;
        this->E = E;
        adj = new list<pair<ll, ll>>[V];
    }

    void addEdge(ll x, ll y, ll c) {
        adj[x].push_back(make_pair(y, c));
        adj[y].push_back(make_pair(x, c));
    }

    void kruskalMST(){

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll V, E;
    cin >> V >> E;

    Graph g(V, E);

    for (ll i = 0; i < E; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        g.addEdge(x - 1, y - 1, c);
    }

    g.kruskalMST();

    return 0;
}