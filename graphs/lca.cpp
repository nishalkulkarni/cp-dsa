#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Tree {
	private:
		ll V;
		list<ll>* adj;
		vector<ll> euler,height,first;
	public:
		Tree(ll V) {
			this->V = V;
			adj = new list<ll>[V];
			height.resize(V);
			first.resize(V);
		}

		void addEdge(ll x, ll y) {
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		void genEuler(ll sp, vector<bool> &visited){
			euler.push_back(sp);

			visited[sp] = true;
			first[sp] = euler.size()-1;

			for(auto i:adj[sp]){
				if(visited[i]==false){
					height[i] = height[sp] + 1;
					genEuler(i,visited);
					euler.push_back(sp);
				}
			}

		}


		void printeuler(){
			for(auto i:euler){
				cout<<i<<' ';
			}cout<<endl;
			for(auto i:height){
				cout<<i<<' ';
			}cout<<endl;
			for(auto i:first){
				cout<<i<<' ';
			}cout<<endl;

		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	Tree g(n);

	ll edges;
	cin >> edges;

	for (ll i = 0; i < edges; i++) {
		ll x, y;
		cin >> x >> y;
		g.addEdge(x - 1, y - 1);
	}
	vector<bool> visited(n,false);
	g.genEuler(0,visited);
	g.printeuler();
	return 0;
}
