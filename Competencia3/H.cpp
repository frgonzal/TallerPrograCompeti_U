#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> grados;
vector<pair<ll,ll>> resultado;
vector<vector<ll>> adj;
struct DSU{
    vector <int> parent, sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            sz[i] = 1;}}
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);}
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];}}
};
void kruskal(int n, vector<tuple<ll,int,int>> &edges){
	DSU dsu(n);
    ll grado_ = -1;
    ll nodo = -1;
    for(int i=0;i<n;i++){
        if(grados[i] > grado_){
            grado_ = grados[i];
            nodo = i;
        }
    }
    for(ll x: adj[nodo]){
        dsu.union_set(nodo, x);
        resultado.push_back({nodo, x});
    }
	for(auto [w, u, v] : edges){
		if(dsu.find_set(u) != dsu.find_set(v)){
			dsu.union_set(u, v);
            resultado.push_back({u,v});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
    grados.assign(n, 0);
	vector <tuple<ll,int,int>> edges(m);
    adj.assign(n, vector<ll>());

	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
        grados[u]++;
        grados[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
		edges[i] = {1, u, v};
	}
	kruskal(n, edges);
    for(auto [x,y]: resultado){
        cout << x<<" "<<y<<endl;
    }
	return 0;
}
