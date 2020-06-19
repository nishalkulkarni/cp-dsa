#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Graph {
    private:
    ll V;
    list<ll>* adj;

    public:
    Graph(ll V) {
        this->V = V;
        adj = new list<ll>[V];
    }

    void addEdge(ll x, ll y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool dfs(ll u, ll v, vector<bool>& visited, vector<ll>& path) {
        path.push_back(u + 1);
        visited[u] = true;
        if (u == v) {
            return true;
        }

        for (auto i : adj[u]) {
            if (!visited[i]) {
                if (dfs(i, v, visited, path)) {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    Graph g(n);

    ll edges;
    cin >> edges;

    for (ll i = 0; i < edges; i++) {
        ll x, y;
        cin >> x >> y;
        g.addEdge(x - 1, y - 1);
    }

    ll u, v;
    cin >> u >> v;
    vector<bool> visited(n);
    vector<ll> path;
    g.dfs(u - 1, v - 1, visited, path);

    for (auto i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
