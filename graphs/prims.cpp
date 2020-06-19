#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class MinHeap {
    vector<pair<ll, ll>> min_heap;
    unordered_map<ll, ll> ele_pos;

    public:
    pair<ll, ll> top() {
        return min_heap[0];
    }

    ll getElementPos(ll ele){
        return ele_pos[ele];
    }

    ll heapSize(){
        return min_heap.size();
    }

    void heapify(ll pos) {
        // Heapify Up
        while (pos != 0 && min_heap[pos].second < min_heap[(int)((pos - 1) / 2)].second) {
            ll parent = (int)((pos - 1) / 2);
            ele_pos[min_heap[pos].first] = parent;
            ele_pos[min_heap[parent].first] = pos;

            swap(min_heap[pos], min_heap[parent]);

            pos = parent;
        }

        // Heapify Down
        ll lpos = 2 * pos + 1;
        ll rpos = 2 * pos + 2;
        ll smallest = pos;

        if (lpos < min_heap.size() && min_heap[smallest].second > min_heap[lpos].second) {
            smallest = lpos;
        }

        if (rpos < min_heap.size() && min_heap[smallest].second > min_heap[rpos].second) {
            smallest = rpos;
        }

        if (smallest != pos) {
            ele_pos[min_heap[pos].first] = smallest;
            ele_pos[min_heap[smallest].first] = pos;

            swap(min_heap[smallest], min_heap[pos]);

            heapify(smallest);
        }
    }

    void insertHeap(pair<ll, ll> ele) {
        ll pos = min_heap.size();
        min_heap.push_back(ele);
        ele_pos[ele.first] = pos;
        heapify(pos);
    }

    void deleteHeap(ll pos) {
        ll last_pos = min_heap.size()-1;

        ele_pos.erase(min_heap[pos].first);
        ele_pos[min_heap[last_pos].first] = pos;

        min_heap[pos] = min_heap[last_pos];

        
        min_heap.pop_back();
        last_pos--;

        heapify(pos);
    }

    void printHeap() {
        for (auto i : min_heap) {
            cout << i.first << " " << i.second << endl;
        }
    }
};

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

    void primsMST() {
        ll total_sum = 0;
        vector<bool> visited(V, false);
        visited[0] = true;

        MinHeap mh;
        ll last_pos = -1;

        vector<ll> key(V, INT_MAX);
        for (auto i : adj[0]) {
            key[i.first] = i.second;
        }

        for (int i = 1; i < V; i++) {
            mh.insertHeap(make_pair(i, key[i]));
        }

        while (mh.heapSize() !=0) {
            pair<ll, ll> top = mh.top();
            mh.deleteHeap(0);

            cout<<"Vertex picked - "<<top.first<<" with edge weight - "<<top.second<<endl;

            total_sum += top.second;

            visited[top.first] = true;

            for (auto i : adj[top.first]) {
                if (!visited[i.first]) {
                    mh.deleteHeap(mh.getElementPos(i.first));
                    key[i.first] = min(key[i.first], i.second);
                    mh.insertHeap(make_pair(i.first, key[i.first]));
                }
            }
        }

        cout << total_sum << endl;
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

    g.primsMST();

    return 0;
}
